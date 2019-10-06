import java.util.Arrays;

public class QuickSort {

	public static void main(String[] args) {
		int[] nums = {3,3, 3, 3, 3,3, 3, 1, 3,3 ,3 ,3};
		quickSort(nums, 0, nums.length-1);
		System.out.println(Arrays.toString(nums));
		int k = 4;
		int result = quickSelect(nums, 0, nums.length-1, k);
		System.out.println(result);
	}

	public static int partition(int[] nums, int left, int right) {
		if (left == right) {
			return left;
		}
		// naive method: choose first element as pivot
		int l = left+1;
		int r = right;
		while (true) {
			while (l <= right && nums[l] > nums[left]) {
				++l;
			}
			while (r >= left+1 && nums[r] < nums[left]) {
				--r;
			}
			if (l >= r) {
				int tmp = nums[left];
				nums[left] = nums[l-1];
				nums[l-1] = tmp;
				return l-1;
			}
			// Swap nums[l] and nums[r]
			int tmp = nums[l];
			nums[l] = nums[r];
			nums[r] = tmp;
            l++;
            r--;
		}
	}

	public static int quickSelect(int[] nums, int left, int right, int k) {
		int pivot = partition(nums, left, right);
		if (pivot == k-1) {
			return nums[pivot];
		}
		if (pivot > k-1) {
			return quickSelect(nums, left, pivot-1, k);
		} else {
			return quickSelect(nums, pivot+1, right, k);
		}
	}
	
	public static void quickSort(int[] nums, int left, int right) {
		int pivot = partition(nums, left, right);
		if (pivot-1 > left) {
			quickSort(nums, left, pivot-1);
		}
		if (pivot+1 < right) {
			quickSort(nums, pivot+1, right);
		}
	}
}
