/*

Nikita, a schoolboy, is currently taking part in one of programming contests. 
He is really upset because all the problem statements are so long and unclear. 
So he took the statement of the first problem and cut it into pieces in such a way that each piece contained exactly one letter. 
After that, he threw away all pieces with letter other than “a”, “b” or “c”. 
Now he has only n pieces and wants to compile from them his own statement that should be shorter and clearer than the original one.

The new statement should be a single word compiled from all n letters placed in some order. 
Nikita wondered if he can compile at least six different words of length n from the letters. 
If this is not true, he will be ruined and will start solving other problems. Help Nikita to answer this monumental question!

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int n,ans;
	cin>>n;
	int a[n];
	a[0]=0;a[1]=0;a[2]=0;
	for(int i=0,tmp;i<n;i++){
		cin>>tmp;
		a[tmp-1]++;
	}
	ans=(a[0]>0) + (a[1]>0) + (a[2]>0);
	if(ans==3) //if we have three different letters automatically yes
		cout<<"Yes"<<endl;
	else if(ans==1) //if there is only 1 letter then automatically no
		cout<<"No"<<endl;
	else{
		sort(a,a+3,greater<int>()); //otherwise we have to sort and check
		if( a[1]>=2 || a[0]>=5 ) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}