#include <iostream>

using namespace std;

int main(void){
	int row;
	char col;
	string ans;

	cin>>row;
	cin>>col;

	if(row<=2){
		if(col=='A' || col=='D') ans="window";
		else ans="aisle";
		cout<<ans<<endl;
		return 0;
	}

	else if(row<=20){
		if(col=='A' || col=='F') ans="window";
		else ans="aisle";
		cout<<ans<<endl;
		return 0;
	}
	else{
		if(col=='A' || col=='K') ans="window";
		else if (col=='C' || col=='D' || col=='G' || col=='G' || col=='H') ans="aisle";
		else ans="neither";
	}

	cout<<ans<<endl;
	return 0;

}