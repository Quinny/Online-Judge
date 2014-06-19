/*

Ten big walnuts is a whole lot of walnuts, that's for sure! Two walnuts is too little for anybody. 
How about six walnuts? Is it a small number of walnuts or a large one? 
The Parrot has already found an answer to this question: after eating a small amount of walnuts he wants to eat some more, while after eating a large amount of walnuts he feels satisfied. 
The Parrot enjoys eating and hates overeating; that's why he wants to know a minimal number of walnuts that is enough to get satisfied.
In order to calculate this number, he conducted a series of experiments. 
Each experiment went like that: the Parrot, being quite hungry, ate a number of walnuts and checked if this was enough to get himself satisfied. Of course, if some number of walnuts is enough, any larger number will do either; vice versa, if after eating a number of walnuts he is still hungry, no smaller number can get the parrot satisfied. 
You should help the Parrot to process the results of the experiments.

*/


#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int n,maxH=0,minS=10;
	char s[10];
	cin>>n;
	for(int i=0,tmp;i<n;i++){
		cin>>tmp;
		cin>>s;
		if(s[0]=='s') minS=min(minS,tmp);
		if(s[0]=='h') maxH=max(maxH,tmp);
	}


	if(minS>maxH && minS!=10 && minS!=2) cout<<minS<<endl;
	else if(minS==10) cout<<"10"<<endl;
	else cout<<"Inconsistent"<<endl;

	return 0;
}