#include <stdexcept> // invalid_argument
#include "auto.hpp"
Auto::Auto(std::string marke = "unbekannt", anzahl ps = -1,
	Tankfuellung tankfuellung = Tankfuellung{},
	Tankgroesse tankgroesse = Tankgroesse{})
	: marke_{ marke }, ps_{ ps }, tankfuellung_{ tankfuellung },
	tankgroesse_{ tankgroesse } {}

Auto& Auto::tanken(double menge) {
	if (tankfuellung_ + menge > tankgroesse_) {
		tankfuellung_ = tankgroesse_;
		throw std::invalid_argument("Tank ist übergelaufen");
	}
	else {
		tankfuellung_ += menge;
	}
	return *this;
}
Auto& Auto::fahren(double verbrauch) {
	if (tankfuellung_ - verbrauch <= 0) {
		tankfuellung_ = 0.0;
		throw std::invalid_argument("Tank ist leer");
	}
	else {
		tankfuellung_ -= verbrauch;
	}
	return *this;
}
std::ostream& Auto::drucke(std::ostream& os) {
	return os << "Das " << marke_ << " Auto mit "
		<< ps_ << "PS, hat " << tankfuellung_ << "/"
		<< tankgroesse_ << "l im Tank.\n";
}
