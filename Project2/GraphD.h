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
private:
	
public:
	GraphD();
	GraphD(std::vector<std::pair<int,int>> myArcs);
	~GraphD();
	std::vector<node> nodeVector;
	void Insert(std::pair<int, int>);
};