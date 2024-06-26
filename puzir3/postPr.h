#ifndef POSTPR_H
#define POSTPR_H

#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include "Puzir.h"

void printLog(double T, std::vector<Puzir> array);

void printSym(std::vector<Puzir> life, std::vector<Puzir> dead);

void printFileLog(std::string file_name, double time, std::vector<Puzir> data);

#endif
