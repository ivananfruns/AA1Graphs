#include "GraphDMatriu.h"

/*
//Constructor utilitzant matrius:
GraphDMatriu::GraphDMatriu(std::vector<std::pair<int, int>> myArcs):nodes{0}
{
	//creem una llista teporal per poder comptar el nombre de nodes, ja tinguin arestes o sense.
	std::list<int> tempList;
	for (int i = 0; i <= myArcs.size(); i++)
	{
		for (std::list<int>::iterator it = tempList.begin(); it != tempList.end(); it++)
		{
			if (*it != myArcs[i].first)
			{
				tempList.push_back(*it);
			}
			if(*it != myArcs[i].second)
			{
				tempList.push_back(*it);
			}
		}
	}

	nodes = tempList.size();
	md = new bool*[nodes];//tenim les files
	for (int i = 0; i < nodes; i++)
	{
		md[i] = new bool[nodes];
	}

	//accedim a cadascun:
	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < nodes; j++)
		{
			bool found=false;
			//recorrem el vector buscant el parell i,j:
			for (const std::pair<int, int> &e : myArcs)
			{
				if (e.first == i && e.second == j)
				{
					found = true;
				}
			}
			if (found)
			{
				md[i][j] = true;
			}
			else
			{
				md[i][j] = false;
			}
		}
	}
}

GraphDMatriu::~GraphDMatriu()
{
	for (int i = 0; i < nodes; i++)
	{
		delete[]md[i];
		delete[]md;
	}
}
*/

GraphDMatriu::GraphDMatriu(std::vector<std::pair<int, int>> myArcs)
{
	for (auto &pair : myArcs)
	{
		matrix[pair] = true;
	}
}

GraphDMatriu::~GraphDMatriu()
{
}

void GraphDMatriu::Insert(std::pair<int, int>arc)
{
	matrix[arc] = true;
}

void GraphDMatriu::Eliminate(std::pair<int, int>arc)
{
	matrix[arc] = false;
}

int GraphDMatriu::getIndex(int n)
{
	int count = 0;
	for (std::map<std::pair<int, int>,bool>::iterator it = matrix.begin(); it != matrix.end(); it++)
	{
		if (it->first.first == n)
		{
			count++;
		}
	}
	return count;
}


