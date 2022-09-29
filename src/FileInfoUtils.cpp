#include<iostream>
using namespace std;
#include<cstring>
#include<map>
#include<fstream>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include "FileInfoUtils.h"

std::string CFileInfoUtils::GetFilePath()
{
    
}

bool CFileInfoUtils::FetchKeyVal(std::string filePath)
{
// Read Key-value pairs from config files
// For example: AuthServers=<IP>
    std::map<std::string, std::string> ConfigInfo;
    std::ifstream fs;
    fs.open(filePath);
    if(fs.good())
    {
        printf("\nFile is there!");
    }
    else{
        printf("aditya");
    }
    
    std::string line;
    while (std::getline(fs, line))
    {
        std::istringstream is_line(line);
        std::string key;
        if (std::getline(is_line, key, '='))
        {
            std::string value;
            if (key[0] == '#')
                continue;
            
            if (std::getline(is_line, value))
            {
                ConfigInfo[key] = value;
                   cout <<  " The IP is: " << ConfigInfo[key] << endl;
            }
        }
    }
 
    return 0;
}
