/*

Two Nikifors play a funny game. 
There is a heap of N stones in front of them. 
Both Nikifors in turns take some stones from the heap. 
One may take any number of stones with the only condition that this number is a nonnegative integer power of 2 (e.g. 1, 2, 4, 8 etc.). 
Nikifor who takes the last stone wins. You are to write a program that determines winner assuming each Nikifor does its best.

*/

#include <iostream>

using namespace std;

int main(void){
	char tmp;
	int ans=0;
		
	while(cin>>tmp)
		ans+=tmp-'0';

	if(ans%3==0) cout<<"2"<<endl; //if the sum of the digits is divisible by 3 then the number must be divisble by 3
	else cout<<"1"<<endl<<(ans%3)<<endl;

	return 0;
}