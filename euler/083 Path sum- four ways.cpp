#include <iostream>
#include <vector>
#define N 80

struct Node{
	int x, y, weight;
	Node(int xx, int yy, int w) : x(xx), y(yy), weight(w) {};
	bool operator < (const Node &a) const { return a.weight < weight; }
};

std::vector<std::pair<int, int>> adjacent_nodes(std::pair<int, int> u);
std::pair<int, int> translate(std::pair<int, int>, int, int);
int min_path(int cost[N][N], std::pair<int, int>);
void relax(int cost[N][N], int dists[N][N], std::pair<int, int> u);
void update_heap(std::vector<Node>&, int dists[N][N]);


int main(){
	int cost[N][N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
			std::cin >> cost[i][j];
	}
	std::cout << min_path(cost, std::make_pair(0, 0)) << std::endl;
	return 0;
}

int min_path(int cost[N][N], std::pair<int, int> start){
	int dists[N][N];
	std::vector<Node> unvisited;
	unvisited.reserve(N * N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			dists[i][j] = INT_MAX;
			Node n(i, j, INT_MAX);
			if(i == start.first && j == start.second){
				dists[i][j] = cost[start.first][start.second];
				n.weight = cost[start.first][start.second];
			}
			unvisited.push_back(n);
		}
	}
	std::make_heap(unvisited.begin(), unvisited.end());
	while(!unvisited.empty()){
		auto u = unvisited.front();
		relax(cost, dists, std::make_pair(u.x, u.y));
		std::swap(unvisited.front(), unvisited.back());
		unvisited.pop_back();
		for(int i = 0; i < unvisited.size(); i++)
			unvisited[i].weight = dists[unvisited[i].x][unvisited[i].y];
		std::make_heap(unvisited.begin(), unvisited.end());
	}
	return dists[N - 1][N - 1];
}

void relax(int cost[N][N], int dists[N][N], std::pair<int, int> u){
	auto s = adjacent_nodes(u);
	for(auto v : s){
		int relaxed = dists[u.first][u.second] + cost[v.first][v.second];
		if(relaxed < dists[v.first][v.second])
			dists[v.first][v.second] = relaxed;
	}
}

std::pair<int, int> translate(std::pair<int, int> u, int dx, int dy){
	return std::make_pair(u.first + dx, u.second + dy);
}

std::vector<std::pair<int, int>> adjacent_nodes(std::pair<int, int> u){
	std::vector<std::pair<int, int>> s;
	if(u.first != 0) // up
		s.push_back(translate(u, -1, 0));
	if(u.second != N - 1) // right
		s.push_back(translate(u, 0, 1));
	if(u.first != N - 1) // down
		s.push_back(translate(u, 1, 0));
	if(u.second != 0)
		s.push_back(translate(u, 0, -1));
	return s;
}