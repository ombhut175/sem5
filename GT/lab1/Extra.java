
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Extra {

    public static void main(String[] args) {
        Solution s1 = new Solution();
        // String s = "Hello world fvsagfffff asdfasdfDEWEEEEVCCCCCC";
        // System.out.println(s1.problem1(s));
        int[] arr = {2,2,2,2,2};
        System.out.println(s1.findKDistantIndices(arr, 2, 2));
    }

}

class Solution {

    String problem1(String problemString) {
        String[] words = problemString.split(" ");
        System.out.println("::: problem1 :::");
        Map<String, Integer> stringWithMaxFrequencies = new HashMap<>();

        for (String word : words) {
            stringWithMaxFrequencies.put(word, maxFrequencyFromWord(word));
        }

        int max = getMaxFromValues(stringWithMaxFrequencies.values());
        // System.out.println(stringWithMaxFrequencies);
        // System.out.println(max);
        String ans = "";

        if (max == 1) {
            return "-1";
        }

        for (Map.Entry<String, Integer> entry : stringWithMaxFrequencies.entrySet()) {
            if (entry.getValue() == max) {
                ans = entry.getKey();
                break;
            }
        }
        return ans;
    }

    int maxFrequencyFromWord(String word) {
        Map<Character, Integer> charCount = new HashMap<>();

        for (char ch : word.toCharArray()) {
            charCount.put(ch, charCount.getOrDefault(ch, 0) + 1);
        }

        return getMaxFromValues(charCount.values());
    }

    int getMaxFromValues(Collection<Integer> values) {
        int max = 0;

        for (int value : values) {
            if (value > max) {
                max = value;
            }
        }

        return max;
    }

    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        int start = 0;
        int end = nums.length - 1;

        ArrayList<Integer> keyIndices = new ArrayList<>();
        List<Integer> result = new ArrayList<>();

        while (end >= start) {
            if (nums[start] == key)
                keyIndices.add(start);

            if (nums[end] == key)
                keyIndices.add(end);

            start++;
            end--;
        }

        for (int i = 0; i < nums.length; i++) {
            if (isIndexValid(i, keyIndices, k)) {
                result.add(i);
            }
        }

        return result;
    }

    private boolean isIndexValid(int index,ArrayList<Integer> keyIndices,int k){
        for (Integer keyIndex : keyIndices) {
            if (subtractToPositive(index, keyIndex) <= k) {
                return true;
            }
        }

        return false;
    }

    public int subtractToPositive(int a, int b) {
        return Math.abs(a - b);
    }

}
