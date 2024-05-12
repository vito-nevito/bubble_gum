#ifndef ROOM_H
#define ROOM_H

#include<vector>

class tFunc
{
protected:
	std::vector<double> c;
public:
	tFunc(std::vector<double> _c): c(_c){};

	virtual double value(double x, double y) { return 0;};

	virtual ~tFunc(){};
};

class Room
{
protected:
	std::vector<double> size;
	double TWall;
	// coeff convection
	double alpha;
	std::vector<double> gravity;
	tFunc* Temperature = nullptr;

public:
	Room(std::vector<double> _size, double _TW, double _alpha, tFunc* _T, std::vector<double> accel)
		: size(_size), TWall(_TW), alpha(_alpha), gravity(accel), Temperature(_T) {};

	~Room();

	double getTemp(double x, double y);

	double getAlpha() {return alpha;};

	std::vector<double> getGrav() {return gravity;};

	double getTW() {return TWall;};
};

// simple distr

class LinearT : public tFunc
{
public:
	LinearT(std::vector<double> _c): tFunc(_c){};

	double value(double x, double y);

	~LinearT(){};
};

class BoxT : public tFunc
{
public:
	BoxT(std::vector<double> _c): tFunc(_c){};

	double value(double x, double y);
	
	~BoxT(){};
};

#endif
