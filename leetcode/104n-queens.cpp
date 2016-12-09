题目描述

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where'Q'and'.'both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

class Solution {
public:
    //时间复杂度Ｏ(n!),空间复杂度Ｏ(n)
    vector<vector<string> > solveNQueens(int n) {
        this->columns = vector<bool>(n, false);
        this->main_diag = vector<bool>(2*n - 1, false);
        this->anti_diag = vector<bool>(2*n - 1, false);
        vector<vector<string> > result;
        vector<int> C(n, -1);
        dfs(C, result, 0);
        return result;
    }
private:
    vector<bool> columns;
    vector<bool> main_diag;
    vector<bool> anti_diag;
    
    void dfs(vector<int> &C, vector<vector<string> > &result, int row){
        const int N = C.size();
        if(row == N){
            vector<string> solution;
            for(int i = 0; i < N; i++){
                string s(N, '.');
                for(int j = 0; j < N; j++){
                    if(j == C[i]) s[j] = 'Q';
                }
                solution.push_back(s);
            }
            result.push_back(solution);
        	return;
        }
        
        for(int j = 0; j < N; j++){
            const bool ok = !columns[j] && !main_diag[row-j+N-1] 
                && !anti_diag[row+j];
            if(!ok) continue;
            C[row] = j;
            columns[j] = main_diag[row-j+N-1] = anti_diag[row+j] = true;
            dfs(C, result, row+1);
            C[row] = -1;
            columns[j] = main_diag[row-j+N-1] = anti_diag[row+j] = false;
        }
    }
};

