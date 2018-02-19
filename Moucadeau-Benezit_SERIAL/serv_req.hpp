//R. Raffin IUT Aix-Marseille, dépt. Informatique, Arles
//Code Serveur pour les Sockets
//attend les clients (en boucle), si connexion, envoie un message et quitte
//Compilation : g++ -Wall sockserv.cpp -o serveur
//votre classe serveur
#include <iostream>

#include <cstdlib>
#include <unistd.h>
#include <cstring>

//pour les sockets
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//#include <pthread.h>
//#include <unordered_map>
//#include <sstream>
#define BACKLOG 2
#define MAXDATASIZE 100

using namespace std;

class serveur {
	private:
		int fd;
		struct sockaddr_in sockserver;
	public:
		serveur(int);
		~serveur(void);
		int attente(void);
		int emission(const int, const char *);
		int reception(const int, char * _buf);
		void deconnexion(const int);
};
