/*


Your program should print to the output the only number Q. If such a number does not exist print −1.


*/

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int x); //checks if the number is prime
int prodDigits(int); //returns the sum of the digits

int main(void){
	int n;
	cin>>n; //read in the number

	if(n==0){
		cout<<10<<endl;
		return 0;
	}

	if(n<10){ //if the number is less than 10, then just add 10 and return
		cout<<n<<endl;
		return 0;
	}

	if(isPrime(n)){ //if the number is prime and greater than 5, then there is no possible solution
		cout<<-1<<endl;
		return 0;
	}

	int i=n;
	for(i=n;prodDigits(i)!=n;i++); //otherwise go until the number is found

	cout<<i<<endl;

}


int prodDigits(int x){
	int ans=1;
	while(x>0){
		ans*=x%10; //pick off the last digit and multiply
		x/=10; //divide by 10
	}
	return ans;
}

bool isPrime(int x){
	for(int i=2;i<sqrt(x);i++){
		if(x%i==0) return false; //if we find a divisor, then its not prime
	}
	return true;
}