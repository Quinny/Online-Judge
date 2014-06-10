#include <iostream>
using namespace std;
int main(void){
	int n,c=1;
	cin>>n;
	if(n<0) c=-1;
	for(int i=n+c;i>=1;i+=c){
		n+=i;
	}
	cout<<n<<endl;
	return 0;
}
