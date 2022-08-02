package boatstosavepeople;

import java.util.Arrays;

public class GreedySolution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int l = 0, r = people.length - 1;
        int res = 0;
        while (l <= r) {
            if (l == r) {
                res++;
                break;
            }
            int sum = people[l] + people[r];
            if (sum <= limit) {
                res++;
                l++;
                r--;
            } else {
                res++;
                r--;
            }
        }
        return res;
    }
}
