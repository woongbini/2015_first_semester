//괄호 문장 검사
//리스트에 문자 하나하나를 넣고

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int element;
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
         fprintf(stderr, "메모리할당에러" );   
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
         fprintf(stderr, "스택이 비어있어요" );
         exit(1);
    } else {
         StackNode *temp = s->top; 
         element item = temp->item;  
         s->top = s->top->link;   
         free(temp);  
          return item;
    }         
}

int check_matching (char *in) { //1.char포인터변수로 받는법
    LinkedStackType s;
     int n=strlen(in); //n=13
     char ch, open_ch;
    init(&s);

     for(int i=0 ; i<n ; i++) {
         ch = in[i];
          switch(ch) {
          case '{' : case '[': case '(':
             push(&s, ch); break;
          case ')' : case '}': case ']':
              if(is_empty(&s)) return 0;
              else {
                 open_ch = pop(&s);
                  if((open_ch == '(' && ch != ')')||
                      (open_ch == '[' && ch != ']')||
                      (open_ch == '{' && ch != '}' )) {
                       return 0;
                 } //if end
                  break;
             } //else end
         } //switch end
    } //for end
     if( !is_empty(&s)) return 0;//모든 괄호 검사를 끝낸 후 스택이 비어있지 않다면, 괄호문장에오류가 있음
     return 1;
    
}

//후위표기식의 연산
int eval(char exp[]) {
     int op1, op2, value, len=strlen(exp); //9
     char ch;
     //책-스택을 배열로 구현한 코드를 이용
    LinkedStackType s;
    init(&s); //top포인터 NULL로 초기화
     for(int i=0 ; i<len ; i++) {
         ch = exp[i];
          if(ch != '+' && ch != '-' && ch != '*' && ch != '/') {
             value = ch - '0';
             push(&s, value); //정수로 변환하여 stack에 push
         } else {
             op2 = pop(&s);
             op1 = pop(&s);
              switch (ch) {
                  case '+' : push(&s,op1+op2); break;
                  case '-' : push(&s,op1-op2); break;
                  case '*' : push(&s,op1*op2); break;
                  case '/' : push(&s,op1/op2); break;
             } //switch end
         } //else end
    } //for end
     return pop(&s);

}

//후위표기식의 연산
int main() {
     int result;
    result = eval( "82/3-32*+"); // 8/2-3+3*2 -> 7
    printf("수식 결과 :  %d \n" , result);
}
