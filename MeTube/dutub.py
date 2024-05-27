# Problem name: MeTube
# Solved by: Kamal

def min_time_to_watch_videos(n, videos):
    from sys import maxsize

    # There are at most 10 categories (a to j)
    total_categories = 10
    INF = maxsize
    dp = [INF] * (1 << total_categories)
    dp[0] = 0
    
    for length, categories in videos:
        cat_mask = 0
        for c in categories:
            cat_mask |= (1 << (ord(c) - ord('a')))
        
        # Update dp array with the current video
        for mask in range((1 << total_categories) - 1, -1, -1):
            new_mask = mask | cat_mask
            dp[new_mask] = min(dp[new_mask], dp[mask] + length)
    
    # The bitmask representing all categories covered
    all_categories_mask = (1 << total_categories) - 1
    
    # Find the minimum time to cover all mentioned categories
    result = INF
    for mask in range(1 << total_categories):
        if dp[mask] < INF:
            covered_categories = 0
            for i in range(total_categories):
                if mask & (1 << i):
                    covered_categories |= (1 << i)
            if covered_categories == all_categories_mask:
                result = min(result, dp[mask])
    
    return result

# Read input
import sys
input = sys.stdin.read
data = input().strip().split('\n')

n = int(data[0])
videos = []
for i in range(1, n + 1):
    parts = data[i].split()
    length = int(parts[0])
    categories = parts[1]
    videos.append((length, categories))

# Get the result
result = min_time_to_watch_videos(n, videos)
print(result)
