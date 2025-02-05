#include<stdio.h>

//too slow

void rot(int* nums, int numsSize){
    int temp1 = nums[0];
    for (int i = 0; i < numsSize - 1; i++){
        int temp2 = nums[i+1];
        nums[i+1] = temp1;
        temp1 = temp2;
    }
    nums[0] = temp1;
}

void rotate(int* nums, int numsSize, int k) {
    for (int i = 0; i < (k%numsSize); i++){
        rot(nums, numsSize);
    }
}

void printArr(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++){
        printf("%d\n", nums[i]);
    }
}

int main(){
    int arr[7] = {1,2,3,4,5,6,7};
    int arrSize = 7;
    rotate(arr, arrSize,3);
    printArr(arr,arrSize);
    return 0;
}