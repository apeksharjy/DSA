import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);  
        int maxLength = 0;
        int balance = 0;

        for (int i = 0; i < nums.length; i++) {
            balance += (nums[i] == 1 ? 1 : -1);

            if (map.containsKey(balance)) {
                maxLength = Math.max(maxLength, i - map.get(balance));
            } else {
                map.put(balance, i);
            }
        }
        return maxLength;
    }
}
