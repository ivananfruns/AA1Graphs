#include "GraphD.h"



GraphD::GraphD()
{
}

GraphD::GraphD(std::vector<std::pair<int, int>> myArcs)
{

	for (int i = 0; i <= myArcs.size(); i++)
	{
		node tmpNode;
		int tmpint;
		tmpNode.info = myArcs[i].first;
		bool found=false;
		for (int j = 0; j < nodeVector.size() && !found; j++)
		{
			if (nodeVector[j].info == tmpNode.info)
			{
				found = true;
				tmpint = j;
			}
		}
		if (!found)  nodeVector.push_back(tmpNode);
		else 
		{
			nodeVector[tmpint].adyacencias.push_back(myArcs[i].second);
		}

	}
}




GraphD::~GraphD()
{
}
