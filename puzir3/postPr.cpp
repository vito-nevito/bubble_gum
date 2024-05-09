#include "postPr.h"

void printLog(double T, std::vector<Puzir> array)
{
	std::cout.setf(std::ios::fixed);
	std::cout << "Step " << T << std::endl;
	unsigned int N = array.size();
	for(unsigned int i = 0; i < N; i++)
	{
		std::cout << "Bubble" << i << " :" << "\t";

		std::vector<double> temp = array[i].getData();
		std::cout << "( " << temp[0] << " ,";
		std::cout << std::setw(6) << temp[1] << " ,";
		std::cout << std::setw(6) << temp[2] << " ,";
		std::cout << std::setw(6) << temp[6] << " )" << std::endl;
	}
	std::cout << std::endl;
};

void printSym(std::vector<Puzir> life, std::vector<Puzir> dead)
{
	double rate = (double)life.size()/(life.size() + dead.size()) * 100;
	std::cout << "Survival rate =  " << rate << " %" << std::endl;
	double symTime = 0;
	double symTemp = 0;
	for(unsigned int i = 0; i < life.size(); i++)
	{
		symTime += life[i].getTime();
		symTemp += life[i].getTemp();
	}
	for(unsigned int i = 0; i < dead.size(); i++)
	{
		symTime += dead[i].getTime();
		symTemp += dead[i].getTemp();
	}
	std::cout << "Average lifetime = " << symTime/(life.size() + dead.size()) << " c" << std::endl;
	std::cout << "Average temperature = "<< symTemp/(life.size() + dead.size()) << " K" << std::endl;
	int countW = 0;
	for(unsigned int i = 0; i < dead.size(); i++)
	{
		if(dead[i].getCause() == 'W')
		{
			countW ++;
		}
	}
	std::cout << "Dead from walls " << countW << std::endl;
};

void printFileLog(std::string file_name, double time, std::vector<Puzir> data)
{	
	std::fstream file;
	if(time == 0.)
	{
		file.open(file_name,std::ios::out | std::ios::trunc);
		file << "time," << "avRad," << "maxRad," << "avTemp," << "avMass" << "\n";
	}
	else
	{
		file.open(file_name, std::ios::app);

	}
	std::vector<double> Rad;
	std::vector<double> Temp;
	std::vector<double> Mass;

	for(unsigned int i = 0; i < data.size(); i++)
	{
		Rad.push_back((data[i].getData())[6]);
		Temp.push_back(data[i].getTemp());
		Mass.push_back(data[i].getMass());
	}
	if(file.is_open())
	{
		file << time << ",";
		file << std::accumulate(Rad.begin(), Rad.end(), 0.0)/data.size() << ",";
		file << *std::max_element(Rad.begin(), Rad.end()) << ",";
		file << std::accumulate(Temp.begin(), Temp.end(), 0.0)/data.size() << ",";
		file << std::accumulate(Mass.begin(), Mass.end(), 0.0)/data.size() << "\n";
	}
	file.close();
};
