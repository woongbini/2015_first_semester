#include <stdio.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b));

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

//전위순회
void PreOrder(TreeNode *node) {
	if(node != NULL) {
		printf("%d->", node->data);
		PreOrder(node->left); 
		PreOrder(node->right);
	}
}
//중위순회
void InOrder(TreeNode *node) {
	if(node != NULL) {
		InOrder(node->left);
		printf("%d->", node->data);
		InOrder(node->right);
	}
}
//후위순회
void PostOrder(TreeNode *node) {
	if(node != NULL) {
		PostOrder(node->left);
		PostOrder(node->right);
		printf("%d->", node->data);
	}
}
//노드의 개수
int get_count(TreeNode *node) {
	int count = 0;
	if(node != NULL) {
		count = 1 + get_count(node->left) + get_count(node->right);
	} return count;
}
//트리의 높이
int get_height(TreeNode *node) {
	int height = 0;
	if(node != NULL) {
		height = 1 + MAX(get_height(node->left), get_height(node->right));
	} return height;
}

int main() {
	//1.순회(이진트리에 속하는 모든 노드를 한번씩 방문하여 노드가 가지고 있는 데이터를 목적에 맞게 처리하는것을 의미한다)
	printf("\npre : "); PreOrder(root);
	printf("\nin : "); InOrder(root);
	printf("\npost : "); PostOrder(root); printf("\n");
	
	//2.노드의 개수 구하는 함수
	printf("노드의 개수 : %d \n",get_count(root));
	
	//2.높이를 구하는 함수
	printf("트리의 높이 : %d \n",get_height(root));

}
  

