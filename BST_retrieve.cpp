#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class BST
{
  int data;                //store value
  BST *left,*right;
public:
BST()                    //default constructor
{
  data=0;
  left=right=NULL;
}
BST(int value)          //parameterised constructor
{
  this->data=value;
  left=right=NULL;
}
BST* createnode(BST* node,int data )     //reconstructing BST
{
  if(node==NULL)
   node= new BST(data);
  if(node->data >data)
   node->left=createnode(node->left,data);
  if(node->data <data)
   node->right=createnode(node->right,data);
  return node;
}
void inorder(BST *root)             //prints inorder traversal 
{
  if(!root)
   return;
  inorder(root->left);
  cout<<root->data<<endl;
  inorder(root->right);
}
};

int main()
{
  fstream fin;
  fin.open("2.txt",ios::in);       //file having preorder traversal is opened in read mode
  int a;
  BST ob,*root=NULL;
  while(fin>>a)                    //reading
   root=ob.createnode(root,a);      //reconstructing
  fin.close();
  ob.inorder(root);                //print inorder traversal of bst
  return 0;
}
