class NumberContainers {
public:
    typedef set<int> st;
    unordered_map<int, int> mp;
    unordered_map<int, st> ind;

    void change(int index, int number) {
        if (mp.find(index) != mp.end()) {
            int num = mp[index];
            auto& indices = ind[num]; // Use reference to modify the actual set
            indices.erase(index);
            if (indices.empty()) {
                ind.erase(num);
            }
            cout << "ankit";
        }

        mp[index] = number;
        ind[number].insert(index);
    }

    int find(int number) {
        if (ind.count(number)) {
            return *ind[number].begin();
        }
        return -1;
    }
};
