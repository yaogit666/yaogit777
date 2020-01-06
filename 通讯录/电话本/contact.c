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
		printf("����ʧ�ܣ��޷����");
			return;
	}
	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�:>");
	scanf("%s", &(pc->data[pc->sz].sex));
	printf("������绰:>");
	scanf("%s", &(pc->data[pc->sz].tele));
	pc->sz++;
	printf("��ӳɹ�\n");
}
void ShowContact(Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%10s\t%5s\t%5s\t%12s\t\n", "����", "����", "�Ա�", "�绰����");
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
		printf("û��ɾ\n");
		return;
	}
	int p = FindName(pc);
	if (p == -1)
	{
		printf("ɾ�����˲�����\n");
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
		printf("û�д�����Ϣ\n");
	}
	else
	{
		printf("%10s\t%5s\t%5s\t%12s\t\n", "����", "����", "�Ա�", "�绰����");
		printf("%10s\t%5d\t%5s\t%12s\t\n", pc->data[p].name,pc->data[p].age, pc->data[p].sex, pc->data[p].tele);
	}
}
void ModifyContact(Contact* pc)
{
	int p = FindName(pc);
	if (p == -1)
	{
		printf("û�д�����Ϣ\n");
	}
	else
	{
		printf("���޸�����:>");
		scanf("%d", &(pc->data[p].age));
		printf("���޸��Ա�:>");
		scanf("%s", &(pc->data[p].sex));
		printf("���޵绰:>");
		scanf("%s", &(pc->data[p].tele));
		printf("�޸ĳɹ�\n");
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
			printf("���ݳɹ�\n");
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
	printf("����ɹ�\n");
	ShowContact(pc);
}
int FindName(Contact* pc)
{
	char arr[NAME_MAX] = {0};
	printf("����������");
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