#include "postPr.h"

void printLog(double T, std::vector<Puzir> array, int N)
{
	std::cout << "Step " << T << std::endl;
	for(int i = 0; i < N; i++)
	{
		std::cout << "Bubble" << i << " :" << std::endl;

		std::vector<double> temp = array[i].getData();
		std::cout << "	x = " << temp[0] << std::endl;
		std::cout << "	y = " << temp[1] << std::endl;
		std::cout << "	z = " << temp[2] << std::endl;
		std::cout << "	radius = " << temp[6] << std::endl;
	}
	std::cout << std::endl;
};


void printSym(std::vector<Puzir> life, std::vector<Puzir> dead)
{
	double rate = (double)life.size()/(life.size() + dead.size()) * 100;
	std::cout << "Survival rate =  " << rate << " %" << std::endl;
	double symTime = 0;
	for(unsigned int i = 0; i < life.size(); i++)
	{
		symTime += life[i].getTime();
	}
	for(unsigned int i = 0; i < dead.size(); i++)
	{
		symTime += dead[i].getTime();
	}
	std::cout << "Average lifetime = " << symTime/(life.size() + dead.size()) << " c" << std::endl;
	int countW = 0;
	for(unsigned int i = 0; i < dead.size(); i++)
	{
		if(dead[i].getCause() == 'W')
		{
			countW ++;
		}
	}
	std::cout << "Dead from walls " << countW << std::endl;
	std::cout << "Dead from collision " << dead.size() - countW << std::endl;
};


