#include "IFormat.h"
#include"Globals.h"

IFormat::IFormat(int n) : Instruction(n)
{
	rt = (instWord >> 16) & 0x1f;
	rs = (instWord >> 21) & 0x1f;
	imm = (instWord & 0x0000FFFF);
}

void IFormat::decodeInst()
{
	switch (opcode)
	{
	case 0x8:			addiDisassemble();
		Instruction::myFunctionPointer = &this->addiSimulate;
		break;
	case 0x9:			addiuDisassemble();
		Instruction::myFunctionPointer = &this->addiuSimulate;

		break;
	case 0xc:			andiDisassemble();
		Instruction::myFunctionPointer = &this->andiSimulate;

		break;
	case 0x4:			beqDisassemble();
		Instruction::myFunctionPointer = &this->beqSimulate;
		break;

	case 0x5:			bneDisassemble();
		Instruction::myFunctionPointer = &this->bneSimulate;

		break;
	case 0xf:			luiDisassemble();
		Instruction::myFunctionPointer = &this->luiSimulate;
		break;

		break;
	case 0x23:			lwDisassemble();
		Instruction::myFunctionPointer = &this->lwSimulate;

		break;
	case 0xd:			oriDisassemble();
		Instruction::myFunctionPointer = &this->oriSimulate;
		break;


	case 0xa:			sltiDisassemble();
		Instruction::myFunctionPointer = &this->sltiSimulate;
		break;

	case 0x28:			sbDisassemble();
		Instruction::myFunctionPointer = &this->sbSimulate;
		break;


	case 0x29:			shDisassemble();
		Instruction::myFunctionPointer = &this->shSimulate;
		break;


	case 0x2b:			swDisassemble();
		Instruction::myFunctionPointer = &this->swSimulate;
		break;

	default:
		instString = "Unknown Instrution";
	}
}

void IFormat::addiDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "addi" + x.registers[rs].name + "," + x.registers[rt].name + "," + to_string(signedImm);
	cout << instString << endl;
}

void IFormat::luiDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "lui" + x.registers[rs].name + "," + x.registers[rt].name + "," + to_string(signedImm);
	cout << instString << endl;
}
void IFormat::addiuDisassemble()
{
	instString += "addiu" + x.registers[rs].name + "," + x.registers[rt].name + "," + to_string(imm);
	cout << instString << endl;
}

void IFormat::andiDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "andi" + x.registers[rs].name + "," + x.registers[rt].name + "," + to_string(signedImm);
	cout << instString << endl;
}

void IFormat::beqDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "beq" + x.registers[rs].name + "," + x.registers[rt].name + "," + to_string(signedImm);
	cout << instString << endl;
}

void IFormat::bneDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "bne" + x.registers[rs].name + "," + x.registers[rt].name + "," + to_string(signedImm);
	cout << instString << endl;
}

void IFormat::lwDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "lw" + x.registers[rt].name + "," + to_string(signedImm) + "(" + x.registers[rt].name + ")";
	cout << instString << endl;
}

void IFormat::oriDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "ori" + x.registers[rs].name + "," + x.registers[rt].name + "," + to_string(signedImm);
	cout << instString << endl;
}

void IFormat::sltiDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "slti" + x.registers[rs].name + "," + x.registers[rt].name + "," + to_string(signedImm);
	cout << instString << endl;
}

void IFormat::sbDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "sb" + x.registers[rt].name + "," + to_string(signedImm) + "(" + x.registers[rt].name + ")";
	cout << instString << endl;
}

void IFormat::shDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "sh" + x.registers[rt].name + "," + to_string(signedImm) + "(" + x.registers[rt].name + ")";
	cout << instString << endl;
}

void IFormat::swDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "lw" + x.registers[rt].name + "," + to_string(signedImm) + "(" + x.registers[rt].name + ")";
	cout << instString << endl;
}

void IFormat::sbSimulate()
{
	memory[rs + signedImm] = rt;
	PC += 4;
}

void IFormat::sltiSimulate()
{
	rd = (rs < signedImm) ? 1 : 0;
	PC += 4;
}

void IFormat::lwSimulate()
{
	rt = memory[rs + signedImm];      // assuming we have a vector called memory
	PC += 4;
}

void IFormat::beqSimulate()
{
	if (rs == rt)
		PC = PC + 4 + signedImm; // actualPC (pointer) or simulated PC? (signedImm here means address)
}