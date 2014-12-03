#include <iostream>

#define N 20
#define M 20

using namespace std;

int prodInDir(int, int, int, int,int[][M]);
bool onGrid(int,int);
int max(int,int);

int main(void){
	int grid[N][M];
	int ans=0;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++)
			cin>>(grid[i][j]);
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			ans=max(ans,prodInDir(i,j,0,1,grid)); //horizontal
			ans=max(ans,prodInDir(i,j,-1,0,grid)); //vertical
			ans=max(ans,prodInDir(i,j,1,1,grid)); //diagonal 1
			ans=max(ans,prodInDir(i,j,-1,-1,grid)); //diagonal 2
			ans=max(ans,prodInDir(i,j,1,-1,grid)); //diagonal 3
			ans=max(ans,prodInDir(i,j,-1,1,grid)); //diagonal 4
		}
	}

	cout<<ans<<endl;

	return 0;
}

int max(int x,int y){
	return x > y? x : y;
}

bool onGrid(int x,int y){
	return x >= 0 && x < N && y >=0 && y < M;
}

int prodInDir(int x, int y, int dx, int dy,int grid[20][20]){
	int ans=1;
	for(int i=0;i<4;i++){
		if(!onGrid(x,y)) return 0;
		ans*=grid[x][y];
		x+=dx; y+=dy;
	}
	return ans;
}

