int term[46]={0};
int climbStairs(int n) {
    if(n==1||n==2){
        return n;
    }
    if(term[n]!=0){
        // returns the value of the term if already calculated, that means if already calculated the term doesn't have to calculated again its automatically returned from the array in which it was stored it would also reduce the space complexity as its structure was similar to tree before while now its kind of 2 linear structures, its called memoization or similar thing can be done with lru_cache in python
        return term[n];
    }
    // n is automatically taken from the current function call no need to do anythng extra or iteration
    term[n]=climbStairs(n-1)+climbStairs(n-2);
    return term[n];
}