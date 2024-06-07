def max_chickens_earned(n,A):
    if (n < 1):
        return -1
    if (n == 1):
        return max(A[0], -A[0])
    if (n == 2):
        return max(A[0] + A[1], A[0] - A[1], -A[0] + A[1], -A[0] - A[1])
    
    ring = [0] * (n + 1)
    ding = [0] * (n + 1)

    ring[0] = 0
    ding[0] = 0

    ring[1] = A[0]
    ding[1] = -A[0]

    ring[2] = max(ring[1] + A[1], ding[1] + A[1])
    ding[2] = max(ring[1] - A[1], ding[1] - A[1])

    ring[3] = max(ring[2] + A[2], ring[1] - A[1] + A[2], ding[1] + A[1] + A[2], ding[2] + A[2])
    ding[3] = max(ring[2] - A[2], ring[1] - A[1] - A[2], ding[1] + A[1] - A[2], ding[2] - A[2])

    for i in range(4, n + 1):

        prev_prev_ring = ring[i - 2] - A[i - 2]
        prev_prev_ding = ding[i - 2] + A[i - 2] 
        prev_prev_prev_ring = max(ring[i - 3] - A[i - 3] + A[i - 2], ring[i - 3] - A[i - 3] - A[i - 2] )
        prev_prev_prev_ding = max(ding[i - 3] + A[i - 3] + A[i - 2], ding[i - 3] + A[i - 3] - A[i - 2] )
        prev_ding =  ding[i - 1] 
        ring[i] = max(prev_ding, prev_prev_ring, prev_prev_ding, prev_prev_prev_ring, prev_prev_prev_ding) + A[i - 1]
        prev_ring = ring[i - 1] 
        ding[i] = max(prev_ring, prev_prev_ring, prev_prev_ding, prev_prev_prev_ring, prev_prev_prev_ding) - A[i - 1]

    return max(ring[n],ding[n])

# Example usage:
A = [-5,-3,-1,-7,-10,-4]            

n = len(A)
print(max_chickens_earned(n,A))