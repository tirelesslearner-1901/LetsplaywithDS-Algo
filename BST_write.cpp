#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
class BST
{
  int data;              //store value
  BST *left,*right;
public:
BST()                 //default constructor
{
  data=0;
  left=right=NULL;
}
BST(int value)       //parameterised constructor
{
  data=value;
  left=right=NULL;
}
BST* insert(BST* root,int value)         //to insert value
{
  if(!root)
   return new BST(value);
  if(value<root->data)
  {
   root->left= insert(root->left,value);
  }
  else
  {
   root->right= insert(root->right,value);
  }
  return root;
}
BST* search(BST* root,int key)           //search the value given by user
{
  if(root==NULL)
  {
    cout<<"Not found!"<<endl;
    return root;
  }
  if(root->data==key)
  {
    cout<<"Present!"<<endl;
    return root;
  }
  if(root->data<key)
    return search(root->right,key);
  else
    return search(root->left,key);
}
BST* remove(BST*& root,int key)        //delete the key
{
  if(root==NULL)
    return root;
  if(root->data<key)
  {
    root->right=remove(root->right,key);
    return root;
  }
  else if(root->data>key)
  {
    root->left =remove(root->left,key);
    return root;
  }
  if (root->left == NULL) 
  { 
    BST* temp = root->right;
    delete root; 
    return temp; 
  } 
  else if (root->right == NULL)
  { 
    BST* temp = root->left; 
    delete root; 
    return temp; 
  } 
   else
  {
    BST* ptr = root;
    BST* temp = root->right; 
    while (temp->left != NULL) { 
     ptr = temp; 
     temp = temp->left; 
    }  
    if (ptr!= root) 
      ptr->left =temp->right; 
    else
      ptr->right = temp->right;   
    root->data = temp->data; 
    delete temp;          
    return root; 
   }
}
void inorder(BST *root)        //prints inorder traversal 
{
  if(!root)
   return;
  inorder(root->left);
  cout<<root->data<<endl;
  inorder(root->right);
}
void preorder(BST *root)      //writes preorder traversal in a text file
{
  fstream fout;
  fout.open("2.txt",ios::out | ios::app);
  if(!root)
    return;
  fout<<root->data<<"\n";
  fout.close();
  preorder(root->left);
  preorder(root->right);
}
};

int main()
{
  BST ob, *root = NULL;
  int tot;
  cout<<"Enter the number of nodes to create BST :";      //getting nodes from user to create BST
  cin>>tot;
  while(tot--)
  {
    int value;
	cout<<"\nEnter value:";
	cin>>value;
	root=ob.insert(root,value);
  }
  int choice;
  do                        //menu for different functions
  {
    cout<<"\nEnter 1 to insert,2 for inorder traversal,3 to delete,4 to search,5 to write preorder in file and 6 to exit";
    cin>>choice;
    switch(choice)
    {
      case 1:{ int k;
       cout<<"\nEnter value:";
       cin>>k;
       root=ob.insert(root,k);
	   break;}
      case 2:{cout<<"\nInorder traversal\n";
       ob.inorder(root);
	   break;}
      case 3:{ int del;
       cout<<"\nEnter the key to be deleted:";
       cin>>del;
       root=ob.remove(root,del);
	   break;}
      case 4:{ int d;
       cout<<"\nEnter the key to be searched:";
       cin>>d;
       root=ob.search(root,d);
	   break;}
      case 5:{ ob.preorder(root);
	   break;}
      case 6:break;
      default:cout<<"Invalid choice!"<<endl;
    }
  }while(choice!=6);
return 0;
}
