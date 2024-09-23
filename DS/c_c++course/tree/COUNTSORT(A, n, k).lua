COUNTSORT(A, n, k)
    for i to k
        C[i] = 0
    for j = 1 to n
        C[A[j]]++
    j = 0
    for i = 1 to k
        while C[i]--
            B[j++] = i
    return B