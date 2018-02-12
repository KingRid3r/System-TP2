#ifndef _H_MYCLASS
#define _H_MYCLASS

#include <iostream>


class MyClass
{
	public:
		int x, y, z;
		std::string maChaine;
		float monFloat;

		void add(const int&);

};

template<class Archive> void serialize(Archive & archive, MyClass & m)
{
	archive( m.x, m.y, m.z, m.maChaine, m.monFloat );
}


#endif