#include <iostream>

// shout out to http://en.wikipedia.org/wiki/Farey_sequence

int farey_between(int, int, int, int, int);

// 4000 / 11999 is the closest fraction in the range 

int main(){
	std::cout << farey_between(1, 3, 4000, 11999, 12000) << std::endl;
	return 0;
}

int farey_between(int a, int b, int c, int d, int n){
	int ans = 0;
	while(c != 1 && d != 2){
		int k = (n + b) / d;
		int tmpc = k * c - a;
		int tmpd = k * d - b;
		a = c;
		b = d;
		c = tmpc;
		d = tmpd;
		ans++;
	}
	return ans;
}