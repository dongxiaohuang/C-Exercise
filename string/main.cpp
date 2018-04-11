#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int const MAX_SIZE = 300;
int main()
{
  char str[] = "this - , is a sample string.";
  char file[MAX_SIZE] = "this is a test";
  cout << "string length strlen  "<< strlen(file) << endl; // despite the size of the array
// --- erase character
  string line;
   cout << "Enter a string: ";
   getline(cin, line);

   for(int i = 0; i < line.size(); ++i)
   {
       if (!((line[i] >= 'a' && line[i]<='z') || (line[i] >= 'A' && line[i]<='Z')))
       {
           line[i] = '\0';
       }
   }
   cout << "Output String: " << line;
   cout << endl;
   char charline[MAX_SIZE];
   cout << "Enter a string: ";
   cin.getline(charline, MAX_SIZE);
   int i = 0;
   while(charline[i] != '\0')
   {
     if(!((charline[i] >= 'a' && charline[i] <= 'z')|| (charline[i] >= 'A' && charline[i] <= 'Z')))
      {
        int j = i;
        while(charline[j] != '\0')
        {
          charline[j] = charline[j+1];
          j++;
        }
      }
      i++;
   }
   cout << charline << endl;
   // split String

  char *pch;
  int index = 0;
  pch = strtok(str, " ,.-");
  while(pch != NULL)
  {
    cout << pch << endl;
    pch = strtok(NULL, " ,.-");
  }
  ifstream infile;
  ofstream outfile;
  infile.open("makefile");
  outfile.open("output.txt");
  infile.get(file[index]);
  while(!infile.eof())
  {
    index++;
    infile.get(file[index]);
  }
  infile.close();
  char* pfile;
  pfile = file;
  pfile = strtok(file, " ,.-");

  while(pfile != NULL)
  {
    cout << pfile<< endl;
    // int i = 0;
    // while(pfile[i] != '\0')
    // {
    // outfile.put(pfile[i]);
    // outfile.put(' ');
    // i++;
    // }
    outfile << pfile << " ";
    pfile = strtok(NULL, " ,.- \t \n");
  }
  outfile.close();
  return 0;
}
