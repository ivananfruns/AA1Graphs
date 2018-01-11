#include "GraphD.h"



GraphD::GraphD()
{
}

GraphD::GraphD(std::vector<std::pair<int, int>> myArcs)
{

	for (int i = 0; i < myArcs.size(); i++)
	{
		node firstNode, secondNode;
		firstNode.info = myArcs[i].first;
		secondNode.info = myArcs[i].second;
		bool firstFound=false;
		bool secondFound = false;
		for (int j = 0; j < nodeVector.size(); j++)
		{
			if (!firstFound && nodeVector[j].info == firstNode.info)
			{
				firstFound = true;
				nodeVector[j].adyacencias.push_back(secondNode.info);
			}
			//també hem d'inserir els nodes que no connecten amb cap altre node:
			if (!secondFound && nodeVector[j].info == secondNode.info)
			{
				secondFound = true;
			}
		}
		//inserim els nodes primers:
		if (!firstFound)
		{
			nodeVector.push_back(firstNode);
		}
		if (!secondFound)
		{
			nodeVector.push_back(secondNode);
		}
	}
}


GraphD::~GraphD()
{
}

void GraphD::Insert(std::pair<int, int> arc)
{
	node firstNode, secondNode;
	firstNode.info = arc.first;
	secondNode.info = arc.second;
	bool firstFound = false;
	bool secondFound = false;
	for (int j = 0; j < nodeVector.size(); j++)
	{
		if (!firstFound && nodeVector[j].info == firstNode.info)
		{
			firstFound = true;
			nodeVector[j].adyacencias.push_back(secondNode.info);
		}
		//també hem d'inserir els nodes que no connecten amb cap altre node:
		if (!secondFound && nodeVector[j].info == secondNode.info)
		{
			secondFound = true;
		}
	}
	if (!firstFound)  nodeVector.push_back(firstNode);
	if (!secondFound) nodeVector.push_back(secondNode);
}
