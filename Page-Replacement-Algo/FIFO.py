def BinarySearch(L, e):
    low = 0
    high = len(L) - 1
    mid = int((low + high) / 2)
        
    while (low <= high):
        if (L[mid] == e):
            return True
        elif (L[mid] > e):
            high = mid - 1
        elif (L[mid] < e):
            low = mid + 1

        mid = int((low + high) / 2)

    if (low > high):
        return False
        
def main():
    flag = 0
    count = 0
    rear = -1
    arr = []
    pageFault = 0

    print ("FIFO Page Replacement Algorithm")
    print ("Enter the free frames available in the memory: ", end = '')
    n = int(input())
    print ("Enter the number of reference string: ", end = '')
    r = int(input())
    
    for i in range(r):
        print ("Enter the frame: ", end = '')
        val = int(input())
            
        if (rear == -1):
            rear += 1
            arr.insert(rear, val)
            count = count + 1
            pageFault = pageFault + 1
            print ("Page Fault\n", arr)

        elif (not(BinarySearch(arr, val))):
            k = 0
            if (rear == n - 1):
                rear = 0
            else:
                rear = rear + 1
                
            count = count + 1
            if (count > n):
                for j in arr:
                    if (j == val):
                        flag = 1
                        break
                if (not flag):
                    for j in arr:
                        if (k == rear):
                            arr.pop(rear)
                            arr.insert(rear, val)
                            pageFault = pageFault + 1
                            break
                    k = k + 1
            else:
                arr.insert(rear, val)
                pageFault = pageFault + 1
            print ("Page Fault\n", arr)

    print ("The number of page fault that occured in ", n, " frames are ", pageFault)

if (__name__ == "__main__"):
    main()
