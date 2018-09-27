// Alycia Riese
// components.cpp

// includes
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <iterator>

// using statements
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::vector;
using std::string;
using std::list;
using std::ifstream;
using std::istringstream;

// function prototypes
vector<list<int>> get_input_file();
list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop, int x);
void print_adj_list(vector<list<int>> adj_list);
bool conn_component(list<int> list1, list<int> list2);

// main
int main()
{
    vector<list<int>> adj_list;

    // form the adjacency list
    adj_list = get_input_file();

    print_adj_list(adj_list);
    return 0;

}


// Asks the user for a file name to process, then adds the contents to the
// adjacency list.
// Returns: adjacency list
vector<list<int>> get_input_file()
{
    ifstream input_file;
    string file_name;

    cout << "Please enter a file name to process\n";
    cin >> file_name;

    input_file.open(file_name.c_str());

    if (input_file.fail())
    {
        cout << "Error opening file, try again" << "\n";
    }

    string line;

    vector <list<int>> adj_list;
    list<int> my_list;

    list<int>::iterator list_iter = my_list.begin();
    vector<list<int>>::iterator vector_iter = adj_list.begin();

    // print the contents of the file
    while(getline(input_file, line))
    {
        istringstream iss(line);

        for (string s; iss >> s;)
        {
            //cout << s << endl;
            // convert string into an int
            int value = stoi(s);

            // if the list is empty, insert value
            if (my_list.size() == 0)
            {
                my_list.insert(list_iter, value);
            }

            // else, find the greater than iterator and insert it there
            else
            {
                list_iter = find_gt(my_list.begin(), my_list.end(), value);
                my_list.insert(list_iter, value);
            }
        }

        adj_list.push_back(my_list);
        my_list.clear();
        list_iter = my_list.begin();
    }

    return adj_list;
}


// finds the iterator that is greater than the int passed in. This sorts the list
list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop, int x)
{
    // loop through list items
    for (list<int>::iterator list_item = start; list_item != stop; list_item++)
    {
        // if the value we want to insert is less than the current list item, return that position
        if (x < *list_item)
        {
            return list_item;
        }
    }

    return stop;
}


// Takes in a vector of lists and prints out all values
void print_adj_list(vector<list<int>> adj_list)
{
    vector<list<int>>::iterator vector_iter;
    list<int>::iterator list_iter;
    int list_num = 0;

    cout << "The adjacency list for your graph:\n";
    for(vector_iter = adj_list.begin(); vector_iter != adj_list.end(); ++vector_iter)
    {
        cout << "list" << list_num << " ";

        for (list_iter = vector_iter->begin(); list_iter != vector_iter->end(); ++list_iter)
        {
            cout << *list_iter << " ";
        }

        cout << "\n";
        list_num++;
    }
}


// Reads two lists, and determines if they can be merged (if they share a value)
bool conn_component(list<int> list1, list<int> list2)
{
    list<int>::iterator list1_iter;
    list<int>::iterator list2_iter;

    for (list1_iter = list1.begin(); list1_iter != list2.end(); ++list1_iter)
    {
        for (list2_iter = list2.begin(); list2_iter != list2.end(); ++list2_iter)
        {
            if (*list1_iter == *list2_iter)
            {
                return true;
            }
        }
    }

    return false;
}


//
bool merge2(list<int> &, list<int> &)
{


}
