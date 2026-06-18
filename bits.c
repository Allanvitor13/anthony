#include <stdio.h>
#include <string.h>

void imprimirBinario(unsigned char n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

int main() {
    char bits[9];
    unsigned char num = 0;

    printf("Digite um numero binario (ate 8 bits): ");
    scanf("%8s", bits);

    // Converter string binária para número
    for (int i = 0; i < strlen(bits); i++) {
        if (bits[i] == '0' || bits[i] == '1') {
            num = num * 2 + (bits[i] - '0');
        } else {
            printf("Erro! Digite apenas 0 e 1.\n");
            return 1;
        }
    }

    printf("\nValor digitado: ");
    imprimirBinario(num);

    printf("\n\n=== OPERACOES BIT A BIT ===\n");

    printf("AND (11110000): ");
    imprimirBinario(num & 0b11110000);

    printf("\nOR  (00001111): ");
    imprimirBinario(num | 0b00001111);

    printf("\nXOR (11111111): ");
    imprimirBinario(num ^ 0b11111111);

    printf("\n\n=== SHIFTS ===\n");

    printf("Shift Logico Esquerda: ");
    imprimirBinario((unsigned char)(num << 1));

    printf("\nShift Logico Direita: ");
    imprimirBinario((unsigned char)(num >> 1));

    printf("\nShift Aritmetico: ");
    imprimirBinario((signed char)num >> 1);

    printf("\nShift Circular: ");
    imprimirBinario((num << 1) | (num >> 7));

    printf("\n\n=== REPRESENTACOES ===\n");

    printf("UInt: %u\n", num);
    printf("SM: %s\n", (num & 128) ? "Negativo" : "Positivo");
    printf("float: %.2f\n", (float)num);
    printf("2C: %d\n", (signed char)num);

    return 0;
}