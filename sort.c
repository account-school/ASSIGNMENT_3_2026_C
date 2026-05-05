#include <stdio.h>

void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void insertInPlace(int arr[], int left, int right, int subarr[]);

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
    int len =  right-left+1;
    int mid = (left + right)/2;
    if (len > 2 && (right > left)) {
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
    } else if (len == 2) {
        merge_sort(arr,left,left);
        merge_sort(arr,right,right);
    }
    merge(arr,left,mid,right);
}

void merge(int arr[], int left, int mid, int right) {
    /* TODO: Implement the merge logic. */
    // temp arrays, as teacher said in office hours
    int leftSide[mid-left+1];
    int lenLeft = mid - left + 1;
    int lenRight = right-mid;
    int rightSide[right-mid]; // no +1 because the last one already includes mid
    int len = right- left + 1;
    int tempArray[len];
    //

    int q = 0;
    for (int n = left; n <=mid; n++) {
        leftSide[q] = arr[n];
        q++;
    }

    q = 0;
    for (int n = mid+1; n <= right; n++) {
        rightSide[q] = arr[n];
        q++;
    }

    int i = 0;
    int j = 0;
    
    int k  = 0;

    while ((k < len) && (i < lenLeft) && (j < lenRight)) {
        if (leftSide[i] <= rightSide[j]) {
            tempArray[k] = leftSide[i];
            i++;
        } else {
            tempArray[k] = rightSide[j];
            j++;
        }
        k++;
    }

    while (i < lenLeft) {
        tempArray[k] = leftSide[i];
        i++;
        k++;
    }
    while (j < lenRight) {
        tempArray[k] = rightSide[j];
        j++;
        k++;
    }
    

    insertInPlace(arr,left,right,tempArray);


}


void insertInPlace(int arr[], int left, int right, int subarr[]) {
    int lenSubArr = right-left+1;
    int k = 0;
    
    for (int n = left; n <= right; n++) {
        arr[n] = subarr[k];
        k++;
    }
}