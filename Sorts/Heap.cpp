
#include<iostream>
#include<stdlib.h>
#include <time.h>

using namespace std;

void maxheapify(int arr[], int n, int i)
{
 int l=2*i +1,r=2*i+2;
 int large = i;
 if(l<n && arr[l]>arr[large])
  large=l;

 if(r<n && arr[r]>arr[large])
  large=r;

 if(large!=i)
 {
   int c= arr[i];
   arr[i]=arr[large];
   arr[large]=c;
   maxheapify(arr,n,large);
  }
}
void Heapsort(int arr[],int n)                  //sorting through heap sort
{
 int i;
 for(i=((n/2)-1);i>=0;i--)
 {
  maxheapify(arr,n,i);
 }
 for(i=n-1;i>=0;i--)
 {
   int c=arr[0];
   arr[0]=arr[i];
   arr[i]=c;
   maxheapify(arr,i,0);
  }
}
void print(int arr[],int n) 
{
 for (int i = 0; i < n; i++)
  cout << arr[i] << " ";
  cout << endl;
}
void compute(int m)                   //compute average execution time of the given array size
{
 int it=1, i;
 double tim1;
 while(it++<=4)
 {
  int a[m];
  srand(time(NULL));
  for(i=0;i<m;i++)
  {
   int no = rand() ;
   a[i]= no;
  }
  clock_t start,end;
  start = clock();
  Heapsort(a,m);
  end = clock();
  tim1+= (double)(end-start)/CLOCKS_PER_SEC;   //calculate time in seconds
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
  case 1:{int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Heapsort(arr, n);
    print(arr,n);
	break;}
  case 2:{  int n;
    cout<<"\nEnter the range :";
    cin>>n;
    compute(n);
	break;}
  default:cout<<"Invalid choice"<<endl;
 }
}

