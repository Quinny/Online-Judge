/*

While Fedya was writing the statement of the problem GOV Chronicles, he realized that there might be not enough paper to print the statements. 
He also discovered that his text editor didn't have the feature of calculating the number of pages in a text. 
Then Fedya decided to write a program that would calculate the number of pages for any given text.
Fedya knew that there were h lines on each page and w symbols in each line. 
Any two neighboring words in a line were separated by exactly one space. 
If there was no place for a word in a line, Fedya didn't hyphen it but put the whole word at the beginning of the next line.

*/

#include <iostream>
#include <cstring>

using namespace std;

int main(void){
	int h,w,n;
	cin>>h>>w>>n;
	char s[10001];

	int lines=1,chars=0; //start at 1 line in case we dont fill it up, 1 page will always be used

	for(int i=0;i<n;i++){
		cin>>s; //read in the word
		if(chars+strlen(s)+1<=w+1) chars+=strlen(s)+1; //if it fits on the line then put it there
		else{
			chars=strlen(s)+1; //otherwise start a new line
			lines++;
		}
	
	}

	cout<<((lines+h-1)/h)<<endl;
		
	return 0;
}