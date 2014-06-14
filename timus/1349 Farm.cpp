/*

given n, display a,b, and c that satisfy a^n + b^n = c^n

http://en.wikipedia.org/wiki/Fermat's_Last_Theorem

states that no numbers exist for n>2

*/


#include <iostream>

using namespace std;

int main(void){
	int n;
	cin>>n;

	if(n==1) cout<<"1 2 3"<<endl;
	else if(n==2) cout<<"3 4 5"<<endl;
	else cout<<"-1"<<endl;
}