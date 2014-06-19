/*

Basically a psuedo login system with error messages

*/

#include <iostream>
#include <map>

using namespace std;

int main(void){
	map< string, pair<string,int> > users;
	int n;
	string command,p1,p2;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>command;
		
		
		if(command=="register"){
			cin>>p1>>p2;
			if(users.empty() || users.find(p1)==users.end()){
				users[p1]=make_pair(p2,0);
				cout<<"success: new user added"<<endl;
			}
			else cout<<"fail: user already exists"<<endl;
		}
		
		
		if(command=="login"){
			cin>>p1>>p2;
			if(users.find(p1)!=users.end()){
				if(users[p1].first==p2){
					if(users[p1].second==0){
						users[p1].second=1;
						cout<<"success: user logged in"<<endl;
					}
					else cout<<"fail: already logged in"<<endl;
				}
				else cout<<"fail: incorrect password"<<endl;
			}
			else cout<<"fail: no such user"<<endl;
		}
		
		
		if(command=="logout"){
			cin>>p1;
			if(users.find(p1)!=users.end()){
				if(users[p1].second==1){
					users[p1].second=0;
					cout<<"success: user logged out"<<endl;
				}
				else cout<<"fail: already logged out"<<endl;
			}
			else cout<<"fail: no such user"<<endl;
		}
	}
	
	return 0;
}