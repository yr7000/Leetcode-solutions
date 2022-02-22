#User function Template for python3

def printFirstNegativeInteger( A, n, k):
    # code here
    result = []
    for i in range(n-k+1):
        result.append(0)
    startFill = 0
    for i in range(n):
        if A[i]<0:
            startFill = max(startFill,i-k+1)
            while startFill<=min(i,n-k):
                result[startFill] = A[i]
                startFill += 1
    return result

#{ 
#  Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        k = int(input())
        
        answer = printFirstNegativeInteger(a, n, k)
        for i in answer:
            print(i,end=" ")
        print()

        T -= 1


if __name__ == "__main__":
    main()


# } Driver Code Ends