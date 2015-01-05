#include <iostream>
#include <queue>
#include "undirected_graph.hpp"

#define N 40

struct Compare{
	bool operator() (std::pair<char, unsigned long> const& a, std::pair<char, unsigned long> const& b){ return a.second > b.second; }
};
using PQ = std::priority_queue<std::pair<char, unsigned long>, std::vector<std::pair<char, unsigned long>>, Compare>;

void add_adjacent(char, undirected_graph<char>&, PQ&);

int main(){
	undirected_graph<char> graph;
	PQ q;
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
	int cost = 0;
	add_adjacent('A', graph, q);
	graph.remove_node('A');
	while(graph.size() > 0){ // go until we have a connection to all verticies
		auto t = q.top();
		while(!graph.has_node(t.first)){
			q.pop();
			t = q.top();
		}
		q.pop();
		cost += t.second;
		add_adjacent(t.first, graph, q); // add all adjacent edges of the lighest vertex found
		graph.remove_node(t.first); // we have a link to the node so delete it
	}
	std::cout << (orig / 2) - cost << std::endl; // divide the original weight by 2 to account for parralel edges*/
	return 0;
}

void add_adjacent(char k, undirected_graph<char>& g, PQ& q){
	for(auto v : g.adjacent_to(k))
		q.push(v);
}