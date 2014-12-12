#include <iostream>
#include <vector>
#include <algorithm>

int perms = 0;
void gen_perms(std::string, std::string);

int main(){
	std::string d="0123456789";
	gen_perms(d,"");
	return 0;
}

void gen_perms(std::string d, std::string cur){
	if(d.length() == 0){
		perms++;
		if(perms == 1000000)
			std::cout << cur << std::endl;
		return;
	}
	for(int i = 0; i < d.length(); i++){
		std::string tmp = d.substr(0, i) + d.substr(i + 1);
		gen_perms(tmp, cur + d[i]);
	}
}