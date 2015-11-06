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
#include "SanE_10_P3_edgrlib.h"
using std::cout;
using std::string;

#define MAXNODES 26

class AdjacencyMatrix
{
	private:
		bool UNDIRECTED = true;
		int empty = -1;
		int n;
		int **adj;
		int totalEdges;
		struct {
			bool exists = false;
			string name;
			int distance;
		} node[MAXNODES][MAXNODES];
	
	public:
		AdjacencyMatrix(int);
		void Generate(std::vector<string>);
		void AddNode(int);
		void DeleteNode(int);
		void SearchNode(int);
		void AddEdge(int, int, string, int);
		void DeleteEdge(int, int);
		void PrintMatrix();
		void PrintList();
		void Kruskal();
};
#endif