#include <iostream>
#include <stdio.h>
#include <vector>

#define KEYSIZE 3
#define MAXCHAR 94

int main(void){
	FILE* in = fopen("cipher.txt","r");
	int analyze[KEYSIZE][MAXCHAR + 1];
	int key[KEYSIZE];
	int i = 0,tmp;
	std::vector<int> message;

	while(!feof(in)){
		fscanf(in,"%d%*c",&tmp);
		analyze[i][tmp]++;
		if( analyze[i][tmp] > analyze[i][key[i]] ) key[i] = tmp;
		message.push_back(tmp);
		i = (i + 1) % KEYSIZE;
	}

	for(int i = 0; i < KEYSIZE; i++)
		key[i] = key[i] ^ ' ';

	int ans = 0;
	for(int i = 0; i < message.size(); i++)
		ans += message[i] ^ key[i%KEYSIZE];

	printf("%d\n",ans);
	return 0;
}
