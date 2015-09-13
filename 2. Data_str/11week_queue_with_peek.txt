#include <stdio.h>
#include <malloc.h> //stdlib같dl 메모리 얼로케이션 가능ㅋ
typedef char element;
typedef struct QueueNode {
     element data;
      struct QueueNode *link;
}QueueNode;
typedef struct {
     QueueNode *front, *rear;
}QueueType;

void init(QueueType *q) { q->front = q->rear = NULL; }
void error(char * message) { fprintf(stderr, "%s\n",message); }
int is_empty(QueueType *q) { return (q->front == NULL); }


void enqueue(QueueType *q, element data) {
     QueueNode *temp = (QueueNode*) malloc (sizeof(QueueNode));
      if(temp == NULL) {
          error( "failed memory");
     } else { //data, link 넣?O고?i    
          temp->data = data;
          temp->link = NULL;
           if(is_empty(q)) { //if first node!!!
              q->front = temp;
              q->rear = temp;
          } else { //2nd, 3rd...node
              q->rear->link = temp;
              q->rear = temp;
          }
     }
}

element dequeue(QueueType *q) {
     QueueNode *temp = q->front;
     element data;
      if(is_empty(q)) {
          error( "empty...\n");
     } else {
          data = q->front->data;
          q->front = q->front->link;
           if(q->front == NULL)
              q->rear = NULL;
          free(temp);
     }
      return data;
}

void showqueue(QueueType *q) {
     QueueNode *temp = q->front;
      while(temp != NULL) {
          printf( "%c->", temp->data);
          temp = temp->link;
     }
     printf( "\n");
}

element peek (QueueType *q) {
      if(is_empty(q))
          error( " ");
      else {
          element data = q->front->data;
           return data;
     }
}

int main() {
     QueueType q;
     init(&q);
     enqueue(&q, 'A'); enqueue(&q,'B' ); enqueue(&q,'C'); enqueue(&q,'D');
      //first delete data -> 'A', 출력후 front를 조절하는 function
     printf( "dequeue() : %c\n", dequeue(&q));
      //printf("dequeue() : %c\n", dequeue(&q));
     showqueue(&q);
      //printf("dequeue() : %c\n", dequeue(&q));
     showqueue(&q);
     printf( "peek() : %c\n", peek(&q));
     
}
  
