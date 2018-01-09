#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
struct node{
	std::list<int> adyacencias;
	int info;
};
class GraphD
{
	
	std::map<int,std::list<int>> nodeMap;
public:
	GraphD();
	GraphD(std::vector<std::pair<int,int>> myArcs);
	~GraphD();
};