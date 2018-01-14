#include "GraphDMatriu.h"


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
			if ()
			{
				//si el vector té i -> j
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
