#include <stdio.h>

int removeDuplicatasSimples(int* nums, int numsSize) {
    int novoTamanho = numsSize;

    for (int i = 0; i < novoTamanho - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            for (int j = i + 1; j < novoTamanho - 1; j++) {
                nums[j] = nums[j + 1];
            }
            novoTamanho--;
            i--;
        }
    }
    return novoTamanho;
}

int main() {
    int nums[] = {1, 1, 2, 3, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int novoTamanho = removeDuplicatasSimples(nums, numsSize);

    printf("Array apos remover duplicatas:\n");
    for (int i = 0; i < novoTamanho; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
