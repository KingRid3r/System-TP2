//R. Raffin, IUT AIX-Marseille, dept. Informatique, Arles
//Ecriture d'un fichier JSON qui contient la sérialisation des données d'une classe simple.
//compilation :
//g++ -c -Wall -std=c++11 -I../cereal-1.2.2/include ecritureJson.cpp
//g++ -Wall -std=c++11 ecritureJson.o myClass.o -o ecriture

#include <cereal/archives/json.hpp>
#include <fstream>
#include <iostream>

#include "myClass.hpp"


int main()
{
	std::ofstream file( "out.json" );
	cereal::JSONOutputArchive archive( file );

	MyClass cClass;
		cClass.x = 10;
		cClass.y = 20;
		cClass.z = 30;
		cClass.maChaine = std::string("Mon p'tit texte");
		cClass.monFloat = 3.1415926535898;

	archive( cClass );

return (0);
}

/* FLOAT
Original:	3.1415926535898
byHand :	3.14159274101257324219
JSON :		3.1415927410125734
			3.1415927410125732421875000
* */