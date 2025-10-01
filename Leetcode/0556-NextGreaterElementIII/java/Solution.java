class Solution {
    public int nextGreaterElement(int n) {
        List<Integer> digits = new ArrayList<>();

        int num = n;
        while (num != 0) {
            int digit = num % 10;
            num /= 10;
            digits.add(digit);
        }
        // Digits: [1, 2]
        Collections.reverse(digits);

        if (!nextPermutation(digits)) {
            return -1;
        }

        // Re-assemble number
        num = 0;
        for (int digit : digits) {
            if (num > Integer.MAX_VALUE/10 ||
                (num == Integer.MAX_VALUE/10 && digit > 7)) {
                return -1;
            }
            num = num * 10 + digit;
        }
        return num;
    }

    private boolean nextPermutation(List<Integer> digits) {
        int i = digits.size()-2;
        while (i >= 0 && digits.get(i) >= digits.get(i+1)) {
            i--;
        }
        if (i < 0) {
            // Impossible
            return false;
        }

        int j = digits.size()-1;
        while (digits.get(j) <= digits.get(i)) {
            j--;
        }

        // swap digits[i] and digits[j]
        int tmp = digits.get(i);
        digits.set(i, digits.get(j));
        digits.set(j, tmp);

        // Reverse last part
        int a = i+1, b = digits.size()-1;
        while (a < b) {
            tmp = digits.get(a);
            digits.set(a, digits.get(b));
            digits.set(b, tmp);
            a++;
            b--;
        }
        return true;
    }
}
