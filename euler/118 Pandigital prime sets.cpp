#include <iostream>

void next_perm(int[]);
bool is_prime(long n);
int num_valids(const int a[], int cur, int index);

int main(){
	int set[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int ans = 0;
	for(int i = 1; i < 362880; i++){
		ans += num_valids(set, 0, -1);
		next_perm(set);
	}
	std::cout << ans << std::endl;
	return 0;
}

int num_valids(const int a[], int cur, int index){
	if(index == 8)
		return is_prime(cur);
	int n = 0;
	int ans = 0;
	for(int i = index + 1; i < 9; i++){
		n = (10 * n) + a[i];
		if(is_prime(n) && n > cur)
			ans += num_valids(a, n, i);
	}
	return ans;
}

bool is_prime(long n){
	if(n <= 3) return n > 1;
	if(n % 2 == 0 || n % 3 == 0) return false;
	for(int i = 5; i * i <= n; i += 6){
		if(n % i == 0 || n % ( i + 2) == 0) return false;
	}
	return true;
}

void next_perm(int set[]){
	int i = 8;
	while (set[i - 1] >= set[i])
		i--;
	int j = 9;
	while (set[j - 1] <= set[i - 1])
		j--;
	std::swap(set[i - 1], set[j - 1]);
	i++;
	j = 9;
	while (i < j) {
		std::swap(set[i - 1], set[j - 1]);
		i++;
		j--;
	}
}