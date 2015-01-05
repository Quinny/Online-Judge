#include <iostream>
#include <queue>
#include <set>
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
	std::set<char> span;
	add_adjacent('A', graph, q);
	span.insert('A');
	graph.remove_node('A');
	while(span.size() < N){ // go until we have a connection to all verticies
		auto t = q.top();
		while(span.find(t.first) != span.end()){ // prevent cycling through parralel edges
			q.pop();
			t = q.top();
		}
		q.pop();
		cost += t.second;
		span.insert(t.first);
		add_adjacent(t.first, graph, q); // add all adjacent edges of the lighest vertex found
	}
	std::cout << (orig / 2) - cost << std::endl; // divide the original weight by 2 to account for parralel edges*/
	return 0;
}

void add_adjacent(char k, undirected_graph<char>& g, PQ& q){
	for(auto v : g.adjacent_to(k))
		q.push(v);
}