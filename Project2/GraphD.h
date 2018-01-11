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
	bool foundAPath = false;
	
public:
	GraphD();
	GraphD(std::vector<std::pair<int,int>>);
	~GraphD();
	std::vector<node> nodeVector;
	void Insert(std::pair<int, int>);
	void Eliminate(std::pair<int, int>);
	int getIndex(node);
	bool arc(node, node);
	bool path(node, node);
};