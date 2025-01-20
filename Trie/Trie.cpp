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
        // DELETION IN TRIE 
        bool deleteWord(string &word){
            return deleteRecursive(root,word,0);
        }
        bool deleteRecursive(TrieNode* node, string word,int depth){
            if(node==NULL){
                return false;
            }
            if(depth==word.size()){
                if(node->isTerminal==false){
                    return false;
                }
                node->isTerminal=false;
                if(nodehasnochildren(node)==true){
                    return true;
                }else{
                    return false;
                }
            }else{
                int index = word[depth]-'a';
                bool result = deleteRecursive(node->children[index],word,depth+1);
                if(result==true){
                    delete node->children[index];
                    node->children[index]=NULL;
                    if(nodehasnochildren(node)==true){
                        return true;
                    }else{
                        return false;
                    }
                }
            }
            return false;
        }
        bool nodehasnochildren(TrieNode* node){
            for(int i=0;i<26;i++){
                if(node->children[i]!=NULL){
                    return false;
                }
            }
            return true;
        }
        // PRINT ALL THE WORDS PRESENT INSIDE A TRIE 
        void printwordsintrie(){
            string currentWord;
            printWordsFunction(root,currentWord);
        }
        void printWordsFunction(TrieNode* node,string currentWord){
            if(node==NULL){
                return;
            }
            if(node->isTerminal==true){
                cout << currentWord << "\n";
            }
            for(int i=0;i<26;i++){
                if(node->children[i]!=NULL){
                    currentWord.push_back('a'+i);
                    printWordsFunction(node->children[i],currentWord);
                    currentWord.pop_back();
                }
            }
        }
};

int main(){
    Trie trie;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        string command;
        cin >> command;
        if(command=="INSERT"){
            string word;
            cin >> word;
            trie.insert(word);
            cout << "INSERTED " << word << " in trie" << "\n";  
        }
        if(command=="DELETE"){
            string word;
            cin >> word;
            bool ans = trie.deleteWord(word);
            if(ans==true){
                cout << "DELETED " << word << " from trie" << "\n";
            }else{
                cout << word << " not present in trie" << "\n";
            }
        }
        if(command=="SHOW"){
            trie.printwordsintrie();
        }
        if(command=="SEARCH"){
            string word;
            cin >> word;
            bool ans = trie.search(word);
            if(ans==true){
                cout << "Word present in trie" << "\n";
            }else{
                cout << "Word not present in trie" << "\n";
            }
        }
    }
}