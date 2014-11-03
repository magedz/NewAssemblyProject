#include <iostream>
#include"RFormat.h"
#include"Globals.h"
#include <string>
using namespace std;

RFormat::RFormat(int n) : Instruction(n)
{
	func = instWord & 0x3F;
	shamt = (instWord >> 6) & 0x1f;
	rd = (instWord >> 11) & 0x1f;
	rt = (instWord >> 16) & 0x1f;
	rs = (instWord >> 21) & 0x1f;
	//PUBLISH YA 7AYAWAAAAAAN
}

void RFormat::decodeInst()
{
	switch (func)
	{
	case 0x20:			addDisassemble();
		Instruction::myFunctionPointer = &this->addSimulate;
		break;
	case 0x21:			adduDisassemble();
		Instruction::myFunctionPointer = &this->adduSimulate;

		break;
	case 0x24:			andDisassemble();
		Instruction::myFunctionPointer = &this->andSimulate;

		break;
	case 0x08:			jrDisassemble();
		Instruction::myFunctionPointer = &this->jrSimulate;
		break;

	case 0x2a:			sltDisassemble();
		Instruction::myFunctionPointer = &this->sltSimulate;
		break;
	case 0x2b:			sltuDisassemble();
		Instruction::myFunctionPointer = &this->sltuSimulate;
		break;

		break;
	case 0x00:			sllDisassemble();
		Instruction::myFunctionPointer = &this->sllSimulate;

		break;
	case 0x02:			srlDisassemble();
		Instruction::myFunctionPointer = &this->srlSimulate;
		break;


	case 0x22:			subDisassemble();
		Instruction::myFunctionPointer = &this->subSimulate;
		break;

	case 0x23:			subuDisassemble();
		Instruction::myFunctionPointer = &this->subuSimulate;
		break;



	default:
		instString = "Unknown Intruction";
		cout << instString;
	}
}

void RFormat::addDisassemble()
{
	instString = "add" + string(" ") + x.registers[rd].name + string(",") + x.registers[rs].name + string(",") + x.registers[rt].name; // vector of rd
	cout << instString;
}
void RFormat::adduDisassemble()
{
	instString = "addu" + string(" ") + x.registers[rd].name + string(",") + x.registers[rs].name + string(",") + x.registers[rt].name;
	cout << instString;
}
void RFormat::adduSimulate()
{
	x.registers[rd].name = x.registers[rs].value + x.registers[rt].value;
}
void RFormat::andDisassemble()
{
	instString = "and" + string(" ") + x.registers[rd].name + string(",") + x.registers[rs].name + string(",") + x.registers[rt].name;
	cout << instString;
}
void RFormat::andSimulate()
{
	x.registers[rd].name = x.registers[rs].value & x.registers[rt].value;
}
void RFormat::jrDisassemble()
{
	instString = "jr" + string(" ") + x.registers[rs].name;
	cout << instString;
}
void RFormat::jrSimulate()
{
	pc = x.registers[rs].value;
}
void RFormat::sltDisassemble()
{
	instString = "slt" + string(" ") + x.registers[rd].name + string(",") + x.registers[rs].name + string(",") + x.registers[rt].name;
	cout << instString;
}
void RFormat::sltSimulate()
{
	x.registers[rd].name = (x.registers[rs].value < x.registers[rt].value) ? 1 : 0;
	PC += 4;
}
void RFormat::sltuDisassemble()
{
	instString = "sltu" + string(" ") + x.registers[rd].name + string(",") + x.registers[rs].name + string(",") + x.registers[rt].name;
	cout << instString;
}
void RFormat::sllDisassemble()
{
	instString = "sll" + string(" ") + x.registers[rd].name + string(",") + x.registers[rt].name + string(",") + to_string(shamt);
	cout << instString;
}
void RFormat::sllSimulate()
{
	x.registers[rd].name = x.registers[rt].value << shamt;
	PC += 4;
}
void RFormat::srlDisassemble()
{
	instString = "sll" + string(" ") + x.registers[rd].name + string(",") + x.registers[rt].name + string(",") + to_string(shamt);
	cout << instString;
	PC += 4;
}
void RFormat::srlSimulate()
{
	x.registers[rd].name = x.registers[rt].value >> shamt;    // or pow(2,shamt) ??
	PC += 4;
}
void RFormat::subDisassemble()
{
	instString = "sll" + string(" ") + x.registers[rd].name + string(",") + x.registers[rs].name + string(",") + x.registers[rt].name;
	cout << instString;
	PC += 4;
}
void RFormat::subSimulate()
{
	x.registers[rd].name = x.registers[rs].value << x.registers[rt].value;
	PC += 4;
}
void RFormat::subuDisassemble()
{
	instString = "sll" + string(" ") + x.registers[rd].name + string(",") + x.registers[rs].name + string(",") + x.registers[rt].name;
	cout << instString;
	PC += 4;
}