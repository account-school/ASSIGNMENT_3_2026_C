#include <stdio.h>

void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    int n;
    printf("Enter a value for n: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    //merge(arr,0,n/2,n-1);
    merge_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


void print_arr(int arr[], int left, int right) {
    int len = right - left + 1;
    printf("\[");
    for (int n = left; n < right; n++) {
        printf("%d ",arr[n]);
    }
    printf("%d\]\n",arr[right]);
}
void merge_sort(int arr[], int left, int right) {
    /* TODO: Implement merge sort by using divide and conquer recursively. This function should call the merge sub-routine. */ 
    int len = right-left+1;
    /*
    print_arr(arr,left,right);
    printf("arr[%d --> %d] length: %d", left, right, len);
    if (len > 2 && right > left) {
        merge_sort(arr,left,((left+right)/2)-1);
        merge_sort(arr,((left+right)/2),right);
    }
    else if (len == 2) {
        merge_sort(arr,left,left);
        merge_sort(arr,right,right);
    }
    */
    
    merge(arr,left,(right-left)/2,right);
}

void merge(int arr[], int left, int mid, int right) {
    /* TODO: Implement the merge logic. */
    int leftlen = mid-left+1;
    int rightlen = right-mid+1;
    int len = right-left+1;
    // using psuedocode on slide 10 as massive helper
    //printf("leftLen: %d, rightLen: %d len: %d ",leftlen, rightlen, len);
    int tempArr[len];
    int i = left;
    int j = mid;
    int k = 0;
    
    while (k < len && i < mid && j < len) {
        //printf("mid: %d, len: %d\n",mid, len);
        //printf("arr\[%d\] ? arr\[%d\]\n", i,j);
        //printf("%d ? %d\n", arr[i],arr[j]);
        if (arr[i] <= arr[j]) {
            tempArr[k] = arr[i];
            i++;
        } else {
            tempArr[k] = arr[j];
            j++;           
        }

        //printf("temp arr::");
        //print_arr(tempArr,left,right);
        k++;
    }
    // implicit if nnot finished, copy values until. at this point one of them (i or j) must be completed by this point
    printf("i: %d, j: %d, k: %d, mid: %d, len: %d\n",i,j,k, mid, len);
    while (i < mid) {
        tempArr[k] = arr[i];
        i++;
        k++;
        //printf("temp arr::");
        //print_arr(tempArr,left,right);
    }
    while (j < len) {
        tempArr[k] = arr[j];
        j++;
        k++;
        //printf("temp arr::");
        //print_arr(tempArr,left,right);
    }
    // copy it into arr[]

    for (int n = 0; n <= len; n++) {
        arr[n] =  tempArr[n];
    }
}
