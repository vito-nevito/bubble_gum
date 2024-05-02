#ifndef D3ARRAY_H
#define D3ARRAY_H

#include<vector>
#include<iostream>

double randDS(double S);

class D3array 
{
private:
	int N, M, K;
	std::vector<std::vector<std::vector<double>>> data;

public:
	D3array(int _N, int _M, int _K);
	std::vector<std::vector<std::vector<double>>> getData();
	void rand(double S);
	void print();
};

#endif
