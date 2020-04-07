#include "People.h" //People 型のため読み込み？

void InputPeople(People *data) {
    printf("name...");
    scanf("%s", data->name);
    printf("age...");
    scanf("%d", &data->age); //この & は ageに掛かる
    printf("sex type 1 or 2");
    scanf("%d", &data->sex);
    putchar('\n');
    return;
}

void ShowPeople(People data) {
    char sex[50];
    switch(data.sex) {
        case 1:
            strcpy(sex, "MALE");
            break;
        case 2:
            strcpy(sex, "FEMALE");
            break;
    }

    printf("%s %d %s", data.name, data.age, sex);
}
