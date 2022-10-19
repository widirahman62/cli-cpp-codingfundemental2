#include "func.h"
struct Topics
{
    const char *name;
    void (*func)();
};
struct Topics topics[] = {
    {"1.\tMemory Management\n", dememory},
    {"2.\tSorting & Searching\n", desorting},
    {"3.\tStack\n", destack},
    {"4.\tQueue\n", myqueue},
    {"5.\tLinked List\n", delink},
};

void enterToContinue()
{
    cout << "Press Enter key to continue" << endl;
    cin.sync();
    cin.ignore();
}
void callTopics(int *caseIndex)
{
    enterToContinue();
    cout << "\033c";
    if (topics[*caseIndex].func != NULL)
    {
        topics[*caseIndex].func();
    }
    else
    {
        cout << "No function assigned to this topic" << endl;
    }
}
bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (std::isdigit(c) == 0)
            return false;
    }
    return true;
}
int main()
{
    cin.sync();
    int currentindex = 0;
    int viewperpage = 3;
    int maintabwidth = 5;
begin:
    string options = "";
    cout << "\033c";
    if (options.length() == 0)
    {
        cout << "Copyright © widirahman62\nHello C++ enthusiast!\nThis program provide you with a list of C++ program examples\nfrom programming lecture that I learned in college (second semester).\nPlease select the topic provided below :\n" << endl;
        for (int i = currentindex; i < currentindex + viewperpage; i++)
        {
            if (i < sizeof(topics) / sizeof(topics[0]))
            {
                int wordlength = 0;
                for (int j = 0; j < strlen(topics[i].name); j++)
                {
                    if (topics[i].name[j] == '\t')
                    {
                        cout << setw(maintabwidth - wordlength);
                        wordlength = 0;
                    }
                    else if (topics[i].name[j] == '\n')
                    {
                        cout << endl;
                        wordlength = 0;
                    }
                    else if (topics[i].name[j] == ' ')
                    {
                        cout << ' ';
                        wordlength = 0;
                    }
                    else
                    {
                        cout << topics[i].name[j];
                        wordlength++;
                    }
                }
            }
            else
            {
                break;
            }
        }
        cout << "\nEnter option(a to next/b to back/number/q to exit): ";
        cin.sync();
        getline(cin, options);
        cout << "You selected option " << options << endl;
    }
    if (isNumber(options) && options.length() != 0)
    {
        int option = stoi(options) - 1;
        if (option < sizeof(topics) / sizeof(topics[0]) && option >= 0)
        {
            callTopics(&option);
        }
        else
        {
            cout << "Invalid option. " << endl;
        }
    }
    else
    {
        if (options[1] != '\0')
        {
            cout << "Invalid option. " << endl;
            enterToContinue();
            goto begin;
        }
        switch (options[0])
        {
        case 'a':
        case 'A':
            if (currentindex + viewperpage < sizeof(topics) / sizeof(topics[0]))
            {
                currentindex += viewperpage;
            }
            else
            {
                cout << "No more topics. " << endl;
                enterToContinue();
            }
            goto begin;
        case 'b':
        case 'B':
            if (currentindex - viewperpage < 0)
            {
                cout << "No more topics. " << endl;
                enterToContinue();
            }
            else
            {
                currentindex -= viewperpage;
            }
            goto begin;
        case 'Q':
        case 'q':
            cout << "Thank you for using this program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid option. " << endl;
            break;
        }
    }
    enterToContinue();
    goto begin;
}
