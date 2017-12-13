#include <iostream>
#include <fstream>
#include <string>

int main()
{
	//take input from file
	std::string in;
	std::ifstream myfile("input.txt");
	if(myfile.is_open())
	{
		getline(myfile, in);
		std::string::iterator cmp;
		int half = std::distance(in.begin(), in.end())/2; //input is guaranteed to be even
		int sum = 0;
		for(std::string::iterator it = in.begin(); it != in.end(); ++it)
		{
			cmp = it;
			//compare *it with element halfway around list
			//case 1: no need to wrap around
			//iterate cmp since i dont think its random access
			//std::cout << std::distance(it, in.end()) << std::endl;
			if(std::distance(it, in.end()) > half) 
				for(int i = 0; i < half; ++i) ++cmp;
			//case 2: need to wrap around
			//iterate cmp backwards
			else
				for(int i = 0; i < half; ++i) --cmp;
			//calculate sum
			if(*it == *cmp) sum += (*it - '0');
		}
		std::cout << "sum: " << sum << std::endl;
	}
	return 0;
}