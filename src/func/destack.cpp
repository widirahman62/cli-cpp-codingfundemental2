void stackpush(int** stack, int* top, int data) {
    (*top)++;
    (*stack) = (int*)realloc((*stack), ((*top) + 1) * sizeof(int));
    (*stack)[(*top)] = data;
}
void stackpop(int** stack, int* top) {
    if ((*top) == -1) {
        cout << "Stack is empty" << endl;
        sleep(5);
    }
    else {
        cout << "Pop " << (*stack)[(*top)] << endl;
        (*top)--;
        (*stack) = (int*)realloc((*stack), ((*top) + 1) * sizeof(int));
    }
}
void stackdisplay(int** stack, int* top) {
    if ((*top) == -1) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "\nStack list :" << endl;
        for (int i = (*top); i >= 0; i--) {
            cout << (*stack)[i] << endl;
        }
    }
}
void searchStack(int** stack, int* top, int search) {
    if ((*top) == -1) {
        cout << "Stack is empty" << endl;
        sleep(5);
    } else {
        for (int i = (*top); i >= 0; i--) {
            if ((*stack)[i] == search) {
                cout << "Found " << search << " at index " << i << endl;
            } else if ((i == (*top)) && (*stack)[i] != search) {
                cout << "Value not found" << endl;
            }
        }
        sleep(5);
    }
}

void destack() {
    int *arr = NULL;
    int *stack = NULL;
    int top = -1;
    int choice;
    int temp;
    int search;
    bool isExit = false;
    destack:
    cout << "\033c";
    while (!isExit) {
        cout << "1. Push\n2. Pop\n3. Display\n4. Search\n5. Exit\n";
        cout << "Choice : ";
        cin.sync();
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input" << endl;
            sleep(2);
            cin.clear();
            cin.ignore();
            cout << "\033c";
            goto destack;
        }
        switch (choice) {
            case 1:
                cout << "Input number : ";
                cin >> temp;
                if (!cin.fail()) {
                    stackpush(&stack, &top, temp);
                } else {
                    cout << "Invalid input" << endl;
                    sleep(2);
                }
                cin.clear();
                cin.ignore();
                cout << "\033c";
                break;
            case 2:
                stackpop(&stack, &top);
                cout << "\033c";
                break;
            case 3:
                stackdisplay(&stack, &top);
                sleep(5);
                cout << "\033c";
                break;
            case 4:
                cout << "Input number to search : ";
                cin >> search;
                if (!cin.fail()) {
                    searchStack(&stack, &top, search);
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
                cout << "Invalid choice" << endl;
                sleep(2);
                cin.clear();
                cin.ignore();
                cout << "\033c";
                break;
        }
    }
}



