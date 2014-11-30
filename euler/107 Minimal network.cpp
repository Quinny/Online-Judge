#include <iostream>
#include <unordered_map>
#include <queue>
#include <set>

#define N 40

struct Compare{
	bool operator() (std::pair<char, int> const& a, std::pair<char, int> const& b){ return a.second > b.second; }
};

using Graph = std::unordered_multimap<char, std::pair<char, int>>; // because typing all this out is annoying
using PQ = std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, Compare>;

void add_adjacent(char, Graph&, PQ&);

int main(){
	Graph graph;
	PQ q;
	int orig = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int w;
			std::cin >> w;
			if(w > -1){ // check if legit number
				graph.insert(std::make_pair('A' + i, std::make_pair('A' + j, w))); // make an adjacency list
				orig += w;
			}
		}
	}
	int cost = 0;
	std::set<char> span;
	add_adjacent('A', graph, q);
	span.insert('A');
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
	std::cout << (orig / 2) - cost << std::endl; // divide the original weight by 2 to account for parralel edges
	return 0;
}

void add_adjacent(char k, Graph& g, PQ& q){
	auto range = g.equal_range(k);
	for_each (
		range.first,
		range.second,
		[&](Graph::value_type& x){ q.push(x.second); }
	);
}