#pragma once
#include<vector>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>

class GraphDMap
{
public:
	std::unordered_map<int,std::list<int>> u_map;
	std::map<int,std::list<int>> map;

	GraphDMap();
	~GraphDMap();
	GraphDMap(std::vector<std::pair<int, int>>);
	void Insert(std::pair<int, int>);
	void Eliminate(std::pair<int, int>);
	int getIndex(int);
	bool path(int, int);
	bool circuit(int);
	bool euler();
};

