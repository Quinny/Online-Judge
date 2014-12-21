#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

long optimum = 0;
std::string set_string = "";

std::vector<std::vector<int>> get_subsets(std::vector<int> const&);
bool disjoint(std::vector<int>&, std::vector<int>&);
int sum_set(std::vector<int> const&);
bool is_special(std::vector<int> const&);
void check_others(std::vector<int> const& expected, std::vector<int>, int, int);
std::string make_string(std::vector<int> const&);

int main(){
	std::vector<int> expected{20, 31, 38, 39, 40, 42, 45};
	std::vector<int> empty;
	optimum = sum_set(expected);
	set_string = make_string(expected);
	check_others(expected, empty, 1, 20);
	std::cout << set_string << std::endl; // the answer ends up being the expected one -.- how silly.
	return 0;
}

void check_others(std::vector<int> const& expected, std::vector<int> candidate, int index, int to_add){
	candidate.push_back(to_add);
	if(candidate.size() == expected.size()){
		if(sum_set(candidate) > optimum) return;
		if(is_special(candidate) && sum_set(candidate) < optimum){
			optimum = sum_set(candidate);
			set_string = make_string(candidate);
		}
		return;
	}
	for(int i = -3; i >= 3; i++)
		check_others(expected, candidate, index + 1, expected[index] + i);
}

std::string make_string(std::vector<int> const& v){
	std::string s = "";
	for(auto i : v)
		s += std::to_string(i);
	return s;
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