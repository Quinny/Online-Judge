/*

I had orginally tried using a n^2 method where i checked each number entered against each other but found that took to long, so I used this approach

since the numbers range from -32767 to 32767, we can bring them into range to add to an array of size 65535 by adding 32767

Then, when reading in the second list of numbers, we can subtract the value of the number from 10000+32767 (42767), to see if the corresponding number has been
entered in the first list.  If it has then we have found a match.

*/



#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	bool entered[65535],found=false; 
	memset(entered,false,sizeof(entered));
	int n;
	cin>>n;
	for(int i=0,tmp;i<n;i++){
		cin>>tmp;
		entered[tmp+32767]=true;
	}
	cin>>n;

	for(int i=0,tmp;i<n;i++){
		cin>>tmp;
		tmp=42767-tmp;
		if(tmp>=0 && tmp<65535 && entered[tmp]){
			found=true;
			break;
		}
	}
	if(found)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}