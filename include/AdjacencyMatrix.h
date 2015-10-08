//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Program 2 - Basic Undirected Graph
//------------------------------------------------------
#include <string>
#include <iostream>
#include "edgrlib.h"
using namespace std;

#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H
#define MAXNODES 26

class AdjacencyMatrix
{
	private:
		int n;
		char **adj;
		bool letters[MAXNODES] = {false};
	
	public:
		AdjacencyMatrix(int);
		void AddNode(int);
		void DeleteNode(int);
		void SearchNode(int);
		void AddEdge(int, int);
		void DeleteEdge(int, int);
		void PrintMatrix();
		void PrintList();
};
#endif