
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
using namespace std;

void Count( int arr[], int n)              //sorting using count sort
{
 int out[n];
 int max = arr[0];
 for(int i=1;i<n;i++)
 {
  if(arr[i]>max)
   max=arr[i];
 }
 int c[max+1];
 for(int i=0;i<=max;i++)
  c[i]=0;
 for(int i=0;i<n;i++)
  c[arr[i]]++;
 for(int i=1;i<=max;i++)
  c[i]+=c[i-1];
 for(int i=n-1;i>=0;i--)
 {
  out[c[arr[i]] - 1] = arr[i];
  c[arr[i]]--;
 }
 for(int i=0;i<n;i++)
  arr[i]=out[i];

}
void print(int arr[], int n) 
{
 for (int i = 0; i < n; i++)
  cout << arr[i] << " ";
  cout << endl;
}
void compute(int m)            //compute average execution time of the given array size
{
 int it=1, i;
 double tim1;
 while(it<=4)
 {
  int a[m];
  srand(time(0));
  for(i=0;i<m;i++)
  {
    int no = rand()% m +1;
    a[i]= no;
  }
  clock_t start,end;
  start = clock();
  Count(a,m);
  end = clock();
  tim1+= (double)(end-start)/CLOCKS_PER_SEC;   //calculate time in seconds
  it++;
 }
 tim1 = tim1/4;
 cout<<"\nAverage time :"<<tim1;
}

int main()
{
 int choice;
 cout<<"\nEnter 1 to sort or 2 to compute execution time :";
 cin>>choice;
 switch(choice)
 {
  case 1:{ int arr[] = {4,2,2,8,3,3,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Count(arr,n);
    print(arr,n);
	break;}
  case 2:{   int n;
    cout<<"\nEnter the range :";
    cin>>n;
    compute(n);
	break;}
  default:cout<<"Invalid choice"<<endl;
 }
}
