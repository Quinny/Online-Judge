/*

The first line contains the number N of test cases, 1 ≤ N ≤ 100. 
Each of the following N lines contains a test: two characters. 
The first character is a lowercase English letter from 'a' to 'h' and the second character is an integer from 1 to 8; 
they specify the rank and file of the square at which the knight is standing.

Output N lines. Each line should contain the number of the squares of the chessboard that are under attack by the knight.



*/

#include <iostream>

using namespace std;
int main(void){
	int n,row,col,ans,rtmp,ctmp;
	string tmp;

	cin>>n;

	for(int i=0;i<n;i++){
		ans=0;
		cin>>tmp;
		col=(tmp[0]-'a')+1;
		row=tmp[1]-'0';

		int dx[]={-2,-2,2,2,1,-1,1,-1};
		int dy[]={1,-1,1,-1,-2,-2,2,2};

		for(int i=0;i<8;i++){
			rtmp=row+dx[i];
			ctmp=col+dy[i];

			if(rtmp>0 && rtmp<=8 && ctmp>0 && ctmp<=8)ans++;
		}
		cout<<ans<<endl;
	}
}