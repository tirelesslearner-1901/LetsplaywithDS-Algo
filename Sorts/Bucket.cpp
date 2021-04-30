#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

struct Node 
{
  float data;
  struct Node *next;
};
struct Node *InsertionSort(struct Node *);
void BucketSort(float arr[],int n)                     //sorting using buckets created using linked list
{
  int i, j;
  struct Node **buckets;
  buckets = (struct Node **)malloc(sizeof(struct Node *) * n);
  for (i = 0; i < n; ++i)
  {
    buckets[i] = NULL;
  }
  for (i = 0; i < n; ++i)
  {
    struct Node *current;
    int pos = n*arr[i];
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = arr[i];
    current->next = buckets[pos];
    buckets[pos] = current;
   }
  for (i = 0; i < n; ++i) 
  {
    buckets[i] = InsertionSort(buckets[i]);
  }
  for (j = 0, i = 0; i < n;i++) 
  {
    struct Node *node;
    node = buckets[i];
    while (node)
	{
      arr[j++] = node->data;
      node = node->next;
    }
  }
  for (i = 0; i < n; ++i) 
  {
    struct Node *node;
    node = buckets[i];
    while (node)
   {
      struct Node *tmp;
      tmp = node;
      node = node->next;
      free(tmp);
   }
  }
  free(buckets);
}
struct Node *InsertionSort(struct Node *list)                 //sorting the linked lists 
{
 struct Node *k, *nodeList;
  if (list == 0 || list->next == 0) 
 {
  return list;
 }
 nodeList = list;
 k = list->next;
 nodeList->next = 0;
 while (k != 0) 
 {
    struct Node *ptr;
    if (nodeList->data > k->data)
	{
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }
    for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) 
	{
      if (ptr->next->data > k->data)
        break;
    }

    if (ptr->next != 0) 
	{
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = 0;
      continue;
    }
 }
  return nodeList;
}
void print(float arr[], int n) 
{
 for (int i = 0; i < n; i++)
  cout << arr[i] << " ";
  cout << endl;
}
void compute(int m)                     //compute average execution time of the given array size
{
 int it=1, i;
 double tim1;
 while(it++<=4)
 {
  float a[m];
  srand(time(0));
  for(i=0;i<m;i++)
  {
   float no = ((float)rand()/(float)RAND_MAX );
   a[i]= no;
  }
  clock_t start,end;
  start = clock();
  BucketSort(a,m);
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
  case 1:{ float arr[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    int n = sizeof(arr) / sizeof(arr[0]);
    BucketSort(arr,n);
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

