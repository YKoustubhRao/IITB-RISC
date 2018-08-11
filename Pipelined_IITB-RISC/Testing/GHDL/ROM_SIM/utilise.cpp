#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
	string inp;
	if(argc > 1)
	{
		inp = argv[1];
		if(inp == "--help")
		{
			cout<<"HELP:\nThis program requires an input argument stating the input assembly file name.\n"
				"It can be called as: "<<argv[0]<<" <Input File Name>\n";
			return 0;
		}
	}
	else
	{
		cout<<"No valid Input Argument Provided\nUse option --help for additional information.\n";
		return -1;
	}
	
	string temp = "";
	temp += "python3 assembler.py ";
	temp += inp;
	temp += " temp.hex";
	
	system(temp.c_str());
	remove("kalpesh.hex");

	ofstream ofile("temp2");
	ofile<<"temp.hex\n2\n256";
	system("g++ ROM_sim_generate.cpp");
	ofile.close();
	
	system("./a.out<temp2");
	
	remove("a.out");
	remove("temp.hex");
	remove("temp2");
	cout<<"\n";	
}
