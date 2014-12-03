#include <iostream>

using namespace std;

int sumMultiples(int,int);

int main(void){


	int threes=sumMultiples(3,1000);
	int fives=sumMultiples(5,1000);
	int commons=sumMultiples(15,1000);

	cout<<(threes + fives - commons)<<endl;

	return 0;
}


int sumMultiples(int multiple, int to){

	return (to-1)/multiple * ((to-1)/multiple + 1) / 2 * multiple;

}
