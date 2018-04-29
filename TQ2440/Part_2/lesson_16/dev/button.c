#define GPFCON (volatile unsigned long*)0x56000050


#define GPF0_MASK (3<<(0*2))
#define GPF1_MASK (3<<(1*2))
#define GPF2_MASK (3<<(2*2))
#define GPF4_MASK (3<<(4*2))

#define GPF0_INT (0x2<<(0*2))
#define GPF1_INT (0x2<<(1*2))
#define GPF2_INT (0x2<<(2*2))
#define GPF4_INT (0x2<<(4*2))

void button_init()
{
    *(GPFCON) &= ~ ((GPF0_MASK)|(GPF1_MASK)|(GPF2_MASK)|(GPF4_MASK));
    *(GPFCON) |= ((GPF0_INT)|(GPF1_INT)|(GPF2_INT)|(GPF4_INT));
}