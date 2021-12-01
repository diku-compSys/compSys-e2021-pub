# Opgaver til 1/12-2021

## Opgave 1

Betragt indkodningen af de instruktioner der er præsenteret til dagens
forelæsning. Hvilke bits i en instruktion skal indgå i bestemmelse af
instruktionens størrelse?

## Opgave 2

Betragt indkodningen af de forskellige former for 'leaq' instruktioner.
Hvilken systematik kan du få øje på?

## Opgave 3

Betragt de aritmetiske instruktioner (dem indkodet med 'aaaa' i Prime)
og hold dem op imod datavejen. Hvilke af de 10 instruktioner bruger ALUen?
Opstil et logisk udtryk [*] der som input har de fire bit i 'aaaa' og som
output har et enkelt signal der bliver sandt, netop når indkodningen
svarer til en instruktion som skal bruge ALUen.

[*] Her menes et udtryk i 'C' som udelukkende bruger boolske operatorer
og arbejder på boolske værdier. Så givet fire boolske variable a0,a1,a2 og a3
svarende til de fire bit, skal du lave et udtryk i C som giver sandt eller
falsk, alt efter om ALUen skal bruges.

Det kan nogen gange hjælpe at opstille en sandhedstabel for problemet først.
En sandhedstabel for fire variable har 16 rækker indeholdende alle kombinationer
af de fire variable. For hver kombination angives tillige output.

## Opgave 4

Midt i datavejen, mellem register-banken og regne-enhederne, sidder en
Mux som vælger om den ene operand til regne-enhederne skal komme fra
register-banken eller fra instruktionen (en indlejret konstant).

Hvilke bits i instruktionen afgør hvordan denne mux skal indstilles?

Opstil et logisk udtryk, der som input har de relevant bits, og som
output et styresignal der er lavt, hvis Mux'en skal vælge input fra
register-banken og højt, hvis den skal vælge input fra instruktionen

## Opgave 5

Omskriv følgende 'C' fragment til 'Prime' symbolsk assembler
{
  long a = 10;
  long b = 24;
  long c = (a << 2) & b;
}

## Opgave 6

Følgende C fragment kan ikke oversættes til Prime, ihvertfald
ikke den delmængde der er præsenteret indtil videre:

{
  printf("En simpel streng\n");
}

Hvorfor ikke?

## Opgave 7

Omskriv følgende 'C' fragment til 'Prime' symbolsk assembler
men brug LEAQ instruktionen til at implementere den sidste linie

{
  long a = 10;
  long b = 24;
  long c = (a * 4) + b + 16384;
}
