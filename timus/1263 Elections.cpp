#include <iostream>
#include <iomanip>

using namespace std;


int main(void){
	int n,m,tmp;

	cin>>n>>m;

	double v[n];
	for(int i=0;i<n;i++) v[i]=0;

	for(int i=0;i<m;i++){
		cin>>tmp;
		v[tmp-1]++;
	}

	for(int i=0;i<n;i++){
		cout<<fixed<<setprecision(2)<<((v[i]/m)*100)<<"%"<<endl;
	}

	return 0;
}