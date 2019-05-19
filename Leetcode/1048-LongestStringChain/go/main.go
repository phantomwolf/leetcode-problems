package main

import "sort"

type ByLength []string

func (a ByLength) Len() int {
    return len(a)
}

func (a ByLength) Swap(i, j int) {
    a[i], a[j] = a[j], a[i]
}

func (a ByLength) Less(i, j int) bool {
    return len(a[i]) < len(a[j])
}

func isPredecessor(a, b string) bool {
    if len(a) + 1 != len(b) {
        return false
    }
    i, j := 0, 0
    for j < len(b) {
        if i == len(a) || a[i] != b[j] {
            j++
            continue
        }
        i++
        j++
    }
    if i == len(a) && j == len(b) {
        return true
    }
    return false
}

// d[i]: max length of word chain using word_0..word_i, and word_i must be selected
func longestStrChain(words []string) int {
    sort.Sort(ByLength(words))
    d := make([]int, len(words))
    longest := 1
    for i := 0; i < len(words); i++ {
        d[i] = 1
        for j := 0; j < i; j++ {
            if isPredecessor(words[j], words[i]) {
                if d[j] + 1 > d[i] {
                    d[i] = d[j] + 1
                }
            }
        }
        if longest < d[i] {
            longest = d[i]
        }
    }
    return longest
}

func main() {
    words := []string{"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"}
    res := longestStrChain(words)
}
