class Solution {
    public int minStartValue(int[] nums) {
        int sum = 0;
        int min = 0;

        for (int x : nums) {
            sum += x;  
            min = Math.min(min, sum); 
        }

        return 1 - min;  
    }
}
