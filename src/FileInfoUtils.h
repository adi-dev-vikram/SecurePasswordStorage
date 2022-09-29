#include <string>
#include <map>
#include <iterator>
using namespace std;

class CFileInfoUtils
{
public:
	CFileInfoUtils(void);
	~CFileInfoUtils(void);

    static bool FetchKeyVal(std::string filePath);
    std::string GetFilePath();
	
private:

};