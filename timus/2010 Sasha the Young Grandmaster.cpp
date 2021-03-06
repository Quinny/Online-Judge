#include <iostream>
#include <algorithm>

using namespace std;

int king(int,int,int);
int knight(int,int,int);
int bishop(int,int,int);
int rook(int,int,int);
int queen(int,int,int);

int main(void){
	int n,row,col;
	cin>>n>>row>>col;
	cout<<"King: "<<king(n,row,col)<<endl;
	cout<<"Knight: "<<knight(n,row,col)<<endl;
	cout<<"Bishop: "<<bishop(n,row,col)<<endl;
	cout<<"Rook: "<<rook(n,row,col)<<endl;
	cout<<"Queen: "<<queen(n,row,col)<<endl;

	return 0;
}

int king(int n,int x,int y){
	int ans=0;
	int dx[]={1,-1,0,0,1,-1,1,-1};
	int dy[]={0,0,1,-1,1,1,-1,-1};
	for(int i=0;i<8;i++){
		if((x+dx[i]>0 && x+dx[i]<=n) && (y+dy[i]>0 && y+dy[i]<=n)) ans++;
	}
	return ans;
}

int knight(int n,int x,int y){
	int ans=0;
	int dx[]={-2,-2,2,2,1,-1,1,-1};
	int dy[]={1,-1,1,-1,-2,-2,2,2};

	for(int i=0;i<8;i++){

		if(x+dx[i]>0 && x+dx[i]<=n && y+dy[i]>0 && y+dy[i]<=n)ans++;
	}
	return ans;
}

int bishop(int n,int x,int y){

	int ans=0;

	ans+=min(n-y,x-1); //up and right
	ans+=min(y-1,x-1); //up and left
	ans+=min(n-y,n-x); //down and right
	ans+=min(n-x,y-1); //down and left
	return ans;
}

int rook(int n, int x,int y){
	return 2*(n-1);
}

int queen(int n,int x,int y){
	return bishop(n,x,y)+rook(n,x,y);
}