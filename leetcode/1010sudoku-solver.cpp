题目描述


Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character'.'.

You may assume that there will be only one unique solution. 

class Solution {
public:
    //时间复杂度Ｏ(9^4),空间复杂度Ｏ(1)
    bool solveSudoku(vector<vector<char> > &board) {
        for(int i = 0; i < 9; i++){
           for(int j = 0; j < 9; j++){
               if(board[i][j] == '.'){
                   for(int k = 0; k < 9; k++){
                       board[i][j] = '1' + k;
                       if(isValid(board, i, j) && solveSudoku(board))
                           return true;
                       board[i][j] = '.';
                   }
                   return false;
               }
           }
        }
        return true;
    }
private:
    bool isValid(vector<vector<char> > &board, int x, int y){
        int i, j;
        for(i = 0; i < 9; i++)
            if(i != x && board[i][y] == board[x][y])
            	return false;
        for(j = 0; j < 9; j++)
            if(j != y && board[x][j] == board[x][y])
            	return false;
        for(i = 3*(x/3); i < 3*(x/3+1); i++)
            for(j = 3*(y/3); j < 3*(y/3+1); j++)
                if((i !=x || j != y) && board[i][j] == board[x][y])
                	return false;
        return true;
    }
};
