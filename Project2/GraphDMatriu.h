#pragma once
#include <vector>
#include <list>
#include <map>

class GraphDMatriu
{
public:
	//bool** md;
	//int nodes;
	std::map<std::pair<int, int>, bool> matrix;

	GraphDMatriu(std::vector<std::pair<int, int>>);
	~GraphDMatriu();
	void Insert(std::pair<int, int>);
	void Eliminate(std::pair<int, int>);
	int getIndex(int);
};

