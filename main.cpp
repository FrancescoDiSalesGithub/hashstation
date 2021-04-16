#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>

#include<string.h>

#include "hashfinder.h"

int main(int argc,char* argv[])
{


	
	switch(argc)
	{
		case 1:
			std::cout<<"help to do"<<std::endl;
			break;
		case 2:
			std::cout<<"missing third argument: possible values [searchfile/searchdb/savedb/updatedb] "<<std::endl;
			break;

		case 3:
			if(strcmp(argv[2],"searchfile")==0)
			{
				std::cout<<"missing fourth argument: possible values [filename.txt]"<<std::endl;
				return -1;
			}

			if(strcmp(argv[2],"searchdb")==0 || strcmp(argv[2],"savedb") == 0 || strcmp(argv[2],"updatedb") == 0)
			{
				std::cout<<"missing fourth argument: possible values [value_in_plain_text]"<<std::endl;
				return -1;
			}

			break;


		case 4:
			try
			{

				if(strcmp(argv[2],"searchfile")==0)
				{
				
					hashidentifier hash(argv[1],argv[3]);
				
					hash.readFile();
					hash.compareHash();
				
					int hashOccurence = hash.getCountHash();
				
					switch(hashOccurence)
					{
						case 0:
							std::cout<<"no occurence found"<<std::endl;
							break;
						case 1:
							std::cout<<"1 occurence found"<<std::endl;
							hash.linesFound();
							break;
						default:
							std::cout<<hashOccurence<<" occurence found"<<std::endl;
							hash.linesFound();
							break;
					}
	
				}
				catch( const char* message)
				{
					std::cout<<message<<std::endl;
				}
			}

			//search on db
			//update on db
			break;

		case 5:
			if(strcmp(argv[2],"md5")==0)
				std::cout<<"elaboration on md5 table..."<<std::endl;
			break;


		default:
			std::cout<<"too much arguments"<<std::endl;
			break;
	};

	return 0;
}
