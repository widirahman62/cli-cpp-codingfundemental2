struct node
{
    string key;
    string value;
    node *next;
};

void delink() {
    node *head, *iterator;
    node *d1 = new node;
    node *d2 = new node;
    node *d3 = new node;

    d1->key = "Name";
    d2->key = "Github Username";
    d3->key = "Software License";

    d1->value = "Widi Rahman";
    d2->value = "widirahman62";
    d3->value = "MIT";

    head = d1;
    d1->next = d2;
    d2->next = d3;
    d3->next = nullptr;

    for (iterator = head; iterator != nullptr; iterator = iterator->next)
    {
        cout << iterator->key << " : " << iterator->value << endl;
    }
    cout << "Thanks for using this program." << endl;
    delete d1;
    delete d2;
    delete d3;
}
