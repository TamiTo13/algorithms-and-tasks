#include <iostream>
#include <stack>

bool readAndDelete (std::stack<char>& primary, std::string word)
{
    if(word == "") return true;
    if(primary.empty()) return false;

    std::stack<char> valid;
    std::stack<char> invalid;


    int j = 0;
    bool covered = false; //дали думата е покрита
    while(!primary.empty())
    {
        if(primary.top() == word[j])
        {
            j++;
            valid.push(primary.top());
        }
        else
        {
            //std::cout<<primary.top()<<" "<<word[j];
            invalid.push(primary.top());
        }

        primary.pop();
        
        if(j == word.length() + 1)
        {
            while(!primary.empty())
            {
                invalid.push(primary.top());
                primary.pop();
            }
            break; 
        }
    };

    while(!invalid.empty())
    {
            primary.push(invalid.top());
            invalid.pop();
    }

    return j >= word.length() - 1;
}


int main()
{
    std::stack<char> a;
    a.push('r');
    a.push('a');
    a.push('c');
    a.push('o');
    a.push('m');
    std::cout<<(readAndDelete(a, "car"));
    while(!a.empty())
    {
        std::cout<<a.top();
        a.pop();
    }

}