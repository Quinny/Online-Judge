#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void){
	double a;
	while(cin>>a)
		cout<<fixed<<setprecision(4)<<sqrt(a)<<endl;
}