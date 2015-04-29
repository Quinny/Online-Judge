#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

std::vector<std::set<int>> get_subsets(std::set<int> const&);
bool disjoint(std::set<int> const&, std::set<int> const&);
int sum_set(std::set<int> const&);
bool is_special(std::set<int> const&);
std::set<int> read_set();

int main(){
	int ans = 0;
	for(int i = 0; i < 100; i++){
		auto s = read_set();
		if(is_special(s))
            ans += sum_set(s);
	}
	std::cout << ans << std::endl;
	return 0;
}

std::set<int> read_set(){
	std::set<int> s;
	int e;
	char c;
	while(c != '\n'){
		std::cin >> e;
		s.insert(e);
        // check for eof
		if(!(std::cin >> std::noskipws >> c))
            break;
    }
    return s;
}

bool is_special(std::set<int> const& s){
	auto subs = get_subsets(s);
	for(auto i = subs.begin(); i != subs.end(); ++i) {
		for(auto j = std::next(i); j != subs.end(); ++j) {
			if(disjoint(*i, *j)){
				int sum1 = sum_set(*i);
				int sum2 = sum_set(*j);
				if(sum1 == sum2)
                    return false;
				if(sum1 >= sum2 && i->size() < j->size())
                    return false;
				if(sum2 >= sum1 && i->size() > j->size())
                    return false;
			}
		}
	}
	return true;
}

int sum_set(std::set<int> const& s){
	return std::accumulate(s.begin(), s.end(), 0);
}

bool disjoint(std::set<int> const& s1, std::set<int> const& s2){
	auto i = s1.begin();
    auto j = s2.begin();
    while (i != s1.end() && j != s2.end()) {
        if (*(i++) == *(j++))
            return false;
    }
    return true;
}

std::vector<std::set<int>> get_subsets(std::set<int> const& s){
	std::vector<std::set<int>> subset;
	std::set<int> empty;
	subset.push_back(empty);
    for (auto i : s) {
		auto tmp = subset;
        for (auto& j : tmp)
            j.insert(i);
        for (auto const& j : tmp)
			subset.push_back(j);
	}
	return subset;
}
