package ShortestBridge;

public class Pair {
    public int i;
    public int j;

    public Pair(int i, int j) {
        this.i = i;
        this.j = j;
    }

    public String toString() {
        return String.format("(%d,%d)", i, j);
    }
}
