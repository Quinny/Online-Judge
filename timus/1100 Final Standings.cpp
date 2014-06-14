/*

Old contest software uses bubble sort for generating final standings. 
But now, there are too many teams and that software works too slow. 
You are asked to write a program, which generates exactly the same final standings as old software, but fast.

*/

#include <cstdio>
#include <algorithm>

using namespace std;

struct student{ //i originally tried an optimized bubble sort using 2 arrays, but went over the allowed time limit for the question
	int id,pts;

	bool operator < (student x) const{
		return pts>x.pts;
	}
}a[150000];

int main(void){
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d %d",&a[i].id,&a[i].pts);
	}
	stable_sort(a,a+n);
	
	for(int i=0;i<n;i++)
		printf("%d %d\n",a[i].id,a[i].pts);
	
	return 0;

}