#include<stdio.h>
#include "People.h"

int main(void) {
    People data;
    People *pdata;
    pdata = &data;
    InputPeople(pdata);
    ShowPeople(*pdata);
    return 0;
}
