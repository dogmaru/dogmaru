#include <stdio.h>
#include <stdlib.h>
#include "DBDLinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));

	plist->head->prev = NULL;
	plist->head->next = plist->tail;

	plist->tail->next = NULL;
	plist->tail->prev = plist->head;

	plist->numOfData = 0;
}

void LInsert(List * plist, Data data) 
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = plist->tail->prev;
	plist->tail->prev->next = newNode;

	newNode->next = plist->tail;
	plist->tail->prev = newNode;

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if(plist->head->next == plist->tail)
		return FALSE;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if(plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LPrevious(List * plist, Data * pdata)
{
	if(plist->cur->next == plist->tail)
		return FALSE;
		
	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	return TRUE;
 } 

int LCount(List * plist)
{
	return plist->numOfData;
}

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	// 3개의 데이터 저장 ///////
	LInsert(&list, 2);
	LInsert(&list, 4);
	LInsert(&list, 8);

	// 저장된 데이터의 조회 ///////
	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		//// 오른쪽 노드로 이동하며 데이터 조회(오른쪽 끝 마지막 데이터까지 출력) 
		while(LNext(&list, &data)) 
			printf("%d ", data);
			 
		printf("\n");
	}

	return 0;
}
