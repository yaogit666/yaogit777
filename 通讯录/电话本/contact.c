#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	pc->data=(PeoInfo*)malloc(3 * sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact::malloc()");
		exit(EXIT_FAILURE);
	}
	pc->capacity = 3;
	LoadContact(pc);
}
void ExitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	pc->capacity = 0;
	free(pc->data);
	pc->data = NULL;
}
void AddContact(Contact* pc)
{
	assert(pc);
	if (CheckCapacity(pc) == 0)
	{
		printf("增容失败，无法添加");
			return;
	}
	printf("请输入姓名:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:>");
	scanf("%s", &(pc->data[pc->sz].sex));
	printf("请输入电话:>");
	scanf("%s", &(pc->data[pc->sz].tele));
	pc->sz++;
	printf("添加成功\n");
}
void ShowContact(Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%10s\t%5s\t%5s\t%12s\t\n", "姓名", "年龄", "性别", "电话号码");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%10s\t%5d\t%5s\t%12s\t\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele);
	}
}
void DelContact(Contact* pc)
{
	int i = 0;
	if (pc->sz == 0)
	{
		printf("没得删\n");
		return;
	}
	int p = FindName(pc);
	if (p == -1)
	{
		printf("删除的人不存在\n");
		return;
	}
	else
	{
		for (i = p; i < pc->sz; i++)
		{
			pc->data[i] = pc->data[i + 1];
			pc->sz--;
		}
	}


}
void SearchConttact(Contact* pc)
{
	int p = FindName(pc);
	if (p == -1)
	{
		printf("没有此人信息\n");
	}
	else
	{
		printf("%10s\t%5s\t%5s\t%12s\t\n", "姓名", "年龄", "性别", "电话号码");
		printf("%10s\t%5d\t%5s\t%12s\t\n", pc->data[p].name,pc->data[p].age, pc->data[p].sex, pc->data[p].tele);
	}
}
void ModifyContact(Contact* pc)
{
	int p = FindName(pc);
	if (p == -1)
	{
		printf("没有此人信息\n");
	}
	else
	{
		printf("请修改年龄:>");
		scanf("%d", &(pc->data[p].age));
		printf("请修改性别:>");
		scanf("%s", &(pc->data[p].sex));
		printf("请修电话:>");
		scanf("%s", &(pc->data[p].tele));
		printf("修改成功\n");
	}
}
int CheckCapacity(Contact* pc)
{
	assert(pc);
	if (pc->capacity == pc->sz)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += 2;
			printf("增容成功\n");
			return 1;
		}
		return 0;
	}
}
void EmptyContact(Contact* pc)
{
	pc->sz = 0;
	free(pc->data);
	pc->data = NULL;
}

int NameMove(void* p1, void* p2)
{
	return strcmp(((PeoInfo*)p1)->name, ((PeoInfo*)p2)->name);
}
void SortContact(Contact* pc)
{
	qsort(pc->data, pc->sz, sizeof(pc->data[0]), NameMove);
	printf("排序成功\n");
	ShowContact(pc);
}
int FindName(Contact* pc)
{
	char arr[NAME_MAX] = {0};
	printf("请输入姓名");
	scanf("%s", arr);
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, arr) == 0)
		{
			return i;
		}
	}
	return -1;
}
void LoadContact(Contact* pc)
{
	FILE* pf = fopen("contact.data", "rb");
	PeoInfo tmp = { 0 };
	if (pf == NULL)
	{
		perror("LoadContact::fopen");
		return;
	}
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		CheckCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	fclose(pf);
	pf = NULL;
}
void SaveContact(Contact* pc)
{
	FILE* pf = fopen("contact.data", "wb");
	if (pf == NULL)
	{
		perror("SaveContact::fopen");
		return;
	}
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data, sizeof(PeoInfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}