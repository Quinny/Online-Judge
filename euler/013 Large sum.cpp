#include <iostream>
#include "BigInteger.hpp"

using namespace std;

int main(void){
	string tmp,n2;
	cin>>tmp;
	BigInteger n1(tmp);
	while(cin>>n2)
		n1+=n2;

	for(int i = 0; i < 10; i++)
		cout<<n1[i];

	cout<<endl;
	return 0;
}