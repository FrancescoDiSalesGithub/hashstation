
#include<sqlite3.h>
#include<string>
class hashstorage
{

	private:
		sqlite3* dbHandle;
		
		std::string value;
		std::string plainTextValue;
	
	public:
		hashstorage(sqlite3*,std::string,std::string);

		void saveValue();
		void searchValue(std::string);
		
};
