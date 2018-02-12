/** Romain Raffin
* IUT, dpt. Informatique, Arles
* Aix-Marseille Université, LSIS UMR7296
* romain.raffin[chez]lsis.org
**/
#include <iostream>
#include "polynomial.hpp"

polynomial::~polynomial()
{
    expression.clear();
}

polynomial::polynomial()
{
}

polynomial::polynomial(const polynomial & _p)
{
	expression.clear();
	for (auto m : _p.expression)
		addMonomial(m);
}

polynomial polynomial::operator=(const polynomial & _p)
{
	expression.clear();
	for (auto m : expression)
		addMonomial(m);

	return(*this);
}

double polynomial::evaluate(const double& _v) const
{
    double res = 0.0;
    for (auto m : expression)
		res += m.evaluate(_v);

    return (res);
}

polynomial polynomial::integrate() const
{
    polynomial res;
    monomial temp;

    for (auto m : this->expression) {
	temp = m.integrate();

	if (temp.getCoefficient() != 0.0)
	    res.addMonomial(temp);
    }
    return (res);
}

polynomial polynomial::differentiate() const
{
    polynomial res;
    monomial temp;

    for (auto m : this->expression) {
	temp = m.differentiate();

	if (temp.getCoefficient() != 0.0)
	    res.addMonomial(temp);
    }
    return (res);
}

void polynomial::addMonomial(const monomial& _m)
{
    expression.push_back(_m);
}

std::ostream& operator<<(std::ostream& _out, const polynomial& _p)
{
    for (auto m : _p.expression)
		_out << m;

    return (_out);
}