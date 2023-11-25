#include "include.h"

class Solution {
public:
    int m, n;
    vector<int> way = {1, 0, -1, 0, 1};

    void back_tracing(bool &ans, vector<vector<char>> board, int x, int y, string word, int cur) {
        board[x][y] = ' ';
        if (ans == true)
            return;

        if(cur == word.size()) {
            ans = true;
            return;
        }

        for(int i = 0; i < way.size() - 1; i++) {
            int tmp_x = x + way[i];
            int tmp_y = y + way[i + 1];

            if(tmp_x < 0 || tmp_x >= m || tmp_y < 0 || tmp_y >= n)
                continue;
            
            

            if(board[tmp_x][tmp_y] == word[cur]) {
                cout << board[tmp_x][tmp_y]<< endl;
                back_tracing(ans, board, tmp_x, tmp_y, word, cur + 1);
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    cout << board[i][j]<< endl;
                    back_tracing(ans, board, i, j, word, 1);
                }
                if(ans == true)
                    return ans;
            }
        }

        return ans;
    }
};

class Solution {
public:

	vector<int> ways = {-1, 0, 1, 0, -1};

    bool exist(vector<vector<char>>& board, string word) {
		bool ans = false;

		for(int i = 0; i < board.size(); i++) {
			for(int j = 0; j < board[0].size(); j++) {
				if(board[i][j] == word[0])
					back_tracking(board, word, i, j, ans);
			}
		}
		return ans;
    }

	void back_tracking(vector<vector<char>>& board, string word, int row, int col, bool& ans) {
		if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return;
		if (board[row][col] != word[0]) return;
		if (word.size() == 1) {
			ans = true;
			return;
		}

		char temp = board[row][col];
		board[row][col] = '#';

		for (int i = 0; i < 4; ++i) {
			int new_row = row + ways[i];
			int new_col = col + ways[i + 1];
			back_tracking(board, word.substr(1), new_row, new_col, ans);
			if (ans) break;
		}

		board[row][col] = temp;
	}
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string& word, int cur_row, int cur_col, int wi) {
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        if(wi == word.size()){
            return true;
        }
        for (int k = 0; k < 4; k++){
            int new_row = cur_row + dx[k];
            int new_col = cur_col + dy[k];
            if(new_row >= 0 && new_row < board.size() && new_col >= 0 && new_col < board[0].size()){
                if(board[new_row][new_col] == word[wi]){
                    board[new_row][new_col] = '-';
                    bool res = exist(board, word, new_row, new_col, wi+1);
                    if(res){
                        return true;
                    }
                    board[new_row][new_col] = word[wi];
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int N = word.size();
        int left = word.find_first_not_of(word[0]);
        int right = N - word.find_last_not_of(word[N - 1]);
        if (left > right) reverse(begin(word), end(word));
        for ( int i = 0; i < board.size(); i++){
            for ( int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[0]){
                    board[i][j] = '-';
                    bool res = exist(board, word, i, j, 1);
                    if(res){
                        return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
};