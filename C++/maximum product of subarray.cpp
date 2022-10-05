#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = { 1, -2, -3, 0, 7, -8, 2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max_ending_here = arr[0];
 
    // min negative product ending
    // at the current position
    int min_ending_here = arr[0];
 
    // Initialize overall max product
    int max_so_far = arr[0];
    
    for (int i = 1; i < n; i++) { 
        int temp = max({arr[i], arr[i] * max_ending_here, arr[i] * min_ending_here}); 
        min_ending_here = min({arr[i], arr[i] * max_ending_here, arr[i] * min_ending_here}); 
        max_ending_here = temp; 
        max_so_far = max(max_so_far, max_ending_here);
        if(max_ending_here>max_so_far)
        max_so_far = max_ending_here;
    }
    
    cout<<"Maximum Product of sub-array is "<< max_so_far;
}