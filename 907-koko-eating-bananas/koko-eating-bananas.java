class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int max = Integer.MIN_VALUE;
        for (int val : piles) {
            max = Math.max(max, val);
        }

        int low = 1; 
        int high = max;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isPossible(piles, h, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    public boolean isPossible(int[] piles, int h, int speed) {
        int time = 0;
        for (int pile : piles) {
            time += (pile + speed - 1) / speed; 
        }
        return time <= h;
    }
}
