#include<string>
#include<vector>

#include<fstream>

class hashidentifier
{

	private:
		std::string hash;
		int countHash;

		std::ifstream fileInput;
		std::vector<std::string> lineVector;
		std::vector<int>linePositionVector;

	public:
		hashidentifier(char*,char*);
		void compareHash();
		void readFile();

		void increment();
		void linesFound();

		std::string getHash();
		void setHash(std::string);

		int getCountHash();
		void setCountHash(int);

		std::vector<std::string> getLineVector();
		void setLineVector(std::vector<std::string>);

};
