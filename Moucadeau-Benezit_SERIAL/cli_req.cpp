#include "cli_req.hpp"
using namespace std;


client::client(const char* _serveur, int _port = 3550) {
struct hostent *he;

	//est-ce que le serveur existe ? (adresse ip valide)
	if ((he = gethostbyname(_serveur)) == NULL){
		cerr << "Client : erreur gethostbyname()" << endl;
		exit(-1);
	}

	//creation d'un socket
	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		cerr << "Client : erreur socket()" << endl;
		exit(-1);
	}

	sockclient.sin_family = AF_INET;
	sockclient.sin_port = htons(_port);
	sockclient.sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(sockclient.sin_zero),8);
}

client::~client(void) {
	close(fd);
}

void client::connexion(void) {

	if(connect(fd, (struct sockaddr *)&sockclient,sizeof(struct sockaddr)) == -1){
		cerr << "Client : erreur connect()" << endl;
		exit(-1);
	}
}

int client::reception(void) {
int numbytes;
char buf[MAXDATASIZE];

	if ((numbytes = recv(fd,buf,MAXDATASIZE,0)) == -1){
		cerr << "Client : erreur recv()" << endl;
		exit(-1);
	}
	buf[numbytes] = '\0';
	cout << "Client : message du serveur : " << buf << endl;

return numbytes;
}
//fonction reception surcharger pour pouvoir recuperer le message serveur dans un bufer
int client::reception(char* buff) {
int numbytes;
char buf[MAXDATASIZE];

	if ((numbytes = recv(fd,buf,MAXDATASIZE,0)) == -1){
		cerr << "Client : erreur recv()" << endl;
		exit(-1);
	}
	buf[numbytes] = '\0';
	cout << "Client : message du serveur : " << buf << endl;
	strcpy(buff, buf);

return numbytes;
}


int client::emission(const char* _s) {
int r;

	r = send(fd, (void *) _s, (size_t) strlen(_s), 0);
	return r;
}
