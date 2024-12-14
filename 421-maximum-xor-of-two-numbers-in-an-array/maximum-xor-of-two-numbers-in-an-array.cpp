struct Node{
    Node* link[2];

    bool containsKey(int bit){
        return (link[bit] != NULL);
    }

    Node* get(int bit){
        return link[bit];
    }

    void put(int bit , Node* node){
        link[bit] = node;
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insertion(int num){
        Node* node = root;
        for(int i = 31 ; i >= 0 ; i--){
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit , new Node());
            }
            node = node->get(bit);
        }
        return;
    }

    int maxisetvalue(int num){
        Node* node = root;
        int maxi = 0;
        for(int i = 31 ; i >= 0 ; i--){
            int bit = (num >> i) & 1;
            if(node->containsKey(1 - bit)){
                maxi = (1 << i) | maxi;
                node = node->get(1-bit);
            }else{
                node = node->get(bit);
            }
        }
        return maxi;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto itr : nums){
            trie.insertion(itr);
        }

        int ans = 0;

        for(auto itr : nums){
            ans = max(ans , trie.maxisetvalue(itr));
        }

        return ans;
    }
};