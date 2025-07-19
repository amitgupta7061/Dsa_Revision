#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    unordered_map<string, Node*> children;
    bool ending;
    Node() {
        ending = false;
    }
};

class Solution {
public:
    void insertInTrie(string &path, Node* root, vector<string> &result) {
        stringstream ss(path);
        string segment;
        bool skip = false;

        while (getline(ss, segment, '/')) {
            if (segment.empty()) continue;

            if (root->ending) {
                skip = true;
                break;
            }

            if (!root->children.count(segment)) {
                root->children[segment] = new Node();
            }
            root = root->children[segment];
        }

        if (!skip) {
            root->ending = true;
            result.push_back(path);
        }
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> result;
        Node* root = new Node();
        sort(folder.begin(), folder.end());

        for (auto &path : folder) {
            insertInTrie(path, root, result);
        }

        return result;
    }
};

int main() {

    return 0;
}