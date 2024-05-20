#include "Puzir.h"
#include<random>

Puzir::Puzir(double _VM, std::vector<int> dir, std::vector<double> _cord, std::vector<double> radInt, Room room, double _charge):
	       	   timeLife(0), cause('\0')
{
	cordinates = _cord;
	acceleration = room.getGrav();

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
	mass = radius * radius;
	temperature = 5000 * std::pow(radius, 3);
	charge = (2*((double)rand()/RAND_MAX) - 1) * _charge;
};

Puzir::Puzir(Puzir B1, Puzir B2)
{
	timeLife = B1.timeLife;
	cause = 'c';
	mass = B1.mass + B2.mass;
	for(int i = 0; i < 3; i++)
	{
		double c = (B1.cordinates[i] * B1.mass + B2.cordinates[i] * B2.mass)/mass;
		double v = (B1.velocity[i] * B1.mass + B2.velocity[i] * B2.mass)/mass;
		double a = (B1.acceleration[i] * B1.mass + B2.acceleration[i] * B2.mass)/mass;
		cordinates.push_back(c);
		velocity.push_back(v);
		acceleration.push_back(a);
	}
	radius = sqrt(mass);
	temperature = 5000 * std::pow(radius, 3);
	charge = B1.charge + B2.charge;
}

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
		std::vector<double> temp = data[i].getCord();
		double R = data[i].getRad();
		double dist2 = 0;
		for(int j = 0; j < 3; j++)
		{
			dist2 += (temp[j] - cordinates[j]) * (temp[j] - cordinates[j]);
		}
		if((dist2 < radius * radius) || (dist2 < R * R))
		{
			cause = 'C';
			return 0;
		}
	}
	return 1;
};

bool Puzir::getStatusR(std::vector<double> len)
{
	if((cordinates[0] - radius < 0) || (cordinates[0] + radius > len[0])
		||(cordinates[1] - radius < 0) || (cordinates[1] + radius > len[1])
		||(cordinates[2] - radius < 0) || (cordinates[2] + radius > len[2]))
	{
		cause = 'W';
		return 0;
	}
	return 1;
};

void Puzir::addTime(double delta)
{
	timeLife += delta;
};

void puzirMerge(std::vector<Puzir>& data)
{
	for(unsigned int i = 0; i < data.size(); i++)
	{
		std::vector<double> tempi = data[i].getCord();
		double Ri = data[i].getRad();
		for(unsigned int j = i + 1; j < data.size(); j++)
		{
			std::vector<double> tempj = data[j].getCord();
			double Rj = data[j].getRad();
			double dist2 = 0;
			for(int k = 0; k < 3; k++)
			{
				dist2 += (tempi[k] - tempj[k]) * (tempi[k] - tempj[k]);
			}
			if((dist2 < Ri * Ri) || (dist2 < Rj * Rj) )
			{
				Puzir M(data[i], data[j]);
				data.erase(data.begin() + i);
				data.erase(data.begin() + j - 1);
				data.push_back(M);
				i = -1;
				break;
			}
		}
	}
};
