/* lineup.c - Natalia */
#include <stdio.h>
#include <string.h>
#include "lineup.h"

void print_label(const char label[])
{
    if (label == NULL) {
        return;
    }
    printf("%s", label);
}

int label_len(const char label[])
{
    if (label == NULL) {
        return 0;
    }
    return (int)strlen(label);
}

void safe_copy(char dest[], int dest_size, const char src[])
{
    if (dest == NULL || dest_size <= 0) {
        return;
    }
    if (src == NULL) {
        dest[0] = '\0';
        return;
    }
    strncpy(dest, src, (size_t)(dest_size - 1));
    dest[dest_size - 1] = '\0';
}

void safe_join(char dest[], int dest_size, const char extra[])
{
    if (dest == NULL || dest_size <= 0 || extra == NULL) {
        return;
    }
    int used = (int)strlen(dest);
    int room = dest_size - 1 - used;   /* chars that still fit */
    if (room <= 0) {
        return;
    }
    strncat(dest, extra, (size_t)room);
}

int labels_match(const char a[], const char b[])
{
    if (a == NULL || b == NULL) {
        return 0;
    }
    return strcmp(a, b) == 0 ? 1 : 0;
}

int find_text(const char label[], const char needle[])
{
    if (label == NULL || needle == NULL) {
        return -1;
    }
    const char *found = strstr(label, needle);
    if (found == NULL) {
        return -1;
    }
    return (int)(found - label);
}
