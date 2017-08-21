CountDiv
======================================================
Compute number of integers divisible by k in range [a..b]

Description
----------------------------------------------
Write a function:

    int solution(int A, int B, int K);

that, given three integers A, B and K, returns the number of integers within the range [A..B] that are divisible by K, i.e.:

    { i : A ≤ i ≤ B, i mod K = 0 }

For example, for A = 6, B = 11 and K = 2, your function should return 3, because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10.

Assume that:

        A and B are integers within the range [0..2,000,000,000];
        K is an integer within the range [1..2,000,000,000];
        A ≤ B.

Complexity:

        expected worst-case time complexity is O(1);
        expected worst-case space complexity is O(1).

解答
----------------------------------------------
找出[A, B]中能被K整除的数。千万不要真的一个个去求余，只要找出范围内第一个可以被K整除的数，以及最后一个能被K整除的数，计算它们之间的距离。
