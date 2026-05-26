class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j){
        //up
        if(i-1>=0 && board[i-1][j]!='s' && board[i-1][j]!='X'){
            board[i-1][j]='s';
            dfs(board,i-1,j);
        }
        //down
        if(i+1<board.size() && board[i+1][j]!='s' && board[i+1][j]!='X'){
            board[i+1][j]='s';
            dfs(board,i+1,j);
        }
        //left
        if(j-1>=0 && board[i][j-1]!='s' && board[i][j-1]!='X'){
            board[i][j-1]='s';
            dfs(board,i,j-1);
        }
        //right
        if(j+1<board[0].size() && board[i][j+1]!='s' && board[i][j+1]!='X'){
            board[i][j+1]='s';
            dfs(board,i,j+1);
        }
    }
    void solve(vector<vector<char>>& board) {
        
        int m=board.size();
        int n=board[0].size();
        
        //vector<vector<int>> visited(m,vector<int>(n));

        for(int i=0;i<m;i++){
            if(i==0 || i==m-1){ 
                for(int j=0;j<n;j++){
                    if(board[i][j]!='s' && board[i][j]=='O'){
                    board[i][j]='s';
                    dfs(board,i,j);
                    }
                }
            }
            else{
                if(board[i][0]!='s' && board[i][0]=='O'){
                    board[i][0]='s';
                    dfs(board,i,0);
                }
                if(board[i][n-1]!='s' && board[i][n-1]=='O'){
                    board[i][n-1]='s';
                    dfs(board,i,n-1);
                }
                //n-1
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='s'){ board[i][j]='O';}
                else if(board[i][j]=='O'){ board[i][j]='X';}
            }
        }
    }
};