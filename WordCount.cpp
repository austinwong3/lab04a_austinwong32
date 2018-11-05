// WordCount.cpp
// Written by Richert Wang for CS 32, F18.

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int total = 0;
	for(int i = 0; i<static_cast<int>(CAPACITY); i++)
	{
		for (int j = 0; j<static_cast<int>(table[i].size()); j++)
		{
			total+=static_cast<int>(table[i].at(j).second);
		}
	}
	return total;
}

int WordCount::getNumUniqueWords() const {
	int total = 0;
	for(int i = 0; i<static_cast<int>(CAPACITY); i++)
	{
		total+=table[i].size();
	}
	return total;
}

int WordCount::getWordCount(std::string word) const {
	if (word == "")
	{
		return 0;
	}
	string vword = stripWord(word);
	for (int i = 0; i < static_cast<int>(vword.length()); i++)
	{
		vword[i] = toupper(vword[i]);
	}
	int ind = hash(vword);
	vector<pair<std::string, size_t>>::const_iterator ptr = table[ind].begin();
	
	for (ptr=table[ind].begin(); ptr < table[ind].end(); ptr++) 
	{
        if(ptr->first == vword)
		{
			return ptr->second;
		}
	}
	return 0;
}
	

int WordCount::incrWordCount(std::string word) {
	if (word == "")
	{
		return 0;
	}
	bool valid = false;
	for(int i = 0; i<static_cast<int>(word.length()); i++ )
	{
		if (isalpha(word[i]))
		{
			valid =true;
		}
	}
	if (valid == false)
	{
		return 0;
	}
	bool exist = getWordCount(word);
	
	
	string vword = stripWord(word);
	for (int i = 0; i < static_cast<int>(vword.length()); i++)
	{
		vword[i] = toupper(vword[i]);
	}
	int ind = hash(vword);
	if (exist)
	{
		//vector<pair<std::string, size_t>>::const_iterator ptr = table[ind].begin();
		
		//for (ptr=table[ind].begin(); ptr < table[ind].end(); ptr++) 
		for (int i = 0; i< static_cast<int>(table[ind].size()); i++)
		{
			if(table[ind][i].first == vword)
			{
				table[ind][i].second+=1;
				return table[ind][i].second;
			}
		}
	}
	else
	{
		pair<std::string, size_t> temp (vword, 1);
		table[ind].push_back(temp);
		return 1;
	}
	return 0;
}


bool WordCount::isWordChar(char c) {
	if(isalpha(c) || c == '-' || c == '\'')
	{
		return true;
	}
	return false;
}


std::string WordCount::stripWord(std::string word) {
	if (word == "")
	{
		return "";
	}
	bool valid = false;
	for(int i = 0; i<static_cast<int>(word.length()); i++ )
	{
		if (isalpha(word[i]))
		{
			valid =true;
		}
	}
	if (valid == false)
	{
		return "";
	}
	bool cont = true;
	while (cont)
	{
		char first = word.at(0);
		if (!isWordChar(first) || first == '-' || first == '\'' )
		{
			word.erase(0,1);
		}
		else{
			cont = false;
		}
	}
	for (size_t i = 1; i < word.size()-1; i++) {
		if (!isWordChar(word.at(i)))
		{
			word.erase(i,1);
			i--;
		}
	}
	
	cont = true;
	while (cont)
	{
		char last = word.at(word.size()-1);
		if (!isWordChar(last) || last == '-' || last == '\'' )
		{
			word.erase(word.size()-1,1);
		}
		else{
			cont = false;
		}
	}
	return word;
}
