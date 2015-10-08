SOURCES = src/SanE_10_P2_Graph.cpp src/parser.cpp src/AdjacencyMatrix.cpp src/edgrlib.cpp
INC_DIR = include

start:	src/SanE_10_P2_Graph.cpp
	@mkdir -p build
	g++ -Wall -std=c++11 -o build/SanE_10_P2_Graph $(SOURCES) -I$(INC_DIR)

run: build/SanE_10_P2_Graph
	./build/SanE_10_P2_Graph
	
clean: 
	rm -rf build