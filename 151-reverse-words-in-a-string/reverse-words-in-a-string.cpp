class Solution {
public:
    // void reverseSingleWord(int start, int end, string& str) {
    //     while(start < end) {
    //         swap(str[start], str[end]);
    //         start++;
    //         end--;
    //     }
    // }
    string reverseWords(string s) {
        //step 1 : reverse whole string
        reverse(s.begin(), s.end());

        int n = s.size();
        int k = 0;
        int left = 0, right = 0;
        while(k < n) {
            while(k < n && s[k] == ' ') k++; //for leading spaces
            if(k == n) break;

            while(k < n && s[k] != ' ') {
                s[right] = s[k];
                right++;
                k++;
            }
            reverse(s.begin() + left, s.begin()+ right);
            s[right] = ' ';
            right++;
            left = right;

            k++;
        }
        s.resize(right-1);
        return s;
    }
};