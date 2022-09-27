#ifndef TANKGROESSE_HPP_INCLUDED
#define TANKGROESSE_HPP_INCLUDED
#include <ostream> // ostream
class Tankgroesse {
public:
	explicit Tankgroesse(double groesse = 0) : groesse{ groesse } {}
	double groesse;
};
inline bool operator>(const double& menge, const Tankgroesse& groesse) {
	return menge > groesse.groesse;
}
inline std::ostream& operator<<(std::ostream& os, const Tankgroesse& groesse) {
	return os << groesse.groesse;
}
#endif // TANKGROESSE_HPP_INCLUDED