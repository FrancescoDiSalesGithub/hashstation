#include "hashfinder.h"

#include<vector>
#include<string>
#include<fstream>

#include<iostream>

hashidentifier::hashidentifier(char* arg,char* filename)
{
	if(arg == NULL)
		throw "string is null";
		
	this->hash = std::string(arg);
	this->countHash = 0;

	fileInput.open(filename);

	if(!fileInput.good())
		throw "file not found";

}

void hashidentifier::compareHash()
{
	int count = 0;
	for(int i=0;i<lineVector.size();i++)
	{
		if(hash == lineVector.at(i))
		{
			count++;
			this->linePositionVector.push_back(i);
		}

	}

	if(count > 0)
		this->setCountHash(count);
}

void hashidentifier::readFile()
{
	std::string line;
	
	while(getline(fileInput,line))
	{
		this->lineVector.push_back(line);
		
	}

	fileInput.close();
}

void hashidentifier::increment()
{
	countHash++;
}

void hashidentifier::linesFound()
{
	if(this->getCountHash() == 1)
		std::cout<<"only one hash found at position: "<<linePositionVector.at(0)<<std::endl;
	else
	{
		std::cout<<"rows found in the file for the specific hash: "<<std::endl;
		for(int i=0;i<linePositionVector.size();i++)
		{
			std::cout<<linePositionVector.at(i)+1<<" ";
		}
		std::cout<<std::endl;
	}
}

std::string hashidentifier::getHash()
{
	return hash;
}

void hashidentifier::setHash(std::string hash)
{
	this->hash = hash;
}

int hashidentifier::getCountHash()
{
	return countHash;
}

void hashidentifier::setCountHash(int count)
{
	this->countHash = count;
}
