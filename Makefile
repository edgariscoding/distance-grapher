SOURCES = src/SanE_10_P2_Graph.cpp src/add.cpp
INC_DIR = include

start:	src/SanE_10_P2_Graph.cpp
	@mkdir -p build
	g++ -Wall -o build/SanE_10_P2_Graph $(SOURCES) -I$(INC_DIR)

run: build/SanE_10_P2_Graph
	./build/SanE_10_P2_Graph
	
clean: 
	rm -rf build