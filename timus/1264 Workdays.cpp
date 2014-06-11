/*

After a success of the previous Vasechkin’s program that allowed to calculate the results of the elections in cause of two days Artemy Sidorovich was placed at the head of the department. 
At the moment Artemy Sidorovich prepares a task for his subordinate — programmer Petechkin. The task is to write a very useful function that would ease the life of all the department programmers. 
For each integer from 0 to M the function would calculate how many times this number appears in the N-element array. 
Artemy Sidorovich deems that the function should work as follows (the sample code for N = 3, M = 1):


*/
#include <iostream>

using namespace std;

int main(void){
	int n,m;
	cin>>n>>m;
	cout<<n*(m+1)<<endl;

	return 0;
}