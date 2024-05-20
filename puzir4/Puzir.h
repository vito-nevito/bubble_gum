#ifndef PUZIR_H
#define PUZIR_H

#include<vector>
#include<cmath>
#include "Room.h"

class Puzir
{
private:
	std::vector<double> cordinates;
	std::vector<double> velocity;
	std::vector<double> acceleration;
	double radius;
	double timeLife;
	char cause;
	double mass;
	double temperature;
	double charge;

public:

	Puzir(double _VM,std::vector<int> dir, std::vector<double> _cord, std::vector<double> radInt, Room room, double _charge);

	Puzir(std::vector<double> _c, std::vector<double> _v, std::vector<double> _a, double _r, double _ch):
	    cordinates(_c), velocity(_v), acceleration(_a), radius(_r), timeLife(0), cause('L'), mass(_r*_r), temperature(5000 * std::pow(radius, 3)), charge(_ch) {};

	Puzir(Puzir B1, Puzir B2);

	std::vector<double>& getVel() {return velocity;};

	std::vector<double>& getCord() {return cordinates;};

	double getRad() {return radius;};

	double getTime() {return timeLife;};

	double getTemp() {return temperature;};

	char getCause() {return cause;};

	double getMass() {return mass;};

	double getCharge() {return charge;};

	std::vector<double>& getAccel() {return acceleration;};

	void setCord(const std::vector<double>& _cord) {cordinates = _cord;};

	void setVel(const std::vector<double>& _vel) {velocity = _vel;};

	void setAccel(const std::vector<double>& _accel) {acceleration =_accel;};

	bool getStatus(std::vector<double> len, std::vector<Puzir> data, int N);

	bool getStatusR(std::vector<double> len);

	void addTime(double delta);
};

void puzirMerge(std::vector<Puzir>& data);

#endif
