void bubbleSort(int array[], int size){
    int temp;

    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                j = 0;
            }
        }
    }
}

int binarySearch(int arr[], int size, int val) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (right - left) / 2;

        if (arr[mid] == val)
            return mid;
        else if (arr[mid] < val)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}
