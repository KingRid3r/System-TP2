/** Romain Raffin
* IUT, dpt. Informatique, Arles
* Aix-Marseille Université, LSIS UMR7296
* romain.raffin[chez]lsis.org
**/
#pragma once

#include <deque>

#include "monomial.hpp"

typedef std::deque<monomial> monomialList;

class polynomial
{
private:
    monomialList expression;

public:

    polynomial();
    ~polynomial();
    polynomial(const polynomial&);
	polynomial operator=(const polynomial & _p);

    void addMonomial(const monomial&);

    double evaluate(const double&) const;

    polynomial integrate() const;
    polynomial differentiate() const;

    friend std::ostream& operator<<(std::ostream&, const polynomial&);
};
