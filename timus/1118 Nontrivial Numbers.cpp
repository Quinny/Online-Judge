#include <iostream>
#include <cmath>

using namespace std;

double getTriv(int);

int main(void){
	int i,j,min;
	double triv=100000000000;
	cin>>i>>j;

	if(i==1){
		cout<<1<<endl;
		return 0;
	}

	for(double tmp;j>=i;j--){
		tmp=getTriv(j);
		if(tmp==-1){
			cout<<j<<endl;
			return 0;
		}
		if(tmp<triv){
			triv=tmp;
			min=j;
		}
	}

	cout<<min<<endl;

	return 0;

}


double getTriv(int x){
	double sum=1;
	for(int i=2;i<sqrt(x);i++){
		if(x%i==0){
			sum+=i + (x/i);
		}
	}

	if(sum==1) return -1;

	return sum/x;
}