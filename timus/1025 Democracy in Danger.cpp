/*

You are to write a program, 
which would determine according to the given partition of the electors the minimal number of supporters of the party, 
sufficient for putting into effect of any decision, with some distribution of those supporters among the groups.


*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int k,ans=0;
	cin>>k; //read in the number of groups
	int a[k]; //initialize an array

	for(int i=0;i<k;i++)
		cin>>a[i]; //read in each value

	sort(a,a+k); //sort the values from smallest the largest

	for(int i=0;i<(k/2)+1;i++) ans+= (a[i]/2)+1; //loop through the majority of the list and have the majority of the citizens vote

	cout<<ans<<endl;

	return 0;
}