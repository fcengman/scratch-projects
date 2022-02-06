import sys


def quickSelect(array, left, right, k):
    
    if (left == right):
        return array[left]
        
    if (k > 0 and k <= right - left + 1):
        pivot = partition(array, left, right)

        if(pivot - left == k - 1):
            return array[pivot]
        if (pivot - left > k - 1):
            return quickSelect(array, left, pivot - 1, k)
        else:
            return quickSelect(array, pivot + 1, right, k - pivot + left - 1)

    return sys.maxsize


def partition(array, left, right):
    pivot = array[right]
    current = left

    for i in range(left, right):
        if(array[i] <= pivot):
            temp = array[i]
            array[i] = array[current]
            array[current] = temp
            current += 1
    temp = array[right]
    array[right] = array[current]
    array[current] = temp
    return current


def main():
    arr = [12, 3, 5, 7, 4, 19, 26]
    n = len(arr)
    k = 3
    kth_smallest = quickSelect(arr, 0, n-1, k)
    print(arr)
    print(kth_smallest)

    arr2 = [12, 13, 17, 14, 21, 3, 4, 9, 21, 8]
    k = 5
    kth_smallest = quickSelect(arr2, 0, len(arr)-1, k)
    print(arr2)
    print(kth_smallest)


if __name__ == "__main__":
    main()
