/* The knows API is defined in the parent class Relation.
      boolean knows(int a, int b); */

public class Solution extends Relation {
    public int findCelebrity(int n) {
        // Candidate of celebrity. Suppose 0 is the celebrity
        int cand = 0;
        // Iterate all people
        for (int i = 1; i < n; i++) {
            if (!knows(i, cand) || knows(cand, i)) {
                // If i doesn't know cand, or cand knows i, cand is absolutely not a celebrity
                // Change cand to i to see if it's a celebrity
                cand = i;
            } else {
                // i is absolutely not a celebrity. Nothing needs to be done.
                // We continue to suppose that cand is a celebrity
            }
        }
        // Now cand is the only possible candidate of the celebrity(if any)
        // We do a final check to see if it's really a celebrity
        for (int i = 0; i < n; i++) {
            if (i == cand) {
                continue;
            }
            if (!knows(i, cand) || knows(cand, i)) {
                // Celebrity doesn't exist
                return -1;
            }
        }
        return cand;
    }
}