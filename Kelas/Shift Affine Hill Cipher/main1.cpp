#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
 ofstream myfile;
  myfile.open ("example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}
