#pragma once
#include <iostream>
#include <string>
#include <set>
#include <list>
#include <vector>
///
/// Represents a multiset of words
///
/// If you need to see how it is intended to be used,
/// check out the corresponding unit tests
///
/// Implement all methods of this class
/// 
class WordsMultiset {
private:
	typedef std::pair<std::string, int> item;
	typedef std::list<item> bucket;
	std::vector<bucket> table;

	int count = 0;
	float load_factor = 0.7f;
public:
	WordsMultiset(){
		table.resize(8);
	};
	/// Adds times occurences of word to the container
	///
	/// For example, add("abc") adds the word "abc" once,
	/// while add("abc", 4) adds 4 occurrances.
	void add(const std::string& word, size_t times = 1) {
		if(contains(word)) {
			int elementIndex = getIndex(word);
			for(auto &i : table[elementIndex]){
				if(i.first == word){
					i.second += times;
				}
			}
		} 
		else {
			auto elementIndex = getIndex(word);
			table[elementIndex].push_back(std::make_pair(word, times));
			count ++;
		}
	}

	/// Checks whether word is contained in the container
	bool contains(const std::string& word) const {
		int elementIndex = getIndex(word);
		for(auto &i : table[elementIndex]){
			if(i.first == word){
				return true;
			}
		}
		return false;
	}

	/// Number of occurrances of word 
	size_t countOf(const std::string& word) const {
		if(contains(word)){
			int elementIndex = getIndex(word);
			for(auto &i : table[elementIndex]){
				if(i.first == word){
					return i.second;
				}
			}
		}
		else {
			return 0;
		}
	}

	/// Number of unique words in the container
	size_t countOfUniqueWords() const {
		return count;
	}


	/// Returns a multiset of all words in the container
	std::multiset<std::string> words() const {
		std::multiset<std::string> toReturn;
		for(auto i = 0 ; i < table.size(); ++i) {
			for(auto j = table[i].begin(); j != table[i].end(); ++j) {
				for(auto q = 0; q < j->second; ++q){
					toReturn.insert(j->first);
				}
			}
		}
		return toReturn;
	}
	int getIndex(const std::string &key)const {
        return std::hash<std::string>()(key) % table.size();
    }
	float getLoadFactor() const {
        return float(count) / float(table.size()) ;
    }

	bool shouldResize() const {
        return getLoadFactor() > load_factor; 
    }
	// std::pair<std::string, int >* findWord(const std::string& element) const {
	// 	int elementIndex = getIndex(element);
	// 	for(auto i : table[elementIndex]){
	// 		if(i.first == element){
	// 			std::pair<std::string, int >*  toReturn = new std::pair<std::string, int>(i);
	// 			return toReturn;
	// 		}
	// 	}
	// 	return nullptr;
	// }
	void resize() {
        std::vector<bucket> oldTable(table.size()*2);
        oldTable.swap(this->table);
        count = 0;

        for (size_t i = 0 ;i < oldTable.size(); ++i) {
            for (auto &i : oldTable[i]) {
                add(i.first, i.second); 
            }  
        }
    }

	bool remove(const std::string &word) {	
		if(contains(word)){
			int elementIndex = getIndex(word);
			for(auto i = table[elementIndex].begin(); i != table[elementIndex].end(); ++i ) {
				if(i->first == word) {
					i->second--;
					if(i->second == 0) {
						table[elementIndex].erase(i);
						count--;
					}
					return true;
				}
			}
		}
		return false;
	}
	// You can add additional members if you need to

	
};

///
/// Results of the comparison of two streams of words
/// DO NOT modify this class
/// If you need to see how it is intended to be used,
/// check out the corresponding unit tests
///
class ComparisonReport {
public:
	/// A multiset of all words that exist in both streams
	WordsMultiset commonWords;

	/// Multisets of words unique to the two streams
	/// The first element of the array contains the words that are unique
	/// to the first stream (a) and the second one -- to the second stream (b)
	WordsMultiset uniqueWords[2];
};

/// 
/// Can be used to compare two streams of words
///
class Comparator {
public:
	//a - two
	//b - two two
	//cw - two
	//uw - 
	ComparisonReport compare(std::istream& a, std::istream& b) {
		std::string word;
		ComparisonReport toReturn;
		while (a >> word) {
			toReturn.uniqueWords[0].add(word);
		}
		while (b >> word){
			if(toReturn.uniqueWords[0].contains(word)){
				toReturn.uniqueWords[0].remove(word);
				toReturn.commonWords.add(word);
			} 
			else {
				toReturn.uniqueWords[1].add(word);
			}
		}
		return toReturn;		
	}
	//"one two three four two one seven");
	//"two one four one one");
	
	//cw -> one -2 two -1  four -1
	//uw[0]->  two -1 three -1 
	//uw[1]-> one -1
	// You can add additional members if you need to
};
