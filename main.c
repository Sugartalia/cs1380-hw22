/* main.c - Natalia */
#include <stdio.h>
#include "lineup.h"

int main(void)
{
    char team[] = "Wolves";
    char buf[20];

    printf("%s len=%d\n", team, label_len(team));

    safe_copy(buf, (int)sizeof buf, team);
    printf("copy: %s\n", buf);

    safe_join(buf, (int)sizeof buf, "-A");
    printf("join: %s\n", buf);

    printf("match same -> %d\n", labels_match("Wolves", team));
    printf("match different -> %d\n", labels_match("Wolves", "Hawks"));
    printf("find olv -> %d\n", find_text(team, "olv"));
    printf("find xyz -> %d\n", find_text(team, "xyz"));

    print_label(NULL);
    printf("NULL len -> %d\n", label_len(NULL));

    return 0;
}
