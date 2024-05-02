#include<iostream>
#include<ctime>
#include<vector>
#include "D3array.h"
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
	srand(time(0));
	double lenX = 1.0; int N = 50;
	double lenY = 1.0; int M = 50;
	double lenZ = 1.0; int K = 50;
	double VM = 0.1;
	double deltaT = 0.5;
	double writeInterval = 0.5;
	double endTime = 10;
	if(argc > 1)
	{
		std::vector<double> data = preProc(std::string(argv[1]));
		for(auto i : data)
			std:: cout << i << std::endl;
		lenX = data[0]; N = data[3];
		lenY = data[1]; M = data[4];
		lenZ = data[2]; K = data[5];
		VM = data[6];
		deltaT = data[7];
		writeInterval = data[8];
		endTime = data[9];
	}

	double deltaX = lenX/N;
	double deltaY = lenY/M;
	double deltaZ = lenZ/K;

	D3array V_x = D3array(N, M, K);
	D3array V_y = D3array(N, M, K);
	D3array V_z = D3array(N, M, K);
	V_x.rand(VM);
	V_y.rand(VM);
	V_z.rand(VM);

	int countP = 0;
	std::vector<Puzir> P;
	int timeN = endTime/deltaT;
	for(int i = 0; i < timeN; i++)
	{
		if(i % 10 == 0)
		{
			P.push_back(Puzir(1, deltaX*(randI(N)+0.5), deltaY*(randI(M)+0.5), deltaZ*(randI(K)+0.5), randD(0.05)));
			countP++;
		}
		for(int j = 0; j < countP; j++)
		{
			if(P[j].getStatus())
			{
			std::vector<double> temp = P[j].getData();
			bool statT = 1;
			int cx = temp[0] / deltaX;
			int cy = temp[1] / deltaY;
			int cz = temp[2] / deltaZ;
			double new_x = deltaX * ((int)(temp[0] + V_x.getData()[cz][cy][cx] * deltaT) / deltaX + 0.5);
			double new_y = deltaY * ((int)(temp[1] + V_y.getData()[cz][cy][cx] * deltaT) / deltaY + 0.5);
			double new_z = deltaZ * ((int)(temp[2] + V_z.getData()[cz][cy][cx] * deltaT) / deltaZ + 0.5);
			if((temp[3]+new_x > lenX) || (new_x - temp[3] < 0.)
				|| (temp[3]+new_y > lenY) || (new_y - temp[3] < 0.)
				|| (temp[3]+new_z > lenZ) || (new_z - temp[3] < 0.))
			{
				statT = 0;
			}
			P[j] = Puzir(statT, new_x, new_y, new_z, temp[3]);
			}

		}
		if(i % int(writeInterval/deltaT) == 0)
		{
			printLog(i*deltaT, P, countP);
		}
	}
}
