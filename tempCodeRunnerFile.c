#include<stdio.h>
typedef struct {
    char Name[100];
    int Roll;
    int marks;
    int fee_paid;
} stu;

int main() {
    stu list[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter Name of Student %d: ", i + 1);
        gets(list[i].Name);
        printf("Enter Roll no of student %d: ", i + 1);
        scanf("%d", &list[i].Roll);
        printf("Enter Marks of student %d: ", i + 1);
        scanf("%d", &list[i].marks);
        printf("Enter Fee paid of student %d: ", i + 1);
        scanf("%d", &list[i].fee_paid);
    }
    return 0;
   }