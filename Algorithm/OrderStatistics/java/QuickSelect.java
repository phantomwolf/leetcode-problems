import java.util.Random;

class QuickSelect {
    /**
     * Quick select algorithm: select the kth(starting from 0) smallest number in sorted order inside an array
     */
    public int quickSelect(int[] nums, int k) {
        int left = 0, right = nums.length - 1;
        while (true) {
            int pivot = partition(nums, left, right);
            if (pivot == k) {
                return nums[pivot];
            }
            if (k < pivot) {
                right = pivot - 1;
            } else {
                left = pivot + 1;
            }
        }
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    private int partition(int[] nums, int left, int right) {
/* Uncomment the following to implement randomized quick select
        Random random = new Random();
        int pivot = random.nextInt(right - left + 1) + left;
        swap(nums, pivot, left);
*/
        int l = left + 1;
        int r = right;
        while (true) {
            while (l <= right && nums[l] < nums[left]) {
                l++;
            }
            while (r >= left && nums[r] > nums[left]) {
                r--;
            }
            if (l >= r) {
                swap(nums, left, r);
                return r;
            }
            swap(nums, l, r);
            l++;
            r--;
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