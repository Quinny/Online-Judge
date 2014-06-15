/*

The first line contains the number n of available wheel pairs (1 ≤ n ≤ 150). 
In the following n lines, diameters of wheels in millimeters are given (they are integers in the range from 600 to 700).

output the number of train cars that can be wheeled

*/


#include <iostream>

using namespace std;

int main(void){
	int n,ans=0;
	int wheels[101];

	memset(wheels,0,sizeof(wheels));

	cin>>n;

	for(int i=0,tmp;i<n;i++){
		cin>>tmp;
		wheels[tmp-600]++;
	}
	for(int i=0;i<101;i++)
		ans+=wheels[i]/4;

	cout<<ans<<endl;


	return 0;
}