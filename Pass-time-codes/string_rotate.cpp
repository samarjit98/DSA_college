#include <iostream>
#include <string>
using namespace std;

bool rotate_string(string s, string b)
{
  string acr, cr;
  acr=s.substr(2, s.size()) + s.substr(0, 2);
  cr=s.substr(s.size()-2, s.size()) + s.substr(0, s.size()-2);

  return ((acr==b)||(cr==b));
}

int main()
{
  string a="geeks", b="eksge", c="ksgee";
  if(rotate_string(a, b))cout << "yes1" << endl;
  if(rotate_string(a, c))cout << "yes2" << endl;
  if(rotate_string(b, c))cout << "yes3" << endl;

  return 0;
}
