#ifndef SQL_H
#define SQL_H

#include <libwebsockets.h>
#include <mysql/mysql.h>

#define MAX_STRING 128


void push(long element);
long pop();

int maybe_init_conection(char *server, char *userdb,
			 char *pass, char *db, int port);
int insert_usr(char *name, unsigned long token);
int insert_msg(char *from, char *to, char *msj);
int select_all();
int select_by_name(char *contact);
int select_by_token(long *wsi);
int f_truncate();

int update();

static char query[MAX_STRING];
static char messagefull[MAX_STRING];
static char query2[MAX_STRING];
static char username[MAX_STRING];
static char iscontact[MAX_STRING];
static char message[MAX_STRING];
static char contact[MAX_STRING];

static MYSQL *conn;
static MYSQL_RES *res;
static MYSQL_ROW row;

#endif /* SQL_H */
