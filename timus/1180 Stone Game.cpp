/*

Two Nikifors play a funny game. 
There is a heap of N stones in front of them. 
Both Nikifors in turns take some stones from the heap. 
One may take any number of stones with the only condition that this number is a nonnegative integer power of 2 (e.g. 1, 2, 4, 8 etc.). 
Nikifor who takes the last stone wins. You are to write a program that determines winner assuming each Nikifor does its best.

*/

#include <iostream>
#include <string>

using namespace std;

int main(void){
	char n[251];
	int ans;
	cin>>n;

	for(int i=0;i<strlen(n);i++)
		ans=(ans*10+n[i]-'0')%3;


	if(ans==0) cout<<"2"<<endl;
	else cout<<"1"<<endl<<ans<<endl;

	return 0;
}