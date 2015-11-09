SOURCES = src/SanE_10_P3_Main.cpp src/SanE_10_P3_helpers.cpp src/SanE_10_P3_AdjacencyMatrix.cpp
INC_DIR = include

start:	src/SanE_10_P3_Main.cpp
	@mkdir -p build
	g++ -Wall -std=c++11 -o build/SanE_10_P3_Main $(SOURCES) -I$(INC_DIR)

run: build/SanE_10_P3_Main
	./build/SanE_10_P3_Main
	
clean: 
	rm -rf build