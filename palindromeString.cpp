/**
 * Quesiton : Check if the string is Palindrome or not.
 */

#include <iostream>

//check palindrome function
bool checkPalindrome(std::string &str)
{
    int stringLength = str.length();
    
    //check the equality of first element with last, vice versa
    //loop runs till the middle of the string
    for(int i = 0 ; i < stringLength/2 ; i++)
    {
        if(str[i] != str[stringLength - 1 - i])
        return false;
    }
    return true;
}
int main()
{
    std::string str;
    std::cout<<"Enter String : ";
    std::cin>>str;

    if(checkPalindrome(str))
    {
        std::cout<<"String : "<<str<<" is palindrome"<<std::endl;
    }
    else
    {
        std::cout<<"String : "<<str<<" is not palindrome"<<std::endl;
    }
    return 0;
}