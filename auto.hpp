#ifndef AUTO_HPP_INCLUDED
#define AUTO_HPP_INCLUDED
#include "tankfuellung.hpp"
#include "tankgroesse.hpp"
#include<string>
#include<ostream>
class Auto {
public:
	using anzahl = unsigned;
	/// Füllt den Tank des Autos auf
	/// @param double Menge des Tankvolumens
	/// @return Auto& Das Objekt des Autos
	Auto& tanken(double);
	/// Fährt das Auto
	/// @param double Menge des verbauchten Treibstoffs
	/// @return Auto& Das Objekt des Autos
	Auto& fahren(double);
	/// Ein Auto
	/// @param std::string Marke des Autos
	/// @param anzahl PS Stärke des Autos
	/// @param Tankfuellung Start-Tankfuellung des Autos
	/// @param Tankgroesse Maximale Tankfuellung
	Auto(std::string, anzahl ps, Tankfuellung, Tankgroesse);
	/// Gibt die Werte des Autos auf einem Strom aus
/// @param std::ostream& Strom zur Ausgabe
/// @return std::ostream& Den selben Strom des Arguments
	std::ostream& drucke(std::ostream&);
private:
	anzahl ps_;
	std::string marke_;
	Tankfuellung tankfuellung_;
	Tankgroesse tankgroesse_;
};
#endif // AUTO_HPP_INCLUDED