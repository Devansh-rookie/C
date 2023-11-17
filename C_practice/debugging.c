#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    
    // tr is the array of a structure of triangle like int or float
    float area[n];
    float p,ar,temp;
    int i;
    for(i=0;i<n;i++){
        p=(tr[i].a+tr[i].b+tr[i].c)/2.0;
        area[i]=pow(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c),0.5);
    }
    for (i=0; i<n-1; i++) {
        for(int j=0;j<n-1;j++){
        if (area[j+1]<area[j]) {
            p=area[j+1];
            area[j+1]=area[j];
            area[j]=p;
            }
        }
    }
    for(i=0;i<n;i++){
        p=(tr[i].a+tr[i].b+tr[i].c)/2.0;
        ar=pow(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c),0.5);
        for(int j=0;j<n;j++){
        if (area[j]==ar) {
            temp=tr[i].a;
            tr[i].a=tr[j].a;
            tr[j].a=temp;
            temp=tr[i].b;
            tr[i].b=tr[j].b;
            tr[j].b=temp;
            temp=tr[i].c;
            tr[i].c=tr[j].c;
            tr[j].c=temp;
        }
        }
    }
    
    
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}