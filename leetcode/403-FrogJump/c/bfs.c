#include <glib.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


#define BITS(type)                  (sizeof(type) * 8)
#define SET_PROBE(key)             (1 << ((BITS(uint8_t) - 1) - (key) % BITS(uint8_t)))
#define SET_BITMAP_ITEM(set, key)   ((set)->bitmap[(key) / BITS(uint8_t)])
#define SET_FIND(set, key)          (SET_BITMAP_ITEM(set, key) & SET_PROBE(key))


typedef struct BitmapSet BitmapSet;
struct BitmapSet {
    uint8_t *bitmap;
    size_t size;
};

typedef struct Step Step;
struct Step {
    int pos;
    int last_pace;
};

void print_bitmap(BitmapSet *set)
{
    printf("bitmap: ");
    for (int i = 0; i < set->size * BITS(uint8_t); ++i) {
        if (SET_FIND(set, i)) {
            printf("%d, ", i);
        }
    }
    puts("");
}

BitmapSet *stonesToBitmap(int *stones, int stonesSize)
{
    BitmapSet *set = (BitmapSet *)malloc(sizeof(BitmapSet));
    set->size = stones[stonesSize - 1] / BITS(uint8_t) + 1;
    set->bitmap = (uint8_t *)malloc(sizeof(uint8_t) * set->size);
    memset(set->bitmap, 0, sizeof(uint8_t) * set->size);
    for (int i = 0; i < stonesSize; ++i) {
        uint8_t probe = SET_PROBE(stones[i]);
        SET_BITMAP_ITEM(set, stones[i]) |= probe;
    }
    return set;
}

bool canCross(int* stones, int stonesSize)
{
    
    BitmapSet *set = stonesToBitmap(stones, stonesSize);
    GQueue *queue = g_queue_new();

    Step *step = (Step *)malloc(sizeof(Step));
    step->pos = stones[1];
    step->last_pace = 1;

    bool res = false;
    g_queue_push_tail(queue, step);
    while (!g_queue_is_empty(queue)) {
        step = g_queue_pop_head(queue);
        for (int pace = step->last_pace - 1; pace <= step->last_pace + 1; ++pace) {
            if (pace == 0)
                continue;
            int next_pos = step->pos + pace;
            if (next_pos == stones[stonesSize - 1]) {
                free(step);
                res = true;
                goto finish;
            }
            if (SET_FIND(set, next_pos)) {
                Step *new_step = (Step *)malloc(sizeof(Step));
                new_step->pos = next_pos;
                new_step->last_pace = pace;
                g_queue_push_tail(queue, new_step);
            }
        }
        free(step);
    }

finish:
    while (!g_queue_is_empty(queue)) {
        step = g_queue_pop_head(queue);
        free(step);
    }
    g_queue_free(queue);
    free(set->bitmap);
    free(set);
    return res;
}


int main(int argc, char *argv[])
{
    //int stones[] = {0, 1, 3, 5, 6, 8, 12, 17};
    int stones[] = {0,1,2,3,4,8,9,11};
    if (canCross(stones, sizeof(stones) / sizeof(int))) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}
