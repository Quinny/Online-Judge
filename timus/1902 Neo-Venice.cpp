/*

The undine Anna has just received a license to steer a gondola. 
Tomorrow she will carry tourists on excursion to the St. Peter's canal. 
This canal is narrow, but many popular routes are passing through it, so there are always a lot of gondolas. 
Anna is afraid that her excitement may lead to a crash with another gondola during the excursion. 
However, all undines are trained to steer the gondola smoothly and with the same speed, so the only threat comes from gondolas sailing in the opposite direction. 
Anna knows the schedule of her colleagues and when she herself will enter the canal. 
Now she wants to know exactly when she will encounter other gondolas, in order to be extra careful around them.

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
	double n,t,s;
	cin>>n>>t>>s;
	for(int i=0,tmp;i<n;i++){
		cin>>tmp;
		cout<<fixed<<setprecision(6)<<((s+tmp+t)/2)<<endl;
	}
	return 0;
}
