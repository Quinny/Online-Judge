/*
After the Snow White with her bridegroom had left the house of the seven dwarfs, their peaceful and prosperous life has come to an end. 
Each dwarf blames others to be the reason of the Snow White's leave. To stop everlasting quarrels, the dwarfs decided to part. 
According to an ancient law, their common possessions should be divided in the most fair way, which means that all the dwarfs should get equal parts. 
Everything that the dwarfs cannot divide in a fair way they give to the Snow White. For example, after dividing 26 old boots, each dwarf got 3 old boots, and the Snow White got the remaining 5 old boots. 
Some of the numbers are very large, for example, the dwarfs have 123456123456 poppy seeds, so it is not easy to calculate that the Snow White gets only one seed. To speed up the divorce, help the dwarfs to determine quickly the Snow White's part.


I had originally just tried using long long and returning num%7, but this didnt work as the numbers were to large

I then did some research and found this article:
http://www.devx.com/tips/Tip/39012

and used that method


*/
#include <iostream>
#include <cstring>

using namespace std;

int main(void){
	char num[52];
	int ans;

	cin>>num;

	for(int i=0;i<strlen(num);i++)
		ans=(ans*10+num[i]-'0')%7;

	cout<<ans<<endl;

}