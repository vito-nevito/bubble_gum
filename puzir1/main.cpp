#include<iostream>
#include<ctime>
#include<vector>
#include "postPr.h"
#include "Puzir.h"
#include "prePr.h"

double randD(double S)
{
	return S * (float) rand() / (float)(RAND_MAX);
};

int randI(int N)
{
	return rand()%(N);
};

int main(int argc, char* argv[])
{
	bool log = 0;
	if(argc > 1 && argv[1][0] == '-' && argv[1][1] == 'l')
	{
		log = 1;
	}

	srand(time(0));
	std::vector<double> lenRoom {10.0, 10.0, 10.0};
	std::vector<double> startPoint {5.0, 1, 5.0};
	std::vector<double> radInt{0, 0.5};
	int N = 100;
	double VM = 0.2;
	std::vector<int> dir {0, 1, 0};
	double deltaT = 0.5;
	double writeInterval = 0.5;
	
	if(argc > 1)
	{
		std::string dataS = "\0";
		for(int i = 1;  i < argc; i++)
		{
			if(argv[i][0] != '-')
			{
				dataS = std::string(argv[i]);
			}
		}
		if(dataS != "\0")
		{
			std::vector<double> data = preProc(dataS);
			for(int i = 0; i < 3; i++)
			{
				lenRoom[i] = data[i];
				startPoint[i] = data[i + 3];
				dir[i] = data[i + 10];
			}
			radInt[0] = data[6]; radInt[1] =  data[7];
			N = data[8];
			VM = data[9];
			deltaT = data[13];
			writeInterval = data[14];
	
		}
	}

	std::vector<Puzir> life;
	std::vector<Puzir> dead;
	for(int i = 0; i < N; i++)
	{
		life.push_back(Puzir(VM, dir, startPoint, radInt));
		for(unsigned int j = 0; j < life.size(); j++)
		{
			std::vector<double> temp = life[j].getData();
			std::vector<double> new_cord;
			for(int k = 0; k < 3; k++)
			{
				new_cord.push_back(temp[k] + deltaT * temp[k + 3]);
			}
			life[j].setCord(new_cord);
		}
		std::vector<Puzir> new_life;
		for(unsigned int j = 0; j < life.size(); j++)
		{ 
			if(life[j].getStatus(lenRoom, life, j))
			{
				life[j].addTime(deltaT);
				new_life.push_back(life[j]);
			}
			else
			{
				dead.push_back(life[j]);
			}
		}
		life = new_life;
		if((i % int(writeInterval/deltaT) == 0) && log)
		{
			printLog(i*deltaT, life, life.size());
		}
	}
	printSym(life, dead);
}
