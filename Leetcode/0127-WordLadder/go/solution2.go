import (
	"container/list"
)

func ladderLength(beginWord string, endWord string, wordList []string) int {
	dict := map[string][]string{}
	for _, word := range wordList {
		for i := 0; i < len(word); i++ {
			maskedWord := word[:i] + "*" + word[i+1:]
			if _, exists := dict[maskedWord]; !exists {
				dict[maskedWord] = []string{}
			}
			dict[maskedWord] = append(dict[maskedWord], word)
		}
	}
	// BFS
	visited := map[string]bool{}
	queue := list.New()
	queue.PushBack(beginWord)
	visited[beginWord] = true
	steps := 1
	for queue.Len() > 0 {
		for size := queue.Len(); size > 0; size-- {
			word := queue.Front().Value.(string)
			queue.Remove(queue.Front())
			// Check if destination reached
			if word == endWord {
				return steps
			}
			// Visit adjacent words
			for i := 0; i < len(word); i++ {
				maskedWord := word[:i] + "*" + word[i+1:]
				for _, next := range dict[maskedWord] {
					if visited[next] {
						continue
					}
					visited[next] = true
					queue.PushBack(next)
				}
			}
		}
		steps++
	}
	return 0
}