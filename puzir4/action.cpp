#include "action.h"
#include<cmath>

#include<iostream>

void calcCord(double deltaT, Room room, Puzir& p)
{
	std::vector<double> vel = p.getVel();
	std::vector<double> oldCord = p.getCord();
	// calc velocity vith convection
	std::vector<double> outVel;
	for(int i = 0; i < 2; i++)
	{
		outVel.push_back(vel[i]);
	}
	double vz = vel[2] + (room.getTemp(oldCord[0], oldCord[1]) - room.getTW()) * room.getAlpha();
	outVel.push_back(vz);
	// calc new cordinates
	std::vector<double> newCord;
	for(int i = 0; i < 3; i++)
	{
		newCord.push_back(oldCord[i] + deltaT * outVel[i]);
	}
	p.setCord(newCord);
};

void  calcVel(double deltaT, Puzir& p) 
{
	std::vector<double> newVel;
	for(int i = 0; i < 3; i++)
	{
		newVel.push_back(p.getVel()[i] + deltaT * p.getAccel()[i]);
	};
	p.setVel(newVel);
};

void  calcAccel(std::vector<Puzir> array, Puzir& p, Room room)
{
	// electrostatic constant
	double K = room.getK();

	std::vector<double> pCord = p.getCord();
	double pQ = p.getCharge();
	std::vector<double> newAccel{0, 0, 0};
	for(Puzir temp : array)
	{
		std::vector<double> tempCord = temp.getCord();
		double tempQ = temp.getCharge();
		if(tempCord != pCord) {
		double dist = 0;
		for(int i = 0; i < 3; i++)
		{
			dist += std::pow((tempCord[i] - pCord[i]), 2);
		}
		dist = std::pow(dist, 3./2);
		for(int i = 0; i < 3; i++)
		{
			newAccel[i] += (K * pQ * tempQ * (pCord[i] - tempCord[i]) / dist);
		}
		}
	}
	std::vector<double> pVel = p.getVel();
	for(int i = 0; i < 3; i++)
	{
		newAccel[i] += room.getGrav()[i];
		newAccel[i] -= room.getVisc() * pVel[i];
	}
	p.setAccel(newAccel);
};
