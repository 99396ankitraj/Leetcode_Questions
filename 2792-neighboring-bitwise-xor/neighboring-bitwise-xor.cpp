class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> orignal(n);
        orignal[0] = 0;

        for(int i = 0 ; i < n-1 ; i++){
           derived[i] == 1 ? orignal[i+1] = ! orignal[i] : orignal[i+1] =  orignal[i]; 
        }

        for(int i = 0 ; i < n ; i++){
            if(derived[i] != orignal[i]^orignal[(i+1)%n]) return false;
        }

        return true;
    }
};