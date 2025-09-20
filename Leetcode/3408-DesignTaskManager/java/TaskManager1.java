public class TaskManager1 {
    // taskId -> [userId, taskId, priority]
    Map<Integer, List<Integer>> taskMap;
    // Sort by priority and taskId
    PriorityQueue<List<Integer>> taskQueue;

    public TaskManager(List<List<Integer>> tasks) {
        taskMap = new HashMap<>();
        taskQueue = new PriorityQueue<>((a, b) -> {
            // First, sort by priority
            int diff = b.get(2) - a.get(2);
            if (diff == 0) {
                // Second, sort by taskId
                diff = b.get(1) - a.get(1);
            }
            return diff;
        });

        // Add tasks
        for (List<Integer> task : tasks) {
            add(task.get(0), task.get(1), task.get(2));
        }
    }

    public void add(int userId, int taskId, int priority) {
        List<Integer> task = Arrays.asList(userId, taskId, priority);
        taskMap.put(taskId, task);
        taskQueue.add(task);
    }

    public void edit(int taskId, int newPriority) {
        List<Integer> task = taskMap.get(taskId);
        List<Integer> newTask = Arrays.asList(task.get(0), taskId, newPriority);
        rmv(taskId);
        taskMap.put(taskId, newTask);
        taskQueue.add(newTask);
    }

    public void rmv(int taskId) {
        List<Integer> task = taskMap.get(taskId);
        // Set userId to -1 to indicate it's deleted
        task.set(0, -1);
    }

    public int execTop() {
        while (!taskQueue.isEmpty()) {
            List<Integer> task = taskQueue.remove();
            if (task.get(0) == -1) {
                continue;
            }
            taskMap.remove(task.get(1));

            return task.get(0);
        }
        return -1;
    }
}

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager obj = new TaskManager(tasks);
 * obj.add(userId,taskId,priority);
 * obj.edit(taskId,newPriority);
 * obj.rmv(taskId);
 * int param_4 = obj.execTop();
 */