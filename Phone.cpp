/*
* Phone Program 
*
* Name: Yelysei Shkirpan
* Date: 23 July , 2023
*/
#include <iostream>
#include <string>
using namespace std;

const string EXIT_WORD = "exit";
const int ROWS = 4;
const int COLUMNS = 2;


int linearSearch(string findMe, string list[ROWS][COLUMNS], int listSize);
/*
* main - requests the name of man and prints its extension if the name is in list
*
* Return: status 
*/
int main()
{
    string name;
    int index;
    string phoneList[ROWS][COLUMNS] = {
        {"Jane", "x1234"},
        {"Joe", "x5678"},
        {"Jack", "x2673"},
        {"John", "x7926"}
    };

    cout << "Name? ";
    cin >> name;
    cout << endl;

    while (name != EXIT_WORD)
    {
        index = linearSearch(name, phoneList, ROWS);
        if (index >= 0)
        {
            cout << name << "'s extension is " << phoneList[index][1];
        }
        else
        {
            cout << name << " is not in the directory";
        }
        
        cout << "\nName? ";
        cin >> name;
        cout << endl;
    }

    return 0;
}

/*
* linearSearch - searches the name in list
*
* Parameter: findMe - Name we are searching for
* Parameter: list - array were we are searching
* Parameter: listSize - number of rows in array
* Return: index of row were name is found
*/
int linearSearch(string findMe, string list[ROWS][COLUMNS], int listSize)
{
    bool found = false;
    int indexRow = 0;

    while ((!found) && (indexRow < listSize))
    {
        if (list[indexRow][0] == findMe)
        {
            found = true;
        }
        else
        {
            indexRow++;
        }
    }

    if (!found)
    {
        indexRow = -1;
    }

    return indexRow;
}

