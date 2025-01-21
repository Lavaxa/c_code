#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "contact.h"

void InitContact(Contact* pc)
{
	memset(pc->data, 0, sizeof(pc->data));
	pc->count = 0;
}

void AddContact(Contact* pc)
{
	if (pc->count == 100)
	{
		printf("ͨѶ¼����\n");
		return;
	}
	printf("��������->");
	scanf("%s", pc->data[pc->count].name);
	printf("��������->");
	scanf("%d", &(pc->data[pc->count].age));
	printf("�����Ա�->");
	scanf("%s", pc->data[pc->count].sex);
	printf("����绰->");
	scanf("%s", pc->data[pc->count].tele);
	printf("�����ַ->");
	scanf("%s", pc->data[pc->count].addr);
	printf("��ӳɹ�\n");
	pc->count++;
}

void ShowContact(Contact* pc)
{
	printf("%20s%10s%10s%15s%25s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		printf("%20s%10d%10s%15s%25s\n", pc->data[i].name,
			                             pc->data[i].age,
			                             pc->data[i].sex,
			                             pc->data[i].tele,
			                             pc->data[i].addr);
	}

}
int FindByName(Contact *pc , char name[])
{
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (0 == strcmp(name, pc->data[i].name))
		{
			return i;
		}
	}
	return -1;

}

void DelContact(Contact* pc)
{
	char name[20];
	int i = 0;
	printf("������Ҫɾ���˵�����");
	scanf("%s", &name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("��ϵ�˲�����\n");
		return;
	}
	else
	{
		for (i = ret; i < pc->count - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
	}
	printf("ɾ�����\n");
	pc->count--;
}

void ModifyContact(Contact* pc)
{
	char name[20];
	printf("������Ҫ�޸��˵�����");
	scanf("%s", &name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("��ϵ�˲�����\n");
		return;
	}
	else
	{
		printf("��������->");
		scanf("%s", pc->data[ret].name);
		printf("��������->");
		scanf("%d", &(pc->data[ret].age));
		printf("�����Ա�->");
		scanf("%s", pc->data[ret].sex);
		printf("����绰->");
		scanf("%s", pc->data[ret].tele);
		printf("�����ַ->");
		scanf("%s", pc->data[ret].addr);
		printf("�޸ĳɹ�\n");
	}
}
void SearchContact(Contact* pc)
{
	char name[20];
	printf("������Ҫ�����˵�����");
	scanf("%s", &name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("��ϵ�˲�����\n");
		return;
	}
	else
	{
		printf("%20s%10s%10s%15s%25s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%20s%10d%10s%15s%25s\n", pc->data[ret].name,
				pc->data[ret].age,
				pc->data[ret].sex,
				pc->data[ret].tele,
				pc->data[ret].addr);
	}
}

void SortContact(Contact* pc)
{
	int i = 0,j = 0;
	for (i = 0; i < pc->count - 1; i++)
	{
		for (j = i + 1; j < pc->count; j++)
		{
			if (pc->data[i].name[0] > pc->data[j].name[0])
			{
				PeoInfo tmp = pc->data[i];
				pc->data[i] = pc->data[j];
				pc->data[j] = tmp;
			}
		}
	}
	printf("����ɹ�\n");
}







