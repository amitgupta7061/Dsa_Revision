#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Node{
        string folder;
        bool remove = false;
        map<string,Node*> child;
        Node(string folder){
            this->folder = folder;
        }
    };
    void insert_in_Trie(Node* root, vector<string>& path){
        for(auto &s: path){
            if(!root->child.count(s))
                root->child[s] = new Node(s);
            
            root = root->child[s];
        }
    }
    string markRepeating(Node* root, unordered_map<string, Node*>& visited){
        string subfolder;
        for(auto &[childfolder,childnode]: root->child)
            subfolder += markRepeating(childnode,visited);
        
        if(subfolder.size()){
            if(visited.count(subfolder)){
                visited[subfolder]->remove = true;
                root->remove = true;
            }else{
                visited[subfolder] = root;
            }
        }
        return "[" + root->folder + subfolder + "]";
    }
    void savePath(Node* root, vector<string>& curr_path, vector<vector<string>>& result){
        if(root->remove) return;
        
        curr_path.push_back(root->folder);
        result.push_back(curr_path);
        for(auto &[subfolder,childnode]: root->child)
            savePath(childnode,curr_path,result);
        
        curr_path.pop_back();
    }
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node("/");
        for(auto &path: paths)
            insert_in_Trie(root,path);
        
        unordered_map<string,Node*> visited;
        markRepeating(root,visited);

        vector<vector<string>> result;
        vector<string> curr_path;
        for(auto &[subfolder,childnode]: root->child)
            savePath(childnode,curr_path,result);

        return result;
    }
};

int main() {

    return 0;
}