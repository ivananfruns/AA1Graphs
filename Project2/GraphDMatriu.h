#pragma once
#include <vector>
#include <list>

class GraphDMatriu
{
public:
	bool** md;
	int nodes;
	GraphDMatriu(std::vector<std::pair<int, int>>);
	~GraphDMatriu();

};

