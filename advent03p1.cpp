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
	//std::vector<int> seq = {R, U, L D}; //keep track of curr direction

	Graph(int s) : size{s} 
	{
		//construct the graph here
		int seq = 0; //keep track of sequence
		int it = 1; //take mod 2 to check if we move counter
		int ctr = 1; //increases everytime it%2 = 0

		//each inserted node will have a previous node 2 prev if val > 2 and not corner (i == ctr-1).
		Node* prev1 = nullptr; //other prev, either up or down
		Node* prev2 = nullptr; //prev in opp direction

		//these nodes have no prev in the downward direction so add seperately
		Node* curr = Node(1);
		curr->right = Node(2);
		prev1 = curr;
		//set prev
		curr = curr->right;
		curr->left = prev1;
		++it;
		//add rest of nodes
		for(int val = 2; val <= size; ++val)
		{
			if(it%2 != 0) //add ctr nodes in this direction 
			{
				for(int i = 0; i < ctr; ++i)
				{
					if(seq == R) { //prev is in up and left directions
						curr->right = Node(val);
						prev2 = curr; 
						curr = curr->right;
						if(i != ctr-1) curr->left = prev2;
						else {
							curr->up = prev1;
							prev1 = prev1->right;
						}

					}
					else if(seq == U){ //prev is down and left
						curr->up = Node(val);
						prev2 = curr; 
						curr = curr->up;
						if(i != ctr-1) curr->left = prev2;
						else {
							curr->up = prev1;
							prev1 = prev1->up;
						}
					}
					else if(seq == L){}
					else {
						//do stuff
					}
				}
				//shift sequence
				if(seq < D) ++seq;
				else seq = R; //reset
				++it;
			}
			else
			{
				if(seq < D) ++seq;
				else seq = R; //reset
			}

		}

	} 

	class Node {
	public:
		Node* right = nullptr;
		Node* left = nullptr;
		Node* up = nullptr;
		Node* down = nullptr;
		int dist; //distance to 1
		int val; //from 1 to size

		Node(int v) : val{v} {}

		//function to find distance to 1, basically dijkstras
	}

}