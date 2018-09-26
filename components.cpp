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

int main()
{
    vector<list<int>> adj_list;

    adj_list = get_input_file();

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
    //cout << "Raw file contents:\n";
    while(!(input_file.eof()))
    {
        getline(input_file, line);

        cout << "line: " << line << endl;

        istringstream iss(line);

        for (string s; iss >> s;)
        {
            cout << s << endl;
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

            cout << "mylist contains:\n";
            for (list_iter = my_list.begin(); list_iter != my_list.end(); ++list_iter)
            {
                cout << *list_iter;
            }
        }

        adj_list.push_back(my_list);
        //adj_list.insert(vector_iter, my_list);
        //vector_iter++;
        my_list.clear();
        list_iter = my_list.begin();

        //for(vector_iter = adj_list.begin(); vector_iter != adj_list.end(); ++vector_iter)
        //{
          //for (list_iter = my_list.begin(); list_iter != my_list.end(); ++list_iter)
          //{
          //    cout << *list_iter << " ";
          //}
            //cout << "adj_list: " << *vector_iter << endl;
            //cout << "\n";
        //}
    }

    return adj_list;
}

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
