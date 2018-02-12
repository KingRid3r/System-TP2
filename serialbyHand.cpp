//R. Raffin IUT Aix-Marseille, dept. Informatique, Arles
//test de sérialisation d'une structure "à la main"
#include <iostream>
#include <cstring>
#include <cstdio>

struct mydata {
	float myfloat;
	char * mytext;
	unsigned int myint;
	std::string myString;
};

int main() {

	//déclaration, allocation et remplissage
		struct mydata * mesdonnees = new struct mydata();
			mesdonnees->myfloat = 3.1415926535898;
			mesdonnees->myint = 1011970;
			mesdonnees->mytext = new char[50];
			strcpy(mesdonnees->mytext, "Une petite phrase de test");
			mesdonnees->myString = std::string("Une phrase plus longue pour tester la chaîne de type String");

	printf( "-------- Serialisation ------------\n");

	printf( "myfloat %.20f\n", mesdonnees->myfloat );
	printf( "myint %d\n", mesdonnees->myint );
	printf( "mytext %s\n", mesdonnees->mytext );
	printf( "strlen(mytext) %lu\n", strlen(mesdonnees->mytext) );

	std::cout << "myString " << mesdonnees->myString << std::endl;
	std::cout << "myString capacity " << mesdonnees->myString.capacity() << std::endl;
	std::cout << "myString size " << mesdonnees->myString.size() << std::endl;

	//serialisation
	char *buffer = new char [200];
	unsigned int index = 0;
		memcpy( (void*) (buffer + index), (void*) &(mesdonnees -> myfloat), sizeof(float) );
		index += sizeof(float);
std::cout << "\tindex = " << index<< std::endl;

		memcpy( (void*) (buffer + index), (void*) &(mesdonnees -> myint), sizeof(int) );
		index += sizeof(int);
std::cout << "\tindex = " << index<< std::endl;

		memcpy( (void*) (buffer + index), (void*) (mesdonnees -> mytext), (strlen(mesdonnees -> mytext) + 1)*sizeof(char) );
		index += (strlen(mesdonnees -> mytext) + 1)*sizeof(char);
std::cout << "\tindex = " << index<< std::endl;

/* Ne peut fonctionner
  		memcpy( (void*) (buffer + index), (void*) &(mesdonnees -> myString), 60 );
		index += sizeof(mesdonnees -> myString);
std::cout << "\tindex = " << index<< std::endl;
*/

delete [] mesdonnees->mytext;
delete mesdonnees;

	printf( "\n-------- De-serialisation ------------\n");


	//de-serialisation
	unsigned int index2 = 0;
		struct mydata * mesdonnees2 = new struct mydata();
			mesdonnees2->mytext = new char[50];

			memcpy((void *) &mesdonnees2->myfloat, (void*) (buffer + index2), sizeof(float));
			index2 += sizeof(float);
std::cout << "\tindex2 = " << index2 << std::endl;

			memcpy((void *) &mesdonnees2->myint, (void*) (buffer + index2), sizeof(int));
			index2 += sizeof(int);
std::cout << "\tindex2 = " << index2 << std::endl;

			memcpy( (void*) mesdonnees2 -> mytext, (void*) (buffer + index2), (26)*sizeof(char) ); //Ouh la triche !!
			index2 += (26)*sizeof(char);
std::cout << "\tindex2 = " << index2 << std::endl;

/*Ne peut fonctionner
			memcpy( (void*) &mesdonnees2 -> myString, (void*) (buffer + index2), 60 );
			index2 += 60;
std::cout << "\tindex2 = " << index2 << std::endl;
*/

	printf( "myfloat2 %.20f\n", mesdonnees2->myfloat );
	printf( "myint2 %d\n", mesdonnees2->myint );
	printf( "mytext2 %s\n", mesdonnees2->mytext );
	printf( "strlen(mytext2) %lu\n", strlen(mesdonnees2->mytext) );
//	std::cout << "myString2 " << mesdonnees2->myString << std::endl;

delete [] mesdonnees2->mytext;
delete mesdonnees2;
delete [] buffer;
	return (0);
}