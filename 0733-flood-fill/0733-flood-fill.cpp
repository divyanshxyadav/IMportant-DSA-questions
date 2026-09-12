class Solution {
public:
void dfs(vector<vector<int>>&vis,int initial_color,vector<vector<int>>& image, int i, int j, int color){
    vis[i][j]=1;
    image[i][j]=color;
    if(i>0){
if(vis[i-1][j]==-1 && image[i-1][j]==initial_color){
    dfs(vis,initial_color,image,i-1,j,color);
}}
    if(i<image.size()-1){
if(vis[i+1][j]==-1 && image[i+1][j]==initial_color){
    dfs(vis,initial_color,image,i+1,j,color);
}}
    if(j>0){
if(vis[i][j-1]==-1 && image[i][j-1]==initial_color){
    dfs(vis,initial_color,image,i,j-1,color);
}}
    if(j<image[0].size()-1){
if(vis[i][j+1]==-1 && image[i][j+1]==initial_color){
    dfs(vis,initial_color,image,i,j+1,color);
}}
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),-1));
        int initial_color=image[sr][sc];
        dfs(vis,initial_color,image,sr,sc,color);
        return image;
    }
};