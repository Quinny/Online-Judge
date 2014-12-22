#include <iostream>

bool is_valid(int[]);
bool check_inners(int[], int);
int min_outer(int[]);
bool valid_sums(int[]);
void next_perm(int[]);
std::string make_string(int[]);

int main(){
	int ring[10];
	std::string max = "";
	for(int i = 0; i < 10; i++)
		ring[i] = i + 1;
	for(int i = 1; i < 3628800; i++){ // 10! = 3628800
		if(is_valid(ring)){
			std::string s = make_string(ring);
			max = std::max(max, s);
		}
		next_perm(ring);
	}
	std::cout << max << std::endl;
	return 0;
}

void next_perm(int ring[]){
	int i = 9;
	while (ring[i - 1] >= ring[i])
		i--;
	int j = 10;
	while (ring[j - 1] <= ring[i - 1])
		j--;
	std::swap(ring[i - 1], ring[j - 1]);
	i++;
	j = 10;
	while (i < j) {
		std::swap(ring[i - 1], ring[j - 1]);
		i++;
		j--;
	}
}

std::string make_string(int ring[]){
	std::string s = "";
	s += std::to_string(ring[0]) + std::to_string(ring[1]) + std::to_string(ring[2]);
	for(int i = 3; i < 10; i += 2){
		s += std::to_string(ring[i]) + std::to_string(ring[i - 1]);
		i + 1 == 10 ? s += std::to_string(ring[1]) : s += std::to_string(ring[i + 1]);
	}
	return s;
}

bool valid_sums(int ring[]){
	int s = ring[8] + ring[9] + ring[1];
	if(ring[0] + ring[1] + ring[2] != s) return false;
	for(int i = 2; i < 7; i += 2){
		if(ring[i] + ring[i + 1] + ring[i + 2] != s) return false;
	}
	return true;
}

int min_outer(int ring[]){
	int min = ring[0];
	for(int i = 3; i < 10; i += 2)
		min = std::min(min, ring[i]);
	return min;
}

bool in_inner(int ring[], int n){
	if(ring[1] == n) return true;
	for(int i = 2; i < 10; i += 2){
		if(ring[i] == n) return true;
	}
	return false;
}

bool is_valid(int ring[]){
	if(in_inner(ring, 10)) return false; // 10 must be on the outer nodes
	if(min_outer(ring) != ring[0]) return false; // I want the first node to be the minimum (reduces search space a bit)
	if(!valid_sums(ring)) return false; // check if all lines add to the same thing
	return true;
}