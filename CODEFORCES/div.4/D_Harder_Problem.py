from collections import defaultdict

def solve():
    t = int(input())  # Read number of test cases
    
    for _ in range(t):
        n = int(input())  # Read the length of array a
        a = list(map(int, input().split()))  # Read the array a
        
        b = [0] * n  # Array to store the result
        freq = defaultdict(int)  # To track the frequency of elements in b
        mode_freq = defaultdict(int)  # To track the frequency of the modes
        max_freq = 0  # To keep track of the highest frequency
        
        for i in range(n):
            # Set the mode of the first i+1 elements
            # We want a[i] to be the mode of the sequence [b1, b2, ..., bi]
            if freq[a[i]] == max_freq:
                b[i] = a[i]
                freq[a[i]] += 1
            else:
                b[i] = a[i]
                freq[a[i]] += 1
            
            # Update the mode frequency and max frequency
            max_freq = max(max_freq, freq[a[i]])
        
        # Print the resulting array b
        print(" ".join(map(str, b)))

# Calling the solve function to execute the code
solve()
