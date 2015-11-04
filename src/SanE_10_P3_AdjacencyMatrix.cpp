//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Incremental Graph Project
//------------------------------------------------------
#include "SanE_10_P3_AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int n) {
	this->n = n;
	adj = new int* [n];
	for (int i = 0; i < n; i++)	{
		adj[i] = new int [n];
		for(int j = 0; j < n; j++) {
			adj[i][j]= empty;
		}
	}
}

void AdjacencyMatrix::Generate(std::vector<string> parsedInput) {
	if (parsedInput[0] == "node") {
		if (parsedInput[1] == "add" && toupper(parsedInput[2][0]) == 'N') {
			AddNode(static_cast<int>((char) toupper(parsedInput[2][1])) - 65);
			return;
		}
		else if (parsedInput[1] == "delete" && toupper(parsedInput[2][0]) == 'N') {
			int oldNode = (static_cast<int>((char) toupper(parsedInput[2][1])) - 65);
			DeleteNode(oldNode);
			return;
		}
		else if (parsedInput[1] == "search" && toupper(parsedInput[2][0]) == 'N') {
			int searchNode = (static_cast<int>((char) toupper(parsedInput[2][1])) - 65);
			SearchNode(searchNode);
			return;
		}
	}
	if (parsedInput[0] == "edge") {
		if (parsedInput[1] == "add" && toupper(parsedInput[2][0]) == 'N' && toupper(parsedInput[3][0]) == 'N') {
			int firstAddEdge = (static_cast<int>((char) toupper(parsedInput[2][1])) - 65);
			int secondAddEdge = (static_cast<int>((char) toupper(parsedInput[3][1])) - 65);
			string name = parsedInput[4];
			int distance = atoi(parsedInput[5].c_str());
			AddEdge(firstAddEdge, secondAddEdge, name, distance);
			return;
		}
		else if (parsedInput[1] == "delete" && toupper(parsedInput[2][0]) == 'N' && toupper(parsedInput[3][0]) == 'N') {
			int firstDelEdge = (static_cast<int>((char) toupper(parsedInput[2][1])) - 65);
			int secondDelEdge = (static_cast<int>((char) toupper(parsedInput[3][1])) - 65);
			DeleteEdge(firstDelEdge, secondDelEdge);
			return;
		}
	}
	if (parsedInput[0] == "kruskal") {
		Kruskal();
		return;
	}
	if (parsedInput[0] == "print")	{
		if (parsedInput[1] == "matrix")	{
			PrintMatrix();
			return;
		}
		else if (parsedInput[1] == "list") {
			PrintList();
			return;
		}
	}
	else {
		userError();
	}
}

void AdjacencyMatrix::AddNode(int nodeName) {
	if (node[nodeName][nodeName].exists) {
		cout << "*** ERROR *** DUPLICATE NODE: N" << (static_cast<char> (nodeName + 65)) << "\n";
	}
	else {
		node[nodeName][nodeName].exists = true;
		cout << "ADDED: NODE N" << (static_cast<char> (nodeName + 65)) << "\n";
	}
}

void AdjacencyMatrix::DeleteNode(int nodeName) {
	if (!node[nodeName][nodeName].exists)	{
		cout << "*** ERROR *** NODE NOT FOUND FOR DELETION: N" << (static_cast<char> (nodeName + 65)) << "\n";
	}
	else {
		cout << "DELETED: NODE N" << (static_cast<char> (nodeName + 65)) << "\n";
		for (int i = 0; i < MAXNODES; i++) {
			if (adj[nodeName][i] != empty) {
				adj[nodeName][i] = empty;
				adj[i][nodeName] = empty;
				cout << "EDGE AUTO REMOVED BY NODE DELETION: N" << (static_cast<char> (nodeName + 65)) << " N" <<  (static_cast<char> (i + 65)) << "\n";
				if(nodeName != i) {
					adj[i][nodeName] = empty;
					node[i][nodeName].exists = false;
					cout << "EDGE AUTO REMOVED BY NODE DELETION: N" << (static_cast<char> (i + 65)) << " N" <<  (static_cast<char> (nodeName + 65)) << "\n";
				}
			}
		}
		node[nodeName][nodeName].exists = false;
	}
}

void AdjacencyMatrix::SearchNode(int nodeName) {
	if (node[nodeName][nodeName].exists)	{
		cout << "NODE N" << (static_cast<char> (nodeName + 65)) << ": FOUND\n";
	}
	else {
		cout << "NODE N" << (static_cast<char> (nodeName + 65)) << ": NOT FOUND\n";
	}
}

