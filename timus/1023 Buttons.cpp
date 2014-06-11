/*

The rules of the game are very simple. There’s a small heap of K buttons before two players. 
The players in turns take buttons from the heap, moreover, at a time one can take a number of buttons from 1 up to L. 
The one who takes the last button is the winner.


The rules of the Olympic Games will be a bit harder then usual. 
The one, who is to make a first step according to a lot, has an opportunity to fix a number K 
with the following restriction to it: 3 ≤ K ≤ 108 
(that is the exact number of buttons that has been prepared for the Olympic tournament). 
The player who is to make the second step fixes a number L that satisfies the following conditions 2 ≤ L < K.

A very crucial task is given to your team: you are to write a program that should help the second player to make his choice. 
In other words, given a number K your program is to find a number L that guaranties a victory to the second player with a proper game of both sides.

*/


#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	int k,ans=0;
	cin>>k; //read in the number of buttons
	for(int i=3;i<=sqrt(k);i++){
		if(k%i==0){ //find the first number that evenly divides k that is greater than or equal to 3 and less than the square root of k
			cout<<i-1<<endl;
			return 0;
		}
	}
	cout<<k-1<<endl; //otherwise the smallest number will be k-1
	return 0;
}
