class Solution {
public:
    int maximumSwap(int num) {
        string data = to_string(num);
        int n = data.length();
        if (n < 2) return num;
        int i = 0, j = 1, maxi = INT_MIN, index = -1;

        while (j < n) {
            if (data[i] < data[j]) {
                while (j < n) {
                    if (data[j] - '0' >= maxi) {
                        maxi = data[j] - '0';
                        index = j;
                    }
                    j++;
                }

                while(i >= 0 && data[i]-'0' < maxi){
                       i--;
                }
                swap(data[i+1],data[index]);
                return stoi(data);
                
            } else {
                i++;
                j++;
            }
        }
        return num;
    }
};