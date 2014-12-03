#include <iostream>
#include <algorithm>

int main(){
	int n;
	std::cin >> n;
	int a[n];
	int k;
	std::cin >> k;
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	std::sort(a, a + n);
	int min = a[n - 1];
	for(int i = 0; i < n - k; i++)
		min = min < a[i + k - 1] - a[i] ? min : a[i + k - 1] - a[i];
	std::cout << min << std::endl;
}