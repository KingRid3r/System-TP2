//R. Raffin, IUT AIX-Marseille, dept. Informatique, Arles
//Lecture d'un fichier JSON qui contient la sérialisation des données d'une classe simple.
//compilation :
//g++ -c -Wall -std=c++11 -I../cereal-1.2.2/include lectureJson.cpp
//g++ -Wall -std=c++11 lectureJson.o myClass.o -o lecture

#include <cereal/archives/json.hpp>
#include <fstream>
#include <iostream>
#include <stdio.h>

#include "myClass.hpp"

int main() {
	std::ifstream file( "out.json" );
	cereal::JSONInputArchive archive( file );

	MyClass cClass;


	archive( cClass);

	std::cout << cClass.x << " " <<  cClass.y  << " "<<  cClass.z  << " " << cClass.maChaine << " " << cClass.monFloat << std::endl;

	printf("float %.25f", cClass.monFloat);
return (0);
}
