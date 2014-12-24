#include <iostream>

int lcs(std::string, int, std::string, int);

int main(){
	std::string s1, s2;
	std::cin >> s1 >> s2;
	std::cout << lcs(s1, s1.size(), s2, s2.size()) << std::endl;
	return 0;
}

int lcs(std::string s1, int m, std::string s2, int n){
	int table[m + 1][n + 1];
	for(int i = m; i >= 0; i--){
		for(int j = n; j >= 0; j--){
			if(i == s1.size() || j == s2.size()) table[i][j] = 0;
			else if(s1[i] == s2[j]) table[i][j] = 1 + table[i + 1][j + 1];
			else table[i][j] = std::max(table[i + 1][j], table[i][j + 1]);
		}
	}
	return table[0][0];
}