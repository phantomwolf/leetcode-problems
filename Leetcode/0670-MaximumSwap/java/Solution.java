public class Solution {
    public int maximumSwap(int num) {
        int n = num;
        int[] swap = null;
        int maxDigit = -1;
        int maxDigitMag = 0;
    
        int mag = 0;
        while (n > 0) {
            int digit = n % 10;
            if (digit < maxDigit) {
                // We can make a swap to get a better result
                swap = new int[]{digit, mag, maxDigit, maxDigitMag};
            }
            // Update max digit seen so far
            if (digit > maxDigit) {
                maxDigit = digit;
                maxDigitMag = mag;
            }
            // Proceed to next digit
            mag++;
            n /= 10;
        }
        if (swap == null) {
            // No swap can be done
            return num;
        }
        // Do the swap
        swap[1] = (int) Math.pow(10, swap[1]);
        swap[3] = (int) Math.pow(10, swap[3]);
        return num - swap[0] * swap[1] - swap[2] * swap[3] + swap[0] * swap[3] + swap[2] * swap[1];
    }
}