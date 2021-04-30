#include<iostream>
using namespace std;  /*Implement a stack using Max-Heap. Here, you have to implement the Push(), Pop(), Isempty(),
and isFull() operations.*/
#define MAX 20
class STACK
{
 int key[MAX],value[MAX];
 int heap;
public:
STACK()                            //constructor
{
 heap=0;
}
int parent(int x)
{ 
 if(x%2!=0)
  return x/2;
 else
  return (x-1)/2;
}
int isFull()                   //isFull
{
 if(heap==MAX)
  return 1;
 else
  return 0;
}
int isEmpty()                //isEmpty()
{
 if(heap==0)
  return 1;
 else
  return 0;
}
int heapsize()
{
 return heap;
}
void push(int x)           //push()
{
 if(!isFull())
{
 heap++;
 maxheapinsert(x,heap);
}
 else
  cout<<"\nStack is full\n";
}
void maxheapinsert(int a,int b)
{
 value[b-1]=a;
 key[b-1]=b;
 int k=b-1;
 while(k>0 && key[parent(k)]<key[k])
 {
   int c=value[k];
   int d=key[k];
   value[k]=value[parent(k)];
   key[k]=key[parent(k)];
   value[parent(k)]=c;
   key[parent(k)]=d;
   k=parent(k);
 }
}
void maxheapify(int i)
{
 int l=2*i +1,r=2*i+2;
 int large = i;
 if(l<heapsize() && key[l]>key[large])
  large=l;

 if(r<heapsize() && key[r]>key[large])
  large=r;

 if(large!=i)
 {
  int c=value[i];
  int d=key[i];
  value[i]=value[large];
  key[i]=key[large];
  value[large]=c;
  key[large]=d;
  maxheapify(large);
 }
}
int pop()                    //pops out last element first 
{
 if(!isEmpty())
 {
   int maxkey=key[0];
   int max=value[0];
   key[0]=key[heap-1];
   value[0]=value[heap-1];
   heap = heap-1;
   maxheapify(0);
   return max;
 }
else
{
	cout<<"No element to pop ";
	return -1;
}
}
};

int main()
{
STACK ob;
int choice;
do
{
 cout<<"\nEnter 1 to push,2 to pop or 3 to exit :";
 cin>>choice;
 switch(choice)
 {
  case 1:{ cout<<"\nEnter element to push :";
  int z; cin>>z;
  ob.push(z);
	break;}
  case 2:{ cout<<"\nElement is :"<<ob.pop();
	break;}
  case 3:break;
  default:cout<<"\nInvalid choice\n";
 }
}while(choice!=3);
return 0;
}
