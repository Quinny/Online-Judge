#include <iostream>
#include <cmath>

bool pandig(long);
bool valid(long, int);

int main(){
	long n1 = 1;
	long n2 = 1;
	long cur = 0;
	long end = 1000000000;
	int t = 2;

	while(!valid(cur, t)){
		t++;
		cur = (n1 + n2) % end;
		n1 = n2;
		n2 = cur;
	}
	std::cout << t << std::endl;

	return 0;
}

bool valid(long cur, int t){
	if(!pandig(cur)) return false;
	double tmp = (t * 0.20898764024997873 - 0.3494850021680094);
	if(!pandig((long)pow(10, tmp - (long)tmp + 8))) return false;
	return true;
}

bool pandig(long n){
	int occur[10];
	memset(occur, 0, sizeof(occur));
	int c = 0;
	while(n > 0){
		if(n % 10 == 0) return false;
		if(occur[n % 10] == 0){
			occur[n % 10]++;
			c++;
		}
		else
			return false;
		n /= 10;
	}
	return c == 9;
}