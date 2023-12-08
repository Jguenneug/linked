#include <iostream>
#include <fstream>

using namespace std;

struct Item {
    int val;
    Item* next;
    Item(int v, Item* n) { val = v; next = n; }
};

void print(Item* head)
{
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void deallocate(Item* head)
{
    Item* temp;
    while (head != nullptr)
    {
        // Add code here to deallocate all the Items
        // in the linked list
        temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    temp = nullptr;
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cout << "Please provide a filename" << endl;
        return 1;
    }
    Item* head = nullptr;
    char* filename = argv[1];

    // Add Your code here to read in integers from the file
    // whose name is given by 'filename' and adds them
    // to the linked list that head will point at (i.e. allocate
    // Items, set their value, and add them to the linked list)
    // The values should be in the list in the same order they appear
    int inputNum = 0;
    int numOfInputs = 0;

    ifstream rfile;
    rfile.open(filename);

    Item* iter = head;
    bool first = true;

    while (rfile >> inputNum)
    {
        if (first)
        {
            numOfInputs = inputNum;
            first = false;
        }
        else
        {
            if (iter == nullptr)
            {
                head = iter = new Item(inputNum, nullptr);
            }
            else
            {
                iter->next = new Item(inputNum, nullptr);
                iter = iter->next;
            }

        }

    }
    rfile.close();

    int numVals;
    int val;
    Item* temp;

    // Call to print the linked list (complete)
    print(head);

    // Call to deallocate the items in the linked list (complete
    // the code for this function above in its definition)
    deallocate(head);

    return 0;
}