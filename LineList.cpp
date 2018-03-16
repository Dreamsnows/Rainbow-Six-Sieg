#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define Error -1
#define ERROR NULL
typedef char ElementType;
typedef struct LNode * PtrToLNode;
struct LNode{
	ElementType Data;
	PtrToLNode next;
}; 
typedef PtrToLNode Position;
typedef PtrToLNode List;
List MakeEmpty()
{
	List L;
	L=(List)malloc(sizeof(struct LNode));
	L->next=NULL;
	return L;
} 
int Length(List L)//链表长度 
{
	Position p;
	int cnt=0;
	p=L;
	while(p)
	{
		p=p->next;
		cnt++;
	}
	printf("表长度:%d",cnt);
	return cnt;
}
ElementType FindKth(List L, int K)//按位序查找 
{
	Position p;
	int cnt=1;
	p=L;
	while(p&&cnt<K)
	{
		p=p->next;
		cnt++;
	}
	if((cnt==K)&&p)
		return p->Data;
	else
		return Error;
}
Position Find(List L, ElementType X)//按值查找 
{
	Position p=L;
	while(p&&p->Data!=X)
		p=p->next;
	if(p)
		return p;
	else
		return ERROR;
}
bool Insert(List L, ElementType X, int i)//插入 
{
	Position tmp,pre;
	int cnt=0;
	pre=L;
	while(pre&&cnt<i-1)
	{
		pre=pre->next;
		cnt++;
	}
	if(pre==NULL||cnt!=i-1)
	{
		printf("插入位置参数错误\n");
		return false;
	}
	else
	{
		tmp=(Position)malloc(sizeof(struct LNode));
		tmp->Data==X;
		tmp->next=pre->next;
		pre->next=tmp;
		return true;
	}
}
bool Delete(List L, int i)
{
	Position tmp,pre;
	int cnt=0;
	pre=L;
	while(pre&&cnt<i-1)
	{
		pre=pre->next;
		cnt++;
	}
	if(pre==NULL||cnt!=i-1||pre->next==NULL)
	{
		printf("删除位置参数错误\n");
		return false;
	}
	else
	{
		tmp=pre->next;
		pre->next=tmp->next;
		free(tmp);
		return true;
	}
}
void DispList(List L)
{
	
}
int main()
{
	List L;
	int sele;
	int a,b;
	sele=1;
	while(sele)
	{
		system("cls");
		printf("**************** Main ****************\n");
		printf("*            1-----建表              *\n");
		printf("*            2-----插入              *\n");
		printf("*            3-----删除              *\n");
		printf("*            4-----显示              *\n");
		printf("*            5---按位序查找          *\n");
		printf("*            6---按值查找            *\n");
		printf("*            7---求表长             *\n");
		printf("*            0-----返回              *\n");
		printf("**************************************!\n");
		printf("请选择菜单号（0-7）:");
		scanf("%d",&sele);
		switch(sele)
		{
			case 1: MakeEmpty();break;
			case 2: printf("请输入要插入的数字:");
					scanf("%d",&a);
					printf("此数字要插入到第几个位置:");
					scanf("%d",&b);
					Insert(L,a,b);
					break;
			case 3: printf("请输入要删除的位置:");
					scanf("%d\n",&a);
					Delete(L,a);
					break;
			case 4: DispList(L);break;
			case 5: printf("请输入要查找第几位序的值:");
					scanf("%d\n",&a);
					FindKth(L,a);
					break;
			case 6: printf("请输入要查找位置的值:");
					scanf("%d\n",&a);
					Find(L,a);
					break;
			case 7: Length(L);break;
			default:exit(0); 
		}
	}	
}
