#include <iostream>
#include "undirected_graph.hpp"
#define N 40

int main(){
	undirected_graph<char> graph;
	int orig = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int w;
			std::cin >> w;
			if(w > -1){ // check if legit number
				graph.connect('A' + i, 'A' + j, w);
				orig += w;
			}
		}
	}
	auto mst = graph.mst();
	std::cout << graph.order() - mst.order() << std::endl;
	return 0;
}