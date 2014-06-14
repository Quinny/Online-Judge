/*

The ZZZ team failed once again. 
They took part in the contest in Yekaterinozavodsk and were the first to solve all the problems. 
They did it even before the monitor was frozen. 
However, in the table of final results they were only second, because the QXX team had a better total time. 
A member of the QXX team supposes that it happened because the participants were unpunctual and used dirty debug methods. 
However, the captain of the ZZZ team claims that their complicated tactics had to be blamed for the failure, because even if all their solutions had been accepted in the first run the team would still have taken the second place. 
Find out which of them is right.

Each wrong submission adds 20 minutes to the time

*/



#include <iostream>

using namespace std;

int main(void){

	int t1,t2,pt=0,tmp;
	cin>>t1>>t2;

	for (int i=0;i<10;i++){
		cin>>tmp;
		pt+=tmp*20;
	}

	if(t2-pt>=t1) cout<<"No chance."<<endl;
	else cout<<"Dirty debug :("<<endl;

	return 0;
}