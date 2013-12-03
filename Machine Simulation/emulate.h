#include <stdbool.h>

unsigned char mem[65536];

typedef struct machine
{
	int A, X, IP, SP;
	int REGS[7];
	bool C, Z, P;
	bool running;
} machine;

enum opcodes
{
     // Data Movement
	LDA, //load accumulator from direct mem
	LAX, //load accumulator from X+offset
	LDI, //load immediate value into accumulator
	LDS, //load stack pointer from memory
	LSI, //load stack pointer with immediate
	STA, //store accumulator to mem
	STX, //store accumulator to X+offset
	LDX, //load segment register from accumulator
	XCHG, //exchange accumulator with memory
	XCHR, //exchange accumulator with register
	LDR, //load accumulator from register
	STR, //store accumulator in register
	PUSH, //push accumulator
	PUSHR, //push register
	POP, //pop accumulator
	POPR, //pop register

   //Arithmetic
	ADR, //add register to accumulator
	ARC, //add R to accumulator with carry
  	ADD, //add mem to accumulator
	ADC, //add mem to accumulator with carry
	ADX, //add X+off to accumulator
	AXC, //add X+off to accumulator with carry
	ADI, //add immediate to accumulator
	AIC, //add immediate plus carry to accumulator
	SUB, //sub mem from A
	SBB, //sub mem from A with borrow
	SBR, //sub reg from accumulator
	SRB, //sub reg from accumulator with borrow
             SBX, //sub X+off from accumulator
             SXB,  //sub X+off from accumulator with borrow
	SBI, //sub immediate from accumulator
	SIB, //sub immediate from accumulator with borrow
	MUL, //multiply register with accumulator and store in reg:accum
	IMUL, //perform signed multiply of reg and accum and store in reg: accum
	DIV, //divide reg by accum and store in accum
	REM, //rem after div reg by accum, store in accum
	IDIV, //signed divide reg by accum
	IREM, //signed remainder after div reg by accum

    // Logical
	ANR, //AND register with Accumulator
             AND, //AND mem with Accumulator
	ANM, //AND accum with memory
	ANI, //AND with immediate
	ORR,
	OR,
	ORM,
	ORI,
	XORR,
	XOR,
	XORM,
	XORI,
	NOT, //NOT accum

    //Shift and Rotate
	SHR,  //shift accumulator right by n bits
	SHL,
	ROR, //rotate accumulator right by n bits
	ROL,

    //Flags
	CLC, //clear carry flag
	CLP, //  "  "  sign flag
	CLZ, // " " zero flag
	STC, //set carry flag
	STP,
	STZ,

    //Control
	CMP, //compare accumulator with mem
	CMPR, //compare accumulator with reg
	CMPI, //compare accumulator with immediate
	CMPX, //compare accumulator with X + off
	JMP, //jump to location
	CALL, //call subroutine at location
	RET, //return from subroutine
	JE, //Jump on zero
	JNE, //Jump if not zero
	JA, //jmp if above
	JNA, //jmp if not above
             JB, //jump if below
             JNB, //jump if not below
             JC, //jump if carry
	JNC, //jump if no carry
    //In-Out
	//OUT, //out accum to port
//	IN, //input accum from port
	OUTB, //output lower byte of accumulator to port
	INB, //input byte from port

    //Other
	HLT, //Halt program execution
	NOP //Do nothing
};

extern machine* initialise(void);
extern void emulate(int, machine *);

