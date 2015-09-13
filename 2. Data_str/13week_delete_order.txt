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

void delete_node(TreeNode **root, int key) {
	TreeNode *t, *p, *child, *succ, *succ_p;
	t = *root; p = NULL;
	//노드값이 존재하는지 탐색트리 검색
	while(t != NULL && key != t->key) {
		p = t;
		//삼항연산자 사용 - (조건) ? 참 : 거짓;
		t = (key < t->key) ? t->left : t->right;
	}
	if(t == NULL) { printf("key is not in the tree\n"); return; }
	
	//case1 - 무자식인경우
	if(t->left == NULL && t->right == NULL) { 
		if(p != NULL) {
			if(p->right == t) p->right = NULL;
			else p->left = NULL;
		} else *root = NULL; //하나였던 노드 삭제, 트리가 비워짐
	
	//case2 - 자식노드가1인경우
	} else if (t->left == NULL || t->right == NULL) {
		child = (t->left != NULL) ? t->left : t->right;
		if(p != NULL) {
			if(p->left == t) p->left = child;
			else p->right = child;
		} else *root = child;
	
	//case3 - 2자식인 경우
	} else {
		succ_p = t; succ = t->right; //오른쪽 서브트리에서 가장 작은값을 가져오기 위한
		while(succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		//부모와 자식을 연결
		if(succ_p->left == succ) succ_p->left = succ->right;
		else succ_p->right = succ->right;
		t->key = succ->key; //구조를 망가트리지 않고 탐색트리 유지
		t = succ;
	} free(t);
}

int main() {
	TreeNode *root = NULL;
	insert_node(&root, 35);
	insert_node(&root, 18);
	insert_node(&root, 7);
	insert_node(&root, 26);
	insert_node(&root, 30);
	insert_node(&root, 22);
	insert_node(&root, 3);
	insert_node(&root, 12);
	insert_node(&root, 68);
	insert_node(&root, 99);

	inorder(root); printf("\n");
	delete_node(&root, 30); //무자식인 경우
	inorder(root); printf("\n");
	delete_node(&root, 68); //1자식인 경우
	inorder(root); printf("\n");
	delete_node(&root, 18); //2자식인 경우
	inorder(root); printf("\n");

	//과제->연습문제 15번 트리 가지고 삭제 case 3개 그림 그리기~ inorder로 검사해야됨.
}
