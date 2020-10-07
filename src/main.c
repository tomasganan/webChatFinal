#include "sql.h"
#include <stdio.h>
#include <iniparser.h>

int main(int argc, const char **argv) {
  read_data();
}


/// Funcion IniParser

void read_data() {
  // IniParser
  char *nomFile = "config.ini";
  char *server, *userdb, *password, *database, *ip;
  int port;
  dictionary *ini = NULL;

  // Cargo archivo de configuracion .ini

  ini = iniparser_load(nomFile);

  server = iniparser_getstring(ini, "DATABASE:server", NULL);
  // printf("%s\n", server);
  userdb = iniparser_getstring(ini, "DATABASE:userdb", NULL);
  // printf("%s\n", userdb);
  password = iniparser_getstring(ini, "DATABASE:password", NULL);
  // printf("%s\n", password);
  if (!strcmp(password, ""))
    password = NULL;

  database = iniparser_getstring(ini, "DATABASE:database", NULL);
  // printf("%s\n", database);
  ip = iniparser_getstring(ini, "SERVER:ip", NULL);
  // printf("%s\n", ip);
  port = iniparser_getint(ini, "SERVER:port", -1);
  // printf("%d\n", port);

  // TODO: Chequear porque hay que comentar esta linea, talvez
  // utilizar un memcpy para copiar los datos a otra dirección
  // iniparser_freedict(ini);

  printf("server: %s\n userdb: %s\n password: %s\n database: %s\n ip: %s\n port: %d\n", server, userdb, password, database, ip, port);
  
}