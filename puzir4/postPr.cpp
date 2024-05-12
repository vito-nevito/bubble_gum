#include "postPr.h"

void printLog(double T, std::vector<Puzir> array)
{
	std::cout.setf(std::ios::fixed);
	std::cout << "Step " << T << std::endl;
	unsigned int N = array.size();
	for(unsigned int i = 0; i < N; i++)
	{
		std::cout << "Bubble" << i << " :" << "\t";

		std::vector<double> temp = array[i].getCord();
		std::cout << "( " << std::setw(6) << temp[0] << " ,";
		std::cout << std::setw(6) << temp[1] << " ,";
		std::cout << std::setw(6) << temp[2] << " ,";
		std::cout << std::setw(6) << array[i].getRad() << " )" << std::endl;
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
		file.open(file_name, std::ios::out | std::ios::trunc);
		file << "time,id,x,y,z,rad,timeLife,mass,temp,charge\n";
	}
	else
	{
		file.open(file_name, std::ios::app);

	}
	for(unsigned int i = 0; i < data.size(); i++)
	{
		Puzir temp = data[i];
		file << time << ","
		<< i << ","
		<< temp.getCord()[0] << ","
		<< temp.getCord()[1] << ","
		<< temp.getCord()[2] << ","
		<< temp.getRad() << ","
		<< temp.getTime() << ","
		<< temp.getMass() << ","
		<< temp.getTemp() << ","
		<< temp.getCharge() << "\n";
	}
	file.close();
};

void getScreenSalome(std::string fileName, std::vector<Puzir> data)
{
	std::fstream file(fileName, std::ios::out | std::ios::trunc);
	std::fstream vis("salomeVis");
	std::string temp;
	for(int i = 0; i < 33; i++)
	{
		temp.clear();
		getline(vis, temp);
		file << temp << "\n";
	}
	for(unsigned int i = 0; i < data.size(); i++)
	{
		std::vector<double> cord = data[i].getCord();
		file << "Sphere_" << i
		<< " = geompy.MakeSphereR(" 
		<< data[i].getRad() 
		<< ")\ngeompy.TranslateDXDYDZ(Sphere_"
		<< i << ", " << cord[0]<< ", " << cord[1] << ", " << cord[2] 
		<< ")\ngeompy.addToStudy( Sphere_" << i << ", 'Sphere_" << i << "' )\n";
	}
	for(int i = 33; i < 43; i++)
	{
		temp.clear();
		getline(vis, temp);
		file << temp << "\n";
	}
	file.close();
};
