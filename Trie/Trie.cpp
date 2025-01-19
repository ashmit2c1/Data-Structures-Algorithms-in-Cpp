#include<bits/stdc++.h>
using namespace std;



struct TrieNode{
    bool isTerminal;
    TrieNode* children[26];
    TrieNode(){
        isTerminal=false;
        for(int i = 0; i<26 ; i++){
            children[i]=NULL;
        }
    }
};

class Trie{
    public:
        TrieNode* root;
        Trie(){
            root=new TrieNode();
        }
        // INSERT IN TRUE 
        void insert(string &word){
            TrieNode* current = root;
            for(int i=0;i<word.size();i++){
                char character = word[i];
                int index=character-'a';
                if(current->children[index]==NULL){
                    current->children[index]=new TrieNode();
                }
                current = current->children[index];
            }
            current->isTerminal=true;
        }
        // SEARCH IN TRIE 
        bool search(const string&word){
            TrieNode*current = root;
            for(int i=0;i<word.size();i++){
                char character = word[i];
                int index=character-'a';
                if(current->children[index]==NULL){
                    return false;
                }
                current=current->children[index];
            }
            return current->isTerminal;
        }
};
