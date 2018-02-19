//R. Raffin IUT Aix-Marseille, dépt. Informatique, Arles
//Code Serveur pour les Sockets
//attend les clients (en boucle), si connexion, envoie un message et quitte
//Compilation : g++ -Wall sockserv.cpp -o serveur

//votre classe client légerement modifié
#ifndef _H_CLIENT
#define _H_CLIENT
#include <iostream>

#include <cstdlib>
#include <unistd.h>
#include <cstring>

//pour les sockets
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXDATASIZE 100
using namespace std;
class client {
	private:
		int fd;
		int port;
    struct sockaddr_in sockclient;
	public:
		client(const char*, int);
		~client(void);
		void connexion(void);
		int reception(void);
		int reception(char* buff);
		int emission(const char* _s);

};
#endif
