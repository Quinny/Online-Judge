/*

Our chemical biologists have invented a new very useful form of life called stripies (in fact, they were first called in Russian - polosatiki, but the scientists had to invent an English name to apply for an international patent). 
The stripies are transparent amorphous amebiform creatures that live in flat colonies in a jelly-like nutrient medium. 
Most of the time the stripies are moving. 
When two of them collide a new stripie appears instead of them. 
Long observations made by our scientists enabled them to establish that the weight of the new stripie isn't equal to the sum of weights of two disappeared stripies that collided; nevertheless, they soon learned that when two stripies of weights m1 and m2 collide the weight of resulting stripie equals to 2·sqrt(m1m2). 

Our chemical biologists are very anxious to know to what limits can decrease the total weight of a given colony of stripies.

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(void){
	int n;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	if(n==1){
		cout<<a[0]<<endl;
		return 0;
	}

	sort(a,a+n,greater<int>()); //sort in decsending so that the square root brings down the values of the largest fish

	double sum=2*sqrt(a[0]*a[1]);

	for(int i=2;i<n;i++)
		sum=2*sqrt(sum*a[i]);

	cout<<fixed<<setprecision(2)<<sum<<endl;
	return 0;
}