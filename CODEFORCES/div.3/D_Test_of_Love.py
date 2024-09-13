def can_ernkor_cross(t, test_cases):
    results = []
    
    for i in range(t):
        n, m, k = test_cases[i][:3]
        river = test_cases[i][3]
        
        possible = False
        
        # Initialize the list to track the minimum swimming distance to each position
        swim_dist = [float('inf')] * (n + 1)
        swim_dist[0] = 0  # Starting point on the left bank
        
        # BFS-like approach to check all reachable positions
        queue = [(0, 0)]  # (current_position, current_swim_dist)
        
        while queue:
            pos, swim = queue.pop(0)
            
            # Try to jump within the allowed range
            for jump in range(1, m + 1):
                next_pos = pos + jump
                
                if next_pos == n + 1:
                    possible = True
                    break
                elif next_pos <= n:
                    if river[next_pos - 1] == 'C':
                        continue
                    elif river[next_pos - 1] == 'W':
                        if swim + 1 <= k and swim + 1 < swim_dist[next_pos]:
                            swim_dist[next_pos] = swim + 1
                            queue.append((next_pos, swim + 1))
                    elif river[next_pos - 1] == 'L':
                        if swim < swim_dist[next_pos]:
                            swim_dist[next_pos] = swim
                            queue.append((next_pos, swim))
            
            if possible:
                break
        
        if possible:
            results.append("YES")
        else:
            results.append("NO")
    
    return results


# Read input
t = int(input().strip())
test_cases = []

for _ in range(t):
    n, m, k = map(int, input().strip().split())
    river = input().strip()
    test_cases.append((n, m, k, river))

# Get results
results = can_ernkor_cross(t, test_cases)

# Print results
for result in results:
    print(result)
