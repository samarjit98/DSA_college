#include<iostream>
using namespace std;
const int d=1;

struct blnode
{
	blnode()
	{
		c=0;
		for(int i=0;i<2*d+1;i++)
		ptr[i]=NULL;
	}
	int data[2*d];
	blnode* ptr[2*d+1];
	int c;
};



void print(blnode *t)
{
	if(t!=NULL)
	{
		int i;
		for(i=0;i<t->c;i++)
		{
			print(t->ptr[i]);
			cout<<t->data[i]<<" ";
		}
		print(t->ptr[i]);
	}
}

void bubSort(int a[],int size)
{
	int i=0,j=0,temp;
	for(i=0;i<size;i++)
	{
		for(j=0;j<(size-1);j++)
		{
		   if(a[j]>a[j+1])
		   {
			  temp=a[j];
			  a[j]=a[j+1];
			  a[j+1]=temp;
		   }
		}
	}
}

void insertSort(blnode *t,int k)
{

	int i,j;
	t->data[t->c++]=k;
	int tmp,size=t->c;
	blnode* tptr;
	for(i=0;i<size;i++)
	{
		for(j=0;j<(size-1);j++)
		{
			if(t->data[j]>t->data[j+1])
			{
				tmp=t->data[j];
				t->data[j]=t->data[j+1];
				t->data[j+1]=tmp;
				tptr=t->ptr[j+1];
				t->ptr[j+1]=t->ptr[j+2];
				t->ptr[j+2]=tptr;
			}
		}
	}
}

int checkLeaf(blnode *t)
{
	int i;
	for(i=0;i<(2*d+1);i++)
	{
		if(t->ptr[i]!=NULL)
		break;
	}
	if(i==(2*d+1))
	return 1;
	else
	return 0;
}

int findIndex(int *a,int k)
{
   int i;
   for(i=0;i<2*d;i++)
   {
   	 if(a[i]==k)
   	 return i;
   }
}

int Add(blnode* &t,int k,blnode* &newt)
{
	int *a=new int[2*d+1];
	int i;
	if(t==NULL)													//Initial run
	{
		t=new blnode;
		t->data[t->c++]=k;
		return -1;
	}
	else                                //Initial run ke baad
	{
		if(checkLeaf(t))                  //Leaf Node
		{

			if(t->c<2*d)										//No overfow
			{
				insertSort(t,k);
				return -1;
			}
			else														//Overflow hai
			{
				newt=new blnode;
				for(i=0;i<2*d;i++)
				a[i]=t->data[i];
				a[i]=k;
				bubSort(a,2*d+1);
				int median=a[d];
				t->c=0;
				for(i=0;i<d;i++)
				{
					t->data[t->c++]=a[i];
					newt->data[newt->c++]=a[d+1+i];
				}
				return median;
			}
		}
		else                               //Not Leaf
		{
			int lol=0;
			if(k<t->data[0])											//First element
			{
				lol=Add(t->ptr[0],k,newt);
			}
			else if(k>t->data[t->c-1])						//Last element
			{
				lol=Add(t->ptr[t->c],k,newt);
			}
			else																		//Middle element
			{
				for(i=1;i<t->c;i++)
				{
					if(k>t->data[i-1]&&k<t->data[i])
					{
						lol=Add(t->ptr[i],k,newt);
						break;
					}
				}
			}
			if(lol!=-1)																	//Parent node hai re
			{
				blnode *New=newt;
				int tdata[2*d];
				int index;
				blnode *tptr[2*d+1];
				if(t->c<2*d)                              //No overflow
				{
					t->ptr[t->c+1]=New;
					insertSort(t,lol);
					return -1;
				}
				else                                      //Overflow hai
				{
				   newt=new blnode;
				   int i;
				   for(i=0;i<2*d;i++)
				   a[i]=t->data[i];
				   a[i]=lol;
				   bubSort(a,2*d+1);
				   int median=a[d];

				   for(i=0;i<2*d;i++)
				   {
				   	 tdata[i]=t->data[i];
				   	 tptr[i]=t->ptr[i];
				   }
				   tptr[i]=t->ptr[i];

				   for(i=0;i<d;i++)
				   {
				   	 if(a[i]==lol)
				   	 t->ptr[i+1]=New;
				   	 else
						 {
						 	index=findIndex(t->data,a[i]);
						 	t->ptr[i+1]=tptr[index+1];
					   }
				   }
				   if(a[d]==lol)
				   newt->ptr[0]=New;
				   else
				   {
				   	 index=findIndex(t->data,a[d]);
				   	 newt->ptr[0]=tptr[index+1];
				   }
				   for(i=d+1;i<=2*d;i++)
				   {
				   	  if(a[i]==lol)
				   	  newt->ptr[i-d]=New;
				   	  else
					  {
					  	index=findIndex(t->data,a[i]);
					  	newt->ptr[i-d]=tptr[index+1];
				   	  }
				   }

				   t->c=0;
				   for(i=0;i<d;i++)
				   {
					 t->data[t->c++]=a[i];
					 newt->data[newt->c++]=a[d+1+i];
				   }
				   return median;
				}
			}
			else
			return -1;
		}
	}
}

int main()
{
	blnode *t=NULL;
	blnode *newt=NULL;
	blnode *tmpt;
	cout<<"Enter :\n";
	int k;
	int lol;
	while(1)
	{
		cin>>k;
		if(k==-1)
		break;
		lol=Add(t,k,newt);
		if(lol!=-1)
		{
				tmpt=new blnode;
		   	tmpt->data[tmpt->c++]=lol;
		   	tmpt->ptr[0]=t;
		   	tmpt->ptr[1]=newt;
		   	t=tmpt;
		}
		cout<<endl;

		print(t);
		cout<<endl;
	}
}
