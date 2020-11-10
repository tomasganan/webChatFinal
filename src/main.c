#include "sql.h"
#include <stdio.h>
#include <iniparser.h>
#include <libwebsockets.h>

/// Estructura para la conexión

struct connection{
    char *server;
    char *userdb;
    char *password;
    char *database;
    char *ip;
    int port;
};

/// Funcion Explode



/// Funcion IniParser

void read_data(struct connection *con) {
  // IniParser
  char *nomFile = "config.ini";
  
  dictionary *ini = NULL;

  // Cargo archivo de configuracion .ini

  ini = iniparser_load(nomFile);

  con->server = iniparser_getstring(ini, "DATABASE:server", NULL);
  // printf("%s\n", server);
  con->userdb = iniparser_getstring(ini, "DATABASE:userdb", NULL);
  // printf("%s\n", userdb);
  con->password = iniparser_getstring(ini, "DATABASE:password", NULL);
  // printf("%s\n", password);
  if (!strcmp(con->password, ""))
    con->password = NULL;

  con->database = iniparser_getstring(ini, "DATABASE:database", NULL);
  // printf("%s\n", database);
  con->ip = iniparser_getstring(ini, "SERVER:ip", NULL);
  // printf("%s\n", ip);
  con->port = iniparser_getint(ini, "SERVER:port", -1);
  // printf("%d\n", port);

  // TODO: Chequear porque hay que comentar esta linea, talvez
  // utilizar un memcpy para copiar los datos a otra dirección
  // iniparser_freedict(ini);  
}

/// Callback HTTP

static int callback_http(struct lws *wsi,
                         enum lws_callback_reasons reason, void *user,
                         void *in, size_t len){
	return 0;
}

/// Callback Dumb Increment

static int callback_dumb_increment(struct lws *wsi,
                                   enum lws_callback_reasons reason,
                                   void *user, void *in, size_t len){
                                       
long wsi_adress = wsi; // El WSI seria como el puntero a la instancia de un websocket  
conn = mysql_init(NULL); // Declaracion de variable para la dB

/// Conexion a la base de datos

// if (!mysql_real_connect(conn, server, userdb, password, database, port, NULL, 0)){
//     fprintf(stderr, "%s\n", mysql_error(conn)); // En caso de error, lo comunica
//     exit(1);
// }

switch (reason) {
    case LWS_CALLBACK_PROTOCOL_INIT:
        printf("LWS_CALLBACK_PROTOCOL. \n");
        break;

    /// EStablecer conexión

    case LWS_CALLBACK_ESTABLISHED:
        printf("CONEXION ESTABLECIDA. \n");
        break;

    /// Cerrar conexión
    
    case LWS_CALLBACK_CLOSED:
        snprintf(query, MAX_STRING, "DELETE FROM users WHERE token=%lu", wsi_adress);
            if (mysql_query(conn, query)) {
                    fprintf(stderr, "%s\n", mysql_error(conn));
            }        
            reset_contact(len); // Reseteo del contacto
          printf("FIN DE SESION.\n");
        break;

    ///
    
    case LWS_CALLBACK_SERVER_WRITEABLE:
        printf("LWS_CALLBACK_SERVER_WRITEABLE. \n");
        break;

    case LWS_CALLBACK_RECEIVE:
        printf("LWS_CALLBACK_RECEIVE \n");
        break;
    
    default:
        printf("DEFAULT! %d \n",reason);
        break;
    }
    return 0;
}
// Config. protocolo, nombre identificatorio del socket en el front

static struct lws_protocols protocols[] = {
    {
        "http-only",   // Protocolo
        callback_http, // Funcion definida por si alguien escribe por http-only
        0             
    },
    {/* dumb */
        "dumb-increment-protocol", // "ID" del socket para el front. Archivo en comun que comparto con el front
        callback_dumb_increment,   //  Funcion para comunicarse en caso de que alguien escriba por dumb-increment-protocol
        0                          
    },
    {
        NULL, NULL, 0   //
    }
};

// -------------| M A I N | -------------



int main(int argc, const char **argv) {

    struct connection con; // Declaracion del a estructura connection
    read_data(&con); // Pasamos la posicion de memoria de la estructura

    // printf("server: %s\n userdb: %s\n password: %s\n database: %s\n ip: %s\n port: %d\n", 
    //         con.server, con.userdb, con.password, con.database, con.ip, con.port);



    // La URL del servidor será: http://localhost:9000
    conn = mysql_init(NULL);
   
    // Conexion a la base de datos
    if (!mysql_real_connect(conn, con.server, con.userdb, con.password, con.database, con.port, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

        snprintf(query, MAX_STRING, "TRUNCATE TABLE users;"); // Eliminacion de todos los user
    
    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    mysql_close(conn);



    // Configuracion para la creacion del socketport

    struct lws_context *context;
    struct lws_context_creation_info context_info = {
        .port = con.port, 
        .iface = NULL, .protocols = protocols,
        .extensions = NULL,
        .ssl_cert_filepath = NULL,
        .ssl_private_key_filepath = NULL,
        .ssl_ca_filepath = NULL,
        .gid = -1, .uid = -1,
        .options = 0, NULL,
        .ka_time = 0,
        .ka_probes = 0,
        .ka_interval = 0
    };
    
    context = lws_create_context(&context_info); // Crear conexion/contexto

    if (context == NULL) {
        fprintf(stderr, "LWS falló \n");
        return -1;
    }
    
    printf("Inicio de servidor...\n");
    
    while (1) {
        lws_service(context, 50); // Proceso de todos los eventos
    }
    
    lws_context_destroy(context); // Destruye la conexion


}