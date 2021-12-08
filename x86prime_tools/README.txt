Online-værktøjerne til x86prime anvendes på følgende måde:

0. Download x86prime_tools/ fra CompSys-depotet

1. Oversæt c-program til x86:
Kør 'python3 gcc-online.py -S -Og -fno-optimize-sibling-calls -fcf-protection=none [filnavn på .c-program]'
Dette generer en x86 assembler fil fra dit c-program, og giver den filendelsen .s

2. Oversæt x86 assembler til x86prime
Kør 'python3 primify.py [filnavn på .s-program]'
Dette generer en x86 prime fil fra x86 assembler-filen, og giver den filendelsen .prime

3. Konverter x86prime til hex-format
Kør 'python3 prasm.py [filnavn på .prime-program]'
Dette generer en fil med filendelsen .hex, som viser hvordan .prime-programmet er indkodet i hex

4. Kør simulation af .hex-program
Kør 'python3 prun.py [filnavn på .hex-program] [start-funktion]'
Start funktionen er eksempelvis (ikke nødvendigvis) main.
Brug -show for at se simulationen

Indsæt værktøjerne i PATH:
1. Kør `chmod u+x install.sh`
2. Kør 'install.sh' som admin
3. Koden kan nu køres fra terminalen fra hvor som helst(e.g. 'primify myfile.c')

Lav filerne eksekverbar:
1. Kør `chmod u+x *.py`
2. Koden kan nu køres som lokale programmer (e.g. './gcc-online.py myfile.c')