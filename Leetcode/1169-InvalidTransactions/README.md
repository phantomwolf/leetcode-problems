# 1169. Invalid Transactions
A transaction is possibly invalid if:

1. the amount exceeds $1000, or;
2. if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.

You are given an array of strings transaction where transactions[i] consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.

Return a list of transactions that are possibly invalid. You may return the answer in any order.

Example 1:

Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
Output: ["alice,20,800,mtv","alice,50,100,beijing"]
Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
Example 2:

Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
Output: ["alice,50,1200,mtv"]
Example 3:

Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
Output: ["bob,50,1200,mtv"]

Constraints:

* transactions.length <= 1000
* Each transactions[i] takes the form "{name},{time},{amount},{city}"
* Each {name} and {city} consist of lowercase English letters, and have lengths between 1 and 10.
* Each {time} consist of digits, and represent an integer between 0 and 1000.
* Each {amount} consist of digits, and represent an integer between 0 and 2000.

## Solution
There're 2 cases where transactions are invalid:

1. transaction amount exceeds 1000
2. If 2 transactions are done within 60 minutes, with same name and different city, both of these 2 transactions are invalid.

Because of case 2, we need to group transactions with the same name and adjacent times together. This can be done via sorting by (name, time). Once we sorted the transactions, starting from transactions[i], let `j = i+1` and linearly scan towards right:

* If `transaction[j].name != transaction[i]`, stop scanning because we've scanned all transactions with the same name.
* If `transaction[j].time - transaction[i].time`, stop scanning because we've scanned all transactions within 60 minutes of transaction[i].
* Otherwise, if `transaction[j].city` and `transaction[i].city` are different, record both `i` and `j` to a hash set.

Finally, convert the hash set to a list of transactions and return.

### Why record the indexes of transactions, not the transaction string themselves?
The problem allows duplicated transactions. Consider the following transactions:

`["alice,20,500,sea", "alice,20,500,sea", "alice,30,500,chi"]`

All 3 transactions are invalid, both transactions[0] and transactions[1] conflicts with transactions[2]. If we record the transaction strings in a hash set, transactions[0] and transactions[1] will become a single entry, which is incorrect.
