class Solution {
    public int minSwapsCouples(int[] row) {
        Map<Integer, Integer> idToSeat = new HashMap<>();
        for (int i = 0; i < row.length; i++) {
            idToSeat.put(row[i], i);
        }

        int minSwaps = 0;
        for (int i = 0; i < row.length; i += 2) {
            int couple = row[i] ^ 1;
            if (row[i+1] == couple) {
                continue;
            }

            // Swap
            int j = idToSeat.get(couple);
            int tmp = row[i+1];
            row[i+1] = row[j];
            row[j] = tmp;
            minSwaps++;

            idToSeat.put(couple, i+1);
            idToSeat.put(row[j], j);
        }
        return minSwaps;
    }
}