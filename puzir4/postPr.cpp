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

void getScreenSalome(std::string fileName, std::vector<Puzir> data, std::vector<double> point, std::vector<double> lenRoom)
{
	std::fstream file(fileName, std::ios::out | std::ios::trunc);
	std::fstream vis("visS/salomeVis");
	std::string temp;
	for(int i = 0; i < 33; i++)
	{
		temp.clear();
		getline(vis, temp);
		file << temp << "\n";
	}
	// add bubbles
	for(unsigned int i = 0; i < data.size(); i++)
	{
		std::vector<double> cord = data[i].getCord();
		file << "Sphere_" << i
		<< " = geompy.MakeSphereR(" 
		<< data[i].getRad() 
		<< ")\ngeompy.TranslateDXDYDZ(Sphere_"
		<< i << ", " << cord[0]<< ", " << cord[1] << ", " << cord[2]
	        << ")\nSphere_" << i << ".SetColor(SALOMEDS.Color(0, 1, 1))\n"
		<< "geompy.addToStudy(Sphere_" << i << ", 'Bubble_" << i << "' )\n";
	}
	// add source
	file << "Vertex_1 = geompy.MakeVertex(" 
		<< point[0] << ", " << point[1] << ", " << point[2] << ")\n"
		<< "Vertex_1.SetColor(SALOMEDS.Color(1, 0, 0))\n"
		<< "geompy.addToStudy(Vertex_1, 'Source' )\n";
	// add walls
	for(int i = 0; i < 3; i++)
	{
		file << "Face_" << i
		<< " = geompy.MakeFaceHW(" 
		<< lenRoom[i] << ", " << lenRoom[(i+1)%3] << ", " << i + 1
		<< ")\nFace_" << i << ".SetColor(SALOMEDS.Color(0.666667, 0.333333, 0))\n";
	}
	file << "geompy.TranslateDXDYDZ(Face_0, "  << lenRoom[0]/2 << ", " << lenRoom[1]/2
	       	<< ", 0)\n";
	file << "geompy.TranslateDXDYDZ(Face_1, 0, "  << lenRoom[1]/2 << ", " << lenRoom[2]/2
	       	<< ")\n";
	file << "geompy.TranslateDXDYDZ(Face_2, "  << lenRoom[0]/2 << ", 0, " << lenRoom[1]/2
	       	<< ")\n";
	for(int i = 0; i < 3; i++)
	{
		file << "geompy.addToStudy(Face_" << i << ", 'Wall_" << i << "' )\n";
	}
	for(int i = 33; i < 43; i++)
	{
		temp.clear();
		getline(vis, temp);
		file << temp << "\n";
	}
	file.close();
};

void getScreenPython(std::vector<Puzir> data, int i)
{
	std::string fileName = "visP/" + std::to_string(i);
	fileName += ".csv";
	std::fstream file(fileName, std::ios::out | std::ios::trunc);
	file << "x,y,z,r,c\n";
	for(unsigned int i = 0; i < data.size(); i++)
	{
		std::vector<double> cord = data[i].getCord();
		double charge = data[i].getCharge();
		int c = 0;
		if(charge > 0)
		{
			c = 1;
		}
		file << cord[0] << "," << cord[1] << "," << cord[2] << ","
		<< c << "\n";
	}
	file.close();

	file.open("visP/info", std::ios::out | std::ios::trunc);
	file << i+1 << "\n";
	file.close();
};
