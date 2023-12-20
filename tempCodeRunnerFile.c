# include<stdio.h>
# include<math.h>
int main(){
	int n,r,c;
	int rev=0;
	printf("enter a number ");
	scanf("%d",&n);
	c=n;
	int i=3;
	while(n>0){
		r=n%10;
		n=n/10;
		rev=rev+pow(r,3)*pow(10,i-1);
		i--;
	}
	if(c==rev){
		printf("it is a palindrome number");
	}
	else{
		printf("it is not a palindrome");
	}
	return 0;
}