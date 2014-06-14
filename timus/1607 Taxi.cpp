#include <iostream>

using namespace std;

int main(void){
	int a,b,c,d;

	cin>>a>>b>>c>>d;

	int i=0;
	while(true){

		if(a+(i*b) >= c-(d*i)){ //if the guys offer is greater than or equal to the taxis then take it
			cout<<(a+(i*b))<<endl;
			break;
		}

		if(a+((i+1)*b) >= c-(d*i)){ //if the guys next offer will be more than the current taxis then take the taxis
			cout<<(c-(d*i))<<endl;
			break;
		}
		i++;
	}

	return 0;
}