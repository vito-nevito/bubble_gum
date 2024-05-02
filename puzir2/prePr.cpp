#include "prePr.h"

void fileOpen(std::ifstream& in)
{
	if(!in.is_open())
	{
		std::cerr << "Can't open file." << std::endl;
		exit(1);
	}
}

std::vector<double> preProc(std::string file_name)
{
	std::vector<double> data;
	std::ifstream in;
	in.open(file_name);
	std::string temp;
	fileOpen(in);
	while(getline(in, temp))
	{
		int c = 0;
		std::string num;
		for(unsigned int i = 0; i < temp.size(); i++)
		{
			if(std::isdigit(temp[i]) || temp[i] == '.')
			{
				c = 1;
				num += temp[i];
			}
			else if(c)
			{
				c = 0;
				data.push_back(stof(num));
				num.clear();
			}
		}
	       	if(c)
		{
			data.push_back(stof(num));
		}
		fileOpen(in);	
	}
	in.close();
	return data;
}
