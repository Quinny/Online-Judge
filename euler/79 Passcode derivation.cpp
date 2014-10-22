#include <stdio.h>
#include <cstring>

bool sameAns(int[], int, bool[]);

int main(void){
	int first, after;
	bool befores[10][10];
	memset(befores,false,sizeof(bool)*10*10);
	while(scanf("%1d",&first)!=-1){
		for(int i = 0; i < 2; i++){
			scanf("%1d",&after);
			befores[after][first] = true;
		}
	}
	
	int ans[10];
	memset(ans,-1,sizeof(ans));
	ans[0] = 7;
	int sizeAns = 1;
	printf("%d",ans[0]);
	for(int j = 0; j < 10; j++){
		for(int i = 0; i < 10; i++){
			if(sameAns(ans,sizeAns,befores[i])){
				ans[sizeAns] = i;
				sizeAns++;
				printf("%d",i);
			}
		}
	}
	printf("0\n");
}

bool sameAns(int ans[], int size, bool row[]){
	int matches = 0;
	for(int i = 0; i < 10; i++){
		if(row[i]){
			bool found = false;
			for(int j = 0; j < size; j++){
				if(ans[j] == i){
					found = true;
					matches++;
					break;
				}
			}
			if(!found) return false;
		}
	}
	return true && matches == size;
}