class Solution {
    public boolean canMakeSquare(char[][] grid) {
       
        int nb = 0;
        int nw =0;

        for (int i = 0; i <= 1; ++i) {
            for (int j = 0; j <= 1; ++j) {
                if(grid[i][j] == 'B'){
                    nb++;
                }
                 else{
                    nw++;
                }
                 if(grid[i][j+1] == 'B'){
                    nb++;
                }
                 else{
                    nw++;
                }
                 if(grid[i+1][j] == 'B'){
                    nb++;
                }
                 else{
                    nw++;
                }
                 if(grid[i+1][j+1] == 'B'){
                    nb++;
                }
                else{
                    nw++;
                }
                if(nb == 4 || nw == 4 || (nb ==3 && nw==1) ||(nb==1 && nw==3)){
                    return true;
                }
                nb=0;
                nw=0;
            }
        }

        return false; 
    }
}
