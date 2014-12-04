#include <iostream>
#include <vector>

std::pair<int, int> find_max(std::vector<std::string>&);

int main(){
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> v;
	while(n--){
		std::string s;
		std::cin >> s;
		v.push_back(s);
	}
	auto ans = find_max(v);
	std::cout << ans.first << std::endl << ans.second << std::endl;
	return 0;
}

std::pair<int, int> find_max(std::vector<std::string>& v){
	int max = 0;
	int c = 0;
	for(int i = 0; i < v.size(); i++){
		for(int j = i + 1; j < v.size(); j++){
			int known = 0;
			for(int k = 0; k < v[i].size(); k++){
				if(v[i][k] == '1' || v[j][k] == '1') known++;
			}
			if(known == max) c++;
			if(known > max){
				c = 1;
				max = known;
			}
		}
	}
	return std::make_pair(max, c);
}