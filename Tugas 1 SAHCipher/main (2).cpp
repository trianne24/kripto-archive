#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream file ("test.txt");

    string file_contents(
        (istreambuf_iterator<char>(file)), istreambuf_iterator<char>()
    );

    cout<<file_contents;
    return 0;
}
