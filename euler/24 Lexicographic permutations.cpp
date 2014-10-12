#include <iostream>
#include <vector>
#include <algorithm>

std::vector< std::string > perms;

void genPerms(std::string,std::string);

int main(void){
	std::string d="0123456789";
	genPerms(d,"");
	std:: cout<< perms[1000000 - 1] <<std::endl;
	return 0;
}

void genPerms(std::string d, std::string cur){
	if(d.length()==0 || perms.size() == 1000000){
		perms.push_back(cur);
		return;
	}
	for(int i=0;i<d.length();i++){
		std::string tmp = d.substr(0,i) + d.substr(i+1);
		genPerms(tmp, cur+d[i]);
	}
}