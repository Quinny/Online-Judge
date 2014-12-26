#include <iostream>
#include <iomanip>

// shout out to this page http://gwydir.demon.co.uk/jo/probability/calcdice.htm

double prob_to_roll(int, int, int);
int ways_to_roll(int, int, int);

int main(){
	double r = 0;
	for(int peter = 9; peter <= 36; peter++){ // lowest peter can throw is 9, highest is 36
		for(int colin = 6; colin < peter; colin++) // colin can throw lowest 6, and we only care if peter beats him
			r += prob_to_roll(9, 4, peter) * prob_to_roll(6, 6, colin);
	}
	std::cout << std::setprecision(7) << r << std::endl;
	return 0;
}

int ways_to_roll(int n, int s, int v){ // number of different ways we can throw n dice with s sides and get v
	if(n == 0 && v == 0) return 1;
	if(n == 0 && v != 0) return 0;
	int ans = 0;
	for(int i = 1; i <= s; i++)
		ans += ways_to_roll(n - 1, s, v - i);
	return ans;
}

double prob_to_roll(int n, int s, int v){ // probabilty to roll v with n dice of s sides
	double denom = 1;
	for(int i = 0; i < n; i++)
		denom *= s;
	return ways_to_roll(n, s, v) / denom;
}