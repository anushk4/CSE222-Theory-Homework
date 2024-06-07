def kthlargest(arr1, arr2, k):
    if len(arr1) == 0:
        return arr2[k]
    elif len(arr2) == 0:
        return arr1[k]

    mida1 = len(arr1) // 2
    mida2 = len(arr2) // 2
    if mida1 + mida2 < k:
        if arr1[mida1] > arr2[mida2]:
            return kthlargest(arr1, arr2[mida2+1:], k - mida2 - 1)
        else:
            return kthlargest(arr1[mida1+1:], arr2, k - mida1 - 1)
    else:
        if arr1[mida1] > arr2[mida2]:
            return kthlargest(arr1[:mida1], arr2, k)
        else:
            return kthlargest(arr1, arr2[:mida2], k)

def kth_largest(arr1, arr2, arr3, k):
    if len(arr1) == 0:
        return kthlargest(arr2, arr3, k)
    elif len(arr2) == 0:
        return kthlargest(arr1, arr3, k)
    elif len(arr3) == 0:
        return kthlargest(arr1, arr2, k)

    mid1 = len(arr1) // 2
    mid2 = len(arr2) // 2
    mid3 = len(arr3) // 2

    if mid1 + mid2 + mid3 < k:
        if arr1[mid1] > arr2[mid2] and arr1[mid1] > arr3[mid3]:
            if arr2[mid2] < arr3[mid3]:
                return kth_largest(arr1, arr2[mid2:], arr3, k - mid2 - 1)
            else:
                return kth_largest(arr1, arr2, arr3[mid3:], k - mid3 - 1)

        elif arr2[mid2] > arr1[mid1] and arr2[mid2] > arr3[mid3]:
            if arr1[mid1] > arr3[mid3]:
                return kth_largest(arr1, arr2, arr3[mid3:], k - mid3 - 1)
            else:
                return kth_largest(arr1[mid1:], arr2, arr3, k - mid1 - 1)
        else:
            if arr1[mid1] < arr2[mid2]:
                return kth_largest(arr1[mid1 + 1:], arr2, arr3, k - mid1 - 1)
            else:
                return kth_largest(arr1, arr2[mid2 + 1:], arr3, k - mid2 - 1)
    else:
        if arr1[mid1] > arr2[mid2] and arr1[mid1] > arr3[mid3]:
            return kth_largest(arr1[:mid1], arr2, arr3, k)
        elif arr2[mid2] > arr1[mid1] and arr2[mid2] > arr3[mid3]:
            return kth_largest(arr1, arr2[:mid2], arr3, k)
        else:
            return kth_largest(arr1, arr2, arr3[:mid3], k)

arr1 = [1, 3, 5, 11, 13]
arr2 = [2, 7, 8, 9, 10]
arr3 = [9, 10, 11, 23, 24]
k = 7

result = kth_largest(arr1, arr2, arr3, k)
print(f"The {k}-th largest element is: {result}")