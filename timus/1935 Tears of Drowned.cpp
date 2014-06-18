/*

Recently Tia Dalma received some good skins of bats as a payment, and now she wants to dry them. 
To dry ingredients fortuneteller usually uses specially prepared books as the magical properties of the skins could be lost during prolonged contact with other objects. 
Tia Dalma knows how many sheets should be on both sides of the skin to save it unspoiled. 
For a i-th skin that number is ai, that is, the distance from it to the neighboring skins and the book cover can’t be less than ai sheets. 
Help a fortuneteller determine the minimum number of sheets that should be in the book to save rare ingredients from damage.

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	sort(a,a+n,greater<int>());

	int ans=a[0];

	for(int i=0;i<n;i++)
		ans+=a[i];

	cout<<ans<<endl;

	return 0;
}