#include <iostream>
#include <vector>
#include <string>

using namespace std;

string closest(string s1,string a[3]){
	int dif=-100000;
	int fdif=-10000;
	string ans="";
	for(int i=0;i<3;i++){
		int val=s1.compare(a[i]);
		if(val<0 && val>dif && s1[0]-a[i][0]>fdif){
			ans=a[i];
			dif=val;
			fdif=s1[0]-a[i][0];
		}
	}
	return ans;
}


int main(void){
	int n;
	cin>>n;
	string codenames[16][3];

	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++) cin>>(codenames[i][j]);
	}
	
	int o;
	cin>>o;
	string last=codenames[o-1][0];

	for(int i=1;i<3;i++){
		if(last.compare(codenames[o-1][i])>0){
			last=codenames[o-1][i];
		}
	}

	vector<string> v;
	v.push_back(last);

	
	for(int i=1;i<n;i++){
		cin>>o;
		last=closest(last,codenames[o-1]);
		if(last==""){
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
		v.push_back(last);
	}

	for(int i=0;i<v.size()-1;i++){
		cout<<v[i]<<endl;
	}
	
	return 0;
}



