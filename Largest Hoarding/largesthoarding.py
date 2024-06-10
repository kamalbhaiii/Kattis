# Problem name: Largest Hoarding
# Solved by: Kamal

def max_rectangle_area(heights, widths, n):
    max_area = 0
    stack = []
    
    i = 0
    while i < n:
        if not stack or heights[stack[-1]] <= heights[i]:
            stack.append(i)
            i += 1
        else:
            h = heights[stack.pop()]
            width = 0
            if not stack:
                for j in range(i):
                    width += widths[j]
            else:
                for j in range(stack[-1] + 1, i):
                    width += widths[j]
            max_area = max(max_area, h * width)
    
    while stack:
        h = heights[stack.pop()]
        width = 0
        if not stack:
            for j in range(n):
                width += widths[j]
        else:
            for j in range(stack[-1] + 1, n):
                width += widths[j]
        max_area = max(max_area, h * width)
    
    return max_area

def main():
    n = int(input())
    
    heights = []
    widths = []
    for i in range(n):
        height, width = map(int, input().split())
        heights.append(height)
        widths.append(width)
    
    largest_area = max_rectangle_area(heights, widths, n)
    monthly_revenue = largest_area * 50
    
    print(f"{monthly_revenue}")

if __name__ == "__main__":
    main()
