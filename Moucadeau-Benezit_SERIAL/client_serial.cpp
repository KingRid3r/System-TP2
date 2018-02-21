#include "cli_req.hpp"
#include "monomial.hpp"
#include "polynomial.hpp"
// #include "cereal-1.2.2/include/cereal/archives/json.hpp"
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
//verif argument
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " <Addresse IP serveur> [<port>]" << endl;
		exit(-1);
	}
//Demande de fonction polynomial
	size_t nbmono;

	do{
		cout << "Entrez un le nombre de monones à utiliés" << endl;
		cin >> nbmono;
	}while(nbmono > 1);
	polynomial poly;
	double buff_C;
	double buff_D;
	monomial buff_mono;
	for (size_t i = 0; i < nbmono; ++i){
		cout << "Entrez le coefficient du" << nbmono+1 << "monone" << endl;
		cin >> buff_C;
		cout << "Entrez le coefficient du" << nbmono+1 << "monone" << endl;
		cin >> buff_D;
		buff_mono = new monomial(buff_C, buff_D);
		poly.addMonomial(buff_mono);
	}
	cout << poly << endl;


//SERIALISATION
	//std::ofstream file( "out.json" );
	//cereal::XMLOutputArchive archive( file );










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
