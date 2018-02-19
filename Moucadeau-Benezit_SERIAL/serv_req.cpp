#include "serv_req.hpp"

serveur::serveur(int _p=1997) {
	sockserver.sin_family = AF_INET;
	sockserver.sin_port = htons(_p);
	sockserver.sin_addr.s_addr = INADDR_ANY;
	bzero(&(sockserver.sin_zero),8);

	//Creation d'un socket
	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ) {
		cerr << "Serveur : erreur creation socket()" << endl;
		exit(-1);
	}

	//liaison (bind) avec le serveur
	if(bind(fd,(struct sockaddr*)&sockserver,sizeof(struct sockaddr)) == -1) {
		cerr << "Serveur : erreur bind()" << endl;
		exit(-1);
	}

	//mise sur écoute
	if(listen(fd,BACKLOG) == -1) {
		cerr << "Serveur : erreur listen()" << endl;
		exit(-1);
	}

}

int serveur::reception(const int _fd, char * _buf) {
int numbytes;
//char buf[MAXDATASIZE];

	if ((numbytes = recv(_fd, _buf,MAXDATASIZE,0)) == -1) {
		cerr << "Serveur : erreur recv()" << endl;
		exit(-1);
		}
	_buf[numbytes] = '\0';
return numbytes;
}

int serveur::attente(void) {
socklen_t sin_size;
int  fd_temp;
struct sockaddr_in client;


sin_size = sizeof(struct sockaddr_in);

	if ((fd_temp = accept(fd,(struct sockaddr *)&client,&sin_size)) == -1){
		cerr << "Serveur : erreur accept()" << endl;
		exit(-1);
	}
	cout << "Serveur : connexion de " << inet_ntoa(client.sin_addr) << endl;
return fd_temp;
}

void serveur::deconnexion(const int _fd) {
	close(_fd);
}

int serveur::emission(const int _fd, const char* _s) {
  int r;
	r = send(_fd, (void *) _s, (size_t) strlen(_s), 0);
	return r;
}

serveur::~serveur(void) {
	close(fd);
}
