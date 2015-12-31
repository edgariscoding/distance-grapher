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
		//Kruskal();
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

// Adds new Adjacency Matrix edge. Sets edge's exists flag to true, assigns name, and disregards distance.
void AdjacencyMatrix::AddNode(int nodeName) {
	if (edge[nodeName][nodeName].exists) {
		std::cout << "*** ERROR *** DUPLICATE NODE: N" << (static_cast<char> (nodeName + 65)) << "\n";
	}
	else {
		edge[nodeName][nodeName].exists = true;
		edge[nodeName][nodeName].name = (static_cast<char> (nodeName + 65));
		edge[nodeName][nodeName].distance = empty;
		std::cout << "ADDED: NODE N" << (static_cast<char> (nodeName + 65)) << "\n";
	}
}

// Deletes existing Adjacency Matrix and removes associated edges automatically.
void AdjacencyMatrix::DeleteNode(int nodeName) {
	if (!edge[nodeName][nodeName].exists) {
		std::cout << "*** ERROR *** NODE NOT FOUND FOR DELETION: N" << (static_cast<char> (nodeName + 65)) << "\n";
	}
	else {
		edge[nodeName][nodeName].exists = false;
		edge[nodeName][nodeName].name = "";
		edge[nodeName][nodeName].distance = empty;
		std::cout << "DELETED: NODE N" << (static_cast<char> (nodeName + 65)) << "\n";
		for (int i = 0; i < MAXNODES; i++) {
			if (edge[nodeName][i].exists) {
				edge[nodeName][i].exists = false;
				edge[nodeName][i].name = "";
				edge[nodeName][i].distance = empty;
				std::cout << "EDGE AUTO REMOVED BY NODE DELETION: N" << (static_cast<char> (nodeName + 65)) << " N" <<  (static_cast<char> (i + 65)) << "\n";
			}
			if (edge[i][nodeName].exists) {
				edge[i][nodeName].exists = false;
				edge[i][nodeName].name = "";
				edge[i][nodeName].distance = empty;
				std::cout << "EDGE AUTO REMOVED BY NODE DELETION: N" << (static_cast<char> (i + 65)) << " N" <<  (static_cast<char> (nodeName + 65)) << "\n";
			}
		}
	}
}

