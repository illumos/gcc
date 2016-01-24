/* { dg-do run { target { { i?86-*-solaris2.* } && lp64 } } } */
/* { dg-options "-msave-args -save-temps " } */

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

/* { dg-final { scan-assembler "pushq\t%rdi" } } */
/* { dg-final { scan-assembler "pushq\t%rsi" } } */
/* { dg-final { scan-assembler "pushq\t%rdx" } } */
/* { dg-final { scan-assembler "pushq\t%rcx" } } */
/* { dg-final { scan-assembler "pushq\t%r8" } } */
/* { dg-final { cleanup-saved-temps } } */
