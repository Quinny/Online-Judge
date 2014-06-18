/*

A 1D person chooses a direction: backward (decreasing his coordinate) or forward (increasing it), and then moves in this direction. 
If he finds an exit, he escapes the maze immediately; if he encounters an obstacle, he reverses his direction and continues walking.
In order to feel the hard life of 1D residents, try to implement a function that will compute a distance a 1D person will walk before finding an exit, based on the initial direction.

*/


#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	int n,x,opos=1001,oneg=-1001;
	cin>>n>>x;

	for(int i=0,tmp;i<n;i++){
		cin>>tmp;
		if(tmp>0 && tmp<opos) opos=tmp;
		if(tmp<0 && tmp>oneg) oneg=tmp;
	}
	if((x>0 && opos<x) || (x<0 && oneg>x)){
		cout<<"Impossible"<<endl;
		return 0;
	}

	if(x>0) cout<<x<<" "<<(abs(2*oneg)+x)<<endl;
	else cout<<((2*opos)+abs(x))<<" "<<(abs(x))<<endl;

	return 0;
}