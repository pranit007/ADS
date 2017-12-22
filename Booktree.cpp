#include<iostream>
#include<string.h>
        
using namespace std;

struct node
{
	int data;
	struct node * left;
	struct node * right;

};

class BST
{
		node* root ;
		int count;
		
	public:
		void init();
		node* createNode(int);
		node* getRoot(){return root;}
		void insert(node * , int);
		int nodeCount();
		void display(node *);
		int minVal(node*);
};

void BST::init()
{
	root = NULL;
	count = 0;
}


node* BST::createNode(int d)
{
	node * tmp = new node;
	tmp->data =d;
	tmp->left = tmp->right = NULL;
	
	count++;
	return tmp;
}
	

void BST::insert( node * r, int data )
{
	if(r == NULL)
	{
		root = createNode(data);
		return;
	}
	else
	{
		if( r->data > data )
		{
			if( r->left == NULL)
				r->left = createNode(data);
				
			else
				insert(r->left, data);
		}
	
		else if(data >= r->data)
		{
			if(r->right == NULL)
				r->right = createNode(data); 	 
			
			else
				insert(r->right, data);
		}

	}
}


void BST::display(node * r)
{
	if(r == NULL)
		return;
		
	cout<<r->data<<"  ";
	
	display(r->left);
	display(r->right);
}
	
int BST::nodeCount(){return count;}
	
	
bool search(node * r , int sv)
{
	if(r == NULL)
		return false;
		
	if(r->data == sv)
		return true;
	
	else
	{
		if( r->data > sv )
		{
			if( r->left == NULL)
				return false;
				
			else
				return search(r->left, sv);
		}
	
		else if(sv >= r->data)
		{
			if(r->right == NULL)
				return false; 	 
			
			else
				return search(r->right, sv);
		}
	}
	
	return false;
}
		
int BST::minVal(node* r)
{
	if(r == NULL)
		return -1;
	else
		while(r->left !=NULL)
			r = r->left;
	return r->data;
}
	
int main()
{
	BST b;
	int d;
	b.init();
	
	while(1)
	{
		cout<<"\n\n*****************************************************";
		cout<<"\nMENU\n1.insert\n2.display\n3.node count\n4.search \n5. min val \nchoice : ";
		int ch;
		cin>>ch;
		
		switch(ch)
		{
			case 1:
					cout<<"\nEnter data :";
					cin>>d;
					b.insert(b.getRoot(), d);
					break;
					
			case 2:
					cout<<"Tree Data in prefix : ";
					b.display(b.getRoot());
					cout<<endl;
					break;
			case 3:
					cout<<"\nNumber of nodes : "<<b.nodeCount();
			case 4:
					cout<<"\nEnter sv :";
					cin>>d;
					if(search(b.getRoot(), d))
						cout<<"found :) ";
					else
						cout<<"\nNot found !";
					break;		
			case 5:
					d=b.minVal(b.getRoot());
					if(d==-1)
					cout<<"\nTree Empty !";
					
					else
					cout<<"\nMin val :"<<d;
		}
	}
	
	return 0;
}	
