#include<stdio.h>

int c=0;
int smallCap, medCap, largeCap, measure;
void waterJug(int A, int B, int C){ // A = small, B= Medium, C = large
    if(A== measure){// || A== measure || B== measure
    // if we only wan to measure with C if all then use the OR which is commented out.
        printf("Done\n");
        c++;
        printf("\nRequired Amount is in A.\n");
        return;
    }
    else if(B== measure){// || A== measure || B== measure
    // if we only wan to measure with C if all then use the OR which is commented out.
        printf("Done\n");
        c++;
        printf("\nRequired Amount is in B.\n");
        return;
    }
    else if(C== measure){// || A== measure || B== measure
    // if we only wan to measure with C if all then use the OR which is commented out.
        printf("Done\n");
        c++;
        printf("\nRequired Amount is in C.\n");
        return;
    }
    if(A == 0 && B ==0){
        printf("C to A: %d  %d  %d\n",smallCap,B,C- smallCap);
        c++;
        waterJug(smallCap, B, C-smallCap);
    }
    // Full Tub is also necessary 
    else if(A == smallCap){
        if(A+B>medCap){
            printf("A to B: %d  %d  %d\n",A-(medCap-B),medCap,C);
            c++;
            waterJug(A-(medCap-B),medCap,C);
        }
        else{
            printf("A to B: %d  %d  %d\n",0,A+B,C);
            c++;
            waterJug(0,A+B,C);
        }
    }

    else if(B == medCap){
        printf("B to C: %d  %d  %d\n",A,0,B+C);
        c++;
        waterJug(A,0,B+C);
    }

    else if (A>=B)
    {
        if(A+B>medCap){
            printf("A to B: %d  %d  %d\n",A-(medCap-B),medCap,C);
            c++;
            waterJug(A-(medCap-B),medCap,C);
        }
        else{
            printf("A to B: %d  %d  %d\n",0,A+B,C);
            c++;
            waterJug(0,A+B,C);
        }
    }
    else if(B>C){
        printf("B to C: %d  %d  %d\n",A,0,B+C);
        c++;
        waterJug(A,0,B+C);
    }
    else if(C>=A){
        if(C+A>smallCap){
            printf("C to A: %d  %d  %d\n",smallCap,B,C-(smallCap-A));
            c++;
            waterJug(smallCap,B,C-(smallCap-A));
        }
        else{
            printf("C to A: %d  %d  %d\n",A+C,B,0);
            c++;
            waterJug(A+C,B,0);
        }
    }
}

int main(){
    int n;
    printf("What is n: ");
    scanf("%d", &n);

    printf("What is the value to measure: ");
    scanf("%d", &measure);

    smallCap = 2*n+1;
    medCap=2*n+3;
    largeCap = 4*n+4;
    printf("Small(A): %d\nMedium(B): %d\nLarge(C): %d\n", smallCap, medCap, largeCap);
    // make a new case where measure is a multiple of small jug e.g. for n=2 measure 8 and 10 maybe?? 
    waterJug(0, 0, 4*n+4);
    printf("No. of steps required: %d\n", c-1);
    return 0;
}
