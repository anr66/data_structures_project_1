#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::vector;
using std::string;
using std::list;
using std::ifstream;

void get_input_file();

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

    while(!(input_file.eof()))
    {
        getline(input_file, line);
	cout << line << endl; 
    }

}


//iterator find_gt()
//{


//}
