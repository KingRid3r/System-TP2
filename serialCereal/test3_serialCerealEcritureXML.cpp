//R. Raffin, IUT AIX-Marseille, dept. Informatique, Arles
//Ecriture d'un fichier XML qui contient la sérialisation des données d'une classe simple.
//compilation : g++ -Wall -std=c++11 -Icereal-1.2.2/include test3_serialCerealEcritureXML.cpp -o ecritureXML

#include <cereal/archives/xml.hpp>
#include <fstream>
#include <iostream>

class MyClass
{
  public:
	int x, y, z;
	std::string maChaine;
	void add(const int& _v) {x+=_v; y+=_v; z+=_v;};
};

template<class Archive> void serialize(Archive & archive, MyClass & m)
{
	archive( m.x, m.y, m.z, m.maChaine );
}


int main()
{
	std::ofstream file( "out.xml" );
	cereal::XMLOutputArchive archive( file );	// depending on the archive type, data may be
												// output to the stream as it is serialized, or
												// only on destruction

	MyClass cClass;
		cClass.x = 10;
		cClass.y = 20;
		cClass.z = 30;
		cClass.maChaine = std::string("Mon p'tit texte");

	archive( cClass );



return (0);
}





