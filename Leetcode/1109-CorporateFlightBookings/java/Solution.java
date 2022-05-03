public class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] diff = new int[n];
        for (int[] booking : bookings) {
            int first = booking[0] - 1, last = booking[1] - 1, seats = booking[2];
            diff[first] += seats;
            if (last + 1 < n) {
                diff[last + 1] -= seats;
            }
        }
        int[] answer = new int[n];
        answer[0] = diff[0];
        for (int i = 1; i < n; i++) {
            answer[i] = answer[i - 1] + diff[i];
        }
        return answer;
    }

    public static void main(String[] args) {
    }
}
