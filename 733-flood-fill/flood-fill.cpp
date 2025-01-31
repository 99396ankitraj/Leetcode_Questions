class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    
    void dfs(int i, int j, vector<vector<int>>& image, int color, int n, int m, int ele) {
        if(i < 0 || i >= n || j < 0 || j >= m || image[i][j] != ele) return;
        
        image[i][j] = color;

        // Explore the four possible directions (down, left, right, up)
        for(auto itr : dir) {
            int nexti = i + itr.first;
            int nextj = j + itr.second;
            dfs(nexti, nextj, image, color, n, m, ele);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int ele = image[sr][sc];

        // If the target color is the same as the current color, no change is needed
        if (ele == color) return image;

        dfs(sr, sc, image, color, n, m, ele);
        return image;
    }
};
