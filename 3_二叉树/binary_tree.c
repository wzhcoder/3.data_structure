#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   
#include "math.h"  
#include "time.h"

#define ok      0
#define error  -1

struct binary_tree_node{
    char data;
    struct binary_tree_node *lchild, *rchild;
};
typedef struct binary_tree_node binary_tree_node;

int i = 0;
binary_tree_node *node;

char str[] = "AB#D##C##";//前序遍历
// char string[] = "AB###";


void create_binary_tree(binary_tree_node **node, char *string)//前序遍历创建二叉树
{

    if(string[i++] == '#'){
        *node = NULL;
		// printf("#");
        // return;
    }else{
        *node = (binary_tree_node *)malloc(sizeof(binary_tree_node));
        (*node)->data = string[i-1];
		// printf("\t%x\r\n", *node);
		// printf("%c", (*node)->data);
        create_binary_tree(&(*node)->lchild, string);
        create_binary_tree(&(*node)->rchild, string);
    }
}

void preorder_traverse(binary_tree_node **node)  //前序遍历
{
    if(*node){//节点非空
        printf("%c\r\n",(*node)->data);
        preorder_traverse(&(*node)->lchild);
        preorder_traverse(&(*node)->rchild);
    }
}

void inorder_traverse(binary_tree_node **node)   //中序遍历
{
    if(*node){//节点非空
        preorder_traverse(&(*node)->lchild);
        printf("%c\r\n",(*node)->data);
        preorder_traverse(&(*node)->rchild);
    }
}

void postorder_traverse(binary_tree_node **node)   //后序遍历
{
    if(*node){//节点非空
        postorder_traverse(&(*node)->lchild);
        postorder_traverse(&(*node)->rchild);
        printf("%c\r\n",(*node)->data);
    }
}

void test()
{
	char test[8180*1024];
	test[8192] = 23;
	printf("%d\r\n",test[8192]);
}

static binary_tree_node *root;

int main(void)
{
    create_binary_tree(&root, str);
	// printf("root = %x \r\n",&root);
	// printf("root->l = %x \r\n",root->lchild);
	// printf("root->r = %x \r\n",root->rchild);
	
    // preorder_traverse(&root);
    postorder_traverse(&root);
}




// #define OK 1
// #define ERROR 0
// #define TRUE 1
// #define FALSE 0

// #define MAXSIZE 100 /* 存储空间初始分配量 */

// typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

// /* 用于构造二叉树********************************** */
// int index=1;
// typedef char String[24]; /*  0号单元存放串的长度 */
// typedef char TElemType;

// String str;



// typedef struct BiTNode  /* 结点结构 */
// {
//    TElemType data;		/* 结点数据 */
//    struct BiTNode *lchild,*rchild; /* 左右孩子指针 */
// }BiTNode,*BiTree;


// TElemType Nil=' '; /* 字符型以空格符为空 */

// Status StrAssign(String T,char *chars)
// { 
// 	int i;
    
// 	if(strlen(chars)>MAXSIZE)
// 		return ERROR;
// 	else
// 	{
// 		T[0]=strlen(chars);
// 		for(i=1;i<=T[0];i++)
// 			T[i]=*(chars+i-1);
// 		return OK;
// 	}
// }



// Status visit(TElemType e)
// {
// 	printf("%c ",e);
// 	return OK;
// }




// /* 构造空二叉树T */
// Status InitBiTree(BiTree *T)
// { 
// 	*T=NULL;
// 	return OK;
// }

// /* 初始条件: 二叉树T存在。操作结果: 销毁二叉树T */
// void DestroyBiTree(BiTree *T)
// { 
// 	if(*T) 
// 	{
// 		if((*T)->lchild) /* 有左孩子 */
// 			DestroyBiTree(&(*T)->lchild); /* 销毁左孩子子树 */
// 		if((*T)->rchild) /* 有右孩子 */
// 			DestroyBiTree(&(*T)->rchild); /* 销毁右孩子子树 */
// 		free(*T); /* 释放根结点 */
// 		*T=NULL; /* 空指针赋0 */
// 	}
// }

// /* 按前序输入二叉树中结点的值（一个字符） */
// /* #表示空树，构造二叉链表表示二叉树T。 */
// void CreateBiTree(BiTree *T)
// { 
// 	TElemType ch;
	
