public class Solution {
    // Calculate the greatest common divisor of a and b
    public long gcd(long a, long b) {
        // Swap a and b if a < b
        if (a < b) {
            long tmp = a;
            a = b;
            b = tmp;
        }
        while (b != 0) {
            long tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

    // Calculate the least common multiple of a and b
    public long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    // Count all the numbers that can is divisible by a, b or c within [1, num]
    public long count(long num, long a, long b, long c) {
        long setA = num / a, setB = num / b, setC = num / c;
        long setAB = num / lcm(a, b);
        long setAC = num / lcm(a, c);
        long setBC = num / lcm(b, c);
        long setABC = num / lcm(c, lcm(a, b));
        return setA + setB + setC - setAB - setAC - setBC + setABC;
    }

    public int nthUglyNumber(int n, int a, int b, int c) {
        // binary search: searching for left boundary
        // window [left, right)
        int left = 1, right = (int) 2e9 + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            long midCount = count(mid, a, b, c);
            if (midCount < n) {
                left = mid + 1;
            } else if (midCount > n) {
                right = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
}