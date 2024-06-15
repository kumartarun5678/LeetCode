class Solution {
    public int reverse(int x) {
        long num = 0;
        int numm = Math.abs(x);
        while(numm>0){
            int rem = numm%10;
            num = num*10+rem;
            numm = numm /10;
        }
        if(Integer.MAX_VALUE<num){
            return 0;
        }
        if(x<0){
            return -1*(int)num;
        }
        else
            return (int) num;
    }
}