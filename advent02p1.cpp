#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>


int main()
{
	int min, max, sum = 0;
	std::string in;
	std::ifstream myfile("input.txt");
	if(myfile.is_open())
	{
		while(getline(myfile, in))
		{
			in.erase(std::remove_if(in.begin(), in.end(), isspace), in.end()); //removes spaces in input
			min = *std::min_element(in.begin(), in.end()) - '0';
			max = *std::max_element(in.begin(), in.end()) - '0';
			sum += max - min;
		}
		std::cout << "sum: " << sum << std::endl;
	}
	return 0;
}