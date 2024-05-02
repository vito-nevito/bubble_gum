#ifndef PUZIR_H
#define PUZIR_H

#include<vector>

class Puzir
{
private:
	bool status;
	double x, y, z;
	double radius;
	double preassure;

public:

	Puzir(bool _s, double _x, double _y, double _z, double _r);

	std::vector<double> getData();

	bool getStatus();
};

#endif
