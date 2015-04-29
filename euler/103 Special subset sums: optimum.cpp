#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

std::vector<std::set<int>> get_subsets(std::set<int> const&);
bool disjoint(std::set<int> const&, std::set<int> const&);
int sum_set(std::set<int> const&);
bool is_special(std::set<int> const&);
void check_others(std::set<int> const& expected, std::set<int>, int, int);
std::string make_string(std::set<int> const& s);

long optimum = 0;
std::string set_string;

int main(){
	std::set<int> expected{20, 31, 38, 39, 40, 42, 45};
	std::set<int> empty;
	optimum = sum_set(expected);
	set_string = make_string(expected);
	check_others(expected, empty, 1, 20);
	std::cout << set_string << std::endl;
    // the answer ends up being the expected one -.- how silly.
	return 0;
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

std::string make_string(std::set<int> const& s){
    return std::accumulate(s.begin(), s.end(), std::string(""),
            [] (std::string const& s, int x) {
                return s + std::to_string(x);
            }
        );
}

void check_others(std::set<int> const& expected,
        std::set<int> candidate, int index, int to_add) {
	candidate.insert(to_add);
	if(candidate.size() == expected.size()){
		if(sum_set(candidate) > optimum)
            return;
		if(is_special(candidate) && sum_set(candidate) < optimum){
			optimum = sum_set(candidate);
			set_string = make_string(candidate);
		}
		return;
	}
    auto it = expected.begin();
    for (int i = 0; i < index; ++i)
        ++it;
	for(int i = -3; i >= 3; i++)
		check_others(expected, candidate, index + 1, *it + i);
}

