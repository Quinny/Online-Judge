/*

Programmer Denis has been dreaming of visiting Antarctica since his childhood. 
However, there are no regular flights to Antarctica from his city. 
That is why Denis has been studying the continent for the whole summer using a local cinema. 
Now he knows that there are several kinds of penguins:

Emperor Penguins, which are fond of singing;
Little Penguins, which enjoy dancing;
Macaroni Penguins, which like to go surfing.

Unfortunately, it was not said in the cartoons which kind of penguins was largest in number. 
Petya decided to clarify this. He watched the cartoons once more and every time he saw a penguin he jotted down its kind in his notebook. 
Then he gave his notebook to you and asked you to determine the most numerous kind of penguins.

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	char s[1000];
	int n,EP=0,MP=0,LP=0;
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>s;
		if(s[0]=='E')EP++;
		if(s[0]=='M')MP++;
		if(s[0]=='L')LP++;
		cin>>s;
	}
	
	int highest=max(EP,max(LP,MP));
	
	if(highest==EP)cout<<"Emperor Penguin"<<endl;
	if(highest==MP)cout<<"Macaroni Penguin"<<endl;
	if(highest==LP)cout<<"Little Penguin"<<endl;
	
	return 0;
}