#include <iostream>

using namespace std;


bool checkTriple(int,int,int);

int main(void){

	for(int i=1;i<1000;i++){
		for(int j=i+1;j<1000-i;j++){
			int k=1000-i-j;
			if(checkTriple(i,j,k)){
				cout<<(i*j*k)<<endl;
				return 0;
			}
		}
	}

	return 0;
}


bool checkTriple(int a,int b,int c){
	return (a*a)+(b*b)==(c*c);
}