#include <stdio.h>
#include <stdlib.h>

// ตัวแปรระดับโลก
int globalVar1 = 1;
int globalVar2 = 2;
int globalVar3 = 3;

// ฟังก์ชัน Recursive 
void recursiveFunction(int count) {
    int stackVar = count;
    printf("Stack variable address (level %d): %p\n", count, (void*)&stackVar);

    // จองหน่วยความจำใน heap
    int* heapVar = (int*)malloc(sizeof(int));
    *heapVar = count;
    printf("Heap variable address (level %d): %p\n", count, (void*)heapVar);

    //not overflow
    if (count < 3) {
        recursiveFunction(count + 1);
    }
    //-----
    
    // overflow
    // recursiveFunction(count + 1);
    // -------

    // คืนหน่วยความจำกลับให้ heap
    free(heapVar);
}

int main() {
    printf("Global variable 1 address: %p\n", (void*)&globalVar1);
    printf("Global variable 2 address: %p\n", (void*)&globalVar2);
    printf("Global variable 3 address: %p\n", (void*)&globalVar3);

    recursiveFunction(1);

    return 0;
}
