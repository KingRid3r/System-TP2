/** Romain Raffin
* IUT, dpt. Informatique, Arles
* Aix-Marseille Université, LSIS UMR7296
* romain.raffin[chez]lsis.org
**/
#include <cmath>
#include "monomial.hpp"

monomial::monomial()
{
    coefficient = 0.0;
    degree = 0.0;
}

monomial::~monomial()
{
    // rien pour l'instant
}

monomial::monomial(const monomial& _m)
{
    coefficient = _m.coefficient;
    degree = _m.degree;
}

monomial::monomial(const double& _c, const double& _d)
{
    coefficient = _c;
    degree = _d;
}

double monomial::evaluate(const double& _v) const
{
    double res;
    res = pow(_v, degree) * coefficient;

    return (res);
}

double monomial::getCoefficient() const
{
    double res = coefficient;
    ;
    return (res);
}

double monomial::getDegree() const
{
    double res = degree;
    ;
    return (res);
}

monomial monomial::integrate() const
{
    monomial res;
    res.degree = this->degree + 1;
    res.coefficient = this->coefficient / (res.degree);
    return (res);
}

monomial monomial::differentiate() const
{
    monomial res;
    res.coefficient = this->coefficient * this->degree;
    res.degree = this->degree - 1;
    return (res);
}

std::ostream& operator<<(std::ostream& _out, const monomial& _m)
{
    _out << "[" << _m.getCoefficient() << ".x^" << _m.getDegree() << "]";
    return (_out);
}
