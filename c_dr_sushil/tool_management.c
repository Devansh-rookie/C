#include<stdio.h>
#include<stdbool.h>

typedef struct hardware
{
    int record;
    char tool_name[100];
    int qty;
    float price;
} hardware;

hardware arr[100];
int n=0;

void input(){
    char ch;
    while(true){
        printf("Input your choice, 'q' to exit and any other to continue");
        scanf("%c",&ch);
        if(ch!='q'){
            printf("Record No: ");
            scanf("%d",&arr[n].record);
            printf("Tool Name: ");
            scanf("%[^\n]s",arr[n].tool_name);
            printf("Quantity: ");
            scanf("%d",&arr[n].qty);
            printf("Cost: ");
            scanf("%f",&arr[n].price);
            n++;
        }
        else break;
    }
}

void delete(){
    printf("What record number to delete: ");
    int key;
    scanf("%d",&key);
    int i;
    for(i=0;i<n;i++){
        if(arr[i].record==key){
            break;
        }
    }

    if (i==n){
        printf("Record not found.");
        return;
    }
    for(int j=i;j<n-1;j++){
        arr[j]=arr[j+1];
    }
    n--;
}

void dump_in_file(){
    FILE *fp;
    fp = fopen("hardware.txt","w");
    for(int i=0;i<n;i++){
        fprintf(fp, "%d,",arr[i].record);
        fprintf(fp, "%s,",arr[i].tool_name);
        fprintf(fp, "%d,",arr[i].qty);
        fprintf(fp, "%f,",arr[i].price);
        fprintf(fp,"\n");
    }
    printf("Successfully dump in file.");
}

void update(){
    printf("What record number to update: ");
    int key;
    scanf("%d",&key);
    int i;
    for(i=0;i<n;i++){
        if(arr[i].record==key){
            break;
        }
    }

    if (i==n){
        printf("Record not found.");
        return;
    }
    printf("What to update:\n");
    printf("1. Record\n2. Tool Name\n3. Quantity\n4. Price");
    int k;
    scanf("%d",&k);
    switch (k)
    {
    case 1:
        printf("What to add: ");
        scanf("%d",&arr[i].record);
        break;
    case 2:
        printf("What to add: ");
        scanf("%[^\n]s",arr[i].tool_name);
        break;
    case 3:
        printf("What to add: ");
        scanf("%d",&arr[i].qty);
        break;
    case 4:
        printf("What to add: ");
        scanf("%f",&arr[i].price);
        break;
    
    default:
        printf("Invalid Input.");
        break;
    }
}

int main(){
    
    int a;
    printf("Give your choice as a number:");
    b:
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        input();
        goto b;
        break;
    case 2:
        delete();
        goto b;
        break;
    case 3:
        dump_in_file();
        goto b;
    case 4:
        update();
        goto b;
    case 5:
        exit(0);
        goto b;
    default:
        printf("Give a valid input.");
        goto b;
        break;
    }
    return 0;
}
