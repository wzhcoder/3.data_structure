#include "my_types.h"
#include "stdlib.h"

typedef int element ;

typedef struct _node{
    element data;
    struct _node *next;
}node;




void head_insert(node *head, int len)//len是不包括头节点的长度
{
    node *new =  NULL;
    node *old = NULL;
    int i;


    old = malloc(sizeof(node));
    old->data = rand()%100;
    old->next = NULL;
    head->next = old;
    // printf("head \t");
    // printf("%d \t", old->data);

    for(i = 0; i < len -1; i++){
        new = malloc(sizeof(node));
        new->data = rand()%100;
        new->next = old;
        head->next = new;
        old = new;
        // printf("%d  ->\t", new->data);
    }
}

void tail_insert(node *head, int len)//len是不包括头节点的长度
{
    node *new =  NULL;
    node *old = NULL;
    int i;

    #define print

    old = malloc(sizeof(node));
    old->data = rand()%100;
    old->next = NULL;
    head->next = old;

    #ifdef print
        printf("head  ->  ");
        printf("%d  ->  ", old->data);
    #endif

    for(i = 0; i < len -1; i++){
        new = malloc(sizeof(node));
        new->data = rand()%100;

        old->next = new;
        new->next =NULL;
        old  = new;
        #ifdef print
            printf("%d  ->  ", new->data);
        #endif
    }
    #ifdef print
        printf("NULL");
    #endif
}


void with_looplist(node *head)//尾插创建有环的列表，总共5个节点
{
    node *new =  NULL;
    node *old = NULL;
    node *temp = NULL;
    
    int i;
    int len =5;

    #define print

    old = malloc(sizeof(node));
    old->data = rand()%100;
    old->next = NULL;
    head->next = old;

    #ifdef print
        printf("head  ->  ");
        printf("%d  ->  ", old->data);
    #endif

    for(i = 0; i < len -1; i++){
        new = malloc(sizeof(node));
        if(i == 1){
            temp = new;
        }

        new->data = rand()%100;

        old->next = new;
        new->next =NULL;
        old  = new;
        #ifdef print
            printf("%d  ->  ", new->data);
        #endif
    }
    new->next = temp;
    #ifdef print
        printf("%d -> ....\r\n", temp->data);
    #endif
}

typedef struct{
    int len;
    node *start;
}loop;

typedef struct{
    unsigned int a:1;

}bit_filed;


loop* is_with_loop(node *head)//返回环的入口点和环的长度
{
    int i = 0;
    node *slower =NULL, *faster = NULL;
    node *temp, *p1, *p2;
    element n_data;
    loop *loop_list;
    int count = 0, len = 0;

    bit_filed flag;
    flag.a = 0;
    temp = head;

    slower = head;
    faster = head;

     
    while(temp != NULL){
        if(temp != head)
            printf("%d\t", temp->data);

        slower = temp->next;
        faster = faster->next->next;

        if(faster == slower){
            printf("with loop\r\n");
            flag.a = 1;
            count++;
        }

        if(flag.a == 1){
            loop_list->len = len++;
        }
        if(count == 2){
            break;
            // return loop_list;
        }
        temp = temp->next;

    }
/* 找到环的入口 */
    p1 = head;
    p2 = head;
    temp = head;

    for(i = 0; i < loop_list->len; i++){
        p1 = p1->next;
    }
    while(temp != NULL){
            // if(temp != head)
            // printf("%d\t", temp->data);

        p1 = p1->next;
        p2 = temp->next;

        if(p1 == p2){
            printf("find loop start = %d\r\n", p1->data);
            return loop_list;
        }
        
        temp = temp->next;

    }

    return NULL;

}

void list_traverse(node *head)//遍历整个链表
{
    int i = 0;
    node *temp;
    element n_data;
    temp = head->next;

    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;    
    }

}

int main()
{
    node head;
    int i;

    loop *loop_list =NULL;
    // head_insert(&head, 5);

    // list_traverse(&head);

    with_looplist(&head);
    loop_list = is_with_loop(&head);
    printf("\r\nlength =%d", loop_list->len);
}