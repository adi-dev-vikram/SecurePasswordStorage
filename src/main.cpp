#include<iostream>>

#include "FileInfoUtils.h"
#include "Encrypter.h"
#include<iostream>
using namespace std;
#include<cstring>
#include<map>
#include<fstream>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
uid_t getuid(void);
uid_t geteuid(void);

void ParseCmdArgs(int argc, char* argv[], std::map<std::string, std::string>& cmdArgMap)
{
	std::string cmdLine = "";

	// Clear command args map
	cmdArgMap.clear();

	// Parse command line.
	for(int i = 0 ; i < argc; i++)
	{
		std::string cmdArg = std::string(argv[i]);
		std::string key,value;
		char delimiter = '=';

		std::string::size_type right = cmdArg.find(delimiter, 0);
		if(std::string::npos != right)
		{
			// split command arguement
			key = cmdArg.substr(0, right);
			value = cmdArg.substr(right+1, cmdArg.size());

		}
		else
		{
			key = cmdArg;
			value = "";
		}

		cmdArgMap[key] = value;
		
		if(i > 0)
		{
			cmdLine.append(" ");
		}
		if(NULL != argv[i])
		{
			cmdLine.append(argv[i]);
		}
	}

	// Log command line
	std::cout << "ExecuteCommand: Command line - '" << cmdLine.c_str() << endl;

	std::cout << "ExecuteCommand: Command arg map size - " << cmdArgMap.size();

	return;
}

int main(int argc,char* argv[])
{
    std::map<std::string, std::string> cmdArgsMap;
    printf("This process is %d\n", getpid());
    printf("The real user ID is %d\n", getuid());
    printf("The effective user ID is %d\n", geteuid());
    // Process Command
    if (argc <= 1)
    {
        // Command is missing. Show help and return error value 10.
        
        std::cout << "Invalid arguments.\n";
        return -1;
    }
    else
    {
        std::string cmd = std::string(argv[1]);

        // don't pass in the first parameter
        ParseCmdArgs(argc, argv, cmdArgsMap);
    }
    
    
    
    auto me = getuid();
    auto myprivs = geteuid();


    if (me == myprivs)
    {
        std::cout << "Running as self\n";
    } 
    else
    {
        std::cout << "Running as somebody else\n";
        if (getuid()) 
        {
            printf("%s", "You are not root!\n");
        }
        else
        {
            printf("%s", "OK, you are root.\n");
        } 
        
    }
    
}
