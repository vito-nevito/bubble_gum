#include<iostream>
#include<ctime>
#include<vector>
#include<map>
#include<cmath>
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
			flags[argv[i][1]] = 1;
		}
	}
};

int main(int argc, char* argv[])
{
	std::map<char, bool> flags
	{
		{'l', 0}, {'d', 0}, {'h', 0},
		{'s', 0}, {'p', 0}
	};
	getFlags(flags, argc, argv);
	if(flags['h'] > 0)
	{
		std::ifstream file;
		file.open("post/puzir_help");
		std::string temp;
		while(!file.eof())
		{
			getline(file, temp);
			std::cout << temp << std::endl;
		}
		file.close();
		return 0;
	}

	std::string dataFile = "post/log.csv";

	srand(time(0));
	std::vector<double> lenRoom {20, 20, 20};
	std::vector<double> startPoint {10, 10, 10};
	double rad = 9;
	double VM = 0.1;
	int N = 50;
	int K = 6;
	std::vector<int> dir {0, 0, -1};
	double deltaT = 0.5;
	double writeInterval = 0.5;
	// relate to temperature
	tFunc* T = new LinearT({300, 10 ,10});
	double konv = 0.;
	double visc = 0.;
	double electr = 10;
	std::vector<double> grav{0, 0, -0.01};
	Room myRoom(lenRoom, 300, konv, visc, electr, T, grav);

	std::vector<Puzir> life;
	for(int i = 0; i < K; i ++)
    {
        double f = (2.0 * i * M_PI)/K;
        double x = startPoint[0] + rad * std::cos(f);
        double y = startPoint[1] + rad * std::sin(f);
        double vX = - VM * std::sin(f);
        double vY = VM * std::cos(f);
        std::vector<double> c {x, y, startPoint[2]};
        std::vector<double> v {vX, vY, 0};
        std::vector<double> a{0, 0, 0};
        double ch = -2 * (i%2) + 1;
        life.push_back(Puzir(c, v, a, 1, ch));
    }
	std::vector<Puzir> dead;
	for(int i = 0; i < N; i++)
	{
		// calc new cordinates
		for(Puzir& j : life )
		{
			calcCord(deltaT, myRoom, j);
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
		if(i == 50 && flags['s'])
		{
			getScreenSalome("visS/i50.py", life, startPoint, lenRoom);
		}
		if(flags['p'])
		{

			getScreenPython(life, i, startPoint, lenRoom);
		}
	}
	printSym(life, dead);
	if(flags['s'])
	{
		getScreenSalome("visS/finaly.py", life, startPoint, lenRoom);
	}
};

