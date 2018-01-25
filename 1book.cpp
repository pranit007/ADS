
#include<iostream>             //include header files
using namespace std;
struct node                 //create structre
{
	bool flag;
	struct node *next;
	union
	{
		char title[10];
		struct node *dlink;
	};
}*root=NULL,*temp1,*temp2,*temp,*chi;

class tree                             //create class
{
	public:
		int ch,i,topic,j,k,i1,i2,st;
		struct node *create()
		{
			if(root==NULL)
			{
				struct node *newnode;
				newnode=new(struct node);
				cout<<"\nEnter the name of book :";           //enter name of book
				cin>>newnode->title;
				newnode->next=NULL;
				newnode->flag=1;
				root=newnode;
			}
			cout<<"Enter the number of chapters in book :";      //enter number of chapters
			cin>>ch;
			for(i=0;i<ch;i++)
			{
				struct node *newnode;
				newnode=new(struct node);
				for(temp1=root;temp1->next!=NULL;temp1=temp1->next);
				temp1->next=newnode;
				newnode->dlink=NULL;
				newnode->flag=0;
				newnode->next=NULL;
				
				struct node *nn;
				nn=new(struct node);
				cout<<"Enter the name of chapter :";            //enter name of chapter
				cin>>nn->title;
				nn->next=NULL;
				nn->flag=1;
				newnode->dlink=nn;
				cout<<"\nEnter the number of sections in this chapter :";   //enter number of sections in chapter
				cin>>topic;
				for(k=0;k<topic;k++)
				{
					struct node *nn;
					nn=new(struct node);
					for(temp2=newnode->dlink;temp2->next!=NULL;temp2=temp2->next);
					temp2->next=nn;
					nn->flag=0;
					nn->next=NULL;
					i1=1;
					
					struct node *newn;
					newn=new(struct node);
					cout<<"\nEnter the name of section :";            //enter name of section
					cin>>newn->title;
					newn->next=NULL;
					newn->flag=1;
 					nn->dlink=newn;
					cout<<"\nEnter the number of subsections in topic :";
					cin>>st;
					for(j=0;j<st;j++)
					{
						struct node *newn;
						newn=new(struct node);
						for(temp=(nn->dlink);temp->next!=NULL;temp=temp->next);
						temp->next=newn;
						newn->dlink=NULL;
						newn->flag=0;
						newn->next=NULL;
						i2=1;
						
						struct node *n;
						n=new(struct node);
						cout<<"Enter the name of subsection is :";  //enter name of subsectoin
						i2++;
						cin>>n->title;
						n->next=NULL;
						n->flag=1;
						newn->dlink=n;
					}
				}
			}
			return root;		
		}
		void display(struct node *r)            
		{
			i=1;
			for(temp=r;temp!=NULL;temp=temp->next)
			{
				if(temp->flag==1)
				{
					cout<<"\n"<<"\nBook Name:"<<temp->title<<endl;    
				}
				else
				{
					for(chi=temp->dlink;chi!=NULL;chi=chi->next)
					{
						if(chi->flag==1)
						{
							cout.width(30);
							cout<<"\n"<<i++<<"."<<"Chapter Name : "<<chi->title; 
						}
						else
						{
							for(temp1=chi->dlink;temp1!=NULL;temp1=temp1->next)
							{
								if(temp1->flag==1)
								{
									cout.width(50);
									cout<<"\n\t"<<"Section Name : "<<temp1->title;
								}
								else
								{
									for(temp2=temp1->dlink;temp2!=NULL;temp2=temp2->next)
									{
										if(temp2->flag==1)
										{
											cout.width(70);
											cout<<"\n\t\tSubsection Name : "<<temp2->title<<endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
};
int main()
{
	struct node *head1;
	tree T1;
	head1=T1.create();  //calling the functions
	T1.display(head1);
}

