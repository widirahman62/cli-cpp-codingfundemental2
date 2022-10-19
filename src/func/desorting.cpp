// create multiple functions for bubble sort, selection sort, and insertion sort
void BubbleSort(int** arr, int* size) {
    int temp;
    for (int i = 0; i < (*size); i++) {
        for (int j = 0; j < (*size) - 1; j++) {
            if ((*arr)[j] > (*arr)[j + 1]) {
                temp = (*arr)[j];
                (*arr)[j] = (*arr)[j + 1];
                (*arr)[j + 1] = temp;
            }
        }
    }
}
void SelectionSort(int** arr, int* size) {
    int temp;
    for (int i = 0; i < (*size); i++) {
        for (int j = i + 1; j < (*size); j++) {
            if ((*arr)[i] > (*arr)[j]) {
                temp = (*arr)[i];
                (*arr)[i] = (*arr)[j];
                (*arr)[j] = temp;
            }
        }
    }
}
void InsertionSort(int** arr, int* size) {
    int temp;
    for (int i = 1; i < (*size); i++) {
        for (int j = i; j > 0; j--) {
            if ((*arr)[j] < (*arr)[j - 1]) {
                temp = (*arr)[j];
                (*arr)[j] = (*arr)[j - 1];
                (*arr)[j - 1] = temp;
            }
        }
    }
}

void BinarySearch(int** arr, int* size, int* search) {
    int left = 0;
    int right = (*size) - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if ((*arr)[mid] == (*search)) {
            cout << "Found " << (*search) << " at index " << mid << endl;
            break;
        }
        else if ((*arr)[mid] < (*search)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    if (left > right) {
        cout << (*search) << " Not found in list" << endl;
    }
}

void SeqSearch(int** arr, int* size, int* search) {
    for (int i = 0; i < (*size); i++) {
        if ((*arr)[i] == (*search)) {
            cout << "Found " << (*search) << " at index " << i << endl;
            break;
        }
        else if (i == (*size) - 1) {
            cout << (*search) << " Not found in list" << endl;
        }
    }
}

void desorting() {
    desorting:
    cout << "Bubble, Selection, & Insertion Sorting program." << endl;
    cout << "This program will sort your input with bubble, selection, and insertion sort." << endl;
    cout << "Please enter how many numbers you want to sort : ";
    int size, start, stop;
    cin.sync();
    cin >> size;
    if (cin.fail()) {
        cout << "Invalid input" << endl;
        sleep(2);
        cin.clear();
        cin.ignore();
        cout << "\033c";
        goto desorting;
    } else {
        int * arr = new int[size];
        for (int i = 0; i < size; i++) {
            cout << "Enter number " << i + 1 << " : ";
            cin.sync();
            cin >> arr[i];
            if (cin.fail()) {
                cout << "Invalid input" << endl;
                sleep(2);
                cin.clear();
                cin.ignore();
                cout << "\033c";
                goto desorting;
            }
        }
        int temp[size];
        cout << "List of numbers : " << endl;
        for (int j = 0; j < size; j++) {
            cout << arr[j] << " ";
            temp[j] = arr[j];
        }
        cout << endl;
        cout << "\nAscending sort with bubble sort..." << endl;
        start = clock();
        BubbleSort(&arr, &size);
        stop = clock();
        cout << "List of numbers after bubble sort : " << endl;
        for (int k = 0; k < size; k++) {
            cout << arr[k] << " ";
        }
        cout << "\nExecution time : " << (stop - start) / double(CLOCKS_PER_SEC) * 1000 << " ms" << endl;
        cout << endl;
        memcpy(arr, temp, size * sizeof(int));
        cout << "Ascending sort with selection sort..." << endl;
        start = clock();
        SelectionSort(&arr, &size);
        stop = clock();
        cout << "List of numbers after selection sort : " << endl;
        for (int l = 0; l < size; l++) {
            cout << arr[l] << " ";
        }
        cout << "\nExecution time : " << (stop - start) / double(CLOCKS_PER_SEC) * 1000 << " ms" << endl;
        cout << endl;
        memcpy(arr, temp, size * sizeof(int));
        cout << "Ascending sort with insertion sort..." << endl;
        start = clock();
        InsertionSort(&arr, &size);
        stop = clock();
        cout << "List of numbers after insertion sort : " << endl;
        for (int m = 0; m < size; m++) {
            cout << arr[m] << " ";
        }
        cout << "\nExecution time : " << (stop - start) / double(CLOCKS_PER_SEC) * 1000 << " ms" << endl;
        cout << endl;
        char choice;
        cout << "Do you want to search for a number that exists in the list? (y for yes/any key to exit) : ";
        cin.sync();
        cin >> choice;
        if(choice == 'y') {
            int search;
            desearching:
            cout << "Enter the number you want to search : ";
            cin.sync();
            cin >> search;
            if (cin.fail()) {
                cout << "Invalid input" << endl;
                cin.clear();
                cin.ignore();
                goto desearching;
            } else {
                cout << "Searching with binary search..." << endl;
                start = clock();
                BinarySearch(&arr, &size, &search);
                stop = clock();
                cout << "Execution time : " << (stop - start) / double(CLOCKS_PER_SEC) * 1000 << " ms" << endl;
                cout << endl;
                cout << "Searching with sequential search..." << endl;
                start = clock();
                SeqSearch(&arr, &size, &search);
                stop = clock();
                cout << "Execution time : " << (stop - start) / double(CLOCKS_PER_SEC) * 1000 << " ms" << endl;
            }
        }
        delete[] arr;
        cout << "\nThanks for using this program." << endl;
    }
}
