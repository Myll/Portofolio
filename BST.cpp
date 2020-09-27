#include <stdio.h>
#include <stdlib.h>


struct data{
	int angka;
	
	data *left,*right;
}*root;


data* createnode(int angka){
	data* temp = (data*)malloc(sizeof(data));
	temp->angka=angka;
	temp->left=temp->right=NULL;
	return temp;
}


data *push(data* temp,int angka){
	if(!temp)
	{
		temp=createnode(angka);
		return temp;
	}
	if(angka<temp->angka)
	{
		temp->left=push(temp->left,angka);
	}
	else
	{
		temp->right=push(temp->right,angka);
	}
}


data* pop(data* temp,int angka)
{
	if(root==NULL)
	{
		printf("No Data\n");
	}
	else
	{
		if(temp->angka>angka)
		{
			temp->left=pop(temp->left,angka);
		}
		else if(temp->angka<angka)
		{
			temp->right=pop(temp->right,angka);
		}
		else
		{
			if(temp==root&&root->left==NULL&&root->right==NULL)
			{
				free(root);
				root=root;	
			}
			if(temp->left!=NULL)
			{
				data* curr=temp->left;
				while(curr->right!=NULL)
				{
					curr=curr->right;
				}
				temp->angka=curr->angka;
				
				if(temp->left==curr)
				{
					temp->left=temp->left->left;
				}
				temp->left(temp->left,curr->angka);
			}
			else if(temp->right!=NULL)
			{
				data* curr=temp->right;
				while(curr->left!=NULL)
			}
			curr=curr->left;
		}
		temp->angka=curr->angka;
		
		if(temp->right==curr)
		{
			temp->right=temp->right->right;
		}
		temp->right=pop(temp->right,curr->angka);
	}
	else
	{
		free(temp);
		temp=NULL;
	}
}


void cetak(data* temp, int level){
	if(!temp)
	{
		return;
	}
	
	cetak(temp->right,level+1);
	for(int i=0;i<level;i++)
	{
		printf("   ");
	}
	printf("%d\n",temp->angka);
	cetak(temp->left,level+1);
}


int main(){
	root=push(root,5);
	push(root,7);
	push(root,2);
	push(root,3);
	push(root,18);
	push(root,9);
	push(root,0);
	push(root,11);
	cetak(root,0);
	
	return 0;
}
