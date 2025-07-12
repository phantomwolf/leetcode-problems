// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

class PeekingIterator implements Iterator<Integer> {
    private Integer val;
    private boolean hasNextVal;
    private Iterator<Integer> iter;

    public PeekingIterator(Iterator<Integer> iterator) {
        // initialize any member here.
        iter = iterator;
        hasNextVal = iter.hasNext();
        val = hasNextVal ? iter.next() : null;
    }

    // Returns the next element in the iteration without advancing the iterator.
    public Integer peek() {
        return val;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    @Override
    public Integer next() {
        Integer res = val;
        hasNextVal = iter.hasNext();
        val = hasNextVal ? iter.next() : null;
        return res;
    }

    @Override
    public boolean hasNext() {
        return hasNextVal;
    }
}