// Searches Adjacency Matrix for the specified edge by checking its exist flag.
void AdjacencyMatrix::SearchNode(int nodeName) {
	if (edge[nodeName][nodeName].exists)	{
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
	else if (!edge[firstEdge][firstEdge].exists) {
		std::cout << "*** ERROR *** NODE N" << (static_cast<char> (firstEdge + 65)) << ": NOT FOUND\n";
	}
	else if (!edge[secondEdge][secondEdge].exists) {
		std::cout << "*** ERROR *** NODE N" << (static_cast<char> (secondEdge + 65)) << ": NOT FOUND\n";
	}
	else if ((edge[firstEdge][secondEdge].exists) || (edge[secondEdge][firstEdge].exists)) {
		edge[firstEdge][secondEdge].exists = true;
		edge[secondEdge][firstEdge].exists = true;
		edge[firstEdge][secondEdge].name = name;
		edge[secondEdge][firstEdge].name = name;
		edge[firstEdge][secondEdge].distance = distance;
		edge[secondEdge][firstEdge].distance = distance;
		std::cout << "EDGE N" << (static_cast<char> (firstEdge + 65)) << " N" << (static_cast<char> (secondEdge + 65)) << " and N" << (static_cast<char> (firstEdge + 65)) << " N" << (static_cast<char> (secondEdge + 65)) << " UPDATE: NAME: " << name << " DIST: " << distance << "\n";
	}
	else {
		edge[firstEdge][secondEdge].exists = true;
		edge[secondEdge][firstEdge].exists = true;
		edge[firstEdge][secondEdge].name = name;
		edge[secondEdge][firstEdge].name = name;
		edge[firstEdge][secondEdge].distance = distance;
		edge[secondEdge][firstEdge].distance = distance;
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
	else if(!edge[firstNode][secondNode].exists) {
		std::cout << "*** ERROR *** EDGE DOES NOT EXIST FOR DELETION: N" << (static_cast<char> (firstNode + 65)) << " N" << (static_cast<char> (secondNode + 65)) << "\n";
	}
	else {
		edge[firstNode][secondNode].exists = false;
		edge[firstNode][secondNode].name = "";
		edge[firstNode][secondNode].distance = empty;
		UNDIRECTED = !edge[secondNode][firstNode].exists;
		--totalEdges;
		std::cout << "DELETED: EDGE N" << (static_cast<char> (firstNode + 65)) << " N" <<  (static_cast<char> (secondNode + 65)) << "\n";
	}
}

// Prints active fields on the Adjacency Matrix.
void AdjacencyMatrix::PrintMatrix() {
	for (int i = 0; i < MAXNODES; ++i) {
		if (i == 0) {
			std::cout << "   ";
		}
		if (edge[i][i].exists) {
			std::cout << " N" << (char) (i + 65) << " ";
		}
	}
	std::cout << "\n";
	for(int i = 0; i < MAXNODES; ++i) {
		if (edge[i][i].exists) {
			std::cout << " N" << (char) (i + 65) << " ";
			for (int j = 0; j < MAXNODES; ++j) {
				if (edge[j][j].exists) {
					std::cout << edge[i][j].distance << "  ";
				}
			}
			std::cout << "\n";
		}
	}
}

// Prints active fields on an Adjacency List generated from the Adjacency Matrix.
void AdjacencyMatrix::PrintList() {
	for (int i = 0; i < MAXNODES; ++i) {
		if (edge[i][i].exists) {
			std::cout << "N" << (static_cast<char> (i + 65)) << " |     ";
			for (int j = 0; j < MAXNODES; ++j) {
				if (edge[i][j].exists && (i != j)) {
					std::cout << "N" << (static_cast<char> (j + 65)) << "(" << edge[i][j].name << "," << edge[i][j].distance << ")     ";
				}
			}
			std::cout << "\n";
		}
	}
}


// Applies Kruskal's Algorithm to a copy of the current Adjacency Matrix then prints an minimum spanning tree Adjacency List.
/*
std::vector<std::pair<int, int>> AdjacencyMatrix::Kruskal() {
	if (!UNDIRECTED) {
		std::cout << "ERROR: Kruskal's Algorithm available only for UNDIRECTED graphs\n";
	}
	else{
		// TODO: Implement Kruskal's Algorithm
		std::cout << "TODO: Implement Kruskal's Algorithm\n";
		std::cout << "Total Edges: " << totalEdges << "\n";

		//IGNORE
		//int edges[totalEdges];
		int k = 0;
		for (int i = 0; i < MAXNODES; ++i) {
			if (edge[i][i].exists) {
				for (int j = (i + 1); j < (MAXNODES - 1); ++j){
					if (edge[i][j].exists) {
						std::cout << "NON SORTED: " << edge[i][j].distance << "\n";
						edges[k] = edge[i][j].distance;
						k++;
					}
				}
			}
		}

		qsort(edges, totalEdges, sizeof(int), compare);

		for (auto x : edges) {
			std::cout << "EDGE: " << x << "\n";
		}

		std::vector< std::pair<int, int> > kruskal() {
			return mst;
		}
		//ENDIGNORE


		std::vector<std::pair<int, int>> mst; //our result

		std::map<int, std::set<int>> trees;
		std::map<int, int> treeByVertex;
		for (int i = 0; i < MAXNODES; ++i)
		{
			std::set<int> tree; // a tree containing a single vertex //? sorted, elements cannot be same
			tree.insert(i);
			trees.insert(std::make_pair(i, tree)); //at startup, the index of a tree is equaled to the index of a vertex
			treeByVertex.insert(std::make_pair(i, i));
		}

		std::multimap<int, std::pair<int, int>> edges;
		for (int i = 0; i < MAXNODES; ++i)
			for (int j = (i + 1); j < (MAXNODES - 1); ++j)
				if (edge[i][j].exists)
					edges.insert(std::make_pair(edge[i][j].distance, std::make_pair(i, j)));

		for (const auto& e : edges)
		{
			int v1 = e.second.first;
			int v2 = e.second.second;
			if (treeByVertex[v1] != treeByVertex[v2]) //use our lookup table to find out if two vertexes belong to different trees
			{
				mst.push_back(std::make_pair(v1, v2)); //the edge is in mst
				trees[v1].insert(trees[v2].begin(), trees[v2].end()); //merge trees
				for (int v : trees[v2]) //modify lookup table after merging
					treeByVertex[v] = treeByVertex[v1];
			}
		}
		return mst;

		//IGNORE
		typedef struct edge {
			int u, v, w;
		} edge;

		typedef struct edgeList {
			edge data[MAXNODES];
			int n;
		} edgeList;

		edgeList eList;
		int G[MAXNODES][MAXNODES], n;
		edgeList spanList;
		void kruskal();
		int find(int belongs[], int vertexno);
		void union1(int belongs[], int c1, int c2);
		void sort();
		void print();
		
		//ENDIGNORE

		//IGNORE
		typedef struct edge {
			int u,v,w;
		}edge;
		typedef struct edgelist {
			edge data[MAXNODES];
			int n;
		}edgelist;
		edgelist elist;
		int G[MAXNODES][MAXNODES],n;
		edgelist spanlist;
		void kruskal();
		int find(int belongs[],int vertexno);
		void union1(int belongs[],int c1,int c2);
		void sort();
		void print();
		void main()
		{
			int
					i,j,total_cost;

			printf("nEnter number of vertices:");

			scanf("%d",&n);

			printf("nEnter the adjacency matrix:n");

			for(i=0;i<n;i++)

				for(j=0;j<n;j++)

					scanf("%d",&G[i][j]);
			kruskal();
			print();
		}
		void kruskal()
		{
			int
					belongs[MAXNODES],i,j,cno1,cno2;
			elist.n=0;

			for(i=1;i<n;i++)

				for(j=0;j<i;j++)
				{
					if(G[i][j]!=0)
					{

						elist.data[elist.n].u=i;

						elist.data[elist.n].v=j;

						elist.data[elist.n].w=G[i][j];

						elist.n++;
					}
				}
			sort();

			for(i=0;i<n;i++)

				belongs[i]=i;
			spanlist.n=0;

			for(i=0;i<elist.n;i++)
			{

				cno1=find(belongs,elist.data[i].u);

				cno2=find(belongs,elist.data[i].v);
				if(cno1!=cno2)
				{

					spanlist.data[spanlist.n]=elist.data[i];
					spanlist.n=spanlist.n+1;

					union1(belongs,cno1,cno2);
				}
			}
		}
		int find(int belongs[],int vertexno)
		{

			return(belongs[vertexno]);
		}
		void union1(int belongs[],int c1,int c2)
		{
			int i;

			for(i=0;i<n;i++)
				if(belongs[i]==c2)
					belongs[i]=c1;
		}
		void sort()
		{
			int i,j;
			edge temp;

			for(i=1;i<elist.n;i++)

				for(j=0;j<elist.n-1;j++)

					if(elist.data[j].w>elist.data[j+1].w)
					{

						temp=elist.data[j];

						elist.data[j]=elist.data[j+1];

						elist.data[j+1]=temp;
					}
		}
		void print()
		{
			int i,cost=0;

			for(i=0;i<spanlist.n;i++)
			{

				printf("n%dt%dt%d", spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);

				cost=cost+spanlist.data[i].w;
			}

			printf("nnCost of the spanning tree=%d", cost);
		}
		//ENDIGNORE
	}
}
*/