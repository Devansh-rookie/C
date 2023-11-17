#include<stdio.h>
#include<math.h>
// if we try to access a value more than that of the array
//say an array has 0,1,2 indices and we are trying to access
//3 then our program will give a runtime error because
//our compiler won't be able to check for such a mistake.
int gst_ques(){
    float item[3];
    for(int i=0; i<=2;i++){
        printf("Price of item %d is? ",i+1);
        scanf("%f",&item[i]);
        item[i]+=0.18*item[i];//changing the list/array here only
    }
    for(int i=0;i<=2;i++){
        printf("Price of item %d incl. GST is: %f\n",i+1,item[i]);
    }
    return 0;
}
int dec(){
    int marks[3]={1,2,3};
    int marks2[]={1,2,3};
    int marks3[3];
    marks3[0]=1;//all indices in the square brackets
    //all of these methods are correct
    return 0;
    }

int _2darrays(){
    //For 2 X 3 Matrix type of a thing
    //first sq bracket is the number of rows while the second one 
    //is the number of columns.
    int marks[2][3];// _ _ _ | _ _ _ type of a structure
    // another way of declaration of 2D arrays
    int array[][2]={{1,2},{3,4}}; 
    // A variable n can be used to let the number of rows.
    //number of columns/number of values has to be predefined while
    //number of rows can be left open ended. all should have same 
    //amount of columns.
    marks[0][0]=90;
    // at 0,0 index 90 marks basically first students 
    //marks in first subject
    marks[1][0]=91;// second student first subject.
    return 0;
}

int count_odd(){
    int n,i,j;
    int arr[n];

    printf("What are the number of values?: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("What is value number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    j=0;
    for(i=0;i<n;i++){
        if(arr[i]%2!=0){
            printf("%d is odd.\n",arr[i]);
            j++;
        }
    }
    printf("%d is the number of odd values",j);
    return 0;
}

int reverse(){
    int n,i,temp;
    int arr[n];
    printf("What are the number of values?: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("What is value number %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n/2;i++){//the loop is from 0 to n/2-1 this is 
    //to avoid reverse the array twice which would result
    //in the same array. is even would work perfect for odd
    //since its int datatype it would result in 5/2=2 instead
    //of 2.5 which is helpful and makes the code run perfectly.
    
        temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

    return 0;
}

int fibonacci_arr(){



    return 0;
}

int check_duplicate_values(){
    int n,i,count=0,j=0,flag=0;
    int arr[n];

    printf("What are the number of values?: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("What is value of number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        flag=0;
        for(j=0;j<n;j++){
            if(i!=j){
                if(arr[i]==arr[j]){
                flag=1;
                // count++;
            }
            }
        }
        if(flag==1){
            count++;
        }
        
    }
    printf("The number of duplicate values: %d",count);
    return 0;
}

int print_unique(){
    int n,i,j=0,flag=0;
    int arr[n];

    printf("What are the number of values?: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("What is value of number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        flag=0;
        for(j=0;j<n;j++){
            if(i!=j){
                if(arr[i]==arr[j]){
                flag++;
                
            }
            }
        }
        if(flag==0){
            printf("%d\t",arr[i]);
        }
        
    }
    return 0;
}




int main(){

    // gst_ques();
    // count_odd();
    // reverse();
    // fibonacci_arr();
    // check_duplicate_values();
    // print_unique();
    return 0;
}

// // finally solved
// #include <stdio.h>
// #include <stdlib.h>

// /*
//  * This stores the total number of books in each shelf.
//  */
// int* total_number_of_books;

// /*
//  * This stores the total number of pages in each book of each shelf.
//  * The rows represent the shelves and the columns represent the books.
//  */
// int** total_number_of_pages;

// int main()
// {
//     int total_number_of_shelves;
//     scanf("%d", &total_number_of_shelves);
    
//     int total_number_of_queries;
//     scanf("%d", &total_number_of_queries);
    

//     int n=total_number_of_queries;
            
//     while (total_number_of_queries--) {
//         int type_of_query;
//         scanf("%d", &type_of_query);
        
//         if (type_of_query == 1) {
//             /*
//              * Process the query of first type here.
//              */
//             int x, y;
//             scanf("%d %d", &x, &y);
//             int i,j,books_n=0;

//         if(total_number_of_queries==n-1){    
//             total_number_of_books = malloc( total_number_of_shelves * sizeof( int ) );

//             for (int i=0; i<total_number_of_shelves; i++) {
//             total_number_of_books[i]=0;
//             }
//             total_number_of_pages = (int **) malloc                 (total_number_of_shelves*sizeof(int *)); 
//             for(i=0;i<total_number_of_shelves;i++)
//              {
//                  total_number_of_pages[i] = (int *) malloc(1100*sizeof(int)); 
//              }//1100 here instead of books_n
            
//             for (i=0; i<total_number_of_shelves; i++) {
//                 for (j=0; j<1100; j++) {
//                     total_number_of_pages[i][j]=0;
//                 }
//             }
//         }
//         // this was an issue because of the fact that it was traversing
//         // the loop multiple times for each thing.
//             total_number_of_books[x]+=1;// no need of another for loop
//             // better optimized
            
//             for (j=0; j<1100; j++) {//1100 here instead of books_n
//                 if (total_number_of_pages[x][j]==0) {
//                        total_number_of_pages[x][j]=y; 
//                        break;
//                 }
                    
            
//         }
//         } else if (type_of_query == 2) {
//             int x, y;
//             scanf("%d %d", &x, &y);
//             printf("%d\n", *(*(total_number_of_pages + x) + y));
//         } else {
//             int x;
//             scanf("%d", &x);
//             printf("%d\n", *(total_number_of_books + x));
//         }
//     }

//     if (total_number_of_books) {
//         free(total_number_of_books);
//     }
    
//     for (int i = 0; i < total_number_of_shelves; i++) {
//         if (*(total_number_of_pages + i)) {
//             free(*(total_number_of_pages + i));
//         }
//     }
    
//     if (total_number_of_pages) {
//         free(total_number_of_pages);
//     }
    
//     return 0;
// }


// //Finally Solved Perfect........
