/** Romain Raffin
* IUT, dpt. Informatique, Arles
* Aix-Marseille Université, LSIS UMR7296
* romain.raffin[chez]lsis.org
**/

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

template<class Archive> void serialize(Archive & archive, polynomial & m)
{
	archive( m.expression);
}
