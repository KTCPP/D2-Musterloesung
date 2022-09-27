#include <iostream>
#include "auto.hpp"
int main()
{
	using namespace std;
	Auto::anzahl ps = 250.0;
	Auto car{ "VW", ps, Tankfuellung{30}, Tankgroesse{60} };
	car.drucke(cout);
	try {
		car.tanken(30.0).fahren(20).tanken(10.);
		car.fahren(50);
		car.drucke(cout);
		car.fahren(20);
	}
	catch (invalid_argument& exc) {
		cerr << exc.what() << endl;
		return -1;
	}
	return 0;
}