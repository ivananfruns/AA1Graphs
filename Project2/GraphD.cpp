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
	bool firstFound = false;
	bool secondFound = false;
	for (int j = 0; j < nodeVector.size(); j++)
	{
		if (!firstFound && nodeVector[j].info == firstNode.info)
		{
			firstFound = true;
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


for (int i = 0; i < myArcs.size(); i++)
{
	int firstNode, secondNode;
	firstNode = myArcs[i].first;
	secondNode = myArcs[i].second;
	for (int j = 0; j < nodeVector.size(); j++)
	{
		if (nodeVector[j].info == firstNode)
		{
			bool found = false;
			for (std::list<int>::iterator it = nodeVector[j].adyacencias.begin(); it != nodeVector[j].adyacencias.end(); it++)
			{
				if (*it == secondNode)
				{
					found = true;
				}
			}
			if (!found)
			{
				nodeVector[j].adyacencias.push_back(secondNode);
			}
		}

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

	for (int i = 0; i < nodeVector.size(); i++)
	{
		if (!firstFound && nodeVector[i].info == firstNode.info)
		{
			firstFound = true;
			nodeVector[i].adyacencias.push_back(secondNode.info);
		}
		//també hem d'inserir els nodes que no connecten amb cap altre node:
		if (!secondFound && nodeVector[i].info == secondNode.info)
		{
			secondFound = true;
		}
	}

	if (!firstFound)  nodeVector.push_back(firstNode);
	if (!secondFound) nodeVector.push_back(secondNode);
}

void GraphD::Eliminate(std::pair<int, int> arc)
{
	int firstNode, secondNode;
	firstNode = arc.first;
	secondNode = arc.second;
	bool firstFound = false;

	for (int i = 0; i < nodeVector.size() && !firstFound; i++)
	{
		if (nodeVector[i].info == firstNode)
		{
			firstFound = true;
			//recorrem la llista d'adjacències del node:
			for (std::list<int>::iterator it = nodeVector[i].adyacencias.begin(); it != nodeVector[i].adyacencias.end(); it++)
			{
				if (*it == secondNode)
				{
					nodeVector[i].adyacencias.remove(*it);//eliminem el segon número
					//nodeVector[i].adyacencias.erase(it);
					break;
				}
			}
		}
	}
}

int GraphD::getIndex(node n)
{
	for (int i = 0; i < nodeVector.size(); i++)
	{
		if (nodeVector[i].info == n.info)
		{
			return nodeVector[i].adyacencias.size();
		}
	}
}

bool GraphD::arc(node n1, node n2)
{
	bool found=false;
	for (int i = 0; i < nodeVector.size(); i++)
	{
		if (nodeVector[i].info == n1.info)
		{
			for (std::list<int>::iterator it = nodeVector[i].adyacencias.begin(); it != nodeVector[i].adyacencias.end(); it++)
			{
				if (*it == n2.info)
				{
					found=true;
					break;
				}
			}
			break;
		}
	}
	return found;
}

bool GraphD::path(node n1, node n2)
{
	for (int i = 0; i < nodeVector.size(); i++)
	{
		if (nodeVector[i].info == n1.info)
		{
			if (arc(nodeVector[i], n2))
			{
				foundAPath = true;
				break;
			}
			else
			{
				for (std::list<int>::iterator it = nodeVector[i].adyacencias.begin(); it != nodeVector[i].adyacencias.end()&&!foundAPath; it++)
				{
					for (int j = 0; j < nodeVector.size()&&!foundAPath; j++)
					{
						if (nodeVector[j].info == *it)
						{
							foundAPath=path(nodeVector[j], n2);
						}
					}
				}
			}
		}
	}
	if (foundAPath)
	{
		foundAPath = false;
		return true;
	}
	else
	{
		return false;
	}
}


