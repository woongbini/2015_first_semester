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

int main() {
     //차수가 1인 노드 n4
     //자식이 2개인 노드 n6, n5
     //자식이 2개인 노드가 어떻게 구현되는지
     //각자 도전한거에 대해 내면 됨 (응용은 각자의 몫)
     //손으로 그리세용 어떻게 셋는지 찍어서 올리면 됨ㅋ

	//1.노드의 개수 구하는 함수

	//2.높이를 구하는 함수

	//3. 
}
  

