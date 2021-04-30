#include<iostream>
#include<conio.h>
using namespace std;

struct Node
{
 int data;
 struct Node *next;
};
class Queue                  //to implement bfs
{ 
 struct Node *front;
 struct Node *rear;
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
  Node *new_mod = new Node();
  new_mod->data= iNode; 
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
	 	turn = front->data;
	 	delete(front);
	 	front=rear=NULL;
	 	return turn;
	 }
	 else
	 {
	 	Node *new_mod=front;
	 	front=front->next;
	 	turn = new_mod->data;
	 	delete(new_mod);
	 	return turn;
	 }
	}
}
};
class Graph
{
  int matrix[10][10];
  int nodes;
public :
Graph(int vertex)                         //constructing matrix for graph
{
 nodes = vertex;
 for(int i=0;i<nodes;i++)
 {
  for(int j=0;j<nodes;j++)
  matrix[i][j]=0;	
 }	
}
int get_nodes()                            //return the current nodes
{
	return nodes;
}
bool valid_edge(int x,int y)              //edge is valid or not
{
if(x>=nodes || y>nodes || x==y)
 return false;
else
 return true;
}
void add_edge(int i,int j)                //adding edge
{
 matrix[i][j]=matrix[j][i]=1;
}
void make_graph(int edge)                //creating graph
{
 int x,y;
 for(int i=1;i<=edge;i++)
 {
  cout<<"Enter edge"<<i<<":";
  cin>>x>>y;
  while(!valid_edge(x,y))
  {
  	cout<<"Enter edge"<<i<<":";
  	cin>>x>>y;
  }
  add_edge(x,y);
 }
}
void add_node()                     //add node
{
  nodes++;
  cout<<"\nThe inserted node is :"<<nodes<<endl;
  for(int i=0;i<nodes;i++)
  {
   matrix[i][nodes-1]=0;
   matrix[nodes-1][i]=0;
  }
}
void delete_node(int m)                   //delete node
{
 if(nodes!=0)
 {
   if(m>=nodes)
    cout<<"\nNode not present!\n";
   else
    { int j= m;
 	for( ;j<nodes;j++)
	 {
	 for(int i=0;i<nodes;i++)
	 {
	 	matrix[i][j]=matrix[i][j+1];  //1 column shift
	 }
	 for(int i=0;i<nodes;i++)
	 {
	 	matrix[j][i]=matrix[j+1][i];  //1 row shift
	 }	
	 }
	 nodes--;	
    }
 }
 else
 cout<<"Oops! Graph is empty"<<endl;
}
void search_node(int m)              //searches for a node
{
 if(m>=0 && m<nodes)
 {  int count=0;
 	int j;
 	for(j=0;j<nodes;j++)
 	{
 	if(matrix[m][j]==1)	
 	{
	  count =1;
 	  cout<<"\nEdge of "<<m<<": "<<j;
	}
    }
    if(count==0)
      cout<<"No edges found!"<<endl;
 }
 else
  cout<<"Node not found!"<<endl;
}
int* prep_traverse()                  //return visited array
{
    int *visited = new int[nodes];
	for(int i=0;i<nodes;i++)
	    visited[i]=0;	
	return visited;
}
void print_dfs(int sv, int *visited)   //dfs traversal
{
	cout<<"\n"<<sv;
	visited[sv]=1;
	for(int i=0;i<nodes;i++){
	 if(i==sv){ continue; }
	 if(matrix[sv][i]==1){
	 if(visited[i]){continue;}
	 print_dfs(i,visited);
	 }
	}
}
void print_bfs(int sv,int *visited)    //bfs traversal 
{ 
 Queue u;
 u.enqueue(sv);
while(!u.isEmpty())
{   int visit = u.dequeue();
	cout<<"\nVisited node :"<<visit;
	visited[visit]=1;
	for(int j=0;j<nodes;j++)
	{
		if(matrix[visit][j]==1 && visited[j]==0)
		 {
		     u.enqueue(j);
		     visited[j]=2;
		 }
	}
}
}
void display_mtrix()     //to display matrix
{
 cout<<"\n\nAdjacency matrix:";
 for(int i=0;i<nodes;i++)
 {
   cout<<"\n";
   for(int j=0;j<nodes;j++)
    cout<<" "<<matrix[i][j];	
 }	
}
};

int main()
{
	int N,E;
    cout<<"Enter the nodes to create Graph :";
    cin>>N;                                      //getting nodes
	Graph ob(N);
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
      	case 1:{  
		  ob.add_node();
			break;}
		case 2:{ int key;
		  cout<<"\nEnter key to delete :";
		  cin>>key;
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
		  ob.print_dfs(sn,ob.prep_traverse());
			break;}
		case 6:{int sn;
		  cout<<"\nEnter the start node :";
		  cin>>sn;
		  ob.print_bfs(sn,ob.prep_traverse());
			break;}
		case 7:{ ob.display_mtrix();
			break;}
		case 8:break;
		default:cout<<"Invalid choice!"<<endl;
	  }
	}while(choice!=8);
    return 0;
	
}
