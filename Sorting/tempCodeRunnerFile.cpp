x + 1 <= heap_size){
            arr[index] = arr[2 * index + 1];
            swap(&arr[index], &arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }