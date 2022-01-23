// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:

    int kthSmallest(int arr[], int l, int r, int k) {
        for(int i=l;i<=r;i++){
            int childIndex = i;
            int parentIndex = ceil(childIndex*1.0/2.0)-1;
            while(parentIndex>=0 and arr[childIndex]>arr[parentIndex]){
                swap(arr[childIndex],arr[parentIndex]);
                childIndex = parentIndex;
                parentIndex = ceil(childIndex*1.0/2.0)-1;
            }
        }
        int j = r;
        while(j>0){
            swap(arr[0],arr[j]);
            int parentIndex = 0;
            while(true){
                int childIndex1 = 2*parentIndex+1,childIndex2 = 2*parentIndex+2;
                if(childIndex1>=j) break;
                if(childIndex2>=j){
                    if(arr[parentIndex] < arr[childIndex1]){
                        swap(arr[parentIndex], arr[childIndex1]);
                        parentIndex = childIndex1;
                    }else{
                        break;
                    }
                }else{
                    int pval = arr[parentIndex],cval1 = arr[childIndex1],cval2 = arr[childIndex2];
                    if(pval > max(cval1,cval2)) break;
                    if(cval1>cval2){
                        swap(arr[parentIndex], arr[childIndex1]);
                        parentIndex = childIndex1;               
                    }else{
                        swap(arr[parentIndex], arr[childIndex2]);
                        parentIndex = childIndex2;
                    }
                
                }
            }
            j--;
        }
        return arr[k-1];
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends