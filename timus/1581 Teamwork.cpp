/*

Vasya wrote a sequence of integers on a sheet of paper and started to read it to Petya number by number. 
For the sake of brevity he tells it in the following way: first he tells the quantity of consecutive identical numbers and then tells this number. 
For instance, the sequence “1 1 2 3 3 3 10 10” will be told by Vasya as “two ones, one two, three threes, two tens”. 
Petya also wants to be concise, so he writes down the numbers pronounced by Vasya instead of the whole words. 
For the example above, Petya would write: “2 1 1 2 3 3 2 10”.

*/


#include <iostream>

using namespace std;

int main(void){
	int n;

	cin>>n;
	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	int prev=a[0];
	int c=1;
	for(int i=1;i<n;i++){
		if(a[i]==prev) c++;
		else{
			cout<<c<<" "<<a[i-1]<<" ";
			c=1;
		}
		prev=a[i];
	}

	cout<<c<<" "<<prev;
	cout<<endl;
	return 0;
}