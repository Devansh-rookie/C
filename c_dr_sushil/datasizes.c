#include<stdio.h>

void write_in_file(){
    FILE *fp;
    fp = fopen("datasize.txt","w");
    fprintf(fp,"Data Type\t\t\t\t\tSize\n");
    fprintf(fp,"char\t\t\t\t\t\t%d\n",sizeof(char));
    fprintf(fp,"unsigned char\t\t\t\t%d\n",sizeof(unsigned char));
    fprintf(fp,"short int\t\t\t\t\t%d\n",sizeof(short int));
    fprintf(fp,"unsigned short int\t\t\t%d\n",sizeof(unsigned short int));
    fprintf(fp,"int\t\t\t\t\t\t\t%d\n",sizeof(int));
    fprintf(fp,"unsigned int\t\t\t\t%d\n",sizeof(unsigned int));
    fprintf(fp,"long int\t\t\t\t\t%d\n",sizeof(long int));
    fprintf(fp,"unsigned long int\t\t\t%d\n",sizeof(unsigned long int));
    fprintf(fp,"float\t\t\t\t\t\t%d\n",sizeof(float));
    fprintf(fp,"double\t\t\t\t\t\t%d\n",sizeof(double));
    fprintf(fp,"long double\t\t\t\t\t%d\n",sizeof(long double));
    fclose(fp);
}

int main(){
    write_in_file();
    return 0;
}
