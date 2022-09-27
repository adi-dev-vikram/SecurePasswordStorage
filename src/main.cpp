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


int main()
{
    printf("This process is %d\n", getpid());
    printf("The real user ID is %d\n", getuid());
    printf("The effective user ID is %d\n", geteuid());
    
    
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
    

