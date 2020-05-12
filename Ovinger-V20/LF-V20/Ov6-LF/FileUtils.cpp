#include "FileUtils.h"

void writeUserInputToFile()
{
	const string filename{"outputfile.txt"};
	ofstream outFile{filename};
	if (!outFile)
		error("Couldn't open file: ",filename);

	cout << "Write some words, they will be output in the file"
			" \"outputfile.txt\", every word on separate lines."
			" quit exits\n> ";

	for (string word; cin >> word && word != "quit";)
		outFile << word << '\n';
}

void addLineNumbers(string filename)
{
	ifstream inFile{filename};
	if (!inFile)
		error("Couldn't open file: ",filename);

	ofstream outFile{filename + ".linum"};
	if (!outFile)
		error("Couldn't open file: ",filename+".linum");

	int lineNumber = 1;
	for (string line; getline(inFile, line); ++lineNumber)
		outFile << lineNumber << ": " << line << '\n';
}

//losning med vector
void characterStatistics(string filename)
{
	ifstream inFile{filename};
	if (!inFile)
		error("Couldn't open file: ",filename);

	vector<int> stats(26); // ev. std::array
	for (unsigned char c; inFile >> c;) {
		if (isalpha(c)) {
			++stats[tolower(c) - 'a'];
		}
	}

	for (char c = 'a'; c <= 'z'; ++c) {
		cout << c << ": " << stats[c - 'a'] << '\t';
		if (c % 3 == 0) {
			cout << '\n';
		}
	}
}

//losning med map

void characterStatisticsV2(string filename){
	map<char, int> charOccurences;

    ifstream inFile{filename};
    if(!inFile){
        error("Couldn't open file: ",filename);
    }

	for (char c = 'a'; c < 'z'; ++c){
        charOccurences[c] = 0;
    } 

    for (unsigned char c; inFile >> c;) {
        if(isalpha(c))
            ++charOccurences[tolower(c)];
    }

	for(auto c : charOccurences){
        cout << c.first << ": " << c.second << "\t";
		if(c.first%3 == 0){
			cout<<'\n';
		}
    }
}