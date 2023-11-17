#include<stdio.h>

int main(){
    int n,age,i;
    float cgpa;
    char name[100];

    FILE *file_pointer;

    file_pointer=fopen("student_data_file.txt","w");
    printf("How many students?");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("What is the name of the student?");
        scanf("%s",name);// array name itself is a pointer so no need to add ampersand to it to specify the address
        fprintf(file_pointer,"%s\t",name);

        printf("What is the age of the student?");
        scanf("%d",&age);
        fprintf(file_pointer,"%d\t",age);

        printf("What is the CGPA of the student?");
        scanf("%f",&cgpa);
        fprintf(file_pointer,"%f\t",cgpa);

        fprintf(file_pointer,"\n");
    }
    fclose(file_pointer);
    return 0;
}
