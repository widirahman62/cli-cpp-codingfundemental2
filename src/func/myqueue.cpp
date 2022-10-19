void enqueue(int** queue, int* front, int* rear, int temp) {
    if (*front == -1 && *rear == -1) {
        *front = 0;
        *rear = 0;
        *queue = new int[1];
        (*queue)[*rear] = temp;
    } else {
        *rear = *rear + 1;
        int* tempQueue = new int[*rear + 1];
        for (int i = 0; i < *rear; i++) {
            tempQueue[i] = (*queue)[i];
        }
        tempQueue[*rear] = temp;
        delete[] *queue;
        *queue = tempQueue;
    }
}

void dequeue(int** queue, int* front, int* rear) {
    if (*front == -1 && *rear == -1) {
        cout << "Queue is empty" << endl;
        sleep(5);
    } else {
        int* tempQueue = new int[*rear];
        for (int i = 0; i < *rear; i++) {
            tempQueue[i] = (*queue)[i + 1];
        }
        delete[] *queue;
        *queue = tempQueue;
        *rear = *rear - 1;
        if (*rear == -1) {
            *front = -1;
        }
    }
}

void queuedisplay(int** queue, int* front, int* rear) {
    if (*front == -1 && *rear == -1) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "\nQueue list :" << endl;
        for (int i = *front; i <= *rear; i++) {
            cout << (*queue)[i] << endl;
        }
    }
}

void searchQueue(int** queue, int* front, int* rear, int search) {
    if (*front == -1 && *rear == -1) {
        cout << "Queue is empty" << endl;
        sleep(5);
    } else {
        for (int i = *front; i <= *rear; i++) {
            if ((*queue)[i] == search) {
                cout << "Found at index " << i << endl;
            } else if ((i == *rear) && (*queue)[i] != search) {
                cout << "Value not found" << endl;
            }
        }
        sleep(5);
    }
}

void myqueue() {
    int* arr;
    int* queue;
    int front = -1;
    int rear = -1;
    int choice;
    int temp;
    int search;
    bool isExit = false;
    myqueue:
    cout << "\033c";
    while (!isExit) {
        cout << "1. Add queue\n2. Reduce queue by 1\n3. Display\n4. Search\n5. Exit\n";
        cout << "Choice : ";
        cin.sync();
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input" << endl;
            sleep(2);
            cin.clear();
            cin.ignore();
            cout << "\033c";
            goto myqueue;
        }
        switch (choice) {
            case 1:
                cout << "Input number : ";
                cin >> temp;
                if (!cin.fail()) {
                    enqueue(&queue, &front, &rear, temp);
                } else {
                    cout << "Invalid input" << endl;
                    sleep(2);
                }
                cin.clear();
                cin.ignore();
                cout << "\033c";
                break;
            case 2:
                dequeue(&queue, &front, &rear);
                cout << "\033c";
                break;
            case 3:
                queuedisplay(&queue, &front, &rear);
                sleep(5);
                cout << "\033c";
                break;
            case 4:
                cout << "Input number to search : ";
                cin >> search;
                if (!cin.fail()) {
                    searchQueue(&queue, &front, &rear, search);
                } else {
                    cout << "Invalid input" << endl;
                    sleep(5);
                }
                cin.clear();
                cin.ignore();
                cout << "\033c";
                break;
            case 5:
                isExit = true;
                cout << "Thanks for using this program." << endl;
                break;
            default:
                cout << "Invalid input" << endl;
                sleep(2);
                cin.clear();
                cin.ignore();
                cout << "\033c";
                break;
        }
    }
    
}


