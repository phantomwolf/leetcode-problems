#include<stdio.h>
#include<string.h>
#define NO_OF_CHARS 256
 
/* This function builds the TF table which represents Finite Automata for a
 *    given pattern  */
// TF[state][char]，表示当处于状态state时，如果接受到字符char，会跳转到哪个状态
void computeTransFun(char *pat, int M, int TF[][NO_OF_CHARS])
{
    int i, lps = 0, x;

    //Fill entries in first row
    // 当state = 0时，仅当char等于pattern的第一个字符时，才能跳转到下一个状态1；
    // 否则停留在原来的状态0
    for (x =0; x < NO_OF_CHARS; x++)
        TF[0][x] = 0;
    TF[0][pat[0]] = 1;

    // Fill entries in other rows
    // 这个循环里，i代表状态，同时也是模式下一个字符的下标；x表示字符
    for (i = 1; i<= M; i++) {
        // Copy values from row at index lps
        for (x = 0; x < NO_OF_CHARS; x++)
            TF[i][x] = TF[lps][x];

        // Update the entry corresponding to this character
        TF[i][pat[i]] = i + 1;

        // Update lps for next row to be filled
        if (i < M)
            lps = TF[lps][pat[i]];
    }
}


/* Prints all occurrences of pat in txt */
void search(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    int TF[M+1][NO_OF_CHARS];

    computeTransFun(pat, M, TF);

    // process text over FA.
    int i, j=0;
    for (i = 0; i < N; i++) {
        j = TF[j][txt[i]];
        if (j == M)
            printf ("\n pattern found at index %d", i-M+1);
    }
}

/* Driver program to test above function */
int main()
{
    char *txt = "GEEKS FOR GEEKS";
    char *pat = "GEEKS";
    search(pat, txt);
    getchar();
    return 0;
}
