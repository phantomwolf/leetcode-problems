/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
*/
int *findAnagrams(char *s, char *p, int *returnSize)
{
    unsigned int plen, slen;
    unsigned int pcount[26] = {0};
    unsigned int scount[26] = {0};
    for (plen = 0; p[plen] != '\0'; ++plen) {
        ++pcount[p[plen] - 'a'];
    }
    for (slen = 0; s[plen + slen] != '\0'; ++slen) {
    }
}
