import java.util.*;
import java.lang.*;


class Solution {
    public int numJewelsInStones(String J, String S) {
        Set<Character> set = new HashSet<Character>();
        for (int i=0; i < J.length(); i++) {
            Character c = new Character(J.charAt(i));
            set.add(c);
        }
        int jewels = 0;
        for (int i=0; i < S.length(); i++) {
            Character c = new Character(S.charAt(i));
            if (set.contains(c)) {
                jewels++;
            }
        }
        return jewels;
    }

    public static void main(String[] args) {
        String J = "aA";
        String S = "aAAbbbb";
        Solution sol = new Solution();
        int jewels = sol.numJewelsInStones(J, S);
        System.out.printf("Jewels: %d\n", jewels);
    }
}
