#include <iostream>

using namespace std;

bool valid(int);

int main(void){

	int i=2520;
	for(;!valid(i);i++);

	cout<<i<<endl;

	return 0;
}

bool valid(int n){
	for(int i=2;i<=20;i++){
		if(n%i!=0) return false;
	}
	return true;
}