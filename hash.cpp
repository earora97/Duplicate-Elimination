#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(i=a;i<b;i++)
#define MX_BL_SIZE 50000
#define BT_MNDG 20
#define LEX_C(veca, vecb) lexicographical_compare(veca.begin(), veca.end(), \
		vecb.begin(), vecb.end())

//GLOBAL VARIABLES
map<int,set<vector<int> > > hashed_map;
ifstream inputstream;
string filename;

void open()
{
	hashed_map.clear();
	inputstream.open(filename.c_str());
}

void Getnext(int number_of_blocks)
{
	string lines;
	vector < int > temp;
	int sum,i;
	while(getline(inputstream,lines))
	{
		sum=0;
		i=0;
		temp.clear();
		string values;
		stringstream tuple;
		tuple<<lines;
		
		while(tuple>>values)
		{
			int individual_num=stoi(values);
			sum+= individual_num;
			sum%=number_of_blocks;
			temp.push_back(individual_num);
		}
		if(hashed_map[sum].find(temp)==hashed_map[sum].end())
		{
			hashed_map[sum].insert(temp);
			cout<<lines<<endl;
		}
	}
	return;
}

void close()
{
	inputstream.close();
}

int main(int argc,char * argv[])
{
	if(argc>=4)
	{

		filename=argv[1];
		int number_of_blocks=atoi(argv[3]);
		int number_of_attr=atoi(argv[2]);
		
		open();
		Getnext(number_of_blocks);
		close();
	}
	else
	{
		cout<<"Invalid number of arguments!\n";
		cout<<"Usage: <Input file> <Output file> <Number of attributes>";
		cout<<" <Number of Blocks in memory used> <Type of index - btree or hash>\n";
		exit(0);
	}
	return 0;
}