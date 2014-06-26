#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double dist(double,double,double,double);

int main(void){
	double pi = 3.1415926535897,r;
	int n;
	cin>>n>>r;
	if(n==1){
		cout<<setprecision(2)<<fixed<<2*pi*r<<endl;
		return 0;
	}

	double lastX,lastY,currentX,currentY,ans=0,firstX,firstY;

	cin>>lastX>>lastY;
	firstX=lastX;firstY=lastY;

	for(int i=0;i<n;i++){
		cin>>currentX>>currentY;

		ans+=dist(lastX,lastY,currentX,currentY);

		lastX=currentX;
		lastY=currentY;
	}

	ans+=dist(lastX,lastY,firstX,firstY) + 2*pi*r;

	cout<<setprecision(2)<<fixed<<ans<<endl;

}

double dist(double x1,double y1,double x2,double y2){
	return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

