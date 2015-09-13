//수식의 표현 3가지
//1.infix(수식의 모호성이 있음) 2.prefix 3.postfix(스택의구조와함께 사용)

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
     //overflow check
    StackNode *temp = (StackNode*)malloc(sizeof(StackNode));   
     if(temp == NULL) {      
         fprintf(stderr, "메모리 할당 에러" );  
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
         fprintf(stderr, "스택이 비어 있쪙" );
         exit(1);
    } else {
         StackNode *temp = s->top;
         element item = temp->item; 
         s->top = s->top->link;  
         free(temp); 
          return item;
    }        
}

int check_matching (char *in) { //1.char포인터 변수로 받는법
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
     if( !is_empty(&s)) return 0; //모든 괄호 검사를 끝낸 후 스택이 비어있지 않다면, 괄호문장에 오류가 있다. 
     return 1;
   
}

//후위표기식의 연산
int eval(char exp[]) {
     int op1, op2, value, len=strlen(exp); //9
     char ch;
     //책->스택을 배열로 구현한 코드를 이용
    LinkedStackType s;
    init(&s); //top초인터 NULL값으로 초기화
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

element peek (LinkedStackType *s) {
     if(is_empty(s)) {
         fprintf(stderr, "스택이빔\n" );
         exit(1);
    } else {
          int item = s->top->item;
          return item;
    }
}

int prec (char op) {
     switch(op) {
     case '(' : case ')': return 0;
     case '+' : case '-': return 1;
     case '*' : case '/': return 2;
    }
     return -1;
}

void infix_to_postfix (char exp[]) {
     int len=strlen(exp); //문자열의 길이 9
     char ch, top_op;
    LinkedStackType s;
    init(&s);
     for(int i=0 ; i<len ; i++) {
         ch = exp[i]; //
          switch(ch) {
          case '+' : case '-': case '*': case '/' :
              while(!is_empty(&s) && prec(ch) <= prec(peek(&s))) {
             printf( "%c", pop(&s));
             }
             push(&s, ch); break;
          case '(' :
             push(&s, ch); break;
          case ')' :
             top_op = pop(&s);
              while(top_op != '(' ) {
                 printf( "%c", top_op);
                 top_op = pop(&s);
             }
              break;
          default:
             printf( "%c", ch); break ;
         } //switch end
    } //for end
     while(!is_empty(&s)) {
         printf( "%c", pop(&s));
    }
}


int main() {
    //printf("수?o식?A 결?a과?u :  %d \n" , eval("93*4+63/-4+"));
    infix_to_postfix( "(2+3)*4+9");

}
