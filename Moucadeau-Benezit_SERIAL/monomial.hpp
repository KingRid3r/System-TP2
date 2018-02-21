/** Romain Raffin
* IUT, dpt. Informatique, Arles
* Aix-Marseille Université, LSIS UMR7296
* romain.raffin[chez]lsis.org
**/

#include <ostream>

class monomial
{
private:
    double coefficient;
    double degree;

public:
    monomial();
    ~monomial();
    monomial(const double&, const double&);

    monomial(const monomial&);

    double evaluate(const double&) const;

    // accesseurs
    double getCoefficient() const;
    double getDegree() const;

    // opérateurs simples
    monomial operator*(const double&);
    monomial operator/(const double&);

    // opérateurs complexes
    monomial differentiate() const;
    monomial integrate() const;

    // sortie ostream
    friend std::ostream& operator<<(std::ostream&, const monomial&);
};

template<class Archive> void serialize(Archive & archive, monomial & m)
{
	archive( m.getCoefficient(), m.getDegree());
}