void AdjacencyMatrix::AddEdge(int firstEdge, int secondEdge, string name, int distance) {
	if( firstEdge > n || secondEdge > n || firstEdge < 0 || secondEdge < 0 || firstEdge == secondEdge ) {
		userError();
	}
	else if( !node[firstEdge][firstEdge].exists ) {
		cout << "*** ERROR *** NODE N" << (static_cast<char> (firstEdge + 65)) << ": NOT FOUND\n";
	}
	else if( !node[secondEdge][secondEdge].exists ) {
		cout << "*** ERROR *** NODE N" << (static_cast<char> (secondEdge + 65)) << ": NOT FOUND\n";
	}
	else if(( adj[firstEdge][secondEdge] != empty ) || ( adj[secondEdge][firstEdge] != empty )) {
		node[firstEdge][secondEdge].name = name;
		node[secondEdge][firstEdge].name = name;
		node[firstEdge][secondEdge].distance = distance;
		node[secondEdge][firstEdge].distance = distance;
		cout << "EDGE N" << (static_cast<char> (firstEdge + 65)) << " N" << (static_cast<char> (secondEdge + 65)) << " and N" << (static_cast<char> (firstEdge + 65)) << " N" << (static_cast<char> (secondEdge + 65)) << " UPDATE: NAME: " << name << " DIST: " << distance << "\n";
	}
	else {
		adj[firstEdge][secondEdge] = distance;
		adj[secondEdge][firstEdge] = distance;
		node[firstEdge][secondEdge].name = name;
		node[secondEdge][firstEdge].name = name;
		node[firstEdge][secondEdge].distance = distance;
		node[secondEdge][firstEdge].distance = distance;
		cout << "ADDED: EDGE N" << (static_cast<char> (firstEdge + 65)) << " N" << (static_cast<char> (secondEdge + 65)) << " NAME: " << name << " DIST: " << distance << "\n";
		cout << "ADDED: EDGE N" << (static_cast<char> (secondEdge + 65)) << " N" << (static_cast<char> (firstEdge + 65)) << " NAME: " << name << " DIST: " << distance << "\n";
	}
}

void AdjacencyMatrix::DeleteEdge(int firstEdge, int secondEdge) {
	if(firstEdge > n || secondEdge > n || firstEdge < 0 || secondEdge < 0) {
		userError();
	}
	else if(adj[firstEdge][secondEdge] == empty) {
		cout << "*** ERROR *** EDGE DOES NOT EXIST FOR DELETION: N" << (static_cast<char> (firstEdge + 65)) << " N" << (static_cast<char> (secondEdge + 65)) << "\n";
	}
	else {
		adj[firstEdge][secondEdge] = empty;
		node[firstEdge][secondEdge].exists = false;
		UNDIRECTED = !node[secondEdge][firstEdge].exists;
		cout << "DELETED: EDGE N" << (static_cast<char> (firstEdge + 65)) << " N" <<  (static_cast<char> (secondEdge + 65)) << "\n";
	}
}

void AdjacencyMatrix::PrintMatrix() {
	for (int x = 0; x < n; x++) {
		if (x == 0){
			cout << "   ";
		}
		cout << " N" << (char) (x + 65) << " ";
	}
	cout << "\n";

	for(int i = 0; i < n; i++) {
		cout << " N" << (char) (i + 65) << " ";
		for(int j = 0; j < n; j++) {
			cout << adj[i][j] << "  ";
		}
		cout << "\n";
	}
}

void AdjacencyMatrix::PrintList() {
	for (int i = 0; i < MAXNODES; ++i) {
		if (node[i][i].exists) {
			cout << "N" << (static_cast<char> (i + 65)) << " |     ";
			for (int j = 0; j < MAXNODES; ++j) {
				if (adj[i][j] != empty) {
					cout << "N" << (static_cast<char> (j + 65)) << "(" << node[i][j].name << "," << node[i][j].distance << ")     ";
				}
			}
			cout << "\n";
		}
	}
}

void AdjacencyMatrix::Kruskal() {
	// TODO: Implement Kruskal's Algorithm
	if (!UNDIRECTED) {
		cout << "ERROR: Kruskal's Algorithm available only for UNDIRECTED graphs\n";
	}
	cout << "\nYou called kruskal... MUST BE IMPLEMENTED ASAP!\n\n";
	return;
}