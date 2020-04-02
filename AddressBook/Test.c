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


void Realloc(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	addr_book->capacity = addr_book->capacity * 2;
	PersonInfor* old_infors = addr_book->person_infors;
	addr_book->person_infors = (PersonInfor*)malloc(
		sizeof(PersonInfor) * addr_book->capacity);
	// 搬运数据
	for (int i = 0; i < addr_book->size; ++i)
	{
		addr_book->person_infors[i] = old_infors[i];
	}
	free(old_infors);
}

void AddPersonInfor(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	printf("添加联系人\n");
	if (addr_book->size >= addr_book->capacity)
	{
		Realloc(addr_book); // 扩容
	}

	printf("请输入联系人姓名:");
	//scanf("%s", addr_book->person_infors[addr_book->size].name);
	PersonInfor* p = &addr_book->person_infors[addr_book->size];
	scanf("%s", p->name);

	printf("请输入联系人电话:");
	scanf("%s", p->phone);

	printf("请输入联系人公司:");
	scanf("%s", p->company);

	printf("请输入联系人地址:");
	scanf("%s", p->address);

	++addr_book->size;
	printf("添加成功!\n");
	system("pause");
	system("cls");
}

void DelPersonInfor(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	printf("删除联系人!\n");
	printf("输入需要删除的联系人序号:");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addr_book->size)
	{
		printf("输入序号错误！删除失败!\n");
		system("pause");
		system("cls");
		return;
	}

	PersonInfor* p = &addr_book->person_infors[id];
	printf("您要删除的联系人是[%d] %s, 输入Y表示确认:", id, p->name);
	char cmd[1024] = { 0 };
	scanf("%s", cmd);
	if (strcmp(cmd, "Y") != 0)
	{
		printf("输入非Y, 取消删除操作!\n");
		system("pause");
		system("cls");
		return;
	}

	PersonInfor* from = &addr_book->person_infors[addr_book->size - 1];
	PersonInfor* to = &addr_book->person_infors[id];
	*to = *from;

	--addr_book->size;
	printf("删除成功!\n");
	system("pause");
	system("cls");
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
