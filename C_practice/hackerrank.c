#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



// int main() 
// {
//     int a, b;
//     scanf("%d\n%d", &a, &b);
//   	// Complete the code.
//     for(;a<=b;a++){
//         if(a>=1&&a<=9){
//             if (a==1) {
//                 printf("one\n");
//             }
//                         if (a==2) {
//                 printf("two\n");
//             }
//                         if (a==3) {
//                 printf("three\n");
//             }
//                         if (a==4) {
//                 printf("four\n");
//             }
//                         if (a==5) {
//                 printf("five\n");
//             }
//                         if (a==6) {
//                 printf("six\n");
//             }
//                         if (a==7) {
//                 printf("seven\n");
//             }
//                         if (a==8) {
//                 printf("eight\n");
//             }
//                         if (a==9) {
//                 printf("nine\n");
//             }
//         }
//         else {
//             if(a%2==0){
//                 printf("even\n");
//             }
//             else {
//                 printf("odd\n");
//             }
//         }
//     }
//     return 0;
// }

int number_zoom(){
    int n,i,j,k=1;
    scanf("%d", &n);
    for(i=1;i<=2*n-1;i++){
        k=1;
        for ( j = 1; j <= 2*n-1; j++)
        {// first print empty square
            if(i==k||i==2*n-k||j==k||j==2*n-k) printf("%d ",k);
            // else if () printf("%d ",n-i);
            k++;
        }// or use another for loop for changing that what is the 
        //outer circle
        

        printf("\n");
    }
    return 0;
}

int sum_array(){
    int n,i,sum=0;

    scanf("%d",&n);
    int arr[n];// some compilers won't allow garbage value in n
    //for declaration of array so its safer to declare it after
    //n has a proper value.
    for(i=0;i<n-1;i++){
        scanf("%d ",&arr[i]);
    }
    scanf("%d",&arr[n-1]);
    for ( i = 0; i < n; i++)
    {
        sum = sum +arr[i];
    }
    printf("%d",sum);
    return 0;
}


int arr_reversal(){
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }


    /* Write the logic to reverse the array. */
    int temp;
    for(i=0;i<num/2;i++){
        temp=arr[num-i-1];//-1 is there to avoid runtime error
        //of traversing ghost of array(index more than allowed).
        arr[num-i-1]=arr[i];
        arr[i]=temp;
    }
    
    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}

int digit_frequency(){
    int i,c0=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0;
    char str[1000];
    fgets(str,1000,stdin);
    for(i=0;str[i]!='\0';i++){
        if (str[i]=='0') {
        c0++;
        }
                if (str[i]=='1') {
        c1++;
        }
                if (str[i]=='2') {
        c2++;
        }        if (str[i]=='3') {
        c3++;
        }        if (str[i]=='4') {
        c4++;
        }        if (str[i]=='5') {
        c5++;
        }        if (str[i]=='6') {
        c6++;
        }        if (str[i]=='7') {
        c7++;
        }        if (str[i]=='8') {
        c8++;
        }
                if (str[i]=='9') {
        c9++;
        }
    }
    printf("%d %d %d %d %d %d %d %d %d %d",c0,c1,c2,c3,c4,c5,c6,c7,c8,c9);

}

int print_in_diff_lines(){
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.
    int i;
    for(i=0;s[i]!='\0';i++){
        if (s[i]!=' ') {
            printf("%c",s[i]);
        }
        else {
            printf("\n");
        }
    }
}


// // Finally Solved

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
                //because this portion is already in a while loop which will run all the times.
            
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

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


int find_nth_term(int n, int a, int b, int c) {
  //Write your code here.
  int i,sum=0;
  if(n==1){
      return a;
  }
  else if (n==2) {
    return b;
  }
  else if (n==3) {
    return c;
  }
  else {
    for(i=1;i<=3;i++){// use 3 here instead of n because of the question
        sum= sum +find_nth_term(n-i, a,  b,  c);
    }
    return sum;
  }
}

int recursion() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}

int boys_girls_marks(){
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>

// //Complete the following function.

// int marks_summation(int* marks, int number_of_students, char gender) {
//   //Write your code here.
//     int sum=0,i;
//     if (gender=='g') {
//         for(i=1;i<number_of_students;i+=2){
//             sum= sum + marks[i];
//         }
//     }
//     else {
//         for(i=0;i<number_of_students;i+=2){
//             sum= sum + marks[i];
//         }
//     }
//   return sum;
// }

// int main() {
//     int number_of_students;
//     char gender;
//     int sum;
  
//     scanf("%d", &number_of_students);
//     int *marks = (int *) malloc(number_of_students * sizeof (int));
 
//     for (int student = 0; student < number_of_students; student++) {
//         scanf("%d", (marks + student));
//     }
    
//     scanf(" %c", &gender);
//     sum = marks_summation(marks, number_of_students, gender);
//     printf("%d", sum);
//     free(marks);
 
//     return 0;
// }

}

int struct_questions(){

//     #include <stdio.h>
// #include <stdlib.h>
// #define MAX_HEIGHT 41

// struct box
// {
// 	/**
// 	* Define three fields of type int: length, width and height
// 	*/
//     int length;
//     int width;
//     int height;
// };

// typedef struct box box;

// int get_volume(box b) {
// 	/**
// 	* Return the volume of the box
// 	*/
    
//     int volume;
//     volume=b.height*b.length*b.width;
//     return volume;
// }

// int is_lower_than_max_height(box b) {
// 	/**
// 	* Return 1 if the box's height is lower than MAX_HEIGHT and 0 otherwise
// 	*/
    
//     if (b.height<41) {
//         return 1;
//     }
//     else {
//         return 0;
//     }
// }

// int main()
// {
// 	int n;
// 	scanf("%d", &n);
// 	box *boxes = malloc(n * sizeof(box));
// 	for (int i = 0; i < n; i++) {
// 		scanf("%d%d%d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
// 	}
// 	for (int i = 0; i < n; i++) {
// 		if (is_lower_than_max_height(boxes[i])) {
// 			printf("%d\n", get_volume(boxes[i]));
// 		}
// 	}
// 	return 0;
// }
return 0;
}


int main() 
{

    // number_zoom();
    // sum_array();
    recursion();
    return 0;
}


