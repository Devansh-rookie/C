// or a function can be made with for loops from 1 to 3 in the upper most then multiples of 3 for all to avoid writing it so many times.

void make_zero(int arr[]){
    for(int i=0;i<10;i++) arr[i]=0;
}

bool check_all_1s_0s(int arr[]){
    for(int i=0;i<10;i++){
        if(arr[i]>=2) return false;
    }
    return true;
}

bool check_all_0s(int arr[]){
    for(int i=0;i<10;i++){
        if(arr[i]!=0) return false;
    }
    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int i,j,k;
    int arr[10];
    make_zero(arr);
    for(i=0;i<boardSize;i++){
        // this is for rows or the first thingy
        for(j=0;j< *boardColSize;j++){
            // these are the columns
            if(board[i][j]!='.') arr[(int)(board[i][j]-48)]++;
        }
        if(!check_all_1s_0s(arr)) return false;
        make_zero(arr);
    }
    for(j=0;j<boardSize;j++){
        // this is for rows or the first thingy
        for(i=0;i< *boardColSize;i++){
            // these are the columns
            if(board[i][j]!='.') arr[(int)(board[i][j]-48)]++;
        }
        if(!check_all_1s_0s(arr)) return false;
        make_zero(arr);
    }
    for(i=0;i<3;i++){
        // this is for rows or the first thingy
        for(j=0;j<3;j++){
            // these are the columns
            if(board[i][j]!='.') arr[(int)(board[i][j]-48)]++;
        }
    }
    if(!check_all_1s_0s(arr)) return false;
    make_zero(arr);
    for(i=3;i<6;i++){
        // this is for rows or the first thingy
        for(j=0;j<3;j++){
            // these are the columns
            if(board[i][j]!='.') arr[(int)(board[i][j]-48)]++;
        }
    }
    if(!check_all_1s_0s(arr)) return false;
    make_zero(arr);
    for(i=6;i<9;i++){
        // this is for rows or the first thingy
        for(j=0;j<3;j++){
            // these are the columns
            if(board[i][j]!='.') arr[(int)(board[i][j]-48)]++;
        }
    }
    if(!check_all_1s_0s(arr)) return false;
    make_zero(arr);

    for(i=0;i<3;i++){
        // this is for rows or the first thingy
        for(j=3;j<6;j++){
            // these are the columns
            if(board[i][j]!='.') arr[(int)(board[i][j]-48)]++;
        }
    }
    if(!check_all_1s_0s(arr)) return false;
    make_zero(arr);

    for(i=0;i<3;i++){
        // this is for rows or the first thingy
        for(j=6;j<9;j++){
            // these are the columns
            if(board[i][j]!='.') arr[(int)(board[i][j]-48)]++;
        }
    }
    if(!check_all_1s_0s(arr)) return false;
    make_zero(arr);

    for(i=3;i<6;i++){
        // this is for rows or the first thingy
        for(j=3;j<6;j++){
            // these are the columns
            if(board[i][j]!='.') arr[(int)(board[i][j]-48)]++;
        }
    }
    if(!check_all_1s_0s(arr)) return false;
    make_zero(arr);

    for(i=3;i<6;i++){
        // this is for rows or the first thingy
        for(j=6;j<9;j++){
            // these are the columns
            if(board[i][j]!='.') arr[(int)(board[i][j]-48)]++;
        }
    }
    if(!check_all_1s_0s(arr)) return false;
    make_zero(arr);

    for(i=6;i<9;i++){
        // this is for rows or the first thingy
        for(j=3;j<6;j++){
            // these are the columns
            if(board[i][j]!='.') arr[(int)(board[i][j]-48)]++;
        }
    }
    if(!check_all_1s_0s(arr)) return false;
    make_zero(arr);
    for(i=6;i<9;i++){
        // this is for rows or the first thingy
        for(j=6;j<9;j++){
            // these are the columns
            if(board[i][j]!='.') arr[(int)(board[i][j]-48)]++;
        }
    }
    if(!check_all_1s_0s(arr)) return false;
    make_zero(arr);
    return true;
}