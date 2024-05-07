#ifndef PUZIR_H
#define PUZIR_H

#include<vector>

class Puzir
{
private:
	std::vector<double> cordinates;
	std::vector<double> velocity;
	double radius;
	double timeLife;
	char cause;
	double mass;

public:

	Puzir(double _VM,std::vector<int> dir, std::vector<double> _cord, std::vector<double> radInt);

	Puzir(Puzir B1, Puzir B2);

	std::vector<double> getData();

	double getTime();

	void setCord(std::vector<double> _cord);

	bool getStatus(std::vector<double> len, std::vector<Puzir> data, int N);

	bool getStatusR(std::vector<double> len);

	void addTime(double delta);

	char getCause();

	double getMass() {return mass;};
};

void puzirMerge(std::vector<Puzir>& data);

#endif
