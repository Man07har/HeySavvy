/* Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example 1:


Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
Example 2:


Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique. */


class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> child;
        string word;
        TrieNode() : word(""), child(vector<TrieNode*>(26, nullptr)) {}
    };
    
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string w : words) {
            TrieNode* curr = root;
            for (char c : w) {
                int i = c - 'a';
                if (curr->child[i] == NULL) curr->child[i] = new TrieNode();
                curr = curr->child[i];
            }
            curr->word = w;
        }
        return root;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> out;
        TrieNode* root = buildTrie(words);
        for(int i = 0; i < board.size(); ++i) 
            for(int j = 0; j < board[0].size(); ++j) 
                dfs(board, i, j, root, out);
        return out;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* curr, vector<string>& out) {
        char c = board[i][j];
        if(c == '#' || curr->child[c - 'a'] == NULL) return;
        curr = curr->child[c - 'a'];
        if (curr->word != "") {
            out.push_back(curr->word);
            curr->word = "";
        }
        board[i][j] = '#';
        if(i > 0) dfs(board, i - 1, j , curr, out); 
        if(j > 0) dfs(board, i, j - 1, curr, out);
        if(i < board.size() - 1) dfs(board, i + 1, j, curr, out); 
        if(j < board[0].size() - 1) dfs(board, i, j + 1, curr, out); 
        board[i][j] = c;
    }
};