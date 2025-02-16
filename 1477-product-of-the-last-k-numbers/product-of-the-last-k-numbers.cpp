class ProductOfNumbers {
public:
    typedef unsigned long long ll;
    vector<ll> store;
    int ind = 0;
    int zero_idx = -1;
    
    void add(int num) {
        if(store.size() == 0){
            store.push_back(num);
            if(num == 0) zero_idx = ind;
        }else{
            store[ind-1] == 0 ? store.push_back(num) : store.push_back(num * store[ind-1]);
            if(num == 0) zero_idx = ind;     
        }
        //cout<<store[ind]<<endl;
        ind++;
    }
    int getProduct(int k) {
         
        if(k > ind){
            cout<<"a"<<endl;
            return -1;
        } 
        int i = ind-k-1;
        
        if(zero_idx > i){
            cout<<"c"<<endl;
             return 0;
        }
        
        if(i < 0 || store[i] == 0){
            cout<<"d"<<endl;
           return store[ind-1];
        } 
        cout<<"b"<<endl;
        return store[ind-1]/store[i];
    }
};

