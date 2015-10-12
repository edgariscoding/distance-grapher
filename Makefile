SOURCES = src/SanE_10_P2_Main.cpp src/SanE_10_P2_parser.cpp src/SanE_10_P2_AdjacencyMatrix.cpp src/SanE_10_P2_edgrlib.cpp
INC_DIR = include

start:	src/SanE_10_P2_Main.cpp
	@mkdir -p build
	g++ -Wall -std=c++11 -o build/SanE_10_P2_Main $(SOURCES) -I$(INC_DIR)

run: build/SanE_10_P2_Main
	./build/SanE_10_P2_Main
	
clean: 
	rm -rf build