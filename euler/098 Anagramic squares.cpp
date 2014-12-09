#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

int largest_square(std::string, std::string, std::set<int> const&);

int main(){
	std::set<int> squares;
	for(int i = 0; i < 40000; i++) // longest anagram is 8 chars
		squares.insert(i * i);
	std::unordered_map<std::string, std::vector<std::string>> anagrams;
	std::string s, tmp;
	while(std::cin >> s){
		tmp = s;
		std::sort(tmp.begin(), tmp.end());
		anagrams[tmp].push_back(s); // find the anagrams
	}
	int largest = 0;
	for(auto x : anagrams){
		if(x.second.size() > 1)
 			largest = std::max(largest, largest_square(x.second[0], x.second[1], squares));
	}
	std::cout << largest << std::endl;
	return 0;
}

int largest_square(std::string x, std::string y, std::set<int> const& squares){
	int largest = 0;
	for(auto n : squares){
		std::string tmp = std::to_string(n);
		if(x.size() != tmp.size()) continue; // check if lenghes differ
		std::map<char, int> dig;
		for(int i = x.size() - 1; i >= 0; i--){
			dig[x[i]] = n % 10; // map characters to integers
			n /= 10;
		}
		std::set<int> s; // check if 2 characters are mapped to the same int
		bool match = true;
		for(auto i : dig){
			if(s.find(i.second) != s.end())
				match = false;
			s.insert(i.second);
		}
		if(!match) continue; // if we found a repeat
		if(dig[y[0]] == 0) continue; // leading 0's are not permitted dude
		int check = 0;
		for(int i = 0; i < y.size(); i++)
			check = (10 * check) + (dig[y[i]]);
		if(squares.find(check) != squares.end() && check > largest) largest = check;
	}
	return largest;
}