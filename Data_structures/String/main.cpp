#include "String.hpp"


int main()
{
    String s("text");
    String s2("text2");

    String result = s + s2;
    std::cout << result.text() << std::endl;

    std::cout << (s != s2) << std::endl;
    
    s[1] = 'k';
    std::cout << s[1] << std::endl;
    
    //std::cout << s.length() << " " << s2.length() << " " << result.length() << std::endl;
}
