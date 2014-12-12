#include <iostream>

#define N 20
#define M 20

int prod_dir(int, int, int, int, int[][M]);
bool on_grid(int, int);

int main(){
	int grid[N][M];
	int ans = 0;
	int dirs[][2] = {{0, 1}, {1, 0}, {1, -1}, {1, 1}};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++)
			std::cin >> grid[i][j];
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			for(int k = 0; k < 4; k++)
				ans = std::max(ans, prod_dir(i, j, dirs[k][0], dirs[k][1], grid));
		}
	}
	std::cout << ans << std::endl;
	return 0;
}

bool on_grid(int x,int y){
	return x >= 0 && x < N && y >=0 && y < M;
}

int prod_dir(int x, int y, int dx, int dy,int grid[20][20]){
	int ans = 1;
	for(int i = 0; i < 4; i++){
		if(!on_grid(x, y)) return 0;
		ans *= grid[x][y];
		x += dx; y += dy;
	}
	return ans;
}