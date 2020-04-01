#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct PersonInfor
{
	char name[1024];
	char phone[1024];
	char company[1024];
	char address[1024];
} PersonInfor;

typedef struct AddressBook
{
	PersonInfor* person_infors;
	int capacity; // 容量
	int size; // 有效联系人
} AddressBook;

AddressBook g_addr_book;

int Menu()
{
	printf("******************************\n");
	printf("       1.添加\n");
	printf("       2.删除\n");
	printf("       3.查询\n");
	printf("       4.修改\n");
	printf("       5.排序\n");
	printf("       6.打印全部\n");
	printf("       7.清空全部\n");
	printf("       0.退出\n");
	printf("******************************\n");
	printf("输入选择：");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Init(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	addr_book->size = 0;
	addr_book->capacity = 10;
	addr_book->person_infors = (PersonInfor*)malloc(
		sizeof(PersonInfor) * addr_book->capacity);
}


int main()
{
	typedef void(*PFunc)(AddressBook*);
	PFunc arr[] = {
		AddPersonInfor,
		DelPersonInfor,
		FindPersonInfor,
		ModPersonInfor,
		SortPersonInfor,
		PrintPersonInfor,
		ClearPersonInfor,
	};
	Init(&g_addr_book);

	while (1)
	{
		int choice = Menu();
		if (choice < 0 || choice > sizeof(arr) / sizeof(arr[0]))
		{
			printf("输入错误，请重新输入！\n");
			system("pause");
			system("cls");
			continue;
		}
		if (choice == 0)
		{
			system("cls");
			printf("GoodBye!\n");
			break;
		}
		arr[choice - 1](&g_addr_book);
	}
	return 0;
}
