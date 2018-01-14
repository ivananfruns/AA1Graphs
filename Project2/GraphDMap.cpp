#include "GraphDMap.h"



GraphDMap::GraphDMap()
{
}


GraphDMap::~GraphDMap()
{
}

//constructor amb map:
GraphDMap::GraphDMap(std::vector<std::pair<int, int>> myArcs)
{
	for (int i = 0; i < myArcs.size(); i++)
	{
		//busquem si la key del "node" existeix:
		if (map.find(myArcs[i].first)!=map.end())
		{
			bool found = false;
			for (std::list<int>::iterator it = map[myArcs[i].first].begin(); it != map[myArcs[i].first].end(); it++)
			{
				if (*it == myArcs[i].second)
				{
					found = true;
				}
			}
			if (!found)
			{
				map[myArcs[i].first].push_back(myArcs[i].second);
			}
		}
		else
		{
			//si no existeix, el posem al map i li posem la llista
			std::list<int> tmpList;
			//en el cas que el segon ìnt`no existeixi, també l'haurem de posar com a node buit
			if (map.find(myArcs[i].second) == map.end())
			{
				map[myArcs[i].second] = tmpList;
			}
			//omplenem la llista del segon "int"
			tmpList.push_back(myArcs[i].second);
			map[myArcs[i].first]=tmpList;
			
		}
		
	}
}

void GraphDMap::Insert(std::pair<int, int>arc)
{
	if (map.find(arc.first) != map.end())
	{
		map[arc.first].push_back(arc.second);
	}
	else
	{
		std::list<int> tempList;
		if (map.count(arc.second) == 0)
		{
			map[arc.second]=tempList;
		}
		tempList.push_back(arc.second);
		map[arc.first]=tempList;
	}
}

void GraphDMap::Eliminate(std::pair<int, int>arc)
{
	if (map.count(arc.first) != 0)//el node existeix
	{
		std::list<int>::iterator it = std::find(map[arc.first].begin(), map[arc.first].end(), arc.second);
		map[arc.first].erase(it);
	}
}

int GraphDMap::getIndex(int node)
{
	return map[node].size();
}

bool GraphDMap::path(int n1, int n2)
{
	bool found = false;
	if (map.count(n1) != 0 && map.count(n2)!=0)//si els nodes existeixen
	{
		//busquem si té connexió directa:
		std::list<int>::iterator it = std::find(map[n1].begin(), map[n1].end(), n2);
		if (it != map[n1].end())//connexió trobada
		{
			found = true;
		}
		else
		{
			for (std::list<int>::iterator it = map[n1].begin(); it != map[n1].end(); it++)
			{
				found = path(*it, n2);
				if (found) break;
			}
		}
	}
	return found;
}

bool GraphDMap::circuit(int node)
{
	if (map.count(node) != 0)
	{
		std::stack<int> m_stack;
		m_stack.push(node);
		while (!m_stack.empty())
		{
			int aux = m_stack.top();
			m_stack.pop();
			if (map[aux].size() != 0)
			{
				for (std::list<int>::iterator it = map[aux].begin(); it != map[aux].end(); it++)
				{
					if (*it != node)
					{
						m_stack.push(*it);
					}
					else
					{
						return true;
					}
				}
			}
			
		}	
	}
	return false;
}

bool GraphDMap::euler()
{
	int count = 0;
	for (auto it=map.begin();it!=map.end();it++)
	{
		if (getIndex(it->first) % 2 != 0)
		{
			count++;
		}
	}
	return count <= 2;
}