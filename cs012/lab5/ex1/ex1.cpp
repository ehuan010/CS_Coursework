#include <iostream>
//#include <cstring>
//#include <string>

using namespace std;


/* str_cat: gets two cstring objects and append the characters of the second 
 * cstring to the first one. You can assume that both cstrings are 
 * null-terminated. The final form of first object should be a valid cstring, 
 * meaning it should have a null-character at the end.
 */
char *str_cat(char *dest, const char *src)
{
  unsigned int a, i, j;
  unsigned int index = 0;
  for(a = 0; dest[a]!= '\0'; ++a)
  {
    index++;
  }
  i=index;
  for (j=0; src[j]!='\0'; j++)
  {
    dest[i] = src[j];
    i++;
    if(src[j+1] == '\0')
    {
      dest[i] = '\0';
    }
  }
  return dest; 
}

/* strrev: gets one cstring object and reverses the string it stores.
 * An example call would be strrev(A); where A is a cstring
 * You can assume that both cstrings are null-terminated.
 * At the end of the function, the cstring object should still be a
 * valid cstring object, having a null-character at the end.
 * Make sure you do not move the null-character to the beginning.
 */
char *str_rev(char *str)
{
  int size = 0;
  unsigned int x, y;
  for(unsigned int i = 0; str[i] != '\0'; ++i)
  {
    size++;
  }
  for(x = 0, y=size-1; x != size/2; x++, y--)
  {
    char temp = str[x];
    str[x] = str[y];
    str[y] = temp;
  }
  return str;
}

int main()
{
  char str[100] = {'H', 'e', 'y', ' '};
  char str2[100] = {'B', 'a', 'b', 'y'};
  //char str3[100] = {'T', 'e', 's', 't'};
  unsigned int size = 13;
  str_cat(str,str2);
  //str_cat(str,str3);
  for(unsigned int i = 0; i < size; ++i)
  {
    cout << str[i];
  }
  cout << endl;
  
  str_rev(str2);
  for(unsigned int i = 0; i < size; ++i)
  {
    cout << str2[i];
  }
  
  cout << endl;
  return 0;
}
