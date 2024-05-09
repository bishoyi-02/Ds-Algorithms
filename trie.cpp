class Node{
public:
    Node* links[26];
    bool f=0; 
};

class Trie{
public:
    Node * root;
    Trie(){
        root=new Node();
    }
    void insert(string &word){
        int n=word.size();
        Node* curr=root;
        for(int i=0;i<n;++i){
            if(!curr->links[word[i]-'a']){
                curr->links[word[i]-'a']=new Node();
            }
            curr=curr->links[word[i]-'a'];
        }
        curr->f=1;
    }

    bool search(string &word){
        int n=word.size();
        Node* curr=root;
        for(int i=0;i<n;++i){
            if(!curr->links[word[i]-'a']){
                return 0;
            }
            curr=curr->links[word[i]-'a'];
        }
        return curr->f;
    }

    bool startsWith(string &prefix){
        int n=word.size();
        Node* curr=root;
        for(int i=0;i<n;++i){
            if(!curr->links[word[i]-'a']){
                return 0;
            }
            curr=curr->links[word[i]-'a'];
        }
        return 1;
    }
};