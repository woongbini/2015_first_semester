/*
큐!
스택의 경우 -> 나중에 들어온 data가 먼저 나가는 구조
큐 -> 먼저 들어온 data가 먼저 나가는 구조(First In First Out 특성)
ex) 매표소 -> 먼저 온놈이 먼저 표사서 입장ㅋ

큐는 뒤에서 새로운 데이터가 추가되고 앞에서 데이터가 하나씩 삭제되는 구조
큐에서 삽입이 일어나는곳을 후단(rear)
          삭제가 일어나는곳을 전단(front)

가장 중요한 함수는 삽입하는 함수인(enqueue) / 삭제하는 함수의 (dequeue)
dequeue함수 -> 큐의 맨앞에 있는 요소를 꺼내서 외부로 반환
enqueue함수 -> 큐에 요소를 추가하는 연산, 큐의 맨 뒤에 새로운 요소를 추가한다.

원형큐
front와 rear의 값이 배열의 끝인 MAX_QUEUE_SIZE-1에 도달하면 다음에 증가되는 값이 0이 되도록
처음에 front와 rear의 값이 모두 0이고, 
삽입시에는 rear이 먼저 증가, 증가된 위치에서 데이터가 삽입된다.
삭제시에는 front가 먼저 증가된 다음, 증가된 위치에서 데이터가 삭제된다.
*/




#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    element queue[MAX_QUEUE_SIZE];
     int front, rear;
}QueueType;

//원형큐의 초기화
void init(QueueType *q) {
    q->front = q->rear = 0;
}

void error (char *message) {
    fprintf(stderr, "%s \n", message);
    exit(1);
}

int is_full (QueueType *q) {
     return ((q->rear+1) % (MAX_QUEUE_SIZE) == q->front);
}

int is_empty (QueueType *q) {
     return q->front == q->rear;
}

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

int main() {
    QueueType q;
    init(&q);
    printf( "[front = %d | rear = %d] \n", q.front, q.rear); //0,0
    enqueue(&q, 10);
    printf( "[front = %d | rear = %d] \n", q.front, q.rear); //0,1
    enqueue(&q, 20);
    printf( "[front = %d | rear = %d] \n", q.front, q.rear); //0,2
    enqueue(&q, 30);
    printf( "[front = %d | rear = %d] \n", q.front, q.rear); //0,3

    printf( "dequeue()=%d \n", dequeue(&q)); //10
    printf( "[front = %d | rear = %d] \n", q.front, q.rear); //1,3
    printf( "dequeue()=%d \n", dequeue(&q)); //20
    printf( "[front = %d | rear = %d] \n", q.front, q.rear); //2,3

    enqueue(&q, 40);
    printf( "[front = %d | rear = %d] \n", q.front, q.rear); //2,4
    enqueue(&q, 50);
    printf( "[front = %d | rear = %d] \n", q.front, q.rear); //2,0
}
