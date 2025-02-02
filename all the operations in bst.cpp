#include <stdio.h>
#include <stdlib.h>
struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};
struct tree *create(int x){
	struct tree *pnode=(struct tree *)malloc(sizeoff(struct tree));
	pnode->data=x;
	pnode->left=NULL;
	pnode->right+NULL;
}
struct tree *insert(struct tree *root,int x){
	if (root==NULL){
		return create(x);
	}
	if (x>root->data){
		root->right=insert(root->right,x);
	}
	else{
		root->left=insert(root->left,x);
	}
	return root;
}
void inordertrv(struct tree *root){
	if (root!=NULL){
		inordertrv(root->left);
		printf("%d\n",root->data);
		inordertrv(root->right);
	}
}
void preordertrv(struct tree *root){
	if (root!=NULL){
		printf("%d\n",root->data);
		preordertrv(root->left);
		preordertrv(root->right);
	}
}
void postordertrv(struct tree *root){
	if (root!=NULL){
		postordertrv(root->left);
		postordertrv(root->right);
		printf("%d\n",root->data);
	}
}
int smallele(struct tree *root){
	while (root->left!=NULL){
		root=root->left;
	}
	return root->data;
}
int largeele(struct tree *root){
	while (root->right!=NULL){
		root=root->right;
	}
	return root->data;
}
int countnode(struct tree *root){
	if (root==NULL){
		return 0;
	}
	else{
		return 1+countnode(root->left)+countnode(root->right);
	}
}
int height(struct tree *root){
	int h1;
	int h2;
	if (root==NULL){
		return 0;
	}
	else{
		h1=1+height(root->left);
		h2=1+height(root->right);
	}
	if (h1>h2){
		return h1;
	}
	else{
		return h2;
	}
}
int internalnode(struct tree *root){
	if (root==NULL || (root->left==NULL && root->right==NULL)){
		return 0;
	}
	else{
		return 1+internalnode(root->left)+internalnode(root->right);
	}
}
struct tree *mirror(struct tree *root){
	root->left=mirror(root->right);
	root->right=mirror(root->left);
	return root;
}
int main() {
    int rootValue, n, value;
    printf("Enter the value of the root node: ");
    scanf("%d", &rootValue);
    struct tree *root = create(rootValue);
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insert(root, value);
    }
    printf("\nInorder traversal:\n");
    inordertrv(root);
    printf("\nPreorder traversal:\n");
    preordertrv(root);
    printf("\nPostorder traversal:\n");
    postordertrv(root);
    printf("\nSmallest element:%d\n",smallele(root));
    printf("\nLargest element:%d\n",largeele(root));
    printf("\ntotal number of node:%d\n",countnode(root));
    printf("\nheight of the tree:%d\n",height(root));
	printf("\ninternal node of the tree:%d\n",internalnode(root));
	printf("\nexternal of the tree:%d\n",countnode(root)-internalnode(root));
	printf("mirror image:\n");
	mirror(root);
	inordertrv(root);
	return 0;
}
