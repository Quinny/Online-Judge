#include <iostream>
#include <vector>

#define HEIGHT 15

using namespace std;

int max(int, int);

int main(void){
	int tree[HEIGHT][HEIGHT];
	memset(tree,0,sizeof(int) * HEIGHT * HEIGHT);
	for(int i=0;i<HEIGHT;i++){
		for(int j=0;j < i+1; j++)
			cin>>tree[i][j];
	}

	for(int i=HEIGHT-2; i>= 0;i--){
		for(int j=0;j<i+1;j++){
			int leftChild = tree[i+1][j];
			int rightChild = tree[i+1][j+1];
			tree[i][j] += max(leftChild, rightChild);
		}
	}

	cout << tree[0][0] << endl;
}

int max(int x, int y){
	return x > y ? x : y;
}