class RandomizedSet {
    // val -> index
    private Map<Integer, Integer> map;
    // A list of val
    private List<Integer> list;
    
    Random random = new Random();

    public RandomizedSet() {
        map = new HashMap<>();
        list = new ArrayList<>();
    }
    
    public boolean insert(int val) {
        if (map.containsKey(val)) {
            return false;
        }

        map.put(val, list.size());
        list.add(val);
        return true;
    }
    
    public boolean remove(int val) {
        int index = map.getOrDefault(val, -1);
        if (index == -1) {
            // val not present
            return false;
        }

        // Move last element to the location of val
        int lastElement = list.get(list.size()-1);
        list.set(index, lastElement);
        map.put(lastElement, index);
        // Remove val from map
        map.remove(val);
        // Remove last position of list(time complexity O(1) because it's the last element of an array)
        list.remove(list.size() - 1);
        return true;
    }
    
    public int getRandom() {
        return list.get(random.nextInt(list.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */