/*

A New Russian Kolyan likes two things: money and order. 
Kolyan has lots of money, but there is no order in it. 
One beautiful morning Kolyan understood that he couldn't stand this any longer and decided to establish order in his money. 
He told his faithful mates to fetch the money from an underground depository, and soon his big room was filled up with red, green, and blue banknotes. 
Kolyan looked with disgust at this terrible mess. 
Now he wants to leave in his depository only banknotes of the same value and to give the rest of the money to the poor. 
He knows exactly that more than half banknotes have the same value. 
But in this mess it is impossible to understand which banknote is the most common.
*/

#include <iostream>

using namespace std;

int main(void){
	int n;
	cin>>n;
	int tmp;

	int count=0;
	int candidate; /* using moore's voting algorithm http://www.cs.utexas.edu/~moore/best-ideas/mjrty/example.html */
	for(int i=0;i<n;i++){
		cin>>tmp;
		if(count==0){
			candidate=tmp;
			count=1;
		}
		else{
			if(tmp==candidate) count++;
			else count--;
		}
	}
	cout<<candidate<<endl;
}