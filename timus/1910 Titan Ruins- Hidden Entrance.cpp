/*

The first line contains the number n of sections in the wall (3 ≤ n ≤ 1000). 
In the second line you are given n positive integers ai, which are the forces of the magic field acting on each section (1 ≤ ai ≤ 106).

Output two integers separated with a space. 
They should be the maximum total force of the field acting on three consecutive sections of the wall and the number of the middle section in this segment. 
It is guaranteed that there is only one answer.


*/

#include <iostream>

using namespace std;

int main(void){
	int n;
	cin>>n;
	int w[n];

	for(int i=0;i<n;i++)
		cin>>w[i];

	int sum=w[0]+w[1]+w[2];
	int mid=2;

	for(int i=1;i+3<n+1;i++){
		if(w[i]+w[i+1]+w[i+2]>sum){
			sum=w[i]+w[i+1]+w[i+2];
			mid=i+2;
		}
	}

	cout<<sum<<" "<<mid<<endl;

	return 0;
}