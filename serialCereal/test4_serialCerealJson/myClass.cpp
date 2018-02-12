#include <cereal/archives/json.hpp>
#include <fstream>

#include "myClass.hpp"

void MyClass::add(const int& _v)
{
	x += _v;
	y += _v;
	z += _v;
}
