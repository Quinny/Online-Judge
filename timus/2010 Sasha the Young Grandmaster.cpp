#include <iostream>

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
	int ans=0,tx=x,ty=y;
	int dx[]={1,-1,1,-1};
	int dy[]={1,1,-1,-1};

	for(int i=0;i<4;i++){
		tx=x+dx[i];
		ty=y+dy[i];
		while((tx>0 && tx<=n) && (ty>0 && ty<=n)){
			tx+=dx[i];
			ty+=dy[i];
			ans++;
		}
	}
	return ans;
}

int rook(int n, int x,int y){
	int ans=0,tx,ty;
	int dx[]={1,-1,0,0};
	int dy[]={0,0,1,-1};
	for(int i=0;i<4;i++){
		tx=x+dx[i];
		ty=y+dy[i];
		while((tx>0 && tx<=n) && (ty>0 && ty<=n)){
			tx+=dx[i];
			ty+=dy[i];
			ans++;
		}
	}
}

int queen(int n,int x,int y){
	return bishop(n,x,y)+rook(n,x,y);
}