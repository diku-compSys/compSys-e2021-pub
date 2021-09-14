#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// prints offset as a hex filling 8 characters padded with zeros.
void printOffset(unsigned int offset) {
    fprintf(stdout, "%08x  ", offset);
}

// prints amount bytes formatted as hex from bytes[].
void printBytesHex(char bytes[16], size_t amount) {
    char output[100] = "";
    for (size_t i = 0; i < amount; i++) {
        char tmp[100] = "";
        if ((i+1) % 8 == 0) {
            // the 8'th and 9'th byte should be seperated by two spaces
            sprintf(tmp, "%02x  ", bytes[i]);
            // strcat(src, dest) appends tmp to output.
            strcat(output, tmp);
        } else {
            sprintf(tmp, "%02x ", bytes[i]);
            strcat(output, tmp);
        }
    }
    // prints it out left-aligned expanding over 50 characters.
    fprintf(stdout, "%-50s", output);
}

// prints bytes from bytes[] as characters.
void printBytes(char bytes[16], size_t amount) {
    fprintf(stdout, "|");
    for (size_t i = 0; i < amount; i++) {
        if (bytes[i] == '\n') {
            // Hexdump(1) uses '.' instead of '\n'
            fprintf(stdout, ".");
        } else {
            fprintf(stdout, "%c", bytes[i]);
        }
    }
    fprintf(stdout, "|\n");
}

// Reads up till 16 bytes of input from fp.
size_t readLine(char out[16], FILE *fp) {
    size_t res = 0;
    size_t i = 0;
    size_t tmp;
    // stop if either 16 bytes have been read, or EOF has been reached.
    while (res < 16 && (tmp = fread(&out[i], sizeof(char), 1, fp)) == 1) {
        res += tmp;
        i++;
    }
    return res;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: hexdump <path>\n");
        return EXIT_FAILURE;
    }
    FILE *f = fopen(argv[1], "r");
    if (f != NULL) {
        unsigned int offset = 0;
        while (1) {
            char bytes[16];

            size_t bytes_read = readLine(bytes, f);
            printOffset(offset);
            printBytesHex(bytes, bytes_read);
            printBytes(bytes, bytes_read);

            offset+= bytes_read;

            if (bytes_read < 16) {
                // on short read, EOF has been reached.
                printOffset(offset);
                fprintf(stdout, "\n");
                break;
            }
        }
        fclose(f);
    }
    return EXIT_SUCCESS;
}