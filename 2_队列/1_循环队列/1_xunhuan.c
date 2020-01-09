#include "my_types.h"

#define ok       0
#define error   -1
#define queue_MaxSize  14
#define MaxSize        (queue_MaxSize+1)


struct _queue{
    int data[MaxSize];
    int front;
    int rear;
};

typedef struct _queue queue;

queue q;

void init_queue(queue *q)
{
    u32 i = 0;

    q->front = 0;
    q->rear = 0;
    for(i = 0; i< queue_MaxSize; i++){
        q->data[q->rear] = rand()%100; 
        printf("第%d个数为:%d \t", i+1,q->data[q->rear]);
        q->rear = (q->rear+1)%MaxSize;
    }
    printf("\r\n\r\n");
}

void queue_traverse(queue *q)
{
    u32 i = 0;
    u32 num = 0;
    u32 length;
    u32 front;

    length = queue_length(q);
    front = q->front;
    for(i =0; i < length; i++)
    {
        printf("第%d个数为:%d \t", i+1, q->data[front]);
        front = (front+1)% MaxSize;
    }

}

int queue_length(queue *q)
{   
    return (q->rear - q->front + MaxSize)% MaxSize;
}

int queue_in(queue *q, int data)
{
    if((q->rear+1)%MaxSize == q->front){//队列满
        return error;
    }else{
        q->data[q->rear] = data;
        q->rear = (q->rear+1)% MaxSize;
        return ok;
    }
}

int queue_out(queue *q, int *data_addr)
{
    if(q->rear == q->front){//队列空
        return error;
    }else{
        *data_addr = q->data[q->front];
        q->front = (q->front+1)% MaxSize;
        return ok;
    }
}

int main(void)
{
    queue q;
    int data;

    init_queue(&q);

    if(queue_out(&q, &data) == ok)
    {
        if(queue_in(&q, 23435) == error){
            return -1;
        }
    }
    
    queue_traverse(&q);

}