/*

Originally I had tried using just a string for this problem and simply erasing adjacent identical letters and then
moving the position back 2.  This worked fine but caused time limit errors.  To fix this i used a stack

First, i checked if the stack was empty, and if it was i set the last character to 0
If the stack wasnt empty, last became the last the was put in the stack

if the next character in the string was the same as the first character in the stack, then the character would be removed from the stack
and also ommited from the string

Finally I read through the stack in reverse order, populating the string.
*/



#include <iostream>
#include <stack>
#include <cstring>

using namespace std;


int main(void){
	stack<char> decode;
	char cipher[200001];
	cin>>cipher;

	int len=strlen(cipher);

	for(int i=0;i<len;i++){
		char last = (decode.empty()? 0 : decode.top());
		if(last==cipher[i]) decode.pop();
		else decode.push(cipher[i]);
	}

	len=decode.size();
	memset(cipher,0,sizeof(cipher));

	for(int i=0;i<len;i++){
		cipher[len-i-1]=decode.top();
		decode.pop();
	}
	cout<<cipher<<endl;

	return 0;
}