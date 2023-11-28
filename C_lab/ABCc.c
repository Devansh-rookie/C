#include<stdio.h>
// #include<conio.h>
typedef struct student{
    char Name[100];
    int Roll;
    int marks;
    int fee_paid;
} stu;

int main() {
    stu list[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter Name of Student %d: \n", i + 1);
        scanf(" %[^\n]s",&list[i].Name);
        // gets(list[i].Name);
        // getch();
        printf("Enter Roll no of student %d: \n", i + 1);
        scanf("%d", &list[i].Roll);
        printf("Enter Marks of student %d: \n", i + 1);
        scanf("%d", &list[i].marks);
        printf("Enter Fee paid of student %d: \n", i + 1);
        scanf("%d", &list[i].fee_paid);
    }
    return 0;
   }