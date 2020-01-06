#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#endif

#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12

#define MAX 1000

typedef struct PeoInfo
{
	char name[NAME_MAX];
	short age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
}PeoInfo;


typedef struct Contact
{
	PeoInfo* data;//ָ��̬���ٵĴ洢�ռ�
	int sz;//��ǰ��Ч��Ϣ�ĸ���
	int capacity;//����
}Contact;

void InitContact(Contact* pc);
void ExitContact(Contact* pc);
void AddContact(Contact* pc);
void ShowContact(Contact* pc);
void DelContact(Contact* pc);
void ModifyContact(Contact* pc);
void EmptyContact(Contact* pc);
void SortContact(Contact* pc);
void SaveContact(Contact* pc);
void LoadContact(Contact* pc);


