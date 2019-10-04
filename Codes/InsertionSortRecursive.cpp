#include <iostream>
using namespace std;

int* Insert(int A[],int n,int ele){
    int i;
    for(i=0;i<n;i++){
        if(ele<A[i]){
            break;
        }
    }
    for(int j=n;j>i;j--){
        A[j] = A[j-1];
    }
    A[i] = ele;
    return A;

}

int* InsertionSort(int A[], int n){
    if(n >= 1)
        return Insert(InsertionSort(A,n-1),n-1,A[n-1]);
    else 
        return A;

}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int* B = InsertionSort(A, n);
    cout << "The array after sorting is: ";
    for (int i = 0; i < n; i++)
        cout << B[i] << " ";
    cout << endl;

    return 0;
}