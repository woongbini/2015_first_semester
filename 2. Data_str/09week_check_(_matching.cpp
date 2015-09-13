#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char element;
typedef struct StackNode {
           element item;
           struct StackNode *link;
}StackNode;

typedef struct {
           StackNode *top;
}LinkedStackType;

void init(LinkedStackType *s) {
     s->top = NULL;
}

void push(LinkedStackType *s, element item) {  
     //overflow check 없음
     StackNode *temp = (StackNode*)malloc(sizeof(StackNode));    
     if(temp == NULL) {       
          fprintf(stderr, "메모리할당에러");   
          return;
     } else {  
          temp->item = item; 
          temp->link = s->top; 
          s->top = temp;
     }     
}

int is_empty(LinkedStackType *s) {
     return (s->top == NULL);
}

element pop(LinkedStackType *s) {   
     //underflow check!!!!
     if(is_empty(s)) {
          fprintf(stderr,"스택이 비어있어요");
          exit(1);
     } else {
          StackNode *temp = s->top; 
          element item = temp->item;  
          s->top = s->top->link;   
          free(temp);  
          return item;
     }         
}

//괄호검사
int check_matching (char *in) { //1.char포인터변수로 받는법
     LinkedStackType s;
     int n=strlen(in); //n=13
     char ch, open_ch;
     init(&s);

     for(int i=0 ; i<n ; i++) {
          ch = in[i];
          switch(ch) {
          case '{': case '[': case '(':
               push(&s, ch); break;
          case ')': case '}': case ']':
               if(is_empty(&s)) return 0;
               else {
                    open_ch = pop(&s);
                    if((open_ch == '(' && ch != ')')||
                         (open_ch == '[' && ch != ']')||
                         (open_ch == '{' && ch != '}')) {
                         return 0;
                    }//if end
                    break;
               }//else end
          }//switch end
     }//for end
     if( !is_empty(&s)) return 0;//모든 괄호 검사를 끝낸 후 스택이 비어있지 않다면, 괄호문장에오류가 있음
     return 1;
    
}

int main() {
     if( check_matching("{A[(i+1)]=0;}") ) //14개(마지막NULL)의 문자열!!
          printf("괄호 검사 : 오류 없음\n");
     else
          printf("괄호 검사 : 오류 발생\n");

     if( check_matching("{A[(i+1)=0;}") ) //14개(마지막NULL)의 문자열!!
          printf("괄호 검사 : 오류 없음\n");
     else
          printf("괄호 검사 : 오류 발생\n");
      
}
