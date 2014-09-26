#include <iostream>

using namespace std;

int main(void){

	long long s1=0;

	for(int i=1;i<=100;i++) s1+= (i*i);

	long long s2=((100*101)/2) * ((100*101)/2);

	cout<<(s2-s1)<<endl;

	return 0;
}