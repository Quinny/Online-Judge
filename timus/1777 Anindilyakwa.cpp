/*

Professor Brian Butterworth found a meadow with three piles of stones. 
He decided to determine whether aborigines can count. 
Professor asked one of the aborigines to point at two piles with the minimal difference of numbers of stones in them and tell what this difference is. 
The aborigine pointed correctly! He was unable to express the difference with words, so he went to a shore and returned with a pile of the corresponding number of stones.
Professor decided to continue his experiments with other aborigines, until one of them points at two piles with equal number of stones. 
All piles that aborigines bring from the shore are left at the meadow. 
So, the second aborigine will have to deal with one more pile, the one brought by the first aborigine.

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){

	vector<long long>stones;
	long long int x1,x2,x3,ans=0;

	cin>>x1>>x2>>x3;
	stones.push_back(x1);stones.push_back(x2);stones.push_back(x3);

	long long int smallest=1000000000000000001;

	while(smallest){
		sort(stones.begin(),stones.end(),greater<long long>());
		ans++;
		smallest=1000000000000000001;
		for(int i=0;i<stones.size()-1;i++){
			smallest=min(smallest,stones[i]-stones[i+1]);
		}
		stones.push_back(smallest);
	}
	cout<<ans<<endl;

	return 0;

}