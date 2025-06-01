import java.util.Random;

class QuickSelect {
    /**
     * Quick select algorithm: select the kth(starting from 0) smallest number in sorted order inside an array
     */
    public int quickSelect(int[] nums, int k) {
        int low = 0, high = nums.length - 1;
        while (true) {
            int pivot = partition(nums, low, high);
            if (pivot == k) {
                return nums[pivot];
            }
            if (k < pivot) {
                high = pivot - 1;
            } else {
                low = pivot + 1;
            }
        }
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    private int partition(int[] nums, int low, int high) {
        Random random = new Random();
        int pivot = random.nextInt(high - low + 1) + low;
        swap(nums, pivot, low);
        int i = low + 1;
        int j = high;
        while (true) {
            while (i <= high && nums[i] < nums[low]) {
                i++;
            }
            while (j >= 0 && nums[j] > nums[low]) {
                j--;
            }
            if (i >= j) {
                swap(nums, low, j);
                return j;
            }
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    public static void main(String[] args) {
        int[] nums = new int[]{3,2,3,1,2,4,5,5,6};
        int k = 5;
        QuickSelect qs = new QuickSelect();
        int res = qs.quickSelect(nums, k);
        System.out.println(res);
    }
}