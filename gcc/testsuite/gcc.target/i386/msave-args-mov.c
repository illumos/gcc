/* { dg-do run { target { { i?86-*-solaris2.* } && lp64 } } } */
/* { dg-options "-msave-args -mforce-save-regs-using-mov -save-temps" } */

#include <stdio.h>

void t(int, int, int, int, int) __attribute__ ((noinline));

int
main(int argc, char **argv)
{
	t(1, 2, 3, 4, 5);
	return (0);
}

void
t(int a, int b, int c, int d, int e)
{
	printf("%d %d %d %d %d", a, b, c, d, e);
}

/* { dg-final { scan-assembler "movq\t%rdi, -8\\(%rbp\\)" } } */
/* { dg-final { scan-assembler "movq\t%rsi, -16\\(%rbp\\)" } } */
/* { dg-final { scan-assembler "movq\t%rdx, -24\\(%rbp\\)" } } */
/* { dg-final { scan-assembler "movq\t%rcx, -32\\(%rbp\\)" } } */
/* { dg-final { scan-assembler "movq\t%r8, -40\\(%rbp\\)" } } */
/* { dg-final { cleanup-saved-temps } } */
