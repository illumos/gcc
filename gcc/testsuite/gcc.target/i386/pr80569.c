/* PR target/80569 */
/* { dg-do assemble } */
/* { dg-options "-O2 -m16 -march=haswell" } */
/* { dg-skip-if "" { *-*-* } "-msave-args" "" } */

void load_kernel(void *setup_addr)
{
    unsigned int seg = (unsigned int)setup_addr >> 4;
    asm("movl %0, %%es" : : "r"(seg));
}
