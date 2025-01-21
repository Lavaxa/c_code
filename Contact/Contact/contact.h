#pragma once
#include <stdio.h>
#define MAX 100
typedef struct PeoInfo
{
	char name[20];
	int age;
	char sex[10];
	char tele[12];
	char addr[30];
}PeoInfo;

typedef struct Contact
{
	PeoInfo data[MAX];
	int count;
}Contact;

void InitContact(Contact* pc);

void AddContact(Contact* pc);

void ShowContact(Contact* pc);

void DelContact(Contact* pc);

void ModifyContact(Contact* pc);

void SearchContact(Contact* pc);

void SortContact(Contact* pc);


