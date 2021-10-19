#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct table_entry {
    int page_idx;
    unsigned int cnts;
} table_entry;


int main() {
    int n;
    scanf("%d", &n);

    FILE *file = fopen("input.txt", "r");

    table_entry* table = malloc(n * sizeof(table_entry));

    for (int i = 0; i < n; ++i) {
        table_entry cur;
        cur.page_idx = -1;
        cur.cnts = 0u;
        table[i] = cur;
    }

    int cur_requested;
    unsigned int hit_cnt = 0;
    unsigned int miss_cnt = 0;

    while (fscanf(file, "%d", &cur_requested) == 1) {
        bool page_found = 0;

        for (int i = 0; i < n; ++i) {
            if (table[i].page_idx == cur_requested) {
                page_found = 1;
                break;
            }
        }

        if (page_found)
            hit_cnt++;
        else
            miss_cnt++;

        if (!page_found) {
            bool fs = 0;
            for (int i = 0; i < n; ++i) {
                if (table[i].page_idx == -1) {
                    table_entry page;
                    page.page_idx = cur_requested;
                    page.cnts = 0;
                    table[i] = page;
                    fs = 1;
                    break;
                }
            }

            if (fs)
                continue;

            unsigned int min_cnt = INT_MAX;
            unsigned int idx = -1;
            for (int i = 0; i < n; ++i) {
                if (min_cnt > table[i].cnts) {
                    min_cnt = table[i].cnts;
                    idx = i;
                }
            }

            table_entry page;
            page.page_idx = cur_requested;
            page.cnts = 0;
            table[idx] = page;
        }

        for (int i = 0; i < n; ++i) {
            table[i].cnts >>= 1;

            if (page_found && cur_requested == table[i].page_idx)
                table[i].cnts |= 1 << 31;
        }
    }

    printf("hits: %d\n", hit_cnt);
    printf("misses: %d\n", miss_cnt);
    printf("ratio: %f\n", (float) hit_cnt / (float) miss_cnt);

    free(table);
    fclose(file);

    /*
    * n=10 8 hits, 992 misses, ratio 0.008065
    * n=50 50 hits, 950 misses, ratio 0.052632
    * n=100 93 hits, 907 misses, ration 0.102536
    */

    return 0;
}
