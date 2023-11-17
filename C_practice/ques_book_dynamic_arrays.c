// finally solved
#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    

    int n=total_number_of_queries;
            
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;
            scanf("%d %d", &x, &y);
            int i,j,books_n=0;

        if(total_number_of_queries==n-1){    
            total_number_of_books = malloc( total_number_of_shelves * sizeof( int ) );

            for (int i=0; i<total_number_of_shelves; i++) {
            total_number_of_books[i]=0;
            }
            total_number_of_pages = (int **) malloc                 (total_number_of_shelves*sizeof(int *)); 
            for(i=0;i<total_number_of_shelves;i++)
             {
                 total_number_of_pages[i] = (int *) malloc(1100*sizeof(int)); 
             }//1100 here instead of books_n
            
            for (i=0; i<total_number_of_shelves; i++) {
                for (j=0; j<1100; j++) {
                    total_number_of_pages[i][j]=0;
                }
            }
        }
        // this was an issue because of the fact that it was traversing
        // the loop multiple times for each thing.
            total_number_of_books[x]+=1;// no need of another for loop
            // better optimized
            
            for (j=0; j<1100; j++) {//1100 here instead of books_n
                if (total_number_of_pages[x][j]==0) {
                       total_number_of_pages[x][j]=y; 
                       break;
                }
                    
            
        }
        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}


//Finally Solved Perfect........
