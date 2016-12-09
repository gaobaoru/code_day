题目描述


Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions. 


class Solution {
public:
    int totalNQueens(int n) {
        this->columns = vector<bool>(n, false);
        this->main_diag = vector<bool>(2*n - 1, false);
        this->anti_diag = vector<bool>(2*n - 1, false);
        vector<vector<string> > result;
        vector<int> C(n, -1);
        dfs(C, result, 0);
        return (int)result.size();
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
