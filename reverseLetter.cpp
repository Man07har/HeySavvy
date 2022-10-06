/* Given a string str, reverse it and omit all non-alphabetic characters.

Example
For str = "krishan", the output should be "nahsirk".

For str = "ultr53o?n", the output should be "nortlu".

Input/Output
[input] string str
A string consists of lowercase latin letters, digits and symbols.

[output] a string */

std::string reverse_letter(const std::string &str)
{
    std::stringstream result;
    for (int i = str.length() - 1; i >= 0; --i)
    {
      char c = str[i];
      if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
      { 
        result << c;
      }
    }
    
    return result.str();
}