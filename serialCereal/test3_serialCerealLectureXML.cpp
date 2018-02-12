//R. Raffin, IUT AIX-Marseille, dept. Informatique, Arles
//Lecture d'un fichier XML qui contient la sérialisation des données d'une classe simple.
//compilation : g++ -Wall -std=c++11 -Icereal-1.2.2/include test3_serialCerealLectureXML.cpp -o lectureXML

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


int main() {
	std::ifstream file( "out.xml" );
	cereal::XMLInputArchive archive( file );

	MyClass cClass;


	archive( cClass);

	std::cout << cClass.x << " " <<  cClass.y  << " "<<  cClass.z  << " " << cClass.maChaine << std::endl;
return (0);
}
