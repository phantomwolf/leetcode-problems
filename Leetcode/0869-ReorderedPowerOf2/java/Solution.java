class Solution {
    public boolean reorderedPowerOf2(int n) {
        int[] inputCount = new int[10];
        int intputLength = countDigits(n, inputCount);
        // For each power of 2
        int num = 1;
        while (true) {
            int[] count = new int[10];
            int length = countDigits(num, count);

            if (length > intputLength) {
                // Impossible
                return false;
            }

            // Compare input number and a power of 2
            if (length == intputLength) {
                boolean res = true;
                for (int i = 0; i < count.length; i++) {
                    if (count[i] != inputCount[i]) {
                        res = false;
                        break;
                    }
                }
                if (res) {
                    return true;
                }
            }

            // Proceed to the next power of 2
            if (Integer.MAX_VALUE / 2 < num) {
                // Overflow
                return false;
            }
            num *= 2;
        }
    }

    // Helper function to calculate the length of an integer, and the count of each digit.
    private int countDigits(int n, int[] count) {
        int length = 0;
        while (n != 0) {
            int digit = n % 10;
            n /= 10;
            length++;
            count[digit]++;
        }
        return length;
    }
}