#include <stdio.h>

int removeDuplicatasEficiente(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int j = 1; 
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[j] = nums[i]; 
            j++;
        }
    }
    return j; 
}

int main() {
    int nums[] = {1, 1, 2, 3, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int novoTamanho = removeDuplicatasEficiente(nums, numsSize);

    printf("Array apos remover duplicatas:\n");
    for (int i = 0; i < novoTamanho; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
