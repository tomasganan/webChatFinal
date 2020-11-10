#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "sql.h"

#define STACK_SIZE 100
#define QUERY_SIZE 200

char **arr;
char **arr2;
char isUserNameString[MAX_STRING] = {0};
char contact[MAX_STRING] = {0};
char from[MAX_STRING] = {0};
char to[MAX_STRING] = {0};
char date[MAX_STRING] = {0};
char msj[MAX_STRING] = {0};


MYSQL *conn;
/* MYSQL_RES *res;
 * MYSQL_ROW row; */

long stack[STACK_SIZE];
int top = -1;
int conection_status = 0;

int maybe_init_conection(char *server, char *userdb, char *pass, char *db,
			 int port) {
  if (!conection_status) {
    conn = mysql_init(NULL); // Declaracion de variable para la db

    // Conexion a la base de datos
    if (!mysql_real_connect(conn, server, userdb, pass, db, port, NULL, 0)) {
      fprintf(stderr, "%s\n",
	      mysql_error(conn)); // En caso de error, lo comunica
      fprintf(stderr, "WebChat: Error conección.\n");
      exit(1);
    } else {
      printf("Conexión establecida correctamente.\n");
    }
    conection_status = 1;
    return 200;
  } else
    return 1;
}

void push(long element) {
  if (top >= STACK_SIZE) {
    printf("NO se puede agregar más elementos. \n");
    return;
  }
  top++;                // Incrementar
  stack[top] = element; // Pushear
  printf("Datos pusheados OK. \n");
}

/// Funcion pop (Elimina elementos de la pila)

long pop() {
  if (top < 0) {
    printf("Pila vacia.\n");
    return INT_MIN;
  }
  return stack[top--];
}

/// Función para insertar usuarios

int insert_usr(char *name, unsigned long token) {
  int exit_code = 0;

  char query[QUERY_SIZE];
  snprintf(query, MAX_STRING,
	  "INSERT INTO users (name, token) VALUES ('%s', '%lu')", name, token);

  if (mysql_query(conn, query)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    fprintf(stderr, "WebChat: Error query insert_usr.\n");
    exit_code = 1;
  }
  return exit_code;
}

/// Función para insertar mensajes

int insert_msg(char *from, char *to, char *msj){
  int exit_code = 0;

  char query[QUERY_SIZE];
  snprintf(query, MAX_STRING, 
    "INSERT INTO msj (desde, recibe, mensaje) VALUES ('%s', '%s', '%s');", from, to, msj);   
      
  if (mysql_query(conn, query)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    fprintf(stderr, "WebChat: Error query insert_msg.\n");
    exit_code = 1;
  }
  return exit_code;
}

/// Seleccion de todos los usuarios.

int select_all(){
  int exit_code = 0;

  char query[QUERY_SIZE];
  snprintf(query, MAX_STRING, "SELECT * FROM users");

  if (mysql_query(conn, query)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
    exit_code = 1;
  }
  return exit_code;
}

/// Seleccion de usuario por nombre

int select_by_name(char *contact){
  int exit_code = 0;

  char query[QUERY_SIZE];
  snprintf(contact, MAX_STRING, "%s",  arr2[1]);
  snprintf(query, MAX_STRING,
    "SELECT * FROM users WHERE name='%s'",  contact); // Consulto a la dB por el user destinario
                        
  if (mysql_query(conn, query)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit_code = 1;
  }
  return exit_code;
}

/// Seleccion de usuario por token 

int select_by_token(long *wsi){
  int exit_code = 0;

  char query[QUERY_SIZE];
  snprintf(query, MAX_STRING,
    "SELECT * FROM users WHERE token='%ln'",  wsi);

  if (mysql_query(conn, query)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit_code = 1;
  }
  return exit_code;
}

/// Truncate

int f_truncate(){
  int exit_code = 0;

  char query[QUERY_SIZE];
  snprintf(query, MAX_STRING,
    "TRUNCATE TABLE users;"); // Eliminacion de todos los user
    
  if (mysql_query(conn, query)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
    exit_code = 1;
  }
  return exit_code;
}

///

int update();

// Funcion reset (Reseteo de contacto = user)

void reset_contact(int len, char* query, MYSQL* conn, MYSQL_RES* res, MYSQL_ROW* row) {
  char contact[MAX_STRING] = {0};
  char reset[MAX_STRING] = {0};
  char *out = NULL;
  snprintf(query, MAX_STRING, "SELECT * FROM users"); // Guardo los ID de todos los usuarios

  if (mysql_query(conn, query)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }
  res = mysql_store_result(conn);
  char value[10];
  char *eptr;
  long long wsi_long;
  while ((row = mysql_fetch_row(res)) != NULL) {
    strcpy(value, row[1]);
    wsi_long = strtoll(value, &eptr, 10);
    free(out);
    push(wsi_long);
  }
  mysql_free_result(res);

  snprintf(query, MAX_STRING, "SELECT * FROM users");

  if (mysql_query(conn, query)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }


  int i = 0;
  for (i = 0; i < top + 1; i++) { // Recorro la pila
    snprintf(reset, MAX_STRING, "reset");
    len = strlen(reset);
    out = (char *)malloc(sizeof(char) * (LWS_SEND_BUFFER_PRE_PADDING + len +
                                         LWS_SEND_BUFFER_POST_PADDING));
    // Configuracion del buffer
    memcpy(out + LWS_SEND_BUFFER_PRE_PADDING, reset, len);

    lws_write(stack[i], out + LWS_SEND_BUFFER_PRE_PADDING, len, LWS_WRITE_TEXT);

    free(out);
  }
  res = mysql_store_result(conn);
  int j = 0;
  while ((row = mysql_fetch_row(res)) != NULL) { // Refresh de usuarios
    for (j = 0; j < top + 1; j++) {
      snprintf(contact, MAX_STRING, "contact:%s", row[2]);
      len = strlen(contact);

      out = (char *)malloc(sizeof(char) * (LWS_SEND_BUFFER_PRE_PADDING + len +
                                           LWS_SEND_BUFFER_POST_PADDING));
      // Configuracion del buffer
      memcpy(out + LWS_SEND_BUFFER_PRE_PADDING, contact, len);

      lws_write(stack[j], out + LWS_SEND_BUFFER_PRE_PADDING, len,
                LWS_WRITE_TEXT);
      free(out);
 }
  }
  pop();

  mysql_free_result(res);
}