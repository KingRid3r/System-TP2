//R.Raffin, IUT Aix-Marseille, dépt. Info, Arles
//test des classes polynome et monome

#include <iostream>
#include "monomial.hpp"
#include "polynomial.hpp"

int main()
{

polynomial p;

monomial m0(10, 0);
monomial m1(3.14,2);

p.addMonomial(m0);
p.addMonomial(m1);

double res = p.evaluate(1.0);
std::cout << "polynome initial " << p << std::endl;
std::cout << "évaluation (1.0) " << res << std::endl;

polynomial deriv = p.differentiate();
polynomial integ = p.integrate();

std::cout << "polynome derive " << deriv << std::endl;
std::cout << "polynome integre " << integ << std::endl;

return (0);
}

