/*

The blonde Angela has a new whim: internet chats.
Of course, as any blonde, she writes her messages using the upper case. 
You are the moderator of Angela's favorite chat and you're fed up with her upper-case messages. 
The problem is that Angela does not respond to your warnings. 
You decided to write a simple antiCAPS corrector, which would make Angela's messages readable.

*/

#include <iostream>
#include <cctype>

using namespace std;

int main(void){
	char c;
	bool upper=true;
	while(cin>>noskipws>>c){
		if(c=='.' || c=='!' || c=='?'){
			cout<<c;
			upper=true;
		}
		else{
			if(c>='A' && c<='Z'){
				if(upper){
					cout<<c;
					upper=false;
				}
				else{
					cout<<((char)tolower(c));
				}
			}
			else if((c>='a' && c<='z')){
				if(upper){
					cout<<((char)toupper(c));
					upper=false;
				}
				else cout<<c;
			}
			else cout<<c;
		}
	}

	return 0;
}