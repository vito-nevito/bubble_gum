#include<iostream>
#include<ctime>
#include<vector>
#include<map>
#include "postPr.h"
#include "Puzir.h"
#include "prePr.h"
#include "Room.h"
#include "action.h"

void getFlags(std::map<char, bool>& flags, int argc, char* argv[])
{
	for(int i = 1;  i < argc; i++)
	{
		if(argv[i][0] == '-')
		{
			flags[argv[i][1]]++;
		}
	}
};

int main(int argc, char* argv[])
{
	std::map<char, bool> flags
	{
		{'l', 0}, {'d', 0}, {'h', 0}
	};
	getFlags(flags, argc, argv);
	if(flags['h'] > 0)
	{
		std::ifstream file;
		file.open("puzir_help");
		std::string temp;
		while(!file.eof())
		{
			getline(file, temp);
			std::cout << temp << std::endl;
		}
		file.close();
		return 0;
	}
	std::string dataFile = "1.csv";

	srand(time(0));
	std::vector<double> lenRoom {10.0, 10.0, 10.0};
	std::vector<double> startPoint {5.0, 1, 5.0};
	std::vector<double> radInt{0, 0.5};
	int N = 100;
	double VM = 0.5;
	std::vector<int> dir {0, 1, 0};
	double deltaT = 0.5;
	double writeInterval = 0.5;
	//relate to  charge
	double CM = 1;
	// relate to temperature
	tFunc* T = new LinearT({300, 10 ,10});
	Room myRoom(lenRoom, 300, 0.0,  T, {0, 0, 9.84});

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
	for(int i = 0; i < N + 10; i++)
	{
		// calc new cordinates
		for(Puzir& j : life )
		{
			calcCord(deltaT, myRoom, j);
		}
		// add 1 bubble
		if(i < N)
		{
			life.push_back(Puzir(VM, dir, startPoint, radInt, myRoom, CM));
		}
		// deadinside detected
		std::vector<Puzir> new_life;
		puzirMerge(life);
		for(Puzir& j : life)
		{
			if(j.getStatusR(lenRoom))
			{
				j.addTime(deltaT);
				new_life.push_back(j);
			}
			else
			{
				dead.push_back(j);
			}
		}
		life = new_life;
		// calc new velocity and acceleration
		for(Puzir& j : life)
		{
			calcVel(deltaT, j);
			calcAccel(life, j, myRoom);
		}
		if((i % int(writeInterval/deltaT) == 0) && flags['l'])
		{
			printLog(i*deltaT, life);
		}
		if(flags['d'])
		{
			printFileLog(dataFile, i*deltaT, life);
		}
	}
	printSym(life, dead);
	getScreenSalome("one.py", life);
};
