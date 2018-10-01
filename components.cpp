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
//using std::stoi;

// function prototypes
vector<list<int> > get_input_file();
list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop, int x);
void print_adj_list(vector<list<int> > adj_list);
bool connComponent(const list<int> &list1, const list<int> &list2);
bool merge2(list<int> &list1, list<int> &list2);

// main
int main()
{
    // declare the adjacency list
    vector<list<int> > adj_list;

    // result of the merge
    bool result;

    // form the adjacency list
    adj_list = get_input_file();

    // print list
    print_adj_list(adj_list);

    // infinite loop time
    while (1)
    {
        int first_number;
        int second_number;

        cout << "Enter two numbers for lists to merge. Enter a negative number to stop.\n";
        cout << "First number:\n";
        cin >> first_number;

        // the user has entered a negative, so stop
        if (first_number < 0)
        {
            cout << "Stopped";
            print_adj_list(adj_list);
            return 0;
        }

        cout << "Second number:\n";
        cin >> second_number;

        // the user has entered a negative, so stop
        if (second_number < 0)
        {
            cout << "Stopped";
            print_adj_list(adj_list);
            return 0;
        }

        // catch the out of range exceptions
        if ((first_number > adj_list.size()) || (second_number > adj_list.size()))
        {
            cout << "You inputted a number out of range, try again\n";
            break;
        }

        // perform the merge
        result = merge2(adj_list.at(first_number), adj_list.at(second_number));

        // if the merge was successful, we need to get rid of the empty list from adj_list
        if (result == true)
        {
            for (vector<list<int>>::iterator test_empty = adj_list.begin(); test_empty != adj_list.end(); ++test_empty)
            {
                if (test_empty->empty())
                {
                    adj_list.erase(test_empty);
                }
            }
        }

        else if (result == false)
        {
            cout << "Lists were not merged, please try again\n";
        }

        // print the list after the merge
        print_adj_list(adj_list);
    }
}


// Asks the user for a file name to process, then adds the contents to the
// adjacency list.
// Returns: adjacency list
vector<list<int> > get_input_file()
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

    vector <list<int> > adj_list;
    list<int> my_list;

    list<int>::iterator list_iter = my_list.begin();
    vector<list<int> >::iterator vector_iter = adj_list.begin();

    // print the contents of the file
    while(getline(input_file, line))
    {
        istringstream iss(line);

        for (string s; iss >> s;)
        {
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
void print_adj_list(vector<list<int> > adj_list)
{
    vector<list<int> >::iterator vector_iter;
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
bool connComponent(const list<int> &list1, const list<int> &list2)
{
    list<int>::const_iterator list1_iter;
    list<int>::const_iterator list2_iter;

    for (list1_iter = list1.begin(); list1_iter != list1.end(); ++list1_iter)
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


// determines which list is bigger and merges the smaller list into it
bool merge2(list<int> &list1, list<int> &list2)
{
    list<int>::iterator list_iter;

    int size1 = list1.size();
    int size2 = list2.size();

    // if list 1 is bigger, merge into list 1
    if (size1 > size2)
    {
        // if they can be merged, merge the lists
        if (connComponent(list1, list2))
    	{
            for (list_iter = list1.begin(); list_iter != list1.end(); ++list_iter)
            {
                int value = *list_iter;
                list<int>::iterator iter = find_gt(list2.begin(), list2.end(), value);
                list1.insert(iter, value);
            }

            list1.unique();
            list2.clear();

    	    return true;
    	}

        else
    	{
    	    cout << "Cannot merge: Lists do not share common node\n";
    		return false;
    	}
    }

    // if list2 is bigger, insert into list2. if they are the same, it doesn't matter
    // which one is bigger, so lets do this
    else
    {
        // if they can be merged, merge the lists
        if (connComponent(list1, list2))
    	{
            for (list_iter = list2.begin(); list_iter != list2.end(); ++list_iter)
            {
                int value = *list_iter;
                list<int>::iterator iter = find_gt(list1.begin(), list1.end(), value);
                list2.insert(iter, value);
            }

            list2.unique();
            list1.clear();

    	    return true;
    	}

        else
    	{
    	    cout << "Cannot merge: Lists do not share common node\n";
    		return false;
    	}
    }
}
