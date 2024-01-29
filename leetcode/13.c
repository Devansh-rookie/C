int cti(char s);
int romanToInt(char* s) {
    // typedef struct roman{
    //     char c;// characters
    //     int v;// value
    // }roman;
    // roman arr[7]={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int sum=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='I'){
            if(s[i+1]=='V'||s[i+1]=='X'){
                sum+=cti(s[i+1])-cti(s[i]);
                i++;
                continue;
            }
            else sum+=cti(s[i]);
        }
        else if(s[i]=='X'){
            if(s[i+1]=='L'||s[i+1]=='C'){
                sum+=cti(s[i+1])-cti(s[i]);
                i++;
                continue;
            }
            else sum+=cti(s[i]);
        }
        else if(s[i]=='C'){
            if(s[i+1]=='D'||s[i+1]=='M'){
                sum+=cti(s[i+1])-cti(s[i]);
                i++;
                continue;
            }
            else sum+=cti(s[i]);
        }
        else{
            sum+=cti(s[i]);
        }
    }
    return sum;
}

int cti(char c){// change to integer
    if(c=='I') return 1;
    else if(c=='V') return 5;
    else if(c=='X') return 10;
    else if(c=='L') return 50;
    else if(c=='C') return 100;
    else if(c=='D') return 500;
    else return 1000;
}
