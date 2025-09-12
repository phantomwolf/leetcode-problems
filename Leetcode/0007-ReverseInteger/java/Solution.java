class Solution {
    public int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            // Detect overflow
            if (res > Integer.MAX_VALUE / 10 ||
                (res == Integer.MAX_VALUE && digit > 7)) {
                    return 0;
            }
            if (res < Integer.MIN_VALUE / 10 ||
                (res == Integer.MIN_VALUE / 10 && digit < -8)) {
                    return 0;
                }
            res = res * 10 + digit;
        }
        return res;
    }

    public int reverse2(int x) {
        int res = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            // Detect overflow
            if (res > (Integer.MAX_VALUE - digit) / 10 ||
                res < (Integer.MIN_VALUE - digit) / 10) {
                    return 0;
            }
            res = res * 10 + digit;
        }
        return res;
    }
}