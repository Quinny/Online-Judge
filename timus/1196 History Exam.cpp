/*

Professor of history decided to simplify the examination process.
At the exam, every student should write a list of historic dates she knows (she should write the years only and, of course, must be able to explain what event took place in this or that year).
Professor has a list of dates that students must know. 
In order to decide upon the student's mark, Professor counts the number of dates in the student's list that are also present in his list. 
The student gets her mark according to the number of coincidences.
Your task is to automatize this process. Write a program that would count the number of dates in the student's list that also occur in Professor's list.

*/

#include <iostream>

using namespace std;

int search(int,int[],int);

int main(void){
  int n,m,ans=0,tmp;
  cin>>n;
  int pl[n];

  for(int i=0;i<n;i++)
    cin>>pl[i];

  cin>>m;
  for(int i=0;i<m;i++){
    cin>>tmp;
    ans+=search(tmp,pl,n);
  }

  cout<<ans<<endl;

  return 0;

}

int search(int needle,int haystack[],int size){
  int hi=size,lo=0,mid;
  while(hi>=lo){
    mid=(hi+lo)/2;
    if(haystack[mid]==needle) return 1;
    if(haystack[mid]>needle) hi=mid-1;
    else lo=mid+1;
  }
  return 0;
}
