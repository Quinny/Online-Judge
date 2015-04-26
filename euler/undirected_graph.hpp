#ifndef QP_UNDIRECTED_GRAPH_H
#define QP_UNDIRECTED_GRAPH_H

#include <map>
#include <vector>
#include <set>
#include <queue>

template <typename T>
struct Edge{
	T from_, to_;
	unsigned long weight_;
	Edge(T f, T t, unsigned long w) : from_(f), to_(t), weight_(w) {};
	Edge<T> flip() const { return Edge<T>(to_, from_, weight_); }
};

template <typename T>
struct EdgeCompare{
	bool operator() (Edge<T> const& a, Edge<T> const& b) const { return a.weight_ > b.weight_; }
};

template <typename T>
using PQ = std::priority_queue<Edge<T>, std::vector<Edge<T>>, EdgeCompare<T>>;

template <typename T>
using adjacency_list = std::vector<Edge<T>>;

template <typename T>
class undirected_graph{
	private:
		std::map<T, adjacency_list<T>> nodes_; // each node is mapped to a vector of ajacent nodes
											   // The unsigned long denotes the weight of the edge

	public:
		void connect(T const& u, T const& v, const unsigned long w); // connects u to v with weight w
		void add_edge(Edge<T> const& e); // Adds edge e to the graph
		void disconnect(T const& u, T const& v); //disconnects u from v
		adjacency_list<T> adjacent_to(T const& u) { // All edges incidient on u
			return nodes_[u];
		}
		void remove_node(T v); //removes node v from the graph completely, including all edges incident upon it
		bool has_node(T const& v) const { // checks if the graph has a node with given payload
			return nodes_.find(v) != nodes_.end();
		}
		size_t size() const { // number of nodes in the graph
			return nodes_.size();
		}
		unsigned long order(){ // order the graph, summation of the order of all verticies
			unsigned long n = 0;
			for(auto i : nodes_){
				for(auto j : i.second){
					n += j.weight_;
				}
			}
			return n / 2; // divide by 2 because the graph is undirected so each edge gets counted twice
		}
		undirected_graph<T> mst(); // returns the MST of the graph
};

template <typename T>
void undirected_graph<T>::connect(T const& u, T const& v, const unsigned long w){
	for(auto i : adjacent_to(u)){
		if(i.to_ == v && i.weight_ == w) return; // check to make sure they are not already connected
												 // Reasoning for this is many input sets include redundancy
	}
	if(u == v) return;
	nodes_[u].push_back(Edge<T>(u, v, w));
	nodes_[v].push_back(Edge<T>(v, u, w));
}

template <typename T>
void undirected_graph<T>::add_edge(Edge<T> const& e){
	nodes_[e.from_].push_back(e);
	nodes_[e.to_].push_back(e.flip());
}

template <typename T>
void undirected_graph<T>::disconnect(T const& u, T const& v){
	for(auto i : nodes_[u]){
		if(i.to_ == v) nodes_[u].erase(i);
	}
	for(auto i : nodes_[v]){
		if(i.to_ == u) nodes_[v].erase(i);
	}
}

template <typename T>
void undirected_graph<T>::remove_node(T v){
	nodes_.erase(v);
	for(auto i : nodes_){
		for(int j = 0; j < i.second.size(); j++){
			if(i.second[j].to_ == v) i.second.erase(i.second.begin() + j);
		}
	}
}

template <typename T>
undirected_graph<T> undirected_graph<T>::mst() {
	undirected_graph<T> m; // the graph representing the minimum spanning tree
	PQ<T> q; // heap of edges
	auto first_node = nodes_.begin()->first;
	for(auto i : adjacent_to(first_node))
		q.push(i);
	while(m.size() != size()){
		auto t = q.top();
		while(m.has_node(t.to_)){
			q.pop();
			t = q.top();
		}
		q.pop();
		m.add_edge(t);
		for(auto i : adjacent_to(t.to_))
			q.push(i);
	}
	return m;
}
#endif
