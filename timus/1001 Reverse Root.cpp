/*

Reverse Root Problem

Given a set of integer numbers output their square roots in the reverse order of which they were entered with at least 4 decimal places

*/


#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

int main(void){
	double a;
	vector<double> v;

	while(cin>>a)
		v.push_back(a); //add all of the numbers to a vector

	for(int i=v.size()-1;i>=0;i--)
		cout<<fixed<<setprecision(4)<<sqrt(v[i])<<endl; //loop through backwards and output their square roots
}