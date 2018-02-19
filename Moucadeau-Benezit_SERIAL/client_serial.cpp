#include "cli_req.hpp"
#include "monomial.hpp"
#include "polynomial.hpp"


int main(int argc, char *argv[])
{
//verif argument
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " <Addresse IP serveur> [<port>]" << endl;
		exit(-1);
	}
//SERIALISATION











//envoie serveur
	client * monclient;

//Si le client veut se connecter sur un numéro de port particulier
	if (argc == 3) {
		unsigned int port = strtol(argv[2], (char **) NULL, 10);
		monclient = new client (argv[1], port);
	}else{
		monclient = new client (argv[1], 3350);
	}
//connection
	monclient -> connexion();
//boucle permetant d'envoyer autant de message de possible
	char* message = new char[MAXDATASIZE];
	while(strcmp(message, "quit")){
		cout << "entré une message pour le serveur (taper quit pour quitter) >" << endl;
		cin >> message;
		monclient -> emission(message);
		monclient -> reception();
	}
return EXIT_SUCCESS;
}