// 	/* scanf("%c",&ch); */
// 	ch=str[index++];

// 	if(ch=='#') 
// 		*T=NULL;
// 	else
// 	{
// 		*T=(BiTree)malloc(sizeof(BiTNode));
// 		if(!*T)
// 			exit(OVERFLOW);
// 		(*T)->data=ch; /* 生成根结点 */
// 		CreateBiTree(&(*T)->lchild); /* 构造左子树 */
// 		CreateBiTree(&(*T)->rchild); /* 构造右子树 */
// 	}
//  }

// /* 初始条件: 二叉树T存在 */
// /* 操作结果: 若T为空二叉树,则返回TRUE,否则FALSE */
// Status BiTreeEmpty(BiTree T)
// { 
// 	if(T)
// 		return FALSE;
// 	else
// 		return TRUE;
// }

// #define ClearBiTree DestroyBiTree

// /* 初始条件: 二叉树T存在。操作结果: 返回T的深度 */
// int BiTreeDepth(BiTree T)
// {
// 	int i,j;
// 	if(!T)
// 		return 0;
// 	if(T->lchild)
// 		i=BiTreeDepth(T->lchild);
// 	else
// 		i=0;
// 	if(T->rchild)
// 		j=BiTreeDepth(T->rchild);
// 	else
// 		j=0;
// 	return i>j?i+1:j+1;
// }

// /* 初始条件: 二叉树T存在。操作结果: 返回T的根 */
// TElemType Root(BiTree T)
// { 
// 	if(BiTreeEmpty(T))
// 		return Nil;
// 	else
// 		return T->data;
// }

// /* 初始条件: 二叉树T存在，p指向T中某个结点 */
// /* 操作结果: 返回p所指结点的值 */
// TElemType Value(BiTree p)
// {
// 	return p->data;
// }

// /* 给p所指结点赋值为value */
// void Assign(BiTree p,TElemType value)
// {
// 	p->data=value;
// }

// /* 初始条件: 二叉树T存在 */
// /* 操作结果: 前序递归遍历T */
// void PreOrderTraverse(BiTree T)
// { 
// 	if(T==NULL)
// 		return;
// 	printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
// 	PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
// 	PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
// }

// /* 初始条件: 二叉树T存在 */
// /* 操作结果: 中序递归遍历T */
// void InOrderTraverse(BiTree T)
// { 
// 	if(T==NULL)
// 		return;
// 	InOrderTraverse(T->lchild); /* 中序遍历左子树 */
// 	printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
// 	InOrderTraverse(T->rchild); /* 最后中序遍历右子树 */
// }

// in(a)
// {
//     in(a->l)
//     {
//         in(a->l->l)
//         print b
//         in(a->l->r)
//         {
//             in(a->l->r->l)
//             print d
//             in(a->l->r->r)
//         }
//     }
//     print a
//     in(a->r){
//         in(a->l)
//         print c
//         in(a->r)

//     }
// }

// /* 初始条件: 二叉树T存在 */
// /* 操作结果: 后序递归遍历T */
// void PostOrderTraverse(BiTree T)
// {
// 	if(T==NULL)
// 		return;
// 	PostOrderTraverse(T->lchild); /* 先后序遍历左子树  */
// 	PostOrderTraverse(T->rchild); /* 再后序遍历右子树  */
// 	printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
// }


// int main()
// {
// 	int i;
// 	BiTree T;
// 	TElemType e1;
// 	InitBiTree(&T);

	
// 	StrAssign(str,"ABDH#K###E##CFI###G#J##");

// 	CreateBiTree(&T);

// 	printf("构造空二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
// 	e1=Root(T);
// 	printf("二叉树的根为: %c\n",e1);

// 	printf("\n前序遍历二叉树:");
// 	PreOrderTraverse(T);
// 	printf("\n中序遍历二叉树:");
// 	InOrderTraverse(T);
// 	printf("\n后序遍历二叉树:");
// 	PostOrderTraverse(T);
// 	ClearBiTree(&T);
// 	printf("\n清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
// 	i=Root(T);
// 	if(!i)
// 		printf("树空，无根\n");
	
// 	return 0;
// }

