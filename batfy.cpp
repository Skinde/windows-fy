#include <iostream>
#include <fstream>

int main(int argc, char ** argv)
{
    std::string filename = "a.bat";
    for (int i = 1; i < argc; i++)
    {
        if (argv[i] == "-o" && i+1 < argc)
        {
            filename = std::string(argv[i+1]) + ".bat";
            i++;
        }
        else
        {
            int i = 0;
            std::string fixed = "";
            for (char c = *argv[1]; c; c=*++argv[1])
            {
                if (c!='\"')
                {
                    
                    fixed = fixed + c;
                    
                }
                i++;
            }
            std::ofstream outfile (filename);
            outfile << fixed;
            outfile.close();
            return 0;
        }
    }
    return -1;

}