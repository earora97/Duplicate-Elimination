#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(i=a;i<b;i++)
#define MX_BL_SIZE 50000
#define BT_MNDG 20
#define LEX_C(veca, vecb) lexicographical_compare(veca.begin(), veca.end(), \
		vecb.begin(), vecb.end())

int main(int argc,char * argv[])
{
	if(argc<=4)
	{
		cout<<"Invalid number of arguments!\n";
		cout<<"Usage: <Input file> <Output file> <Number of attributes> <Number of Blocks in memory used> <Type of index - btree or hash>" << endl;
		exit(0);
	}
	
	int index,number_attributes,number_of_blocks;
	string input_file,output_file,command;

	input_file = argv[1];
	number_attributes = atoi(argv[2]);
	number_of_blocks = atoi(argv[3]);
	index = atoi(argv[4]);
	output_file = "Output.txt";
	
	if(index == 0)
		command+="./hash ";
	else
		command += "./btree ";
	
	command += (input_file + " ") + (to_string(number_attributes)) + " " + (to_string(number_of_blocks)) + " " + "> "+output_file;
	
	system("g++ -std=c++11 -o hash hash.cpp");
	system("g++ -std=c++11 -o btree btree.cpp");
	cout << "Query:  " << command << endl;
	system(command.c_str());
	return 0;
}