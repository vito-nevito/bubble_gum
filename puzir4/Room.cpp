#include "Room.h"

double Room::getTemp(double x, double y)
{
	return Temperature->value(x, y);
};

Room::~Room()
{
	// if(Temperature != nullptr)
	// {
	// 	delete Temperature;
	// }
};

// simple functions

double LinearT::value(double x, double y)
{
	return c[0] + c[1] * x + c[2] * y;
};

double BoxT::value(double x, double y)
{
	if((x >= c[0]) && (x <= c[1])
	 	&& (y >= c[2]) && (y <= c[3]) )
	{
		return c[5];
	}
	else
	{
		return c[4];
	}
};
