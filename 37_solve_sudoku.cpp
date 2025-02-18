#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    bool isValid(vector<vector<char>>& board, int row, int col, int num){
        for (int i = 0; i < 9; i++){
            if (board[row][i] == num + '0' || board[i][col] == num + '0'){
                return false;
            }
        }
        int subRow = (row/3)*3, subCol = (col/3)*3;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (board[subRow + i][subCol + j] == num + '0'){
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for (int row = 0; row < 9; row++){
            for (int col = 0; col < 9; col++){
                if (board[row][col] == '.'){
                    for (int num = 1; num <= 9; num++){
                        if (isValid(board, row, col, num)){
                            board[row][col] = num + '0';
                            if (solve(board)){
                                return true;
                            }
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board){
        solve(board);
    }

    void printBoard(vector<vector<char>>& board){
        for (int row = 0; row < 9; row++){
            for (int col = 0; col < 9; col++){
                cout<<board[row][col]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution sol;
    sol.solveSudoku(board);
    sol.printBoard(board);
    return 0;
}