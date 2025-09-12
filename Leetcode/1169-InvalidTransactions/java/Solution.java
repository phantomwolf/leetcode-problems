record Transaction(String name, int time, int amount, String city, int index) {
    public static Transaction create(String transaction, int index) {
        String[] arr = transaction.split(",");
        return new Transaction(arr[0], Integer.parseInt(arr[1]), Integer.parseInt(arr[2]), arr[3], index);
    }
}

public class Solution {
    public List<String> invalidTransactions(String[] transactions) {
        // Corner case
        if (transactions.length == 0) {
            return new ArrayList<>();
        }

        Transaction[] arr = new Transaction[transactions.length];
        for (int i = 0; i < transactions.length; i++) {
            arr[i] = Transaction.create(transactions[i], i);
        }
        Arrays.sort(arr, (a, b) -> {
            int cmp = a.name().compareTo(b.name());
            if (cmp != 0) return cmp;
            return a.time() - b.time();
        });

        Set<Integer> invalidIndexes = new HashSet<>();
        for (int i = 0; i < arr.length; i++) {
            // case 1: amount exceeds $1000
            if (arr[i].amount() > 1000) {
                invalidIndexes.add(arr[i].index());
            }
            // case 2: within 60 minutes, same name, different city
            for (int j = i+1; j < arr.length; j++) {
                // arr is sorted by (name, time).
                // If different name or time not within 60 mins, no need to compare
                if (!arr[j].name().equals(arr[i].name()) || arr[j].time() - arr[i].time() > 60) {
                    break;
                }
                if (!arr[j].city().equals(arr[i].city())) {
                    invalidIndexes.add(arr[i].index());
                    invalidIndexes.add(arr[j].index());
                }
            }
        }
        return invalidIndexes.stream()
            .map(index -> transactions[index])
            .collect(Collectors.toList());
    }
}
