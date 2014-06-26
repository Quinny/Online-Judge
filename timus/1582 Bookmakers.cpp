#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	double k1,k2,k3;
	cin>>k1>>k2>>k3;

	cout<<round(1000/((1/k1)+(1/k2)+(1/k3)))<<endl;

	return 0;
}