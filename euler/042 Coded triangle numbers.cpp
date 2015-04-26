#include <stdio.h>
#include <set>
#include <iostream>

// the longest word in the file is 14 characters, 14*26 = 364
#define LIMIT 365

int wordVal(char* s);

int main(void){
	int sum = 0;
	//std::set<int> triangles;
    bool triangles[66430] = {false};
	for(int i = 1; i < LIMIT; i++){
		triangles[sum] = true;
        sum += i;
	}

	FILE* nFile = fopen("p042_words.txt","r");
	char tmp[20];
	int ans = 0;
	while (!feof(nFile)) {
		fscanf(nFile,"%*c%[^\"]s%*c%*c", tmp);
		if (tmp[0] != ',' && triangles[wordVal(tmp)])
			ans++;
	}
	printf("%d\n", ans - 1);

	return 0;
}

int wordVal(char* s){
	int val = 0;
	while(*s)
		val+=( (*(s++))-'A' )+1;
	return val;
}
