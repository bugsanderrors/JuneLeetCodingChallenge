/*
    Word Search II

    Given a 2D board and a list of words from the dictionary, find all words in the board.

    Each word must be constructed from letters of sequentially adjacent cell,
    where "adjacent" cells are those horizontally or vertically neighboring.
    The same letter cell may not be used more than once in a word.

    Example:
    Input: 
    board = [
    ['o','a','a','n'],
    ['e','t','a','e'],
    ['i','h','k','r'],
    ['i','f','l','v']
    ]
    words = ["oath","pea","eat","rain"]

    Output: ["eat","oath"]

    Note:
        * All inputs are consist of lowercase letters a-z.
        * The values of words are distinct.
*/

class TrieNode{
    public:
        vector<TrieNode*> children;
        bool isEnd;
        TrieNode()
        {
            children = vector<TrieNode*>(26, NULL);
            isEnd = false;
        }
};
class Trie{
private:
    TrieNode* root;
public:
    TrieNode* getRoot() {return root;}
    Trie(vector<string>& words)
    {
        root = new TrieNode();
        for(string s : words)
            insert(s);
    }
    
    void insert(string word)
    {
        TrieNode* temp = root;
        
        for(int i=0; i<word.size(); i++)
        {
            int idx = word[i] - 'a';
            if(temp->children[idx] == NULL)
                temp->children[idx] = new TrieNode();
            
            temp = temp->children[idx];           
        }
        
        temp->isEnd = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> res;
        
        Trie* trie = new Trie(words);
        TrieNode* root = trie->getRoot();
        
        
        for(int i=0; i<board.size(); ++i)
            for(int j=0; j<board[0].size(); ++j)
            {
                    dfs(board, i, j, root, "", res);
            }
        
        vector<string> ans;
        
        for(auto it : res)
            ans.push_back(it);
        
        return ans;
    }
    
private:
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root, string word, set<string>& res)
    {
        if(i<0 || j<0 || i >=board.size() || j>=board[0].size() || board[i][j] == '#')
            return;
        char c = board[i][j];
        if(root->children[c - 'a'] != NULL)
        {
            word = word+c;
            root = root->children[c - 'a'];
            if(root->isEnd)
                res.insert(word);
            
            board[i][j] = '#';
            dfs(board, i+1, j, root, word, res);
            dfs(board, i-1, j, root, word, res);
            dfs(board, i, j+1, root, word, res);
            dfs(board, i, j-1, root, word, res);
            board[i][j] = c;
        }   
    }
    
};