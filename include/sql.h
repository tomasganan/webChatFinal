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

#endif /* SQL_H */
