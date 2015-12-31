//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Incremental Graph Project
//------------------------------------------------------
#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <string>
#include "SanE_10_P3_helpers.h"

#define MAXNODES 26

class AdjacencyMatrix
{
	private:
		bool UNDIRECTED;
		static const int empty = -1;
		unsigned int totalEdges;
		struct {
			bool exists = false;
			std::string name = "";
			int distance = empty;
		} edge[MAXNODES][MAXNODES];
	
	public:
		AdjacencyMatrix();
		void Generate(std::vector<std::string>);
		void AddNode(int);
		void DeleteNode(int);
		void SearchNode(int);
		void AddEdge(int, int, std::string, int);
		void DeleteEdge(int, int);
		void PrintMatrix();
		void PrintList();
		//std::vector<std::pair<int, int>> Kruskal();
};
#endif