#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <wincon.h>
#include "emulate.h"

#define IMM fetch(MC->IP+1)
#define IMM8 mem[MC->IP+1]
#define MEM fetch(fetch(MC->IP+1))
#define OFF fetch(MC->IP+1)
#define REG MC->REGS[IMM8]


void _gotoxy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
}


machine * initialise(void)
{
	static machine * mach;

	for (int i = 0; i<65536; i++) mem[i] = 0;
	mach = calloc(sizeof(machine),1);
	mach->SP = 0xA000;

	return mach;
}

int fetch(int address)
{
	return mem[address]+mem[address+1]*256;
}

void put(int address, int value)
{
	mem[address] = (value % 256);
             mem[address+1] = (value / 256);
	if ((address >= 0xa000) && (address < 0xa000 + 80*40*2) && (address%2 == 0))
	{
		_gotoxy(((address-0xa000)/2)%80+1,((address-0xa000)/2)/80+1);
		//_textbackground(value >> 12);
		//_textcolor((value >> 8) & 0x000F);
		_putch(value & 0x00FF);
	}

	return;
}

void setflags(int testval, machine * MC)
{
	MC->Z = (testval == 0);
	MC->P = (testval > 0);
	return;
}

void emulate(int startaddress, machine * MC)
{
	int temp;
	long int ltemp;
	MC->IP = startaddress;

	MC->running=true;

	while (MC->running)
	{
		switch (mem[MC->IP])
		{
			case HLT:
			{
				MC->running = false;
			} break;
			case LDA:
			{
				MC->A = MEM;
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case LAX:
			{
				MC->A = fetch(OFF+MC->X);
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case LDI:
			{
				MC->A = IMM;
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case LDS:
			{
				MC->SP = MEM;
				MC->IP+=2;
			} break;
			case LSI:
			{
				MC->SP = IMM;
				MC->IP+=2;
			} break;
			case STA:
			{
				put(IMM,MC->A);
				MC->IP+=2;
			} break;
			case STX:
			{
				put(IMM+MC->X,MC->A);
				MC->IP+=2;
			} break;
			case LDX:
			{
				MC->X = MC->A;
			} break;
			case XCHG:
			{
				temp = MEM;
				put(IMM,MC->A);
				MC->A = temp;
				MC->IP+=2;
			} break;
			case XCHR:
			{
				temp = MC->A;
				MC->A = REG;
				REG = temp;
				MC->IP++;
			} break;
			case LDR:
			{
				MC->A = REG;
				setflags(MC->A,MC);
				MC->IP++;
			} break;
			case STR:
			{
				REG = MC->A;
				MC->IP++;
			} break;
			case PUSH:
			{
				MC->SP-=2;
				put(mem[MC->SP],MC->A);
			} break;
			case PUSHR:
			{
				MC->SP-=2;
				put(mem[MC->SP],REG);
				MC->IP++;
			} break;
			case POP:
			{
				MC->A = fetch(MC->SP);
				MC->SP+=2;
			} break;
			case POPR:
			{
				REG = fetch(MC->SP);
				MC->SP+=2;
				MC->IP++;
			} break;
			case ADR:
			{
				MC->A = MC->A + REG;
				MC->C = (MC->A < REG);
				setflags(MC->A,MC);
				MC->IP++;
			} break;
			case ARC:
			{
				MC->A = MC->A + REG + MC->C;
				MC->C = (MC->A < REG);
				setflags(MC->A,MC);
				MC->IP++;
			} break;
			case ADD:
			{
				MC->A = MC->A + MEM;
				MC->C = (MC->A < MEM);
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case ADC:
			{
				MC->A = MC->A + MEM+MC->C;
				MC->C = (MC->A < MEM);
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case ADX:
			{
				MC->A = MC->A + fetch(OFF+MC->X);
				MC->C = (MC->A < fetch(OFF+MC->X));
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case AXC:
			{
				MC->A = MC->A + fetch(OFF+MC->X)+MC->C;
				MC->C = (MC->A < fetch(OFF+MC->X));
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case ADI:
			{
				MC->A = MC->A + IMM;
				MC->C = (MC->A < IMM);
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case AIC:
			{
				MC->A = MC->A + IMM + MC->C;
				MC->C = (MC->A < IMM);
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case SBR:
			{
				MC->A = MC->A - REG;
				MC->C = (MC->A > REG);
				setflags(MC->A,MC);
				MC->IP++;
			} break;
			case SRB:
			{
				MC->A = MC->A - REG - MC->C;
				MC->C = (MC->A > REG);
				setflags(MC->A,MC);
				MC->IP++;
			} break;
			case SUB:
			{
				MC->A = MC->A - MEM;
				MC->C = (MC->A > MEM);
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case SBB:
			{
				MC->A = MC->A - MEM-MC->C;
				MC->C = (MC->A > MEM);
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case SBX:
			{
				MC->A = MC->A - fetch(OFF+MC->X);
				MC->C = (MC->A > fetch(OFF+MC->X));
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case SXB:
			{
				MC->A = MC->A - fetch(OFF+MC->X)-MC->C;
				MC->C = (MC->A > fetch(OFF+MC->X));
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case SBI:
			{
				MC->A = MC->A - IMM;
				MC->C = (MC->A > IMM);
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case SIB:
			{
				MC->A = MC->A - IMM - MC->C;
				MC->C = (MC->A > IMM);
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case MUL:
			{
				ltemp = (unsigned int) REG;
				ltemp*= (unsigned int) MC->A;
				setflags(ltemp,MC);
				REG = ltemp/65536;
				MC->A = ltemp%65536;
				MC->IP++;
			} break;
			case IMUL:
			{
				ltemp = REG;
				ltemp*= MC->A;
				setflags(ltemp,MC);
				REG = ltemp/65536;
				MC->A = ltemp%65536;
				MC->IP++;
			} break;
			case DIV:
			{
				MC->A = (unsigned int) REG/ (unsigned int) MC->A;
				setflags(MC->A,MC);
				MC->IP++;
			} break;
			case IDIV:
			{
				MC->A = REG/MC->A;
				setflags(MC->A,MC);
				MC->IP++;
			} break;
			case REM:
			{
				MC->A = (unsigned int) REG% (unsigned int) MC->A;
				setflags(MC->A,MC);
				MC->IP++;
			} break;
			case IREM:
			{
				MC->A = REG%MC->A;
				setflags(MC->A,MC);
				MC->IP++;
			} break;
			case ANR:
			{
				MC->A = MC->A & REG;
				setflags(MC->A,MC);
				MC->IP++;
			} break;
			case AND:
			{
				MC->A = MC->A & MEM;
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case ANM:
			{
				put(IMM, MC->A & MEM);
				setflags(IMM,MC);
				MC->IP+=2;
			} break;
			case ANI:
			{
				MC->A = MC->A & IMM;
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case ORR:
			{
				MC->A = MC->A | REG;
				setflags(MC->A,MC);
				MC->IP++;
			} break;
			case OR:
			{
				MC->A = MC->A | MEM;
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case ORM:
			{
				put(IMM, MC->A | MEM);
				setflags(IMM,MC);
				MC->IP+=2;
			} break;
			case ORI:
			{
				MC->A = MC->A | IMM;
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case XORR:
			{
				MC->A = MC->A ^ REG;
				setflags(MC->A,MC);
				MC->IP++;
			} break;
			case XOR:
			{
				MC->A = MC->A ^ MEM;
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case XORM:
			{
				put(IMM, MC->A ^ MEM);
				setflags(IMM,MC);
				MC->IP+=2;
			} break;
			case XORI:
			{
				MC->A = MC->A ^ IMM;
				setflags(MC->A,MC);
				MC->IP+=2;
			} break;
			case NOT:
			{
				MC->A = ~MC->A;
				setflags(MC->A,MC);
			} break;
			case SHR:
			{
				MC->A = MC->A >> IMM8;
				setflags(MC->A,MC);
				MC->IP++;
			} break;
			case SHL:
			{
				MC->A = MC->A << IMM8;
				setflags(MC->A,MC);
				MC->IP++;
			} break;
			case ROR:
			{
				ltemp = MC->A << (16 - IMM8%16);
				MC->A = ltemp/65536 + ltemp%65536;
				setflags(MC->A,MC);
				MC->IP++;
			} break;
			case ROL:
			{
				ltemp = MC->A << IMM8%16;
				MC->A = ltemp/65536 + ltemp%65536;
				setflags(MC->A,MC);
				MC->IP++;
			} break;
			case CLC:
			{
				MC->C = false;
			} break;
			case CLP:
			{
				MC->P = false;
			} break;
			case CLZ:
			{
				MC->Z = false;
			} break;
			case STC:
			{
				MC->C = true;
			} break;
			case STP:
			{
				MC->P = true;
			} break;
			case STZ:
			{
				MC->Z = true;
			} break;
			case CMPR:
			{
				temp = MC->A - REG;
				MC->C = (temp > REG);
				setflags(temp,MC);
				MC->IP++;
			} break;
			case CMP:
			{
				temp = MC->A - MEM;
				MC->C = (temp > MEM);
				setflags(temp,MC);
				MC->IP+=2;
			} break;
			case CMPX:
			{
				temp = MC->A - fetch(OFF+MC->X);
				MC->C = (temp > fetch(OFF+MC->X));
				setflags(temp,MC);
				MC->IP+=2;
			} break;
			case CMPI:
			{
				temp = MC->A - IMM;
				MC->C = (temp > IMM);
				setflags(temp,MC);
				MC->IP+=2;
			} break;
			case JMP:
			{
				MC->IP = IMM-1;
			} break;
			case CALL:
			{
				MC->SP-=2;
				put(mem[MC->SP],MC->IP+2);
				MC->IP=fetch(MC->IP+1)-1;
			}
			case RET:
			{
				MC->IP = fetch(mem[MC->SP])-1;
				MC->SP+=2;
			}
			case JE:
			{
				if (MC->Z) MC->IP = IMM-1;
				else MC->IP+=2;
			} break;
			case JNE:
			{
				if (!MC->Z) MC->IP = IMM-1;
				else MC->IP+=2;
			} break;
			case JA:
			{
				if (MC->P) MC->IP = IMM-1;
				else MC->IP+=2;
			} break;
			case JNA:
			{
				if (!MC->P) MC->IP = IMM-1;
				else MC->IP+=2;
			} break;
			case JB:
			{
				if ((!MC->P) && (!MC->Z)) MC->IP = IMM-1;
				else MC->IP+=2;
			} break;
			case JNB:
			{
				if (MC->P || MC->Z) MC->IP = IMM-1;
				else MC->IP+=2;
			} break;
			case JC:
			{
				if (MC->C) MC->IP = IMM-1;
				else MC->IP+=2;
			} break;
			case JNC:
			{
				if (!MC->C) MC->IP = IMM-1;
				else MC->IP+=2;
			} break;
//			case IN:
//			{
//
//			} break;
//			case OUT:
//			{
//
//			} break;
			case INB:
			{

			} break;
			case OUTB:
			{

			} break;
			case NOP:
			{

			} break;
		}

		MC->IP++;
	}

	return;
}
