#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>

int getWordScore(std::string);

int main(void){
	FILE* nFile=fopen("names.txt","r");
	char tmp[200];
	std::vector< std::string > names;

	while(!feof(nFile)){
		fscanf(nFile,"%*c%[^\"]s%*c%*c",tmp);
		if(tmp[0]!=',')
			names.push_back(tmp);
	}
	names.erase(names.begin()+names.size()-1);
	sort(names.begin(),names.end());

	unsigned long long total=0;
	for(int i=0;i<names.size();i++)
		total+= (i+1) * getWordScore(names[i]);


	printf("%llu\n",total);
	return 0;
}

int getWordScore(std::string s){
	int score=0;
	for(char c:s)
		score+= (c-'A')+1;
	return score;
}