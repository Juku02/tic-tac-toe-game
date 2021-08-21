#ifndef CONNECTION_H
#define CONNECTION_H

#define MAX 4096

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

class Connection
{
private:
   int port;
   char buffor[MAX];
   char *hostname;
   
public:
   void initServerConnection();
   void initClientConnection();
   void finishConnection();
   void mutex();
};


#endif