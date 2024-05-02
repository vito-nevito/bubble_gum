#include "Puzir.h"
#include<random>

Puzir::Puzir(double _VM, std::vector<int> dir, std::vector<double> _cord, std::vector<double> radInt):
	       	   timeLife(0), cause('\0') 
{
	cordinates = _cord;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<> R(0, 1);

	for(int i = 0; i < 3; i++)
	{
		double v = _VM * R(gen);
		if(v * dir[i] < 0)
		{
			v *= -1;
		}
		velocity.push_back(v);
	}

	radius = ((double)rand()/RAND_MAX)*(radInt[1] - radInt[0]) + radInt[0];
};

std::vector<double> Puzir::getData()
{
	std::vector<double> temp(cordinates);
	for(int i = 0; i < 3; i++)
	{
		temp.push_back(velocity[i]);
	}
	temp.push_back(radius);
	return temp;
};
	
double Puzir::getTime()
{
		return timeLife;
};

void Puzir::setCord(std::vector<double> _cord)
{
	cordinates = _cord;
};

bool Puzir::getStatus(std::vector<double> len, std::vector<Puzir> data, int N)
{
	if((cordinates[0] - radius < 0) || (cordinates[0] + radius > len[0])
		||(cordinates[1] - radius < 0) || (cordinates[1] + radius > len[1])
		||(cordinates[2] - radius < 0) || (cordinates[2] + radius > len[2]))
	{
		cause = 'W';
		return 0;
	}
	for(unsigned int i = N + 1 ; i < data.size() ; i++)
	{
		std::vector<double> temp = data[i].getData();
		double dist2 = 0;
		for(int j = 0; j < 3; j++)
		{
			dist2 += (temp[j] - cordinates[j]) * (temp[j] - cordinates[j]);
		}
		if(dist2 < radius * radius)
		{
			cause = 'C';
			return 0;
		}
	}
	return 1;
};

void Puzir::addTime(double delta)
{
	timeLife += delta;
};

char Puzir::getCause()
{
	return cause;
};
