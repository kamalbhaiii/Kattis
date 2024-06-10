// Problem name: Largest Hoarding
// Solved by: Kamal
// Test cases failed

#include <stdio.h>
#include <stdlib.h>

int maxRectangleArea(int heights[], int widths[], int n) {
    int max_area = 0;
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;
    int i = 0;
    int* left_width = (int*)malloc(n * sizeof(int));
    int* right_width = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        left_width[i] = widths[i];
        right_width[i] = widths[i];
    }

    while (i < n) {
        if (top == -1 || heights[stack[top]] <= heights[i]) {
            stack[++top] = i++;
        } else {
            int h = heights[stack[top--]];
            int width = 0;
            if (top == -1) {
                for (int j = 0; j < i; j++) {
                    width += widths[j];
                }
            } else {
                for (int j = stack[top] + 1; j < i; j++) {
                    width += widths[j];
                }
            }
            int area = h * width;
            if (area > max_area) {
                max_area = area;
            }
        }
    }

    while (top != -1) {
        int h = heights[stack[top--]];
        int width = 0;
        if (top == -1) {
            for (int j = 0; j < n; j++) {
                width += widths[j];
            }
        } else {
            for (int j = stack[top] + 1; j < n; j++) {
                width += widths[j];
            }
        }
        int area = h * width;
        if (area > max_area) {
            max_area = area;
        }
    }

    free(stack);
    free(left_width);
    free(right_width);
    return max_area;
}

int main() {
    int n;
    scanf("%d", &n);

    int* heights = (int*)malloc(n * sizeof(int));
    int* widths = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &heights[i], &widths[i]);
    }

    int largest_area = maxRectangleArea(heights, widths, n);
    int monthly_revenue = largest_area * 50;

    printf("%d\n", monthly_revenue);

    free(heights);
    free(widths);
    return 0;
}