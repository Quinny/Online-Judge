/*

A traffic light at the turn for the “MEGA” shopping center from the Novomoskovskiy highway works in such a way that k cars are able to take a turn in one minute. 
At weekends all the residents of the city drive to the mall to take a shopping, which results in a huge traffic jam at the turn. 
Administration of the mall ordered to install a camera at the nearby bridge, which is able to calculate the number of cars approaching this turn from the city. 
The observation started n minutes ago. You should use the data from the camera to determine the number of cars currently standing in the traffic jam.

*/

#include <iostream>

using namespace std;

int main(void){
	int k,n,a,total=0;

	cin>>k>>n;

	for(int i=0;i<n;i++){
		cin>>a;
		total+=a-k;
		if(total<0) total=0;
	}

	cout<<total<<endl;

	return 0;

}