#include <iostream>
#include <vector>

using namespace std;

void maxSum(vector<int>,int,int,int,int*);

int main(void) {
	int max=0;
	int tmp;
	vector<int> tree;

	while(cin>>tmp)
		tree.push_back(tmp);

	maxSum(tree,0,0,1,&max);

	cout << max <<endl;

	return 0;
}


void maxSum(vector<int> tree,int i,int sum,int level,int* max){
	if(i > tree.size())
		return;

	sum+=tree[i];
	if(sum > (*max))
		(*max)=sum;

	int leftChild=i+level;
	int rightChild=i+level+1;

	maxSum(tree,leftChild,sum,level+1,max);
	maxSum(tree,rightChild,sum,level+1,max);

}