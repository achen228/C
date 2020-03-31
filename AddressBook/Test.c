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
