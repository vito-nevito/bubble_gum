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

public:

	Puzir(double _VM,std::vector<int> dir, std::vector<double> _cord, std::vector<double> radInt);

	std::vector<double> getData();

	double getTime();

	void setCord(std::vector<double> _cord);

	bool getStatus(std::vector<double> len, std::vector<Puzir> data, int N);

	void addTime(double delta);

	char getCause();
};

#endif
