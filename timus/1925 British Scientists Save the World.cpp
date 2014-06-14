/*
The aliens invented a smart protection: every year, in order to avoid an explosion, you had to enter a number, which is less than the number shown on the screen by two. 
Fortunately, aliens decided that it takes a lot of computing resources to check whether the input number is correct every year. 
That is why the test is carried out once in n + 1 years. Moreover, they check only that the sum of all numbers entered since the last test matches the expected one.


The good news is that all symbols, which the bomb showed, and all numbers, which were entered, were recorded and the scientists already finished decrypting. 
Recently a number k appeared on mysterious device's screen and the scientists are sure that this time can be a fatal one. 
So, you have a chance to save the world by finding out what number should be entered in order to avoid an explosion.

*/


#include <iostream>

using namespace std;

int main(void){
	int n,s1,s2=0,tmp;

	cin>>n>>s1;

	for(int i=0;i<n;i++){
		cin>>tmp;
		s1+=tmp;
		cin>>tmp;
		s2+=tmp;
	}
	int x= s1-(2*(n+1))-s2;

	x>=0 ? cout<<x<<endl : cout<<"Big Bang!"<<endl;

	return 0;
}