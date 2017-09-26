#include <bits/stdc++.h>
using namespace std;
int n;
int a[1001];
struct node {
	int val;
	struct node *l,*r;
};
struct node * insert(struct node *x,struct node * curr_root) {
	
	if(x->val <= curr_root->val)
		if(curr_root->l)
			curr_root->l = insert(x,curr_root->l);
		else
			curr_root->l = x;
	else
		if(curr_root->r)
			curr_root->r = insert(x,curr_root->r );
		else
			curr_root->r = x;
	return curr_root;
}
int height(struct node * curr_root) {
	int l = 0,r = 0;
	if(curr_root->l) 
		l = height(curr_root->l);
	if(curr_root->r)	
		r = height(curr_root->r);
	return 1+ max(l,r);
}
int main() {
	cin>>n;
	scanf("%d",&a[1]);
	struct node * root  = new node();
	root->val = a[1];
	root->l = NULL;
	root->r = NULL;
	for(int i = 2;i <= n;i++) {
		scanf("%d",&a[i]);
		struct node * x = new node();
		x->val = a[i];
		x->l = NULL;
		x->r = NULL;
		root = insert(x,root);
	}
	printf("%d\n",height(root));
}