// #include <stdio.h>
// #include <stdbool.h>
// int main(void) {
// 	// your code goes here

// 	int test_cases,number_solved,i;
// 	scanf("%d",&test_cases);
// 	while(test_cases>0){
// 	    bool flag=false;
// 	    scanf("%d",&number_solved);
// 	    int ratings[number_solved];
// 	    for(i=0;i<number_solved;i++){
// 	        scanf("%d",&ratings[i]);
// 	    }
// 	    for(i=0;i<number_solved-1;i++){
// 	        if(ratings[i+1]<ratings[i]){
// 	            flag=false;
// 	            break;
// 	        }
// 	        else flag=true;
// 	    }
// 	    if(flag) printf("Yes\n");
// 	    else printf("No\n");
// 	    test_cases--;
// 	}
// 	return 0;
// }


// #include <stdio.h>

// int main(void) {
// 	// your code goes here
// 	int t,n,x,i,sum=0;
// // 	int a[n],b[n];
// 	scanf("%d",&t);
// 	while(t>0){
// 	    sum=0;
// 	    scanf("%d %d",&n,&x);
// 	    int a[n],b[n];// depends from compiler to complier if we need to enter the variable value before or after the array declaration
// 	    for(i=0;i<n;i++){
// 	        scanf("%d",&a[i]);
// 	    } 
// 	    for(i=0;i<n;i++){
// 	        scanf("%d",&b[i]);
// 	    }
// 	    for(i=0;i<n;i++){
// 	        if(a[i]>=x){
// 	            sum=sum+b[i];
// 	        }
// 	    }
// 	    printf("%d\n",sum);
// 	    t--;
// 	}
// 	return 0;
// }

// #include <stdio.h>

// int main(void) {
// 	// your code goes here
// 	// break the code into pieces like done in this example by first understanding the logic then doing the rest of the coding
// 	int t,n,i;
// 	scanf("%d",&t);
	
// 	while(t>0){
// 	    int sum=0;
// 	    scanf("%d",&n);
// 	    int a[n],b[n];// because of compiler
// 	    for(i=0;i<n;i++){
// 	        scanf("%d",&a[i]);
// 	    }
// 	    for(i=0;i<n;i++){
// 	        scanf("%d",&b[i]);
// 	    }
// 	    for(i=0;i<n;i++){
// 	        if(2*a[i]>=b[i] && 2*b[i]>=a[i]) sum++;
// 	    }
// 	    printf("%d\n",sum);
// 	    t--;
// 	}
// 	return 0;
// }


// #include <stdio.h>

// int main(void) {
// 	// your code goes here
// 	int t,n,i,max,max2,sum;
// 	scanf("%d",&t);
// 	while (t>0){
// 		scanf("%d",&n);// ampersand '&' is mandatory
// 		int arr[n];
// 		for(i=0;i<n;i++){
// 			scanf("%d",&arr[i]);
// 		}
// 		max=arr[0];
// 		for(i=0;i<n;i++){
// 			if(arr[i]>max){
// 				max=arr[i];
// 			}
// 		}
// 		max2=-max;
// 		for(i=0;i<n;i++){
		   
// 			if(max>arr[i]) {//important to check this condition
// 			    if(arr[i]>max2) max2=arr[i];
			    
// 			}
// 		}
// 		sum = max2+max;
// 		printf("%d\n",sum);
// 		t--;
// 	}
// 	return 0;
// }

// #include <stdio.h>

// int main(void) {
// 	// your code goes here
// 	int t,n,i,s_o=0,s_a=0;//sum om and sum addy
// 	scanf("%d",&t);
// 	while(t>0){
//		scanf("%d",&n);
// 	    int o[n],a[n];
// 	    for(i=0;i<n;i++){
//             scanf("%d",&o[i]);
// 	    }
// 	    for(i=0;i<n;i++){
//             scanf("%d",&a[i]);
// 	    }
// 	    for(i=0;i<n;i++){
// 	        if(o[i]==0) {
// 	            s_o=i;
// 	            break;
// 	        }
// 	    }
// 	    for(i=0;i<n;i++){
// 	        if(a[i]==0) {
// 	            s_a=i;
// 	            break;
// 	        }
// 	    }
// 	    if(s_o>s_a) printf("OM\n");
// 	    else if(s_a>s_o) printf("ADDY\n");
// 	    else printf("DRAW\n");//s_o=s_a
// 	    t--;
// 	}
// 	return 0;
// }


// #include <stdio.h>

// int main(void) {
// 	// your code goes here
// 	int t,n,i,s_o=0,s_a=0;//sum om and sum addy
// 	scanf("%d",&t);
// 	while(t>0){
// 	    s_a=0;
// 	    s_o=0;
// 	    scanf("%d",&n);
// 	    int last_max=0; // for comparision of the largest values
// 	    int o[n],a[n];
// 	    for(i=0;i<n;i++){
//             scanf("%d",&o[i]);
// 	    }
// 	    for(i=0;i<n;i++){
//             scanf("%d",&a[i]);
// 	    }

//         for(i=0;i<n;i++){
            
//             if(o[i]==0){// basically reset the s_o
//                 if (s_o>last_max) last_max=s_o;
//                 s_o=0;
//             }
//             else s_o++;// increase if anything because it will b reset to 0 if the term is 0
//         }
//         if (last_max>s_o) s_o=last_max;// final storage variable
//         last_max=0;// reset last_max again** point of mistake
//         for(i=0;i<n;i++){
            
//             if(a[i]==0){// basically reset the s_a
//                 if (s_a>last_max) last_max=s_a;
//                 s_a=0;
//             }
//             else s_a++;// increase if anything because it will b reset to 0 if the term is 0
//         }
//         if (last_max>s_a) s_a=last_max;// final storage variable


// 	    if(s_o>s_a) printf("OM\n");
// 	    else if(s_a>s_o) printf("ADDY\n");
// 	    else printf("DRAW\n");//s_o=s_a
// 	    t--;
// 	}
// 	return 0;
// }


//We have populated the solutions for the 10 easiest problems for your support.
//Click on the SUBMIT button to make a submission to this problem.

// #include<stdio.h>
   
// int arr[1000000]={0};

    
// int main()
// {
// 	int a,n;
//     scanf("%d",&n);
//     while(n--)
//     {
// 	    scanf("%d",&a);
//         arr[a]++;
//     }
//     a=0;
//     while(a<1000000)
//     {
//         while(arr[a])
//         {
//             printf("%d\n",a);
//             arr[a]--;
//         }
//     a++;
//     }
// return 0;
// }



