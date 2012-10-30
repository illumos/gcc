/* Test -msave-args */
/* { dg-do compile { target { { i?86-*-solaris2.* } && lp64 } } } */
/* { dg-options "-msave-args" } */
/* { dg-final { scan-assembler "movq\t%rsi, -32\\(%rbp\\)" } } */
/* { dg-final { scan-assembler "movq\t%rsi, -16\\(%rbp\\)" } } */
/* { dg-final { scan-assembler "movq\t%rdi, -8\\(%rbp\\)" } } */

int
foo(int argc, char **argv)
{
    return (1);
}
