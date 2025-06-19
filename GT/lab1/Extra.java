
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public class Extra {

    public static void main(String[] args) {
        Solution s1 = new Solution();
        String s = "Hello world";
        s1.problem1(s);

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
        System.out.println(stringWithMaxFrequencies);
        System.out.println(max);

        return "";
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
}
