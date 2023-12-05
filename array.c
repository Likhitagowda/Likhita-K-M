#include <stdio.h>
#include <stdlib.h>

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int candidate1 = 0, count1 = 0;
    int candidate2 = 1, count2 = 0;


    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

   
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        }
    }

  
    int* result = NULL;
    *returnSize = 0;

    if (count1 > numsSize / 3) {
        result = (int*)realloc(result, (*returnSize + 1) * sizeof(int));
        result[*returnSize] = candidate1;
        (*returnSize)++;
    }

    if (count2 > numsSize / 3 && candidate1 != candidate2) {
        result = (int*)realloc(result, (*returnSize + 1) * sizeof(int));
        result[*returnSize] = candidate2;
        (*returnSize)++;
    }

    return result;
}

int main() {
   
    int nums1[] = {3, 2, 3};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int returnSize1;
    int* result1 = majorityElement(nums1, numsSize1, &returnSize1);
    printf("Output for [3, 2, 3]: ");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d ", result1[i]);
    }
    printf("\n");

    int nums2[] = {1};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize2;
    int* result2 = majorityElement(nums2, numsSize2, &returnSize2);
    printf("Output for [1]: ");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");

    int nums3[] = {1, 2};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    int returnSize3;
    int* result3 = majorityElement(nums3, numsSize3, &returnSize3);
    printf("Output for [1, 2]: ");
    for (int i = 0; i < returnSize3; i++) {
        printf("%d ", result3[i]);
    }
    printf("\n");

   
    free(result1);
    free(result2);
    free(result3);

    return 0;
}
