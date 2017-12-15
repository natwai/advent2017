#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>


int main()
{
	int sum = 0;
	std::string in;
	std::vector<int> nums;
	std::ifstream myfile("input.txt");
	std::vector<int>::iterator cmp;
	if(myfile.is_open())
	{
		while(getline(myfile, in))
		{
			std::istringstream iss(in); //for operating on the string... i need the iterator
			std::copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::back_inserter(nums)); //somehow im treating the strings as ints
			//cmp = nums.begin(); //compare it to this
			for(cmp = nums.begin(); cmp != nums.end(); ++cmp) {
				for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
				{
					if(!(cmp == it)) {
						if( *it % *cmp == 0 ){
							//std::cout << "it: " << *it << "\t cmp: " << *cmp <<std::endl;
							sum += *it / *cmp;
							//std::cout << "sum: " << sum << std::endl;
							break;
						}
					}
					
				}
			}
			nums.clear();
		}
		std::cout << "sum: " << sum << std::endl;
	}
	return 0;
}