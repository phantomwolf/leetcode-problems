#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 256


int getNextState(char *pat, int M, int state, int x)
{
    // If the character c is the same as next character in pattern,
    // then simply increment state
    if (state < M && x == pat[state])
        return state + 1;

    int ns, i; // ns stores the result which is next state

    // ns finally contains the longest prefix which is also suffix
    // in "pat[0..state-1]c"

    // Start from the largest possible value and stop when you find
    // a prefix which is also suffix
    // 当下一个字符x与模式pat的下一个字符不相同时，state有可能原地不动，或者跳到之前的state，
    // 所以第一层循环就是遍历所有可能跳转到的state。
    for (ns = state; ns > 0; ns--) {
        // state的数值，就是既是其适当后缀又是其前缀的字符串的长度。既然得知了长度，
        // 我们就可以去看看相应的字符串是否真的既是前缀又是后缀
        // 如果是的话，就返回新的state。
        if (pat[ns - 1] == x) {
            for (i = 0; i < ns - 1; i++) {
                if (pat[i] != pat[state - ns + 1 + i])
                    break;
            }
            if (i == ns - 1)
                return ns;
        }
    }
    return 0;
}


/* This function builds the TF table which represents Finite Automata for a
 * given pattern */
void computeTF(char *pat, int M, int TF[][NO_OF_CHARS])
{
    int state, x;
    for (state = 0; state <= M; ++state)
        for (x = 0; x < NO_OF_CHARS; ++x)
            TF[state][x] = getNextState(pat, M, state, x);
}


/* Prints all occurrences of pat in txt */
void search(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    int TF[M + 1][NO_OF_CHARS];

    computeTF(pat, M, TF);

    // Process txt over FA
    int i, state = 0;
    for (i = 0; i < N; ++i) {
        state = TF[state][txt[i]];
        if (state == M) {
            printf("Pattern found at index %d\n", i - M + 1);
        }
    }
}


int main()
{
    char *txt = "AABAACAADAABAAABAA";
    char *pat = "AABA";
    search(pat, txt);
    return 0;
}
