#include <iostream>

#define SIZE 20

using namespace std;

int main(void){
	long grid[SIZE+1][SIZE+1];

	for(int i=0;i<SIZE;i++){
		grid[i][SIZE]=1; //all of the right edge and bottom edge points only have 1 possible path
		grid[SIZE][i]=1;
	}

	for(int i=SIZE-1;i>=0;i--){
		for(int j=SIZE-1;j>=0;j--)
			grid[i][j]=grid[i+1][j] + grid[i][j+1]; //add the possible paths of the adjacent squares
	}

	cout<<grid[0][0]<<endl; //number of possible paths from the origin will be the total

	return 0;
}
