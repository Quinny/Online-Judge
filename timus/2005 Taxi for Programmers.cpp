/*

The clock shows 11:30 PM. 
The sports programmers of the institute of maths and computer science have just finished their training. 
The exhausted students gloomily leave their computers. 
But there’s something that cheers them up: Misha, the kind coach is ready to give all of them a lift home in his brand new car. 
Fortunately, there are no traffic jams on the road. Unfortunately, all students live in different districts. 
As Misha is a programmer, he highlighted and indexed five key points on the map of Yekaterinburg: the practice room (1), Kirill’s home (2), Ilya’s home (3), Pasha’s and Oleg’s home (4; they live close to each other) and his own home (5). 
Now he has to find the optimal path. The path should start at point 1, end at point 5 and have minimum length. 
Moreover, Ilya doesn’t want to be the last student to get home, so point 3 can’t be fourth in the path.

*/

#include <iostream>
#include <algorithm>

using namespace std;

int getDist(int[5][5],int[5]);

int main(void){
	int perms[][5]={{1,2,3,4,5},
			   {1,4,3,2,5},
			   {1,3,2,4,5},
			   {1,3,4,2,5}};

	int d[5][5];
	for(int i=0;i<5;i++){
		for(int x=0;x<5;x++){
			cin>>d[i][x];
		}
	}

	int ans=getDist(d,perms[0]);
	int index=0;

	for(int i=1,tmp;i<4;i++){
		tmp=getDist(d,perms[i]);
		if(tmp<ans){
			ans=tmp;
			index=i;
		}
	}

	cout<<ans<<endl;
	for(int i=0;i<5;i++) cout<<perms[index][i]<<" ";
	cout<<endl;

	return 0;
}


int getDist(int d[5][5],int perm[5]){
	int ans=0;
	for(int i=0;i<4;i++){
		ans+=d[perm[i]-1][perm[i+1]-1];
	}
	return ans;
}