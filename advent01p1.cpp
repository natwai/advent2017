#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//take input

int main () 
{
	std::string in;
	std::ifstream myfile("input.txt");
	int sum = 0;
	if (myfile.is_open())
	{
		while ( getline (myfile,in) )
		{
			std::string::iterator cmp = ++in.begin();
			for( std::string::iterator it = in.begin(); it != in.end(); ++it)
			{
				if (cmp != in.end())
				{
					if(*it == *cmp)
					{
						int val = int(*it) - '0';
						sum += val;
					}
					++cmp;
				}	
			}
			if(in.front() == in.back())
				sum += int(in.back()) - '0';
		}
		myfile.close();
		std::cout << sum <<std::endl;
	}
	return 0;   
}
