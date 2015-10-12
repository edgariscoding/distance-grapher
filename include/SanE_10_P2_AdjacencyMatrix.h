//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Program 2 - Basic Undirected Graph
//------------------------------------------------------
#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include <string>
#include <iostream>
#include "SanE_10_P2_edgrlib.h"
#include "SanE_10_P2_parser.h"
#include <vector>
using namespace std;

#define MAXNODES 26

class AdjacencyMatrix
{
	private:
		int n;
		char **adj;
		bool letters[MAXNODES] = {false};
	
	public:
		AdjacencyMatrix(int);
		void Generate(vector<string>);
		void AddNode(int);
		void DeleteNode(int);
		void SearchNode(int);
		void AddEdge(int, int);
		void DeleteEdge(int, int);
		void PrintMatrix();
		void PrintList();
};
#endif