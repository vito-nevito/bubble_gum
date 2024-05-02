#include "Puzir.h"

Puzir::Puzir(bool _s, double _x, double _y, double _z, double _r):
	       	status(_s), x(_x), y(_y), z(_z), radius(_r) {};

std::vector<double> Puzir::getData()
{
	return std::vector<double> {x, y, z, radius};
};
	
bool Puzir::getStatus()
{
		return status;
};
