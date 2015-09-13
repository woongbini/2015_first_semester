#include <stdio.h>

typedef struct TreeNode {
      struct TreeNode *left;
      int data;
      struct TreeNode *right;
}TreeNode;

/*    15(n6)
     /     \
   4(n4)  20(n5)
   /     /   \
  1     16    25
(n1)   (n2)  (n3)   */

TreeNode n1 = {NULL, 1, NULL};
TreeNode n2 = {NULL, 16, NULL};
TreeNode n3 = {NULL, 25, NULL};
TreeNode n4 = {&n1,  4, NULL};
TreeNode n5 = {&n2, 20, &n3};
TreeNode n6 = {&n4, 15, &n5};
TreeNode *root = &n6;

void preorder(TreeNode *root) {
	if(root) {
		printf("%d-> ", root->data); //15->4->1->20->16->25->
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(TreeNode *root) {
	if(root) {
		inorder(root->left);
		printf("%d-> ", root->data);
		inorder(root->right);
	}
}
void postorder(TreeNode *root) {
	if(root) {
		postorder(root->left);
		postorder(root->left);
		printf("%d-> ", root->data);
	}
}
int main() {
	printf("전위순회: "); preorder(root); 
	printf("\n중위순회: "); inorder(root);
	printf("\n후위순회: "); postorder(root); 
}
