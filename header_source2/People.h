#ifndef _INCLUDE_PEOPLE_
#define _INCLUDE_PEOPLE_

#include<stdio.h>
#include<string.h>

typedef struct {
    char name[50];
    int age;
    int sex;
} People;

extern void InputPeople(People *data);
extern void ShowPeople(People data);

#endif
