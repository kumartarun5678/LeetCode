class Solution {
    public boolean isPalindrome(int x) {
        int num = 0;
        if(x==0){
            return true;
        }
        int numm = Math.abs(x);
        while(numm>0){
            int rem = numm%10;
            num = num*10+rem;
            numm = numm/10;
        }
        if(x>0){
            if(num == x){
                return true;
            }
        }
        return false;
    }
}