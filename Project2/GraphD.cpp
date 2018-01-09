#include "GraphD.h"



GraphD::GraphD()
{
}

GraphD::GraphD(std::vector<std::pair<int, int>> myArcs)
{

	for (int i = 0; i <= myArcs.size(); i++)
	{
		
		tmpNode.info = myArcs[i].first;
		nodeMap[myArcs[i].first] = 
	}
}




GraphD::~GraphD()
{
}
