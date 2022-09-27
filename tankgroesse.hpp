#ifndef TANKFUELLUNG_HPP_INCLUDED
#define TANKFUELLUNG_HPP_INCLUDED
#include "tankgroesse.hpp"
class Tankfuellung {
public:
	explicit Tankfuellung(double stand = 0) : stand{ stand } {}
	double stand;
	// Überladen hier, damit es nicht zu einer zyklischen Abhängigkeit kommt
	inline Tankfuellung& operator=(const Tankgroesse& groesse) {
		stand = groesse.groesse;
		return *this;
	}
	inline Tankfuellung& operator=(const double& groesse) {
		stand = groesse;
		return *this;
	}
	inline Tankfuellung& operator+=(const double& menge) {
		stand += menge;
		return *this;
	}
	inline Tankfuellung& operator-=(const double& menge) {
		stand -= menge;
		return *this;
	}
};
inline double operator+(const Tankfuellung& tank, const double& menge) {
	return tank.stand + menge;
}
inline double operator-(Tankfuellung& tank, const double& menge) {
	return tank.stand - menge;
}
inline std::ostream& operator<<(std::ostream& os, const Tankfuellung& tank) {
	return os << tank.stand;
}
#endif // TANKFUELLUNG_HPP_INCLUDED