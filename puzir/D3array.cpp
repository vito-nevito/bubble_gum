#include "D3array.h"

double randDS(double S)
{
	int sign = 2 * (rand()%2) - 1;
	return sign * S * (double)(rand())/(RAND_MAX);
};

D3array::D3array(int _N, int _M, int _K): N(_N), M(_M), K(_K)
{
	std::vector < std::vector < std::vector <double> > >
	temp(K, std::vector < std::vector<double> > (M, std::vector<double>(N)));
	data = temp;
};

std::vector<std::vector<std::vector<double>>> D3array::getData()
{
	return data;
};

void D3array::rand(double S)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			for(int k = 0; k < K; k++)
			{
				data[k][j][i] = randDS(S);
			}
		}
	}
};

void D3array::print()
{
	for(int k = 0; k < K; k++)
	{
		for(int j = 0; j < M; j++)
		{
			for(int i = 0; i < N; i++)
			{
				std::cout << data[k][j][i] << "  ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
};
