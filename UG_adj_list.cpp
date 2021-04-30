#include<iostream>
#include<conio.h>
using namespace std;
struct que             //node for queue
{
  int b;
  struct que* next;
};
struct Node            //node for graph
{
  int data;
  struct Node *nextnode;
  struct Edge *firstedge;
};
struct Edge{          //edge for graph
  struct Node *endNode;
  struct Edge *nextedge;
};
class Queue           //queue - empty(),enqueue() and dequeue()
{ 
  que *front;
  que *rear;
public:
Queue()
{
  front=NULL;
  rear=NULL;	
}
int isEmpty()
{
	if(front==NULL && rear==NULL)
	return 1;
	else
	return 0;
}
void enqueue(int iNode)
{
  que *new_mod = new que;
  new_mod->b= iNode; 
  new_mod->next= NULL;
  if(front==NULL)
  {
   front=new_mod;
   rear =new_mod;	
  }   
  else
  {
   rear->next=new_mod;
   rear=new_mod;
  } 
}
int dequeue()
{  int turn;
	if(isEmpty())
	{
	cout<<"Empty queue!"<<endl;
	turn = -1;
	return turn;
	}
	else
	{
	 if(front==rear)
	 {
	 	turn = front->b;
	 	delete(front);
	 	front=rear=NULL;
	 	return turn;
	 }
	 else
	 {
	 	que *new_mod=front;
	 	front=front->next;
	 	turn = new_mod->b;
	 	delete(new_mod);
	 	return turn;
	 }
	}
}
};
class Graph
{
  Node *start = NULL;
  int nodes ;
  int edge;
  int *arr;
Node* list_node(int inode)         //initialising node
{
  Node* new_mod = new Node;
  new_mod->data=inode;
  new_mod->nextnode=NULL;
  new_mod->firstedge=NULL;
  return new_mod;
}
Edge* list_edge(struct Node* inode)  //initialising edge
{
  Edge* new_edge = new Edge;
  new_edge->endNode= inode;
  new_edge->nextedge= NULL;
  return new_edge;
}
public:
Graph(int n)               //initialization of graph
{
	for(int i=0;i<n;i++)
	{ int k;
	 cout<<"Enter node "<<i<<endl;
	 cin>>k;
	 add_node(k);	
	}
}
struct Node* valid_node(int x)    //checks whether a node is valid
{
  struct Node *ptr,*loc;
  ptr=start;
  while(ptr!=NULL)
  {
	if(ptr->data==x)
	{ loc= ptr;
	 return loc;
	}
	ptr= ptr->nextnode;
  }
  loc=NULL;
  return loc; 
}
void make_graph(int edge)     //creating graph
{
 int x,y;
 for(int i=1;i<=this->edge;i++)
 {
  cout<<"Enter edge "<<i<<":";
  cin>>x>>y;
  add_edge(x,y);
 }
}
void add_node(int m)           //adding node
{
  struct Node *temp ,*ptr;
  temp=list_node(m);
  if(start==NULL)
  {
   start = temp;
  }
  else
  {
    ptr=start;
    while(ptr->nextnode!=NULL)
       ptr=ptr->nextnode;
    ptr->nextnode=temp;	
  }
nodes++;
}
void delete_connectededges(int m)          //delete edges connected to the node to be deleted
{
  struct Node *temp;
  struct Edge *p,*q;
  temp=start;
  while(temp!=NULL)
  {
	if(temp->firstedge==NULL)
	{
		temp=temp->nextnode;
		continue;
	}
	if(temp->firstedge->endNode->data == m)
	{
		p=temp->firstedge;
		temp->firstedge=temp->firstedge->nextedge;
		delete(p);
		edge--;
		continue;
	}
	q= temp->firstedge;
	while(q->nextedge!=NULL)
	{
		if(q->nextedge->endNode->data == m)
		{
			p=q->nextedge;
			q->nextedge= p->nextedge;
			delete(p);
			edge--;
			continue;
		}
		q=q->nextedge;
	}
	temp=temp->nextnode;
  }
}
void delete_node(int m)             //delete node
{
	struct Node *temp,*ptr;
	struct Edge *p,*q;
	if(start==NULL)
	cout<<"No vertices to remove!"<<endl;
	if(start->data== m)
	{
		temp= start;
		start = start->nextnode;
	}
	else
	{
		ptr=start;
		while(ptr->nextnode!=NULL)
		{
			if(ptr->nextnode->data==m)
			 break;
			ptr= ptr->nextnode;
		}
		if(ptr->nextnode!=NULL)
		{
			temp = ptr->nextnode;
			ptr->nextnode = temp->nextnode;
		}
		else
		cout<<"Node not found!"<<endl;
	}
	p = temp->firstedge;
	while(p!=NULL)
	{
		q = p;
		p = p->nextedge;
		delete(q);
	}
	delete(temp);
	nodes--;
}
void add_subedge(struct Node *a,struct Node *b)          //adding edge from both orientations
{
  struct Edge *p,*q;
  p=list_edge(b);
  if(a->firstedge==NULL)
   { a->firstedge=p;
    return;
   }
  q=a->firstedge;
  while(q->nextedge!=NULL)
   q=q->nextedge;
  q->nextedge =p;
}
void add_edge(int i,int j)            //adding edge
{ 
  int x=i,y=j;
  struct Node *s,*d;
  while(valid_node(x)==NULL ||valid_node(y) ==NULL)
  {
	cout<<"Reinsert correct pair of nodes"<<endl;
	cin>>x>>y;
  }
  s=valid_node(x);
  d=valid_node(y);
  add_subedge(s,d);
  add_subedge(d,s);
  edge++;
}
void search_node(int m)                //searches for a node,if exists print its edges
{
 if(valid_node(m)!=NULL)
 {
 	struct Node *temp;
	temp = valid_node(m);
	struct Edge *ptr;
	ptr=temp->firstedge;
	if(ptr!=NULL)
	{
	while(ptr!=NULL)
	{
	 cout<<"Edge :"<<ptr->endNode->data<<endl;
	 ptr=ptr->nextedge;
	}
    }
    else
    cout<<"Zero edges"<<endl;
 }
 else
 cout<<"Invalid node!"<<endl;
}
int* prep_traverse()                 //returns visited array
{
    int *visited = new int[nodes];
	for(int i=0;i<nodes;i++)
	    visited[i]=0;	
	return visited;
}
int* node_array()                  //returns array of nodes
{
  struct Node *ptr;
  ptr=start;
  arr = new int[nodes]; int i=0;
  while(ptr!=NULL)
  {
    arr[i]=ptr->data;
    ptr=ptr->nextnode;
    i++;
  }
  return arr;
}
int pos(int *arr,int sv)
{
 int k;
 for(int i=0;i<nodes;i++)
 {
   if(arr[i]==sv)
   {
    k=i;
    break;
   }
  }
  return k;
}
void print_dfs(int sv,int *visited,int *arr)   //dfs traversal
{
  cout<<"\n"<<sv;
  visited[pos(arr,sv)]=1;
  struct Node *temp;
  temp=valid_node(sv);
  struct Edge *ptr;
  ptr=temp->firstedge;
  while(ptr!=NULL)
  {
    if(visited[pos(arr,ptr->endNode->data)]==0)
      print_dfs(ptr->endNode->data,visited,arr);
     ptr=ptr->nextedge;
  }
}
void print_bfs(int sv,int *visited,int *arr)   //bfs traversal
{
 Queue u; 
 u.enqueue(sv);
 while(!u.isEmpty())
 {   int visit = u.dequeue();
	cout<<"\nVisited node :"<<visit;
	visited[pos(arr,visit)]=1;
	struct Node *temp;
    temp=valid_node(visit);
    struct Edge *ptr;
    ptr=temp->firstedge;
    while(ptr!=NULL)
    {
	if(visited[pos(arr,ptr->endNode->data)]==0)
	{
	 visited[pos(arr,ptr->endNode->data)]=1;
	 u.enqueue(ptr->endNode->data);
	}
	ptr=ptr->nextedge;
    }
 }
}
void display()                    //display graph
{
 struct Node *ptr;
 struct Edge *p;
 ptr = start;
 while(ptr!=NULL)
 {
  cout<<ptr->data<<"->";
  p=ptr->firstedge;
  while(p!=NULL)
  {
    cout<<p->endNode->data<<" ";
    p=p->nextedge;
  }
   cout<<"\n";
   ptr=ptr->nextnode;
  }
}
};
int main()
{   
    int N,E;
    cout<<"Enter the nodes to create Graph :";
    cin>>N;                                      //getting nodes
	Graph ob(N);
//	ob.add_edge(1,2);
    cout<<"Enter the edges to create Graph :";
    cin>>E;                                     //getting edges
    ob.make_graph(E);
    int choice;
    do                                   //menu for different functions
    {
      cout<<"\nEnter 1 to insert node,2 to delete,3 to insert edge,4 to search,5 for DFS traversal,6 for BFS,7 to display and 8 to exit :";
      cin>>choice;
      switch(choice)
      {
      	case 1:{ int key;
		  cout<<"\nEnter key to insert :";
		  cin>>key; 
		  ob.add_node(key);
			break;}
		case 2:{ int key;
		  cout<<"\nEnter key to delete :";
		  cin>>key;
		  ob.delete_connectededges(key);
		  ob.delete_node(key);
			break;}
		case 3:{ int x,y;
		  cout<<"\nEnter edge to insert :";
		  cin>>x>>y;
		  ob.add_edge(x,y);
			break;}
		case 4:{ int key;
		  cout<<"\nEnter key to be searched :";
		  cin>>key;
		  ob.search_node(key);
			break;}
		case 5:{ int sn;
		  cout<<"\nEnter the start node :";
		  cin>>sn;
		  ob.print_dfs(sn,ob.prep_traverse(),ob.node_array());
			break;}
		case 6:{int sn;
		  cout<<"\nEnter the start node :";
		  cin>>sn;
		  ob.print_bfs(sn,ob.prep_traverse(),ob.node_array());
			break;}
		case 7:{ ob.display();
			break;}
		case 8:break;
		default:cout<<"Invalid choice!"<<endl;
	  }
	}while(choice!=8);
    return 0;
}
