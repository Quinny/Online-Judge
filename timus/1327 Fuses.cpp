/*

On Privalov's first workday, Janus burdened Aldan with the task of four-dimensional convolution in the conjuration space. 
Aldan worked for a while, flashing its lights and rewinding tapes, then a fuse blew and the machine shut down. 
Well, replacing fuses is something even a programmer can do. But Janus is rather absent-minded, and he, being lost in thoughts about his convolution problem, forgot about the weak fuse next day. 
So, on a third day Janus launched his program again, blowing another fuse. 
The fourth day went calmly, but on a fifth day one more fuse had to be replaced. And Janus is still not going to give up…

Your task is to help Sasha in making the requisition for spare parts. 
The requsition is made for a specific period - from the A-th workday to the B-th workday inclusive. 
You should calculate, how many fuses Janus is going to blow with his programs in the specified period of time.


*/

#include <iostream>

using namespace std;

int main(void){
	int a,b,ans=0;
	cin>>a>>b;
	for(int i=a;i<=b;i++){
		if(i%2==1)ans++;
	}
	cout<<ans<<endl;

	return 0;
}