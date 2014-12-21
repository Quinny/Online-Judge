#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<std::vector<int>> get_subsets(std::vector<int> const&);
bool disjoint(std::vector<int>&, std::vector<int>&);
int sum_set(std::vector<int> const&);
bool is_special(std::vector<int> const&);
std::vector<int> read_set();

int main(){
	int ans = 0;
	for(int i = 0; i < 100; i++){
		auto s = read_set();
		std::cout << i << std::endl;
		if(is_special(s)) ans += sum_set(s);
	}
	std::cout << ans << std::endl;
	return 0;
}

std::vector<int> read_set(){
	std::vector<int> v;
	int e;
	char c;
	while(c != '\n'){
		std::cin >> e;
		v.push_back(e);
		if(!(std::cin >> std::noskipws >> c)) break; // check for end of file
		std::cout << e << " ";	
	}
	std::cout << std::endl;
	return v;
}

bool is_special(std::vector<int> const& v){
	auto subs = get_subsets(v);
	for(auto i : subs){
		for(auto j : subs){
			if(disjoint(i, j)){
				int sum1 = sum_set(i);
				int sum2 = sum_set(j);
				if(sum1 == sum2) return false;
				if(sum1 >= sum2 && i.size() < j.size()) return false;
				if(sum2 >= sum1 && i.size() > j.size()) return false;
			}
		}
	}
	return true;
}

int sum_set(std::vector<int> const& v){
	return std::accumulate(v.begin(), v.end(), 0);
}

bool disjoint(std::vector<int>& v1, std::vector<int>& v2){
	if(v1 == v2) return false;
	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());
	int min_length = v1.size() > v2.size() ? v2.size() : v1.size();
	for(int i = 0; i < min_length; i++){
		if(v1[i] == v2[i]) return false;
	}
	return true;
}

std::vector<std::vector<int>> get_subsets(std::vector<int> const& set){
	std::vector<std::vector<int>> subset;
	std::vector<int> empty;
	subset.push_back(empty);
	for (int i = 0; i < set.size(); i++){
		auto tmp = subset;
		for (int j = 0; j < tmp.size(); j++)
			tmp[j].push_back(set[i]);
		for (int j = 0; j < tmp.size(); j++)
			subset.push_back(tmp[j]);
	}
	return subset;
}