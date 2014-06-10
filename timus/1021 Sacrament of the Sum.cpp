/*

Sacrament of the Sum

Your program should decide, if it is possible to choose from two lists of integers such two numbers that their sum would
be equal to 10 000.


*/


#include <iostream>

using namespace std;

int main(void){
	int x,y,t;
	cin>>x; //get the length of the first list
	int a[x];
	for(int i=0;i<x;i++)
		cin>>a[i]; //read in each value

	cin>>y; //get the length of the second list
	for(int i=0;i<y;i++){
		cin>>t;
		for(int c=0;c<x;c++){
			if(t+a[c]==10000){ //check if any of the values in the second list add to be 10 000
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl; //if not then print no
	return 0;
}
