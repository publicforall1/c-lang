#include "lib/heap.h"
#include <stdio.h>

// Demo Max Heap
//
//     73
//     /\
//   68 55
//   /\
// 65 57
//

int main(void) {
    Heap h;
    init_heap(&h);

    append_heap(&h, 57);
    append_heap(&h, 68);
    append_heap(&h, 55);
    append_heap(&h, 63);
    append_heap(&h, 73);

    build_max_heap(&h);

    print_heap_sort(h);
    show_heap(h);

    return 0;
}