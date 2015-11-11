//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Incremental Graph Project
//------------------------------------------------------
#include <SanE_10_P3_AdjacencyMatrix.h>


AdjacencyMatrix::AdjacencyMatrix() {
	UNDIRECTED = true;
}

// Generates Adjacency Matrix using parsed input to call necessary functions.
void AdjacencyMatrix::Generate(std::vector<std::string> parsedInput) {
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
			std::string name = parsedInput[4];
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

// Adds new Adjacency Matrix node. Sets node's exists flag to true, assigns name, and disregards distance.
void AdjacencyMatrix::AddNode(int nodeName) {
	if (node[nodeName][nodeName].exists) {
		std::cout << "*** ERROR *** DUPLICATE NODE: N" << (static_cast<char> (nodeName + 65)) << "\n";
	}
	else {
		node[nodeName][nodeName].exists = true;
		node[nodeName][nodeName].name = (static_cast<char> (nodeName + 65));
		node[nodeName][nodeName].distance = empty;
		std::cout << "ADDED: NODE N" << (static_cast<char> (nodeName + 65)) << "\n";
	}
}

// Deletes existing Adjacency Matrix and removes associated edges automatically.
void AdjacencyMatrix::DeleteNode(int nodeName) {
	if (!node[nodeName][nodeName].exists) {
		std::cout << "*** ERROR *** NODE NOT FOUND FOR DELETION: N" << (static_cast<char> (nodeName + 65)) << "\n";
	}
	else {
		node[nodeName][nodeName].exists = false;
		node[nodeName][nodeName].name = "";
		node[nodeName][nodeName].distance = empty;
		std::cout << "DELETED: NODE N" << (static_cast<char> (nodeName + 65)) << "\n";
		for (int i = 0; i < MAXNODES; i++) {
			if (node[nodeName][i].exists) {
				node[nodeName][i].exists = false;
				node[nodeName][i].name = "";
				node[nodeName][i].distance = empty;
				std::cout << "EDGE AUTO REMOVED BY NODE DELETION: N" << (static_cast<char> (nodeName + 65)) << " N" <<  (static_cast<char> (i + 65)) << "\n";
			}
			if (node[i][nodeName].exists) {
				node[i][nodeName].exists = false;
				node[i][nodeName].name = "";
				node[i][nodeName].distance = empty;
				std::cout << "EDGE AUTO REMOVED BY NODE DELETION: N" << (static_cast<char> (i + 65)) << " N" <<  (static_cast<char> (nodeName + 65)) << "\n";
			}
		}
	}
}

// Searches Adjacency Matrix for the specified node by checking its exist flag.
void AdjacencyMatrix::SearchNode(int nodeName) {
	if (node[nodeName][nodeName].exists)	{
		std::cout << "NODE N" << (static_cast<char> (nodeName + 65)) << ": FOUND\n";
	}
	else {
		std::cout << "NODE N" << (static_cast<char> (nodeName + 65)) << ": NOT FOUND\n";
	}
}

// Adds (or updates) a bidirectional edge to the Adjacency Matrix.
void AdjacencyMatrix::AddEdge(int firstEdge, int secondEdge, std::string name, int distance) {
	if( firstEdge > MAXNODES || secondEdge > MAXNODES || firstEdge < 0 || secondEdge < 0 || firstEdge == secondEdge ) {
		userError();
	}
	else if (!node[firstEdge][firstEdge].exists) {
		std::cout << "*** ERROR *** NODE N" << (static_cast<char> (firstEdge + 65)) << ": NOT FOUND\n";
	}
	else if (!node[secondEdge][secondEdge].exists) {
		std::cout << "*** ERROR *** NODE N" << (static_cast<char> (secondEdge + 65)) << ": NOT FOUND\n";
	}
	else if ((node[firstEdge][secondEdge].exists) || (node[secondEdge][firstEdge].exists)) {
		node[firstEdge][secondEdge].exists = true;
		node[secondEdge][firstEdge].exists = true;
		node[firstEdge][secondEdge].name = name;
		node[secondEdge][firstEdge].name = name;
		node[firstEdge][secondEdge].distance = distance;
		node[secondEdge][firstEdge].distance = distance;
		std::cout << "EDGE N" << (static_cast<char> (firstEdge + 65)) << " N" << (static_cast<char> (secondEdge + 65)) << " and N" << (static_cast<char> (firstEdge + 65)) << " N" << (static_cast<char> (secondEdge + 65)) << " UPDATE: NAME: " << name << " DIST: " << distance << "\n";
	}
	else {
		node[firstEdge][secondEdge].exists = true;
		node[secondEdge][firstEdge].exists = true;
		node[firstEdge][secondEdge].name = name;
		node[secondEdge][firstEdge].name = name;
		node[firstEdge][secondEdge].distance = distance;
		node[secondEdge][firstEdge].distance = distance;
		++totalEdges;
		std::cout << "ADDED: EDGE N" << (static_cast<char> (firstEdge + 65)) << " N" << (static_cast<char> (secondEdge + 65)) << " NAME: " << name << " DIST: " << distance << "\n";
		std::cout << "ADDED: EDGE N" << (static_cast<char> (secondEdge + 65)) << " N" << (static_cast<char> (firstEdge + 65)) << " NAME: " << name << " DIST: " << distance << "\n";
	}
}

// Deletes an existing unidirectional edge on the Adjacency Matrix. Sets UNDIRECTED flag if single edge is deleted.
void AdjacencyMatrix::DeleteEdge(int firstNode, int secondNode) {
	if(firstNode > MAXNODES || secondNode > MAXNODES || firstNode < 0 || secondNode < 0) {
		userError();
	}
	else if(!node[firstNode][secondNode].exists) {
		std::cout << "*** ERROR *** EDGE DOES NOT EXIST FOR DELETION: N" << (static_cast<char> (firstNode + 65)) << " N" << (static_cast<char> (secondNode + 65)) << "\n";
	}
	else {
		node[firstNode][secondNode].exists = false;
		node[firstNode][secondNode].name = "";
		node[firstNode][secondNode].distance = empty;
		UNDIRECTED = !node[secondNode][firstNode].exists;
		--totalEdges;
		std::cout << "DELETED: EDGE N" << (static_cast<char> (firstNode + 65)) << " N" <<  (static_cast<char> (secondNode + 65)) << "\n";
	}
}

// Prints active fields on the Adjacency Matrix.
void AdjacencyMatrix::PrintMatrix() {
	for (int i = 0; i < MAXNODES; ++i) {
		if (i == 0){
			std::cout << "   ";
		}
		if (node[i][i].exists) {
			std::cout << " N" << (char) (i + 65) << " ";
		}
	}
	std::cout << "\n";
	for(int i = 0; i < MAXNODES; i++) {
		if (node[i][i].exists) {
			std::cout << " N" << (char) (i + 65) << " ";
			for (int j = 0; j < MAXNODES; j++) {
				if (node[j][j].exists) {
					std::cout << node[i][j].distance << "  ";
				}
			}
			std::cout << "\n";
		}
	}
}

// Prints active fields on an Adjacency List generated from the Adjacency Matrix.
void AdjacencyMatrix::PrintList() {
	for (int i = 0; i < MAXNODES; ++i) {
		if (node[i][i].exists) {
			std::cout << "N" << (static_cast<char> (i + 65)) << " |     ";
			for (int j = 0; j < MAXNODES; ++j) {
				if (node[i][j].exists && (i != j)) {
					std::cout << "N" << (static_cast<char> (j + 65)) << "(" << node[i][j].name << "," << node[i][j].distance << ")     ";
				}
			}
			std::cout << "\n";
		}
	}
}


// Applies Kruskal's Algorithm to a copy of the current Adjacency Matrix then prints an minimum spanning tree Adjacency List.
void AdjacencyMatrix::Kruskal() {
	if (!UNDIRECTED) {
		std::cout << "ERROR: Kruskal's Algorithm available only for UNDIRECTED graphs\n";
	}
	else{

		// TODO: Implement Kruskal's Algorithm
		std::cout << "TODO: Implement Kruskal's Algorithm\n";

	}
	return;

}