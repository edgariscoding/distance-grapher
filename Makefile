start:	src/SanE_10_P2_Graph.cpp
	g++ -o build/SanE_10_P2_Graph src/SanE_10_P2_Graph.cpp -I.

run: build/SanE_10_P2_Graph
	./build/SanE_10_P2_Graph
	
clean: 
	rm -f build/*