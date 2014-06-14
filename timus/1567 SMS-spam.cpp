/*

Petr, a student, decided to start his own business. 
He offers SMS advertising services to the business owners renting offices in the newly built “Prisma” tower. 
If an office owner wants to use the service, he devises a slogan and Petr texts it from his personal phone to thousands of Ekaterinburg citizens (he already bought the pirated list of mobile phone numbers). 
The cost of each slogan sent is a sum of costs of each character typed. 
Cost of an individual character is determined according to a very simple scheme: each tap at the phone's keyboard costs 1 rouble.

Petr's phone doesn't support sophisticated text input technologies, such as T9, and only the english alphabet can be used.

The “_” character in the table denotes whitespace. If you want to, for example, type “a”, you need to press the “1” button once. 
To type “k”, you press “4” twice. To type “!”, press “0” three times
*/

#include <iostream>
#include <cstring>

using namespace std;

int getCost(char,char[]);

int main(void){
	char keys[][4]={"abc","def","ghi","jkl","mno","pqr","stu","vwx","yz",".,!"," "};
	char c;
	int ans=0;

	while(cin>>noskipws>>c){
		for(int i=0;i<11;i++) ans+=getCost(c,keys[i]);
	}

	cout<<ans<<endl;

	return 0;
}

int getCost(char c,char key[]){
	for(int i=0;i<strlen(key);i++){
		if(c==key[i]) return i+1;
	}
	return 0;
}