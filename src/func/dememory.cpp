void dememory() {
    int* memory;
    int size;
    dememorybegin:
    cout << "Memory Managemment" << endl;
    cout << "This program will allocate some memory\nbased on your input with value of random number.\nPlease enter how much memory you want to allocate :" << endl;
    cin.sync();
    cin >> size;
    if (cin.fail()) {
        cout << "Invalid input" << endl;
        sleep(2);
        cin.clear();
        cin.ignore();
        cout << "\033c";
        goto dememorybegin;
    } else {
        memory = new int[size];
        srand(time(0));
        for (int i = 0; i < size; i++) {
            dememoryagain:
            memory[i] = rand() % 999999 + 100000;
            if (memory[i] > 999999) {
                goto dememoryagain;
            }
        }
        cout << "Memory allocated successfully." << endl;
        cout << "List of allocated memory : " << endl;
        cout << "Address\t\t\tValue" << endl;
        for (int i = 0; i < size; i++) {
            cout << &memory[i] << "\t\t" << memory[i] << endl;
        }
        cout << endl;
        delete[] memory;
        cout << "Memory deallocated successfully." << endl;
        cout << "Thanks for using this program." << endl;
    }
    
}
