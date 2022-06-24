import java.lang.*;
import java.util.*;


public class Main {
    public static void main(String[] args) {
        calc(3, 0);
    }

    static void calc(int n, int c) {
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) == 1) {
                    System.out.printf("s += a[%d + c]%n", j);
                }
            }
            System.out.printf("x[%d] = s%n", i);
        }
    }
}
