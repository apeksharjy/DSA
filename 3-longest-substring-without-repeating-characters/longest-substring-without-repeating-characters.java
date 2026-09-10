class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> seen = new HashSet<>();
        int left = 0;
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) 
        {
            while (seen.contains(s.charAt(i))) {
                seen.remove(s.charAt(left));
                left++;
            }
            seen.add(s.charAt(i));
            maxLength = Math.max(maxLength, i - left + 1);
        }
        return maxLength;
    }
}