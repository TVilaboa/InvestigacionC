#include <stdio.h>
#include "emulate.h"

int main(void)
{
    machine * mymachine;

    getchar();

    mymachine = initialise();

    mem[0] = LDI;
    mem[1] = 128;
    mem[2] = 12;
    mem[3] = XCHR;
    mem[4] = 0;
    mem[5] = LDI;
    mem[6] = 0;
    mem[7] = 0xA0;
    mem[8] = LDX;
    mem[9] = XCHR;
    mem[10] = 1;
    mem[11] = LDI;
    mem[12] = 65;
    mem[13] = 131;
    mem[14] = STX;
    mem[15] = 0;
    mem[16] = 0;
    mem[17] = XCHR;
    mem[18] = 0;
    mem[19] = SBI;
    mem[20] = 1;
    mem[21] = 0;
    mem[22] = CMPI;
    mem[23] = 0;
    mem[24] = 0;
    mem[25] = JNA;
    mem[26] = 38;
    mem[27] = 0;
    mem[28] = XCHR;
    mem[29] = 0;
    mem[30] = XCHR;
    mem[31] = 1;
    mem[32] = ADI;
    mem[33] = 2;
    mem[34] = 0;
    mem[35] = JMP;
    mem[36] = 8;
    mem[37] = 0;
    mem[38] = HLT;

    emulate(0,mymachine);

    getchar();

    return 0;
}

