#include<stdio.h>
#include<string.h>

const int PERSON_LEN = 3;
const char NAME_ARR[3][50] = {"TARO", "HANAKO", "JIRO"};
const int AGE_ARR[] = {10, 20, 30};
const char SEX_ARR[] = {'m', 'f', 'm'};

typedef struct {
    char name[50];
    int age;
    char sex;
} person;

void input(person *data, int i);
void output(person data);

int main(void) {
    person data[PERSON_LEN];
    int i;

    for(i=0; i<PERSON_LEN; i++) input(&data[i], i);
    for(i=0; i<PERSON_LEN; i++) output(data[i]);
    return 0;
}

void input(person *data, int i) {
    strcpy(data->name, NAME_ARR[i]);
    data->age = AGE_ARR[i];
    data->sex = SEX_ARR[i];
    return;
}

void output(person data) {
    printf("[person] name:%s age:%d sex:%c\n", data.name, data.age, data.sex);
    return;
}
