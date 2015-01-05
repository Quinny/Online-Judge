#ifndef QP_UNDIRECTED_GRAPH_H
#define QP_UNDIRECTED_GRAPH_H

#include <map>
#include <vector>

template <typename T>
using adjacency_list = std::vector<std::pair<T, unsigned long>>;

template <typename T>
class undirected_graph{
	private:
		std::map<T, adjacency_list<T>> nodes_; // each node is mapped to a vector of ajacent nodes
											   // The unsigned long denotes the weight of the edge

	public:
		void connect(T u, T v, unsigned long w){
			nodes_[u].push_back(std::make_pair(v, w));
			nodes_[v].push_back(std::make_pair(u, w));
		}

		void disconnect(T u, T v){
			for(auto i : nodes_[u]){
				if(i.first == v) nodes_[u].erase(i);
			}
			for(auto i : nodes_[v]){
				if(i.first == u) nodes_[v].erase(i);
			}
		}

		adjacency_list<T> adjacent_to(T u){
			return nodes_[u];
		}

		void remove_node(T v){
			nodes_.erase(v);
			for(auto i : nodes_){
				for(int j = 0; j < i.second.size(); j++){
					if(i.second[j].first == v) i.second.erase(i.second.begin() + j);
				}
			}
		}
};

#endif