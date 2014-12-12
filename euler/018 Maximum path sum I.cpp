#include <iostream>
#include <vector>
#define HEIGHT 15

int main(void){
	int tree[HEIGHT][HEIGHT];
	memset(tree, 0, sizeof(int) * HEIGHT * HEIGHT);
	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < i + 1; j++)
			std::cin >> tree[i][j];
	}
	for(int i = HEIGHT - 2; i >= 0; i--){
		for(int j = 0; j < i + 1; j++){
			int lc = tree[i + 1][j];
			int rc = tree[i + 1][j + 1];
			tree[i][j] += std::max(lc, rc);
		}
	}
	std::cout << tree[0][0] << std::endl;
}