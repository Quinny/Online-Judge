/*

There is a famous spammer among our friends. 
In the end of every contest he is submitting his incorrect solutions at the speed of a machine-gun. 
In addition, he cheats by means of using several accounts for debugging. 
The judges eventually decided to disqualify the spammer. 
For that, they first want to discover all of his debugging accounts. 
The judges know which teams submitted their solutions in the last ten minutes of a contest. 
They regard as the spammer's debugging accounts all accounts which submitted solutions at least twice during the last ten minutes of the contest. 
Your task is to find these accounts.

*/


#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void){
	string name;
	map<string, int> teams; //map the team name to the number of submissions they made in the last 10 minutes

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>name;
		if(teams.find(name)==teams.end()) teams[name]=1; //if the team isnt in the map, add them
		else teams[name]++; //otherwise increment their submission
	}

	for(auto team = teams.cbegin(); team != teams.cend(); ++team){
		if(team->second>=2) cout<<team->first<<endl; //output all the teams with 2 or more submissions
	}
	return 0;
}