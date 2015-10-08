//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Program 2 - Basic Undirected Graph
//------------------------------------------------------

#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int n)
{
	this->n = n;
	adj = new char* [n];
	for (int i = 0; i < n; i++)
	{
		adj[i] = new char [n];
		for(int j = 0; j < n; j++)
		{
			adj[i][j] = '0';
		}
	}
}

void AdjacencyMatrix::AddNode(int i)
{
	if (letters[i])
	{
		cout << "*** ERROR *** DUPLICATE NODE: " << (static_cast<char> (i + 65)) << "\n";
	}
	else
	{
		letters[i] = true;
		cout << "ADDED: NODE " << (static_cast<char> (i + 65)) << "\n";
	}
}

void AdjacencyMatrix::DeleteNode(int nodeName)
{
	if (!letters[nodeName])
	{
		cout << "*** ERROR *** NODE NOT FOUND FOR DELETION: " << (static_cast<char> (nodeName + 65)) << "\n";
	}
	else
	{
		cout << "DELETED: NODE " << (static_cast<char> (nodeName + 65)) << "\n";
		for (int i = 0; i < MAXNODES; i++)
		{
			if (adj[nodeName][i] == '1')
			{
				adj[nodeName][i] = '0';
				adj[i][nodeName] = '0';
				cout << "EDGE AUTO REMOVED BY NODE DELETION: " << (static_cast<char> (nodeName + 65)) << "-" <<  (static_cast<char> (i + 65)) << "\n";
				cout << "EDGE AUTO REMOVED BY NODE DELETION: " << (static_cast<char> (i + 65)) << "-" <<  (static_cast<char> (nodeName + 65)) << "\n";

			}
		}
		letters[nodeName] = false;
	}
}

void AdjacencyMatrix::SearchNode(int i)
{
	if (letters[i])
	{
		cout << "NODE " << (static_cast<char> (i + 65)) << ": FOUND\n";
	}
	else
	{
		cout << "NODE " << (static_cast<char> (i + 65)) << ": NOT FOUND\n";
	}
}

void AdjacencyMatrix::AddEdge(int firstEdge, int secondEdge)
{
	if(firstEdge > n || secondEdge > n || firstEdge < 0 || secondEdge < 0)
	{
		userError();
	}
	else if(!letters[firstEdge])
	{
		cout << "*** ERROR *** NODE " << (static_cast<char> (firstEdge + 65)) << ": NOT FOUND\n";
	}
	else if(!letters[secondEdge])
	{
		cout << "*** ERROR *** NODE " << (static_cast<char> (secondEdge + 65)) << ": NOT FOUND\n";
	}
	else if((adj[firstEdge][secondEdge] == '1') || (adj[secondEdge][firstEdge] == '1'))
	{
		cout << "*** ERROR *** EDGE NOT DELETED * DUPLICATE: " << (static_cast<char> (firstEdge + 65)) << "-" << (static_cast<char> (secondEdge + 65)) << "\n";
	}
	else
	{
		adj[firstEdge][secondEdge] = '1';
		adj[secondEdge][firstEdge] = '1';
		letters[firstEdge] = true;
		letters[secondEdge] = true;
		cout << "ADDED: EDGE " << (static_cast<char> (firstEdge + 65)) << "-" << (static_cast<char> (secondEdge + 65)) << "\n";
		cout << "ADDED: EDGE " << (static_cast<char> (secondEdge + 65)) << "-" << (static_cast<char> (firstEdge + 65)) << "\n";

	}
}

void AdjacencyMatrix::DeleteEdge(int firstEdge, int secondEdge)
{
	if(firstEdge > n || secondEdge > n || firstEdge < 0 || secondEdge < 0)
	{
		userError();
	}
	else if(!letters[firstEdge] && !letters[secondEdge])
	{
		cout << "*** ERROR *** EDGE DOES NOT EXIST FOR DELETION: " << (static_cast<char> (firstEdge + 65)) << "-" << (static_cast<char> (secondEdge + 65)) << "\n";
	}
	else
	{
		adj[firstEdge][secondEdge] = '0';
		adj[secondEdge][firstEdge] = '0';
		letters[firstEdge] = false;
		letters[secondEdge] = false;
		cout << "DELETED: EDGE" << (static_cast<char> (firstEdge + 65)) << "-" <<  (static_cast<char> (secondEdge + 65)) << "\n";
		cout << "DELETED: EDGE" << (static_cast<char> (secondEdge + 65)) << "-" <<  (static_cast<char> (firstEdge + 65)) << "\n";
	}
}

void AdjacencyMatrix::PrintMatrix()
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			cout << adj[i][j] << " ";
		cout << endl;
	}
}

void AdjacencyMatrix::PrintList()
{
	int i, j;
	for (i = 0; i < MAXNODES; i++)
	{
		if (letters[i])
		{
			cout << (static_cast<char> (i + 65)) << " | ";
			for (j = 0; j < MAXNODES; j++)
			{
				if (adj[i][j] == '1')
				{
					cout << (static_cast<char> (j + 65)) << " ";
				}
			}
			cout << "\n";
		}
	}
}