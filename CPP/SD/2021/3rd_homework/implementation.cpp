#include<iostream>
#include<fstream>
#include "interface.hpp"


#include <chrono>

using namespace std;
using namespace std::chrono;
int main(int argc, char* argv[] ) {
	//auto start = high_resolution_clock::now();
	std::ifstream file;
	file.open(argv[1]);

	std::ifstream file2;
	file2.open(argv[2]);
	Comparator c;
	ComparisonReport report = c.compare(file,file2);
	std::cout << report.commonWords.countOfUniqueWords() << " "<<report.uniqueWords[0].countOfUniqueWords() << " " << report.uniqueWords[1].countOfUniqueWords();
	// auto stop = high_resolution_clock::now();
	// auto duration = duration_cast<microseconds>(stop - start);
  
    // cout << "Time taken by function: "
    //      << duration.count() << " microseconds" << endl;
	return 0;
}
//Beacause i know how much u value reading a fine book, i used harry potter and the sorcerer's stone <3
//as for the 3rd file i used harry potter and the order of the phoenix