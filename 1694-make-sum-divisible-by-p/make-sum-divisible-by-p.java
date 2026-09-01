import java.util.*;

class Solution {
    public int minSubarray(int[] nums, int p) {
        long sum = 0;
        for (int x : nums) {
            sum += x;
        }
        int rem = (int)(sum % p);
        if (rem == 0) return 0;

        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);

        long prefix = 0;
        int ans = nums.length;

        for (int i = 0; i < nums.length; i++) {
            prefix += nums[i];
            int current = (int)(prefix % p);
            int need = (current - rem + p) % p;

            if (map.containsKey(need)) {
                ans = Math.min(ans, i - map.get(need));
            }
            map.put(current, i);
        }

        return ans == nums.length ? -1 : ans;
    }
}
