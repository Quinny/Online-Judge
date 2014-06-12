/*
Little Boy is mad at Karlsson, who ate all the sweets in the flat and even went to the neighbours to eat their sweets too.
 Now Little Boy's parents brought home a chocolate bar, and, sure enough, Karlsson is here already and wants to eat it. 
 However, this time Little Boy has firmly decided that not a single piece of chocolate will go to this glutton. 
 Little Boy wants to use Karlsson's addiction to the games of chance and suggests playing the following game.
 A chocolate bar can be considered as a rectangle of square “units” arranged in m rows and n columns and separated by “lines”. 
 Two players take alternate turns. At his turn, a player must take one piece of chocolate and split it into two along one of the lines. 
 If a player can't make a legal move (which happens when all pieces of chocolate consist of a single unit square), he loses, and the winner takes all the chocolate.

*/

#include <iostream>

using namespace std;

int main(void){

	int n,m;

	cin>>m>>n;
	
	cout<<((n*m-1)%2==1?"[:=[first]":"[second]=:]")<<endl;

	
	return 0;
}