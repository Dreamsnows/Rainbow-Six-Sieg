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
int Length(List L)//������ 
{
	Position p;
	int cnt=0;
	p=L;
	while(p)
	{
		p=p->next;
		cnt++;
	}
	printf("����:%d",cnt);
	return cnt;
}
ElementType FindKth(List L, int K)//��λ����� 
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
Position Find(List L, ElementType X)//��ֵ���� 
{
	Position p=L;
	while(p&&p->Data!=X)
		p=p->next;
	if(p)
		return p;
	else
		return ERROR;
}
bool Insert(List L, ElementType X, int i)//���� 
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
		printf("����λ�ò�������\n");
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
		printf("ɾ��λ�ò�������\n");
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
		printf("*            1-----����              *\n");
		printf("*            2-----����              *\n");
		printf("*            3-----ɾ��              *\n");
		printf("*            4-----��ʾ              *\n");
		printf("*            5---��λ�����          *\n");
		printf("*            6---��ֵ����            *\n");
		printf("*            7---���             *\n");
		printf("*            0-----����              *\n");
		printf("**************************************!\n");
		printf("��ѡ��˵��ţ�0-7��:");
		scanf("%d",&sele);
		switch(sele)
		{
			case 1: MakeEmpty();break;
			case 2: printf("������Ҫ���������:");
					scanf("%d",&a);
					printf("������Ҫ���뵽�ڼ���λ��:");
					scanf("%d",&b);
					Insert(L,a,b);
					break;
			case 3: printf("������Ҫɾ����λ��:");
					scanf("%d\n",&a);
					Delete(L,a);
					break;
			case 4: DispList(L);break;
			case 5: printf("������Ҫ���ҵڼ�λ���ֵ:");
					scanf("%d\n",&a);
					FindKth(L,a);
					break;
			case 6: printf("������Ҫ����λ�õ�ֵ:");
					scanf("%d\n",&a);
					Find(L,a);
					break;
			case 7: Length(L);break;
			default:exit(0); 
		}
	}	
}
