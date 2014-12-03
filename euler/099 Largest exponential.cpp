#include <stdio.h>
#include <cmath>

int main(void){
	int max =  0, maxLine = 1;
	int base, expon;
	int line = 1;
	while(scanf("%d,%d",&base,&expon) != -1){
		if(expon * log(base) > max){
			max = expon * log(base);
			maxLine = line;
		}
		line++;
	}
	printf("%d\n",maxLine);
	return 0;
}