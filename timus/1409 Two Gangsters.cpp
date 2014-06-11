/*

Two gangsters Harry and Larry had a rest at countryside. 
They decided to spend some time shooting, so they put several beer cans (no more than 10) on a log.
Harry started to shoot cans one after another from the leftmost to the right and Larry – from the rightmost to the left. 
At some moment it happened so that they shot one and the same can.

Determine how many cans were not shot by Harry and how many cans were not shot by Larry.

*/

#include <iostream>

using namespace std;
int main(void){
	int a,b;

	cin>>a>>b;

	cout<<b-1<<" "<<a-1<<endl;

	return 0;
}