#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

 //주소를 저장할수있는 형태로~~
typedef struct TreeNode {
      struct TreeNode *left;
      int data;
      struct TreeNode *right;
}TreeNode;

typedef TreeNode *element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
     int front, rear;
}QueueType;
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

void init(QueueType *q) { q->front = q->rear = 0;}
void error (char *message) { fprintf(stderr, "%s \n", message); exit(1);}
int is_full (QueueType *q) { return ((q->rear+1) % (MAX_QUEUE_SIZE) == q->front);}
int is_empty (QueueType *q) { return q->front == q->rear;}

element dequeue (QueueType *q) {
     //underflow check
     if(is_empty(q)){
         error( "큐가 공백\n" );
    } else {
         q->front = (q->front+1) % (MAX_QUEUE_SIZE);
          return q->queue[q->front];
    }
}
void enqueue (QueueType *q, element item) {
     //overflow check
     if( is_full(q) ) {
         error( "큐가 꽉참\n" );
    } else {
         q->rear = (q->rear+1) % (MAX_QUEUE_SIZE); //0 1 2 3 4 0 1 2 3 4 0 ...
         q->queue[q->rear] = item;
    }
}

void level_order(TreeNode *root) {
	QueueType q;
	init(&q); //큐의 초기화 -> front = rear = 0
	enqueue(&q, root); //15의 주소가 들어감

	while(!is_empty(&q)) {
		root = dequeue(&q);
		printf("%d-> ", root->data);
		if(root->left) enqueue(&q, root->left);
		if(root->right) enqueue(&q, root->right);
	}//while end
}

int main() {
	 level_order(root);
}
