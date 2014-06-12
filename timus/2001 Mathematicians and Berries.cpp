/*

One day, two mathematicians were walking in the forest and picking berries. 
They’d been walking for two hours, and then they stopped and decided to see who’s got more berries. 
They took out the scales (can you imagine a mathematician going to the forest without any scales?) 
and they weighed their baskets with berries. They wrote the resulting numbers a1 and b1 down on a piece of paper. 
Then the second mathematician put all his berries to the first one’s basket (so that his basket became completely empty) and they weighed their baskets again and they received numbers a2 and b2, 
correspondingly. At last, the first mathematician put all the berries to the second one’s basket (so that his basket became completely empty); they weighed the baskets and got numbers a3 and b3, correspondingly. 
This data was enough to find the winner and the happy mathematicians moved on. 
Your task is to calculate the mass of the berries in each mathematician’s basket by the start of the competition.


*/

#include <iostream>

using namespace std;

int main(void){
	int a,b,tmp1,tmp2;

	cin>>a>>b;

	cin>>tmp1>>tmp2;

	b-=tmp2;

	cin>>tmp1>>tmp2;

	a-=tmp1;

	cout<<a<<" "<<b<<endl;

	return 0;
}