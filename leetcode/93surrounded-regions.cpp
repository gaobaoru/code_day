题目描述


Given a 2D board containing'X'and'O', capture all regions surrounded by'X'.

A region is captured by flipping all'O's into'X's in that surrounded region .

For example,

X X X X
X O O X
X X O X
X O X X


After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

class Solution {
public:
    //时间复杂度Ｏ(n),空间复杂度Ｏ(n)
    void solve(vector<vector<char>> &board) {
        if(board.empty()) return;
        const int m = board.size();
        const int n = board[0].size();
        for(int i = 0; i < n; i++){
            bfs(board, 0, i);
            bfs(board, m-1, i);
        }
        for(int j = 1; j < m-1; j++){
            bfs(board, j, 0);
            bfs(board, j, n-1);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '+')
                    board[i][j] = 'O';
            }
        }
    }
private:
    void bfs(vector<vector<char> > &board, int i, int j){
        typedef pair<int, int> state_t;
        queue<state_t> q;
        const int m = board.size();
        const int n = board[0].size();
        
        auto state_is_valid = [&](const state_t &s){
            const int x = s.first;
            const int y = s.second;
            if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
                return false;
            return true;
        };
        
        auto state_extend = [&](const state_t &s){
            vector<state_t> result;
            const int x = s.first;
            const int y = s.second;
            const state_t new_states[4] = {{x-1,y},{x+1,y},
            							{x,y-1}, {x, y+1}};
            for(int k = 0; k < 4; k++){
                if(state_is_valid(new_states[k])){
                    board[new_states[k].first][new_states[k].second] = '+';
                    result.push_back(new_states[k]);
                }
            }
            return result;
        };
        
        state_t start = {i, j};
        if(state_is_valid(start)){
            board[i][j] = '+';
            q.push(start);
        }
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            auto new_states = state_extend(cur);
            for(auto s : new_states) q.push(s);
        }
    }
};
