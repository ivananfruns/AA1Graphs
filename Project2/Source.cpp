#include <iostream>
#include "GraphD.h"

int main()
{
	std::vector<std::pair<int, int>> myArcs({ {1,2},{1,3},{2,3},{3,4} });//std::make_pair(1,2), std::make_pair(1,3),std::make_pair(2,3),std::make_pair(3,4) });
	//myArcs.push_back(std::make_pair(1, 2));
	GraphD myGraphD(myArcs);//es construeix nodeVector;

	for (int i = 0; i < myGraphD.nodeVector.size(); i++)
	{
		std::cout << "El node " << myGraphD.nodeVector[i].info << " connecta amb: \n";
		for (std::list<int>::iterator it= myGraphD.nodeVector[i].adyacencias.begin(); it!= myGraphD.nodeVector[i].adyacencias.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		std::cout << std::endl;
	}


	system("pause");
	return 0;
}