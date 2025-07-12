#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    string endingword;
    unordered_map<char, Node*> children;
    
    Node(char data){this->data = data; this->endingword = "";}
};

class Solution {
public:
    void push(string &word, Node* root){
        Node* curr = root;
        for(char &ch : word){
            if(curr->children.count(ch)){
                curr = curr->children[ch];
            } else {
                Node* child = new Node(ch);
                curr->children[ch] = child;
                curr = curr->children[ch];
            }
        }
        curr->endingword = word;
    }
    vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void DFS(vector<vector<char>> &board, int r, int c, Node* root, vector<string> &result){
        char ch = board[r][c];
        if(!root->children.count(ch)) return;
        
        root = root->children[ch];
        if(root->endingword != ""){
            result.push_back(root->endingword);
            root->endingword = "";
        }
        board[r][c] = '#'; // indicating visited cell

        for(auto &it : direction){
            int nr = r + it.first, nc = c + it.second;
            if(nr >= 0 and nc >= 0 and nr < board.size() and nc < board[0].size() and
                    board[nr][nc] != '#'){        
                DFS(board, nr, nc, root, result);
            }
        }
        board[r][c] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        Node* root = new Node('\0');
        for(auto &word : words)
            push(word, root);
        
        int m = board.size(), n = board[0].size();
        vector<string> result;

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                DFS(board, r, c, root, result);
            }
        }
        
        return result;
    }
};

int main() {

    return 0;
}