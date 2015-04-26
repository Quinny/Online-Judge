#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

int largest_square(std::string const&, std::string const&, std::set<int> const&);
bool repeat_mapping(std::map<char, int> const&);

int main(){
    std::set<int> squares;
    // longest anagram is 8 chars
    for(int i = 0; i < 40000; i++)
        squares.insert(i * i);
    std::unordered_map<std::string, std::vector<std::string>> anagrams;
    std::string s, tmp;
    while(std::cin >> s){
        tmp = s;
        std::sort(tmp.begin(), tmp.end());
        // find the anagrams
        anagrams[tmp].push_back(s);
    }
    int largest = 0;
    for (auto x : anagrams) {
        if(x.second.size() > 1)
            largest = std::max(largest,
                      largest_square(x.second[0], x.second[1], squares));
    }
    std::cout << largest << std::endl;
    return 0;
}

bool repeat_mapping(std::map<char, int> const& m) {
    bool o[10] = {false};
    for(auto i : m) {
        if (o[i.second])
            return true;
        o[i.second] = true;
    }
    return false;
}

int largest_square
(std::string const& x, std::string const& y, std::set<int> const& squares) {
    int largest = 0;
    for(auto n : squares) {
        std::string tmp = std::to_string(n);
        // check if lengthes differ
        if (x.size() != tmp.size())
            continue;
        std::map<char, int> dig;
        for(int i = x.size() - 1; i >= 0; i--){
            dig[x[i]] = n % 10; // map characters to integers
            n /= 10;
        }
        if (repeat_mapping(dig))
            continue;
        // no leading zeros allowed dude
        if (dig[y[0]] == 0)
            continue;
        int check = 0;
        for(int i = 0; i < y.size(); ++i)
            check = (10 * check) + (dig[y[i]]);
        if(check > largest && squares.find(check) != squares.end())
            largest = check;
    }
    return largest;
}
