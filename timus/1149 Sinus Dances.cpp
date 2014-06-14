#include <iostream>

using namespace std;

void A(int,int);
void S(int,int);

int main(void){
	int n;
	cin>>n;
	S(n,1);
	cout<<endl;

	return 0;
}

void A(int n,int cur){
	 cout<<"sin("<<cur;
	 if(cur<n){
	 	if(cur%2==1) cout<<"-";
	 	else cout<<"+";
	 	A(n,cur+1);
	 }
	 cout<<")";
}

void S(int n,int cur){
	if(cur<n){
		cout<<"(";
		S(n,cur+1);
		cout<<")";
	}
	A(n+1-cur,1);
	cout<<"+"<<cur;
}