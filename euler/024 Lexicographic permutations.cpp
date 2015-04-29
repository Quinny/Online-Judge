#include <iostream>

std::string rth_permute(std::string d, int r);

int main(){
	std::string d = "0123456789";
	std::cout << rth_permute(d, 999999) << std::endl;
	return 0;
}

std::string rth_permute(std::string d, int r){ // Page 71 of "a discipline of programming" by edsger w. dijkstra
	int s = 0, kfac = 1, k = 1, n = d.size();
	while(k != n){
		kfac *= k + 1;
		k++;
	}
	while(k != 1){
		kfac /= k;
		k--;
		int i = n - k - 1;
		int j = n - k;
		while(s + kfac <= r){
			s = s + kfac;
			std::swap(d[i], d[j]);
			j++;
		}
	}
	return d;
}
