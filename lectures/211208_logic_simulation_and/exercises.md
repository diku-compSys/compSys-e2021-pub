# Opgaver til 8/12-2021

Start med opgaver der ikke blev nået i mandags, dog ikke opgave 8 som i stedet gives igen nedenfor

## Opgave 1

Til forelæsningen indgik følgende program i prime assembler:

Start:
    leaq data,%rsi
    movq $0,%rax
    movq $0,%rbp
    leaq (%rsi, %rax, 8), %r11
    movq (%r11), %rdx
    addq $1, %rax
    addq %rdx,%rbp
    leaq (%rsi, %rax, 8), %r11
    movq (%r11), %rdx
    addq $1, %rax
    addq %rdx,%rbp
    stop

   .align 8
data:
   .quad 42
   .quad 21


Brug prasm til at indkode det i hex-format og prun til at simulere det.

## Opgave 2

Gennemgå figuren med datavejen/mikroarkitekturen givet i A5 og hold den op overfor indholdet i løkken i "main.c" fra A5. Hvilke dele af figuren er udeladt/ikke repræsenteret i "main.c" ?

## Opgave 3

Givet følgende erklæringer:

long* inA; long* inB; long* out; long size

Omskriv følgende 'C' fragment til 'Prime' symbolsk assembler

{
    long* limit = inA + size;
    while (inA < limit) {
          if (*inA < *inB) {
             *out = *inB;
          } else {
             *out = *inA;
          }
          ++inA;
          ++inB;
          ++out;
    }
}

## Opgave 4

Implementer Fibonacci funktionen (den rekursive udgave) i Prime assembler.


## Opgave 5 (Opgave 8 fra mandag)

Omskriv følgende 'C' funktion til 'Prime' symbolsk assembler

long copy(long* from, long* to, long size) {
  while (size > 0) {
    *to++ = *from++;
    --size;
  }
}

