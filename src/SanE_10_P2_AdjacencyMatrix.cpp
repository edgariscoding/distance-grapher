//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Program 2 - Basic Undirected Graph
//------------------------------------------------------

#include "SanE_10_P2_AdjacencyMatrix.h"

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

void AdjacencyMatrix::Generate(vector<string> parsedInput)
{
	if (parsedInput[0] == "node")
	{
		if (parsedInput[1] == "add")
		{
			AddNode(static_cast<int>((char) toupper(parsedInput[2][0])) - 65);

		}
		else if (parsedInput[1] == "delete")
		{
			int oldNode = (static_cast<int>((char) toupper(parsedInput[2][0])) - 65);
			DeleteNode(oldNode);
		}
		else if (parsedInput[1] == "search")
		{
			int searchNode = (static_cast<int>((char) toupper(parsedInput[2][0])) - 65);
			SearchNode(searchNode);
		}
		else
		{
			userError();
		}
	}
	else if (parsedInput[0] == "edge")
	{
		if (parsedInput[1] == "add")
		{
			int firstAddEdge = (static_cast<int>((char) toupper(parsedInput[2][0])) - 65);
			int secondAddEdge = (static_cast<int>((char) toupper(parsedInput[3][0])) - 65);
			AddEdge(firstAddEdge, secondAddEdge);
		}
		else if (parsedInput[1] == "delete")
		{
			int firstDelEdge = (static_cast<int>((char) toupper(parsedInput[2][0])) - 65);
			int secondDelEdge = (static_cast<int>((char) toupper(parsedInput[3][0])) - 65);
			DeleteEdge(firstDelEdge, secondDelEdge);
		}
		else
		{
			userError();
		}
	}
	else if (parsedInput[0] == "print")
	{
		if (parsedInput[1] == "matrix")
		{
			PrintMatrix();
		}
		else if (parsedInput[1] == "list")
		{
			PrintList();
		}
		else
		{
			userError();
		}
	}
	else
	{
		userError();
	}
}

void AdjacencyMatrix::AddNode(int nodeName)
{
	if (letters[nodeName])
	{
		cout << "*** ERROR *** DUPLICATE NODE: " << (static_cast<char> (nodeName + 65)) << "\n";
	}
	else
	{
		letters[nodeName] = true;
		cout << "ADDED: NODE " << (static_cast<char> (nodeName + 65)) << "\n";
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
				if(nodeName != i)
				{
					cout << "EDGE AUTO REMOVED BY NODE DELETION: " << (static_cast<char> (i + 65)) << "-" <<  (static_cast<char> (nodeName + 65)) << "\n";

				}

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
		cout << "*** ERROR *** DUPLICATE EDGE: " << (static_cast<char> (firstEdge + 65)) << "-" << (static_cast<char> (secondEdge + 65)) << "\n";
	}
	else if(firstEdge == secondEdge)
	{
		adj[firstEdge][secondEdge] = '1';
		letters[firstEdge] = true;
		cout << "ADDED: EDGE " << (static_cast<char> (firstEdge + 65)) << "-" << (static_cast<char> (secondEdge + 65)) << "\n";
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
		cout << "DELETED: EDGE " << (static_cast<char> (firstEdge + 65)) << "-" <<  (static_cast<char> (secondEdge + 65)) << "\n";
		cout << "DELETED: EDGE " << (static_cast<char> (secondEdge + 65)) << "-" <<  (static_cast<char> (firstEdge + 65)) << "\n";
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