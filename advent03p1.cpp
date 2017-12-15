//construct a bidirectional, fully connected graph
//each node has a left, right, up and down

#include <iostream>
#include <vector>
#define R 0 //right
#define U 1 //up
#define L 2 //left
#define D 3 //down

class Graph {
public:
	int size;
	int it = 1; //take mod 2 to check if we move counter
	int ctr = 1; //increases everytime it%2 = 0
	std::vector<int> seq = {R, U, L D}; //keep track of curr direction

	Graph(int s) : size{s} 
	{
		//construct the graph here
		int val = 1; //will count up to size
		//each inserted node will have a previous node to the right. a node will have a prev node in the down direction if curr direction is not down AND if val > 2.
	} 

	class Node {
	public:
		int* right;
		int* left;
		int* up;
		int* down;
		int dist; //distance to 1
		int val; //from 1 tp size

		//function to find distance to 1
	}

}