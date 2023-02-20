#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize){
    int result = 0;
    int temp_s = 0, temp_h = 0;
    int left_index = 0, right_index = heightSize - 1;
    while (left_index < right_index) {
        temp_h = fminl(height[left_index], height[right_index]);
        temp_s = temp_h * (right_index - left_index);
        result = temp_s > result ? temp_s : result;
        while (height[left_index] <= temp_h && left_index < right_index) {
            left_index++;
        }
        while (height[right_index] <= temp_h && left_index < right_index) {
            right_index--;
        }
    }
    return result;
}
