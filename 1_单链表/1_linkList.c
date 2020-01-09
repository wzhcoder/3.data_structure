#include "my_types.h"
#include "stdlib.h"
struct _node{

    int  data;
    struct _node *next;
};

struct fuck{

    struct fuck *you;
   
};

typedef struct _node  node; //节点类型为 node

node *head_insert(u32 num);
node *taile_insert(u32 num);
void list_delete(node *head);
void list_traverse(node *head);

node *search_node(node *head, u32 i, u32 num);
int node_insert(node *head,u32 i,int data,u32 num);
int node_delete(node *head,u32 i,u32 num);

static node *head ;


int main(int argc, char *argv[])
{
    
    u32 i = 3;//第几个节点的数据
    u32 num = 15; //新建的链表中节点的个数


    head = taile_insert(num);
    // printf("第%d个节点的数据为%d\r\n", i, search_node(head, i, num)->data);
    printf("\r\n");

    node_insert(head, 5, 3434, num);
    // printf("%d\r\n",search_node(head, 6, num+1)->data);
    list_traverse(head);


}


node *taile_insert(u32 num)//新的节点从上一个创建的节点的尾部插入，所有新的节点都在头结点的后面,返回头结点
{
    node *p;
    node *temp;
    u32 i = 0;
    node *head;
    srand(time(0));

    head = (node*)malloc(sizeof(node));
    head->data = num;
    head->next = NULL;
    temp = head;

    printf("新建的链表为：\r\n");
    for(i = 0; i<num; i++){
        p = (node*)malloc(sizeof(node));
        p->data = rand()%100;
        temp->next = p;
        temp = p;
        printf("第%d个节点：%d\t", i+1, p->data);
    }
    printf("\r\n");
    temp->next = NULL;

    return head;
    
}

void list_traverse(node *head)
{
    
    node *temp;
    u32 i = 1;

    temp = head;
    while(temp){
        temp = temp->next;
        if(temp){
            printf("第%d个节点：%d\t", i, temp->data);
        }
        i++;
    }
}

node *search_node(node *head, u32 i, u32 num)//查找第i个节点,（从头结点之后的第一个节点算起）返回第i个节点
{
    node *p;
    u32 count = 1;
    if(i <= 0 ){
        printf("i只能大于0");
        return ;
    }else if(i > num){
        printf("超出范围");
        return ;
    }


    p = head->next;//从第一个结点开始查

    while(count < i){

        p = p->next;
        count ++;
    }
    return p;
}

int node_insert(node *head,u32 i,int data,u32 num)//在第i个节点后插入新节点
{
    node *p;
    node *new_p;
    u32 count = 1;

    if(i <= 0 ){
        printf("i只能大于0");
        return -1;
    }else if(i > num){
        printf("超出范围");
        return -1;
    }
    
    p = head->next;//从第一个结点开始查
    while(count < i){
        p = p->next;
        count ++;
    }
   
    new_p = (node*)malloc(sizeof(node));
    new_p->data = data;
    new_p->next = p->next;
    p->next = new_p;

    return 0;
}

int node_delete(node *head,u32 i,u32 num)//删除第i个节点
{
    node *p;
    node *p_delete;
    u32 count = 1;

    if(i <= 0 ){
        printf("i只能大于0");
        return -1;
    }else if(i > num){
        printf("超出范围");
        return -1;
    }

    p = head->next;//从第一个结点开始查
    while(count < (i-1)){
        p = p->next;
        count ++;
    }
    p_delete = p->next;
    p->next = p_delete->next;
    free(p_delete);

    return 0;
}

void list_delete(node *head)
{
    node *temp;
    
    temp = head;
    while(temp != NULL){
        free(temp);
        temp = temp->next;
    }
    head->next = (node*)NULL;
}




node *head_insert(u32 num)//头插法,从头节点后插入num个节点，新的节点从上一个创建的节点的头部插入，所有的新的节点都在头节点的后面
{
    u32 i = 0;
    node *p;
    node *head;

    srand(time(0));
    printf("新建的链表为：\r\n");
    head = (node*)malloc(sizeof(node));
    head->data = num;
    head->next = (node*)NULL;
    // printf("node size = %ld\r\n",sizeof(node));

    for(i = 0; i<num; i++){
        p = (node*)malloc(sizeof(node)); //在内存中创造一个新节点，指针p（即新节点p）存放这个新节点的地址
        p->data = rand()%100;
        p->next = head->next;
        head->next = p;  
        
        printf("第%d个节点：%d\t", num-i, p->data);
    }
    printf("\r\n");
}
