#include <iostream>
#define MAX 1000

int cycle_length(int);

int main(){
	int max = 0;
	int d = 0;
	for(int i = MAX; i > 0; i--){
		if(max > i) break;
		int tmp = cycle_length(i);
		if(tmp > max){
			max = tmp;
			d = i;
		}
	}
	std::cout << d << std::endl;
	return 0;
}

int cycle_length(int denom){
	int remainders[denom];
	memset(remainders, 0, sizeof(remainders));
	int pos = 0;
	int cur = 1;
	while(cur != 0 && remainders[cur] == 0){
		remainders[cur] = pos;
		cur = (cur * 10) % denom;
		pos++;
	}
	return pos - remainders[cur];
}