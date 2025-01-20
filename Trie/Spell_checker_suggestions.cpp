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
        void loadDictionary(vector<string>&strings){
            for(int i=0;i<strings.size();i++){
                string word = strings[i];
                insert(word);
            }
        }
        vector<string>suggestions(const string&word){
            vector<string>suggestions;
            suggestionsRecursion(root,word,"",suggestions);
            return suggestions;
        }
        void suggestionsRecursion(TrieNode* node,string word,string current,vector<string>&suggestions){
            if(node==NULL){
                return;
            }
            if(node->isTerminal==true){
                suggestions.push_back(current);
            }
            for(int i=0;i<26;i++){
                if(node->children[i]!=NULL){
                    suggestionsRecursion(node->children[i],word,current + char(i+'a'),suggestions);
                }
            }
        }
};

int main(){
    vector<string>dict = {"hello","hell","world","word","apple","ape"};
    Trie trie;
    trie.loadDictionary(dict);
    string word;
    cin >> word;
    bool ans=trie.search(word);
    if(ans==true){
        cout << "WORD PRESENT IN TRIE" << "\n";
    }else{
        cout << "WORD SPELLED WRONG< NOT PRESENT< DID YOU MEAN " << "\n";
        vector<string>suggest=trie.suggestions(word);
        for(int i=0;i<suggest.size();i++){
            string word = suggest[i];
            cout << " \""<<word<< "\"" << "\n";
        }
    }
}