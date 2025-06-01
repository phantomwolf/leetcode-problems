import java.lang.*;
import java.util.*;
import java.util.stream.Collectors;

class Solution1 {
    private String q2s(int[] A, Deque<Integer> q) {
        return q.stream().map(i -> A[i]).collect(Collectors.toList()).toString();
    }

    private void print(int[] A, int i, int j, int l, int r, Deque<Integer> q) {
        System.out.printf(" ");
        for (int m = 0; m < A.length; m++) {
            if (m == i) {
                System.out.printf("i");
            } else if (m == j) {
                System.out.printf("j");
            } else {
                System.out.printf(" ");
            }
            System.out.printf("  ");
        }
        System.out.printf("\n%s, q=%s\n ", Arrays.toString(A), q2s(A, q));
        for (int m = 0; m < A.length; m++) {
            if (m == l) {
                System.out.printf("l");
            } else if (m == r) {
                System.out.printf("r");
            } else {
                System.out.printf(" ");
            }
            System.out.printf("  ");
        }
        System.out.printf("\n");
    }

    public long countNonDecreasingSubarrays(int[] A, long k) {
        // Reverse the array
        int n = A.length;
        for (int i = 0; i < n / 2; ++i) {
            int temp = A[i];
            A[i] = A[n - 1 - i];
            A[n - 1 - i] = temp;
        }

        long res = 0;
        Deque<Integer> queue = new ArrayDeque<>();
        for (int j = 0, i = 0; j < A.length; ++j) {
            while (!queue.isEmpty() && A[queue.peekLast()] < A[j]) {
                int r = queue.pollLast();
                int l = queue.isEmpty() ? i - 1 : queue.peekLast();
                print(A, i, j, l, r, queue);
                k -= 1L * (r - l) * (A[j] - A[r]);
                System.out.printf("k -= (r - l) * (A[j] - A[r]) = (%d - %d) * (%d - %d), k = %d\n", r, l, A[j], A[r], k);
            }
            queue.addLast(j);
            System.out.printf("q = %s, i = %d\n", q2s(A, queue), i);
            while (k < 0) {
                k += A[queue.peekFirst()] - A[i];
                System.out.printf("k += A[queue.peekFirst()] - A[i] = %d - %d, k = %d\n", A[queue.peekFirst()], A[i], k);
                if (queue.peekFirst() == i) {
                    queue.pollFirst();
                }
                ++i;
                System.out.printf("q = %s, i = %d\n", q2s(A, queue), i);
            }
            res += j - i + 1;
            System.out.printf("res += j - i + 1 = %d - %d + 1, res = %d\n", j, i, res);
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = new int[]{6,3,1,2,4,4};
        int k = 7;
        Solution1 s = new Solution1();
        s.countNonDecreasingSubarrays(nums, k);
    }
}