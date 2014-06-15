/*

This evening the great magician is also reading the book. 
One of the chapters describes Sandro's famous discovery: he invented a universal spell many years ago. 
Any substring (a few consecutive symbols of the string) of the universal spell is also a spell, and its power is equal to the number of times this spell is encountered in the universal spell (for example, the string “ue” encounters in the string “queue” twice, and the string “aba” encounters in the string “abababa” three times).
Sandro has a lot of free time now and he wants to find the most powerful spell. Help Sandro do it.

What i realized about this question is that any single character in the most occuring substring will be just as powerful as the entire phrase
So i only needed to look for the most occuring character in the string

*/

#include <iostream>
#include <cstring>

using namespace std;

int main(void){
	char spell[50];
	int count[26];

	memset(count,0,sizeof(count));

	cin>>spell;

	for(int i=0;i<strlen(spell);i++)
		count[spell[i]-'a']++;

	int max=count[0],index=0;
	for(int i=1;i<26;i++){
		if(count[i]>max){
			max=count[i];
			index=i;
		}
	}
	cout<<((char)(index+'a'))<<endl;

	return 0;
}