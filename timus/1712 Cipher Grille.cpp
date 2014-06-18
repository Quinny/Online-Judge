#include <iostream>

using namespace std;

void rotate90(int[4][4]); //rotate the array 90 degrees
void transpose(int[4][4]); //rotating 90 is the same as transposing and then reversing the rows
void revrow(int [4][4]);

int main(void){
	int g[4][4];
	char p[4][4];
	char tmp;

	for(int i=0;i<4;i++){
		for(int x=0;x<4;x++){
			cin>>tmp;
			g[i][x]= tmp=='X';
		}
	}

	for(int i=0;i<4;i++){
		for(int x=0;x<4;x++){
			cin>>tmp;
			p[i][x]=tmp;
		}
	}

	for(int i=0;i<4;i++){
		for(int x=0;x<4;x++){
			for(int j=0;j<4;j++){
				if(g[x][j]) cout<<p[x][j];
			}
		}
		rotate90(g);
	}
	
	cout<<endl;
	return 0;
}

void rotate90(int a[4][4]){
	transpose(a);
	revrow(a);
}

void transpose(int a[4][4]){
	for(int i=0;i<4;i++){
		for(int x=i;x<4;x++){
			swap(a[i][x],a[x][i]);
		}
	}
}

void revrow(int a[4][4]){
	for(int i=0;i<4;i++){
		swap(a[i][0],a[i][3]);
		swap(a[i][1],a[i][2]);
	}
}