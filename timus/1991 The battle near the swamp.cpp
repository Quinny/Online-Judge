/*

And here they are: two armies lined up along the bank of the swamp. 
The droids of the Federation are well-disciplined soldiers. 
They stand in neat formation, divided into n blocks of k droids each. 
The gungans have a foolproof weapon against droids, which is small energy balls called boom booms. 
One such ball can disable exactly one droid.

Jar Jar Binks also decided to split his army into n parts and give each part a task to destroy the corresponding block of droids. 
Each part received a truck with boom booms. 
Now help general Binks calculate the number of boom booms that will be left unused and the number of droids that will survive the attack. 
You can assume that when a boom boom is fired at a droid by a gungan, it always hits the target.

*/


#include <iostream>

using namespace std;

int main(void){
	int n,k,tmp;
	cin>>n>>k;
	int u=0,s=0;

	for(int i=0;i<n;i++){
		cin>>tmp;
		if(tmp>k) u+=tmp-k;
		if(tmp<k)s+=k-tmp;
	}

	cout<<u<<" "<<s<<endl;


	return 0;
}