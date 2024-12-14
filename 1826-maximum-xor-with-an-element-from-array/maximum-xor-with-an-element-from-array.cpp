struct Node{
    Node* link[2];

    //function which we will use in insertion
    bool containsKey(int bit){
        return (link[bit] != NULL);
    }

    void put(int bit , Node* node){
        link[bit] = node;
    }

    Node* get(int bit){
        return link[bit];
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
        }

        int maxiSet(int num){
            int maxi = 0;
            Node* node = root;
            for(int i = 31 ; i >= 0 ; i--){
                int bit = (num >> i) & 1;
                if(node->containsKey(1 - bit)){
                    maxi = (1 << i) | maxi;
                    node = node->get(1 - bit);
                }else{
                    node = node->get(bit);
                }
            }
            return maxi;
        }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size() , -1);
        sort(nums.begin(),nums.end());
        priority_queue<pair<int , pair<int ,int>> , vector<pair<int , pair<int ,int>>> , greater<pair<int , pair<int ,int>>>>pq;
        for(int i = 0 ; i < queries.size() ; i++){
            int a = queries[i][0]; 
            int b = queries[i][1];
            pq.push({b , {a , i}});
        }

        Trie trie;
        int i = 0;

        while(!pq.empty()){
            auto front =pq.top();
            pq.pop();
            int a = front.first;
            int b = front.second.first;
            int ind = front.second.second;

            while(i < nums.size() && nums[i] <= a){
                trie.insertion(nums[i]);
                i++;
            }

            if(i == 0){
                ans[ind] = -1;
            }else{
                ans[ind] = trie.maxiSet(b);
            }

        }

        return ans;
    }
};