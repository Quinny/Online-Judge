/*

As everybody knows, there are a lot of stores in skyscrapers, it's the favourite place of glamorous girls. 
Blonde Cindy loves only one thing — the shopping. Today is one of the best days, she's going shopping to the new skyscraper “Prisma”. 
At first she decided to visit all the stores. But actually the “Prisma” is so large that you can find not just one store of each brand. 
Every time when Cindy found the brand, she has visited before, she told “Bayan”, and went on shopping.
Cindy saw all the stores in the “Prisma”. So how many times did she tell “Bayan”?

*/

#include <iostream>
#include <cstring>

using namespace std;

bool visited(char[],char[][31],int);

int main(void){
	int n,sz=0;
	cin>>n;
	char stores[n][31];
	char store[31];
	cin.getline(store,31); //kill the newline


	for(int i=0;i<n;i++){
		cin.getline(store,31);
		if(!visited(store,stores,sz)){
			strcpy(stores[sz],store);
			sz++;
		}
	}
	cout<<(n-sz)<<endl;

	return 0;
}


bool visited(char store[],char stores[][31],int sz){
	for(int i=0;i<sz;i++){
		if(strcmp(store,stores[i])==0) return true;
	}
	return false;
}
