/*

A brand new sapper robot is able to neutralize mines in a rectangular region having integer height and width (N and M respectively). 
Before the robot begins its work it is placed near the top leftmost cell of the rectangle heading right. 
Then the robot starts moving and neutralizing mines making a clockwise spiral way (see picture). 
The spiral twists towards the inside of the region, covering all the cells. 
The region is considered safe when all the cells are visited and checked by the robot.
Your task is to determine the number of the turns the robot has to make during its work.

*/

#include <iostream>

using namespace std;

int main(void){
	unsigned int n,m;
	cin>>n>>m;

	if(n>m) cout<<(2*(m-1)+1)<<endl;
	else cout<<(2*(n-1))<<endl;

	return 0;
}