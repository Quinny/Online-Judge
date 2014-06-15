#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void){
	int n,tmp;
	double sum;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		sum+=abs(tmp);
	}

	cout<<fixed<<setprecision(6)<<(sum/n)<<endl;

	return 0;
}