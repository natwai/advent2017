#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>


int main()
{
	int min, max, sum = 0;
	std::string in;
	std::vector<int> nums;
	std::ifstream myfile("input.txt");
	if(myfile.is_open())
	{
		while(getline(myfile, in))
		{
			std::istringstream iss(in); //for operating on the string... i need the iterator
			std::copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::back_inserter(nums)); //somehow im treating the strings as ints
			min = *std::min_element(nums.begin(), nums.end());
			//std::cout << "min: " << min << std::endl;
			max = *std::max_element(nums.begin(), nums.end());
			//std::cout << "max: " << max << std::endl;
			sum += max - min;
			nums.clear();
		}
		std::cout << "sum: " << sum << std::endl;
	}
	return 0;
}