// includes
#include <iostream>
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
void get_input_file();
list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop, int x);

int main()
{
    std::vector <std::list<int>> adj_list;

    get_input_file();

    return 0;

}


void get_input_file()
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

    // print the contents of the file
    cout << "Raw file contents:\n";
    while(!(input_file.eof()))
    {
        getline(input_file, line);
        //istringstream iss(line);
        //vector<string> split_string(istream_iterator<string>(iss), istream_iterator<string>());
        //cout << split_string << endl;

        string delimiter = " ";

        while (line.find(delimiter) != string::npos)
        {
            string token = line.substr(0, line.find(delimiter));

            line.erase(0, line.find(delimiter) + delimiter.length());

            vector<string> split_string;
            vector<string>::iterator v_it;

            //v_it = split_string.begin();
            v_it = split_string.insert(v_it, token);
            //split_string.insert(token);
            for (v_it = split_string.begin(); v_it < split_string.end(); v_it++)
            {
                cout << ' ' << *v_it;
            }
        }


        //cout << split_string << endl;


        //cout << line << endl;
    }
}


list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop, int x)
{
    // loop through list items
    for (list<int>::iterator list_item = start; list_item != stop; list_item++)
    {

    }

}
