func searchMatrix(matrix [][]int, target int) bool {
    // bot: bottom
    top, bot := 0, len(matrix)-1
    for top <= bot {
        mid := top + (bot - top)/2
        if matrix[mid][0] < target {
            // search downwards
            top = mid + 1
        } else if matrix[mid][0] > target {
            bot = mid - 1
        } else {
            return true
        }
    }
    // bot is the row we're looking for
    if bot < 0 {
        // No such row exists
        return false
    }
    left, right := 0, len(matrix[0])-1
    for left <= right {
        mid := left + (right - left)/2
        if matrix[bot][mid] < target {
            left = mid + 1
        } else if matrix[bot][mid] > target {
            right = mid - 1
        } else {
            return true
        }
    }
    return false
}