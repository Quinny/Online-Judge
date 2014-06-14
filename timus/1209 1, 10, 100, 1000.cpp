/*

Let's consider an infinite sequence of digits constructed of ascending powers of 10 written one after another. 
Here is the beginning of the sequence: 110100100010000… You are to find out what digit is located at the definite position of the sequence.
*/


#include <iostream>
#include <cmath>

bool isPerfectSquare(long long); //check if a number is a perfect square

using namespace std;

int main(void){
	long long n;
	cin>>n;
	long long a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];



	/*
	I found out that the sequence of indexes where 1 appeared was (n^2 -n +2)/2

	I knew that for a 1 to appear, a[i] = (n^2 - n + 2)/2

	I then used the quadratic equation and came up with n = ( 1+sqrt(8*a[i]-7) )/2

	I observed that this equation held true if and only if 8*a[i]-7 was a perfect square
	*/
	for(int i=0;i<n;i++){
		if(isPerfectSquare(8*a[i]-7)) cout<<"1"<<" ";
		else cout<<"0"<<" ";
	}
	cout<<endl;

}


bool isPerfectSquare(long long x){
	long long tmp=(long long)sqrt(x+0.5);
	return tmp*tmp==x;
}