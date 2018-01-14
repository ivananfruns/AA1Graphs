#include <iostream>
#include "GraphD.h"
#include"GraphDMap.h"

int main()
{
	std::vector<std::pair<int, int>> myArcs({ {1,2},{1,3},{2,3},{3,4} });//std::make_pair(1,2), std::make_pair(1,3),std::make_pair(2,3),std::make_pair(3,4) });

	//myArcs.push_back(std::make_pair(1, 2));
	/*
	//MYGRAPHD:***********************************************************************************************************************************
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

	std::cout << "\nInsert: \n";
	myGraphD.Insert({ 4,5 });
	for (int i = 0; i < myGraphD.nodeVector.size(); i++)
	{
		std::cout << "El node " << myGraphD.nodeVector[i].info << " connecta amb: \n";
		for (std::list<int>::iterator it = myGraphD.nodeVector[i].adyacencias.begin(); it != myGraphD.nodeVector[i].adyacencias.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "\nEliminate: \n";
	myGraphD.Eliminate({ 3,4 });
	for (int i = 0; i < myGraphD.nodeVector.size(); i++)
	{
		std::cout << "El node " << myGraphD.nodeVector[i].info << " connecta amb: \n";
		for (std::list<int>::iterator it = myGraphD.nodeVector[i].adyacencias.begin(); it != myGraphD.nodeVector[i].adyacencias.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		std::cout << std::endl;
	}
	myGraphD.Insert({ 3,4 });
	std::cout << "\n\nGRAF:\n";
	for (int i = 0; i < myGraphD.nodeVector.size(); i++)
	{
		std::cout << "El node " << myGraphD.nodeVector[i].info << " connecta amb: \n";
		for (std::list<int>::iterator it = myGraphD.nodeVector[i].adyacencias.begin(); it != myGraphD.nodeVector[i].adyacencias.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << "\ngetIndex: \n";
	node n1;
	n1.info = 1;
	std::cout << "Index of node " << n1.info << " is: " << myGraphD.getIndex(n1) << std::endl;

	std::cout << "\nVerificar si hi ha un arc: \n";
	node n2;
	n2.info =4;
	std::cout << "Nodes " << n1.info << " and " <<n2.info<<" have an ark? "<< myGraphD.arc(n1,n2) << std::endl;
	
	std::cout << "\nVerificar si hi ha un path: \n";
	std::cout << "Nodes " << n1.info << " and " << n2.info << " have a path? " << myGraphD.path(n1, n2) << std::endl;
	

	//MYGRAPHDMAP:***********************************************************************************************************************************
	GraphDMap myGraphDMap(myArcs);//es construeix nodeVector;

	for (auto it=myGraphDMap.map.begin();it!=myGraphDMap.map.end();it++)
	{
		std::cout << "El node " << it->first<< " connecta amb: \n";
		for (std::list<int>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
		{
			std::cout << *it2 << std::endl;
		}
		std::cout << std::endl;
	}

	//PATH:
	int n1 = 1;
	int n2 = 4;
	std::cout << "\nVerificar si hi ha un path: \n";
	std::cout << "Nodes " << n1 << " and " << n2 << " have a path? " << myGraphDMap.path(n1, n2) << std::endl;

	//Inserim un arc de 4 a 1:
	myGraphDMap.Insert({ 4,1 });
	std::cout << "Insert <4,1>\n";
	for (auto it = myGraphDMap.map.begin(); it != myGraphDMap.map.end(); it++)
	{
		std::cout << "El node " << it->first << " connecta amb: \n";
		for (std::list<int>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
		{
			std::cout << *it2 << std::endl;
		}
		std::cout << std::endl;
	}

	//CIRCUIT:
	std::cout << "\nVerificar si hi ha un circuit: \n";
	std::cout << "Circuit per a " << n1 << ": " << myGraphDMap.circuit(n1) << std::endl;

	//EULERIÀ:
	std::cout << "\nVerificar si es Euleria: \n";
	std::cout << "Euleria: " << myGraphDMap.euler() << std::endl;
	*/

	
	system("pause");
	return 0;
}