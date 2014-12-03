#include <iostream>

using namespace std;

int largestPrimeFactor(long);

int main(void){

	cout<<(largestPrimeFactor(600851475143))<<endl;

	return 0;
}

int largestPrimeFactor(long n){

	int prime=2;
	int largest=0;

	while(n!=1){
		if(n%prime==0){
			if(prime > largest) largest=prime;
			prime=2;
			n=n/largest;
		}
		else prime++;
	}

	return largest;

}