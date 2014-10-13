#include <stdio.h>
#include <map>

#define LIMIT 365 //the longest word in the file is 14 characters, 14*26 = 364

int wordVal(char* s);

int main(void){
	int sum = 0;
	std::map<int,bool> triangles;
	for(int i = 1; i < LIMIT; i++){
		triangles[sum] = true;
		sum+=i;
	}

	FILE* nFile = fopen("22names.txt","r");
	char tmp[20];
	int ans = 0;
	while(!feof(nFile)){
		fscanf(nFile,"%*c%[^\"]s%*c%*c",tmp);
		if(tmp[0]!=',' && triangles.find(wordVal(tmp)) != triangles.end())
			ans++;
	}
	printf("%d\n",ans);

	return 0;
}

int wordVal(char* s){
	int val = 0;
	while(*s)
		val+=( (*(s++))-'A' )+1;
	return val;
}
