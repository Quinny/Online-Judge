/*

At the start of each school year, a very important event happens at Hogwarts. 
Each of the first-year wizards and witches is assigned to one of the four Hogwarts houses. 
The bravest children are put to Gryffindor, the cleverest are put to Ravenclaw, the most hard-working go to Hufflepuff, and Slytherin becomes home to the most ambitious. 
The assignment is carried out in the Great Hall of Hogwarts castle in the following way: when the name of a first-year student is called, he or she comes out to the center of the Hall and puts on the famous Sorting Hat. 
The Hat estimates the situation in the head of the young wizard or witch and cries out the name of the house to which the student is assigned. 
A special elf writes down the Hat's decisions. 
After the sorting, the elf must quickly compile lists of students of each house. 
Members of the Society for the Promotion of Elfish Welfare beg you to help the elf in this hard work.

*/
#include <iostream>
#include <vector>

using namespace std;

int main(void){
	string name,house;
	vector<string> houses[4];
	string names[]={"Slytherin:", "Hufflepuff:", "Gryffindor:", "Ravenclaw:"};
	int n;
	cin>>n;
	cin.ignore();

	for(int i=0;i<n;i++){
		getline(cin,name);
		getline(cin,house);

		if(house[0]=='S') houses[0].push_back(name);
		else if(house[0]=='H') houses[1].push_back(name);
		else if(house[0]=='G') houses[2].push_back(name);
		else houses[3].push_back(name);
	}

	for(int i=0;i<4;i++){
		cout<<names[i]<<endl;
		for(int x=0;x<houses[i].size();x++){
			cout<<houses[i][x]<<endl;
		}
		cout<<endl;
	}

	return 0;
}