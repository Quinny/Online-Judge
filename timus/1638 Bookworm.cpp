/*

Petya bought a 100-volume edition of Advice of Veterans of Programming Contests and hoped that the succession of his failures would come to an end. 
He mounted a bookshelf on the wall and put the volumes onto the shelf in increasing order from left to right closely to each other. 
But Petya didn't know that inside the first sheet of one of the volumes there lived a mathematical worm, which was infinitely small and very voracious. 
The worm started to gnaw its way through the volumes perpendicularly to the sheets. 
It stopped upon reaching the last sheet of another volume. 
The following day Petya discovered the damage and became interested in how many millimeters the worm had gnawed.

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	int t1,t2,start,end;
	cin>>t1>>t2>>start>>end;
	cout<<abs(((end-start)*(2*t2+t1))-t1)<<endl;
}