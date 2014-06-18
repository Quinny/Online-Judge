/*

When the dill was ripe, Ivan Vasil'evich harvested it and put it into boxes. 
He filled n boxes with dill of the first variety and m boxes with dill of the second variety. 
The weight of each box with dill in kilograms was an integer and all the weights were different. 
In order to please his neighbors Ivan Ivanovich and Ivan Nikiforovich, Ivan Vasil'evich decided to give each of them two boxes with dill, one box of each variety. 
Ivan Vasil'evich didn't want Ivan Ivanovich and Ivan Nikiforovich to quarrel, so he decided that the total weight of the boxes given to each of the neighbors should be equal. 
Ivan Vasil'evich considered all the possible variants and saw that this was impossible. 
Find the weights of all the boxes with dill stocked by Ivan Vasil'evich.

*/

#include <iostream>

using namespace std;

int main(void){
	int n,m;
	cin>>n>>m;

	for(int i=1;i<=n;i++)
		cout<<i<<" ";
	cout<<endl;

	for(int i=n+1;i<m+n+1;i++)
		cout<<(i*100)<<" ";
	cout<<endl;

	return 0;
}