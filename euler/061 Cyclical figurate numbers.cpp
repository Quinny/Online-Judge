#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>

int tri(int);
int square(int);
int pent(int);
int hex(int);
int hept(int);
int oct(int);
int first_2(int);
int last_2(int);
std::unordered_map<int, int> fillmap(int(*foo)(int), int, int);

void recurse(int n, std::vector<bool> used, std::vector<std::unordered_map<int, int>>& firsts, int set, std::vector<int> chain);

int main(){
	// 4 digit triangle numbers go from	 	[45, 140]
	// 4 digit sqaure numbers go from 		[32, 99]
	// 4 digit pentagonal go from 			[26, 81]
	// 4 digit hexagonal go from			[23, 70]
	// 4 digit heptagonal go from			[21, 63]
	// 4 digit octagonal go from			[19, 58]
	auto tri_firsts = fillmap(tri, 45, 140);
	auto sq_firsts = fillmap(square, 32, 99);
	auto pent_firsts = fillmap(pent, 26, 81);
	auto hex_firsts = fillmap(hex, 23, 70);
	auto hept_firsts = fillmap(hept, 21, 63);
	auto oct_firsts = fillmap(oct, 19, 58);

	std::vector<std::unordered_map<int, int>> firsts{tri_firsts, sq_firsts, pent_firsts, hex_firsts, hept_firsts, oct_firsts};
	std::vector<bool> used {false, false, false, false, false, false};
	std::vector<int> chain;

	for(int i = 45; i <= 140; i++)
		recurse(tri(i), used, firsts, 0, chain);
	return 0;
}

void recurse(int n, std::vector<bool> used, std::vector<std::unordered_map<int, int>>& firsts, int set, std::vector<int> chain){
	chain.push_back(n);
	used[set] = true;
	bool found = true;
	for(auto i : used) found = found && i;
	if(found){
		if(chain.back() % 100 ==  chain.front() / 100)
			std::cout << std::accumulate(chain.begin(), chain.end(), 0) << std::endl;
		return;
	}
	int look = last_2(n);
	for(int i = 0; i < firsts.size(); i++){
		if(firsts[i][look] && !used[i])
			recurse(firsts[i][look], used, firsts, i, chain);
	}
}

std::unordered_map<int, int> fillmap( int(*foo)(int), int start, int end){
	std::unordered_map<int, int> m;
	for(int i = start; i <= end; i++){
		int t = foo(i);
		m[first_2(t)] = t;
	}
	return m;
}

int first_2(int n){
	return n / 100;
}

int last_2(int n){
	return n % 100;
}

int tri(int n){
	return (n * (n + 1)) / 2;
}

int square(int n){
	return n * n;
}

int pent(int n){
	return (n * (3 * n - 1)) / 2;
}

int hex(int n){
	return n * (2 * n - 1);
}

int hept(int n){
	return (n * (5 * n - 3)) / 2;
}

int oct(int n){
	return n * (3 * n - 2);
}
