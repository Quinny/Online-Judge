#include <iostream>
#include "BigInteger.hpp"
using namespace std;

int main(void){
	BigInteger n(2);
	int ans=0;

	for(int i=0;i<999;i++)
		n+=n;

	for(int i=0;i<n.length();i++)
		ans += n[i];

	cout<<ans<<endl;

	return 0;
}