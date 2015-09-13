#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct TreeNode {
      struct TreeNode *left;
      int data;
      struct TreeNode *right;
}TreeNode;

/*     +(n7)
      /     \
   *(n5)    +(n6)
   /  \     /   \
  1   4    16    25
(n1) (n2)  (n3)  (n4)   */

TreeNode n1 = {NULL, 1, NULL};
TreeNode n2 = {NULL, 4, NULL};
TreeNode n3 = {NULL, 16, NULL};
TreeNode n4 = {NULL, 25, NULL};
TreeNode n5 = {&n1, '*', &n2};
TreeNode n6 = {&n3, '+', &n4};
TreeNode n7 = {&n5, '+', &n6};
TreeNode *root = &n7;

int evaluate(TreeNode *root) {
	if(root == NULL) return 0;
	//연산자, 피연산자를 식별
	if(root->left == NULL && root->right == NULL) { //피연산자	
		return root->data;
	} else { //연산자임
		int op1 = evaluate(root->left); //밑에 있는 왼쪽 피연산자를 op1에 저장
		int op2 = evaluate(root->right); //밑에 있는 오른쪽 피연산자를 op2에 저장
		switch(root->data) {
			case '+': return op1 + op2; 
			case '-': return op1 - op2;
			case '*': return op1 * op2;
			case '/': return op1 / op2;
		}//switch end
	}//if-else end
	return 0;
}

int main() {
	printf("연산결과 = %d \n",evaluate(root)); //45
	//다음주에는 노드를 동적으로 만들어 보겠다.
	//이진탐색트리에서 어떤 노드가 제거가 된다고 했을때, 조건을 만족하면서 제거하는거
	//
}
