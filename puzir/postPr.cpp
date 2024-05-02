#include "postPr.h"

void printLog(double T, std::vector<Puzir> array, int N)
{
	std::cout << "Time " << T << std::endl;
	for(int i = 0; i < N; i++)
	{
		std::cout << "Bubble" << i << " :" << std::endl;
		if(array[i].getStatus())
		{
			std::vector<double> temp = array[i].getData();
			std::cout << "	x = " << temp[0] << std::endl;
			std::cout << "	y = " << temp[1] << std::endl;
			std::cout << "	z = " << temp[2] << std::endl;
			std::cout << "	radius = " << temp[3] << std::endl;
		}
		else
		{
			std::cout << "	does not exist.\n";
		}

	}
	std::cout << std::endl;
};
