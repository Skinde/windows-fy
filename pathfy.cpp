#include <iostream>
#include <cstdlib>
#include <io.h>

int main(int argc,char ** argv)
{
    std::string corrected_argv;
    if (argc == 2)
    {

        for (char c = *argv[1]; c; c=*++argv[1])
        {
            if (c != '\"')
            {
                corrected_argv = corrected_argv + c;
            }
        }
        system(("setx /M path \"%path%;"+corrected_argv+"\"").data());
        return 0;
    }
    else
    {
        std::cout << "Invalid number of arguments";
        return -1;
    }
    
}