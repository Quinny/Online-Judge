#include <iostream>
#define MAX 1000

int getCycleLength(int);

int main(void){
	int max = 0;
	int d = 0;
	for(int i = 1000; i > 0; i--){
		if(max > i) break;
		int tmp = getCycleLength(i);
		if(tmp > max){
			max = tmp;
			d = i;
		}
	}
	std::cout << d << std::endl;
	return 0;
}

int getCycleLength(int denom){
	int remainders[denom];
	for(int i = 0; i < denom; i++)
		remainders[i] = 0;

	int pos = 0;
	int cur = 1;
	while(cur != 0 && remainders[cur] == 0){
		remainders[cur] = pos;
		cur = (cur * 10) % denom;
		pos++;
	}
	return pos - remainders[cur];
}