#include<iostream>
using namespace std;

class HEAP
{
int *A, size,n,heap;
public:
HEAP()                                      //constructor
{ 
cout<<"\nEnter the size of array :";
cin>>n;
A =new int(n);
cout<<"\nEnter the elements :";
for(int i=0;i<n;i++)
cin>>A[i];
size=n;
}
int heapsize()                             //returns heapsize
{
return size;
}
void maxheapify(int i)                     //performs max-heapify on the given node
{
int l=2*i +1,r=2*i+2;
int large = i;
if(l<heapsize() && A[l]>A[large])
large=l;

if(r<heapsize() && A[r]>A[large])
large=r;

if(large!=i)
{
int c= A[i];
A[i]=A[large];
A[large]=c;
maxheapify(large);
}
}
void BuildHeap()                       //constructing max-heap using build-max-heap
{
int i;
for(i=((n/2)-1);i>=0;i--)
{
maxheapify(i);
}
}
int parent(int x)
{ 
if(x%2!=0)
 return x/2;
else
return (x-1)/2;
}
void buildHeap2()                      //constructing max-heap using max-heap-insert
{
heap=1; int i;
int *B=new int(heap);
B[0]=A[0];
for(i=0;i<size;i++)
B=maxheapinsert(A[i],B);

cout<<"\nMax heap in array form :\n";
for(int i=0;i<size;i++)
cout<<B[i]<<" ";
cout<<"\n";
}
int*  maxheapinsert(int key,int B[])
{
int *C=new int(heap);
for(int i=0;i<(heap-1);i++)
C[i]= B[i];
int q=heap-1;
C[q]=key;
heap++;
while(q>0 && C[parent(q)]<C[q])
{
	int c= C[q];
	C[q]=C[parent(q)];
	C[parent(q)]=c;
	q=parent(q);
}
delete[] B;
return C;
}
void printheap()                          //print heap
{
cout<<"\nMax heap in array form :\n";
for(int i=0;i<size;i++)
cout<<A[i]<<" ";
cout<<"\n";
}
};

int main()
{
HEAP ob ;
int choice;
cout<<"\nEnter 1 to make heap using BUILD-HEAP or 2 using HEAP-INSERT :";
cin>>choice;
switch(choice)
{
 case 1:{ob.BuildHeap();
        ob.printheap();
	break;}
 case 2:{ob.buildHeap2();
	break;}
 default:cout<<"Invalid choice"<<endl;
}
return 0;
}
