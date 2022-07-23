package SurroundedRegions;

// do DFS starting from the borders
public class Solution {
    public void solve(char[][] board) {
        int M = board.length, N = board[0].length;
        boolean[][] visited = new boolean[M][N];
        for (int i = 0; i < M; i++) {
            dfs(board, i, 0, visited);
            dfs(board, i, N - 1, visited);
        }
        for (int j = 0; j < N; j++) {
            dfs(board, 0, j, visited);
            dfs(board, M - 1, j, visited);
        }
        // Flip unvisited O
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    private void dfs(char[][] board, int i, int j, boolean[][] visited) {
        if (board[i][j] == 'X' || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        for (int[] arr : neighbors(i, j)) {
            int m = arr[0], n = arr[1];
            if (m < 0 || m >= board.length || n < 0 || n >= board[0].length) {
                // out of range
                continue;
            }
            dfs(board, m, n, visited);
        }
    }

    private int[][] neighbors(int i, int j) {
        return new int[][]{
                {i + 1, j},
                {i - 1, j},
                {i, j + 1},
                {i, j - 1},
        };
    }
}
