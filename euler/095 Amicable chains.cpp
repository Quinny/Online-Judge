#include <iostream>
#include <set>
#include <unordered_map>

//int sum_divisors(int);
std::pair<int, int> smallest_elem(int);

struct sum_divisors {
    mutable std::unordered_map<int, int> m_;
    int operator () (int n) const {
        if (m_[n])
            return m_[n];
        int ans = 1;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                ans += i;
                if(i * i != n)
                    ans += n / i;
            }
        }
        return m_[n] = ans;
    }
};

sum_divisors sum_div;

int main(){
	int max_size = 0;
	int min_elem = 1000000;
	for(int i = 1; i < 1000000; i++){
		auto x = smallest_elem(i);
		if(x.first > max_size){
			max_size = x.first;
			min_elem = x.second;
		}
	}
	std::cout << min_elem << std::endl;
	return 0;
}

// chain size, smallest element
std::pair<int, int> smallest_elem(int start) {
	std::set<int> chain;
	chain.insert(start);
	int m = sum_div(start);
	while(chain.insert(m).second) {
		if(m > 1000000)
            return std::make_pair(-1, -1);
		m = sum_div(m);
	}
	if(m == start)
		return std::make_pair(chain.size(), *(chain.begin()));
	return std::make_pair(-1, -1);
}
