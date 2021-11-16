def mergesort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left, right = arr[:mid], arr[mid:]
        mergesort(left)
        mergesort(right)
        i = j = k = 0
        while i < len(left) and j < len(right):
            if left[i] > right[j]:
                arr[k] = right[j]
                j += 1
            else:
                arr[k] = left[i]
                i += 1
            k += 1
        while i < len(left):
            arr[k] = left[i]
            i += 1; k += 1
        while j < len(right):
            arr[k] = right[j]
            j += 1; k += 1
    return arr
  # Note: This merge-sort is written by Antt(Anthony-Sheu).
