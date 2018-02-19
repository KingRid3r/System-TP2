#include "serv_req.hpp"
#include "monomial.hpp"
#include "polynomial.hpp"



int main(void)
{
//creation du serveur
	serveur monserveur (2001);
	int fd_client;
	char* buff = new char[MAXDATASIZE];
//attente de connection
	fd_client = monserveur.attente();
//boucle permetant autant de reception que voulu
	while(strcmp(buff, "quit")){
		monserveur.reception(fd_client, buff);
		cout << fd_client << " : " << buff << "\n";
//Condition pour pouvoir verifier la reception du serveur final et de conserver quit pour le bon fonctionnnment de l'appli
		if(strcmp(buff,"quit")){
			monserveur.emission(fd_client,strcat(buff, " Lu-serv"));
		}else{
			monserveur.emission(fd_client,buff);
		}
	}

		monserveur.deconnexion(fd_client);
	return EXIT_SUCCESS;
}
