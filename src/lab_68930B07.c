#include <stdio.h>
#include <string.h>
#include "get_line.h"
#include "essay.h"

#define MAXLEN 1000

const char ESSAY[] = "Ah Love! could you and I with Fate conspire \
To grasp this sorry Scheme of Things entire, \
Would not we shatter it to bits -- and then \
Re-mould it nearer to the Heart's Desire!";

int strindex(const char source[], char pattern[])
{
    if (source == NULL || pattern == NULL) {
        return -1;
    }

    size_t src_len = strlen(source);
    size_t pat_len = strlen(pattern);

    if (pat_len == 0) {
        return 0;
    }

    if (pat_len > src_len) {
        return -1;
    }

    for (size_t i = 0; i <= src_len - pat_len; i++) {
        size_t j = 0;
        while (j < pat_len && source[i + j] == pattern[j]) {
            j++;
        }
        if (j == pat_len) {
            return (int)i;
        }
    }

    return -1;
}

// DO NOT change the code below
#ifndef ___TEST___
int main(void)
{
    char pattern[MAXLEN] = "";

    printEssay(ESSAY);
    read_pattern_from_stdio( pattern, MAXLEN);
    int pos = strindex(ESSAY, pattern);
    printResult(ESSAY, pos);

    return 0;
}
#endif
// DO NOT change the code above

