/*
ģ��AVL Tree
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct anode
{
	anode *left;
	anode *right;
	int value;
	int height;
};
int height(anode *t)
{
	if(t==NULL)
		return -1;
	else
		return t->height;
}
anode* singleRotateLeft(anode* t)
{
	anode* tree=t->left;
	t->left=tree->right;
	tree->right=t;
	t->height=max(height(t->left),height(t->right))+1;
	tree->height=max(height(tree->left),t->height)+1;
	return tree;
}
anode* singleRotateRight(anode* t)
{
	anode* tree=t->right;
	t->right=tree->left;
	tree->left=t;
	t->height=max(height(t->left),height(t->right))+1;
	tree->height=max(height(tree->right),t->height)+1;
	return tree;
}
anode* doubleRotateLeft(anode* t)
{
	t->left=singleRotateRight(t->left);
	return singleRotateLeft(t);
}
anode* doubleRotateRight(anode* t)
{
	t->right=singleRotateLeft(t->right);
	return singleRotateRight(t);
}
anode* insert(int x,anode* t)
{
	if(t==NULL)
	{
		//new �Ƕ�̬�ڴ���䣬�������������tָ��һ���������ı���tree ����ִ�����tָ��ı�����ʧ t�ᱨ��
		t=new anode;
		t->height=0;
		t->left=t->right=NULL;
		t->value=x;
	}
	else if(x<t->value)
	{
		t->left=insert(x,t->left);
		if(height(t->left)-height(t->right)>=2)
			if(x<t->left->value)
				t=singleRotateLeft(t);
			else
				t=doubleRotateLeft(t);
	}
	else
	{
		t->right=insert(x,t->right);
		if(height(t->right)-height(t->left)>=2)
			if(x>t->right->value)
				t=singleRotateRight(t);
			else
				t=doubleRotateRight(t);
	}
	t->height=max(height(t->left),height(t->right))+1;
	return t;
}

int main()
{
	int n;
	scanf("%d",&n);
	anode *tree=NULL;
	for(int i=0;i<n;++i)
	{
		int tmp;
		scanf("%d",&tmp);
		tree=insert(tmp,tree);
	}
	printf("%d\n",tree->value);
	return 0;
}