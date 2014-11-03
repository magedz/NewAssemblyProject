#include<string>
#include<vector>
using namespace std;
#ifndef GLOBALS_H
#define GLOBALS_H

class Globals
{
public:
	struct reg
	{
		int value;
		string name;
	};
	vector <string> funcList;
	vector<int> labels; // label0 is in index 0 ..etc
	vector<reg> registers;
	//vector<int> registerNames;
	vector<char> M;
	//vector<char>R;
	vector<int> binaryList;
	//Instruction* PC;

	Globals()
	{
		reg x;
		x.name = "$0";
		registers.push_back(x);
		x.name = "$v0";
		registers.push_back(x);
		x.name = "$v1";
		registers.push_back(x);
		x.name = "$a0";
		registers.push_back(x);
		x.name = "$a1";
		registers.push_back(x);
		x.name = "$a2";
		registers.push_back(x);
		x.name = "$a3";
		registers.push_back(x);
		x.name = "$t0";
		registers.push_back(x);
		x.name = "$t1";
		registers.push_back(x);
		x.name = "$t2";
		registers.push_back(x);
		x.name = "$t3";
		registers.push_back(x);
		x.name = "$t4";
		registers.push_back(x);
		x.name = "$t5";
		registers.push_back(x);
		x.name = "$t6";
		registers.push_back(x);
		x.name = "$t7";
		registers.push_back(x);
		x.name = "$s0";
		registers.push_back(x);
		x.name = "$s1";
		registers.push_back(x);
		x.name = "$s2";
		registers.push_back(x);
		x.name = "$s3";
		registers.push_back(x);
		x.name = "$s4";
		registers.push_back(x);
		x.name = "$s5";
		registers.push_back(x);
		x.name = "$s6";
		registers.push_back(x);
		x.name = "$s7";
		registers.push_back(x);
		x.name = "$t8";
		registers.push_back(x);
		x.name = "$t9";
		registers.push_back(x);
		x.name = "$k0";
		registers.push_back(x);
		x.name = "$k1";
		registers.push_back(x);
		x.name = "$gp";
		registers.push_back(x);
		x.name = "$sp";
		registers.push_back(x);
		x.name = "$fp";
		registers.push_back(x);
		x.name = "$ra";
		registers.push_back(x);

	}
	



};
#endif
