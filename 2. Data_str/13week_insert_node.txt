//트리노드 동적할당
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
}TreeNode;

void insert_node(TreeNode **root, int key) {
	TreeNode *t, *p, *n;
	t = *root; p = NULL; 

	//이진탐색트리 내에 중복값을 검사
	while (t != NULL) { 
		if(key == t->key) return;
		p = t;
		if(key < t->key) t = t->left;
		else t = t->right;
	}

	//메모리받고, 노드생성
	n = (TreeNode*) malloc (sizeof(TreeNode));
	if(n == NULL) return;
	n->key = key;
	n->left = n->right = NULL;
	
	if(p != NULL) { //첫번째 노드 아닐경우
		if(key < p->key) p->left = n;
		else p->right = n;
	} else //첫번째 노드일경우
		*root = n;

}
void inorder(TreeNode *root) {
	if(root) {
		inorder(root->left);
		printf("%d-> ", root->key);
		inorder(root->right);
	} 
}
TreeNode* search_node(TreeNode *node, int key) {
	while(node != NULL) {
		if(key == node->key) return node;
		if (key < node->key) node = node->left;
		else node = node->right;
	} return NULL;
}
//이진탐색트리의 노드검사- 순환함수(재귀함수)
TreeNode* search (TreeNode *node, int key) {
return NULL;	
}

int main() {
	TreeNode *root = NULL;
	insert_node(&root, 3);
	insert_node(&root, 12);
	insert_node(&root, 18);
	insert_node(&root, 7);
	insert_node(&root, 26);
	insert_node(&root, 31);
	insert_node(&root, 7);
	insert_node(&root, 26);

	inorder(root);
	printf("\n");
	if(search_node(root, 7) != NULL) printf("트리에 있쪄영 ><\n");
	else printf("트리에 없쪄영 >< \n");

	if(search(root, 12) != NULL) printf("트리에 있쪄영 >< \n");
	else printf("트리에 없쪄영 >< \n");

}
