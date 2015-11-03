'''
First In First Out Page Replacement Algorithm

This concept involves the pages to be entered in the order of a linear list
with first in and removed as first out

Developed by Ibrahim
'''

#Binary Search for the element if it is already present in the current queue
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

#Main Fuction Body
def main():
    front = -1
    count = 0
    rear = -1
    arr = []            #List
    pageFault = 0       #Number of Page Faults

    print ("FIFO Page Replacement Algorithm")
    print ("Enter the free frames available in the memory: ", end = '')
    n = int(input())    #Input the number of available free frames
    print ("Enter the number of reference string: ", end = '')
    r = int(input())    #Input the number of reference strings to be placed inside the free frames
    
    #Repeat while i < r
    for i in range(r):
        print ("Enter the frame: ", end = '')
        val = int(input())  #Enter the reference string
        
        # Initially if the queue is empty
        if (rear == -1):
            front += 1
            rear += 1
            arr.insert(rear, val)
            count = count + 1
            pageFault = pageFault + 1
            print ("Page Fault\n", arr)

        #Else if the string has values, check whether the current reference string
        #is already in the queue. If not then proceed
        elif (not(BinarySearch(arr, val))):
            k = 0
            if (rear == n - 1):
                rear = 0
            else:
                rear = rear + 1
                
            count = count + 1
            
            #if the queue is full then start from initial index
            if (count > n):
                for j in arr:
                    if (k == front):
                        arr.pop(front)
                        if (front == n - 1):
                            front = 0
                        else:
                            front += 1
                        arr.insert(rear, val)
                        pageFault = pageFault + 1
                        break
                    k = k + 1
            else:
                arr.insert(rear, val)
                pageFault = pageFault + 1
            print ("Page Fault\n", arr)

    print ("The number of page fault that occured in ", n, " frames are ", pageFault)

#Call the main() if the __main__ namespace is called
if (__name__ == "__main__"):
    main()
