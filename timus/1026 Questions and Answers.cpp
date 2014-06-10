/*


Input of the problem consists of two parts. 
At first, a database is written, and then there’s a sequence of queries. 
The format of database is very simple: in the first line there’s a number N, in the next N lines there are numbers of the database one in each line in an arbitrary order. 
A sequence of queries is written simply as well: in the first line of the sequence a number of queries K (1 ≤ K ≤ 100) is written, and in the next K lines there are queries one in each line. 
The query "Which element is i-th by its value?" is coded by the number i. 
A database is separated from a sequence of queries by the string of three symbols "#".


*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void){
	int n,b;
	string tmp; //to store the ###
	cin>>n; //read in the number of entries
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	sort(a,a+n); //sort the array of entries
	cin>>tmp; //eat up the ###
	cin>>n; //read in the number of queries
	for(int i=0;i<n;i++){
		cin>>b;
		cout<<a[b-1]<<endl; //return the i'th value by order
	}
	return 0;
}
