#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>


int binario(int numero){

    int binario[100];
    int resultado = numero;

    int count = 0;
        
        printf("\nConversao do numero: '%d' para binario:\n\n", numero);

        while (resultado > 0) 
        {
            printf("%d / 2 = ",resultado);

            binario[count] = resultado % 2;
            resultado = resultado / 2;
            printf("%d resto = %d \n",resultado,binario[count]);

            count++;

        }          

        printf("\nBinario: ");

        for (int i = count - 1; i >= 0; i--) 
            {
                printf("%d", binario[i]);
            } 

            printf("\n");
}


int decimal(char entrada[101]) {

    int tamanho = strlen(entrada);
    int binario[tamanho - 1];
    int tabela[tamanho];
    int decimal = 0;

    printf("\nConversao do binario '%s' para decimal:\n\n", entrada);

    for (int i = 0; i < tamanho; i++) {
        binario[i] = entrada[i] - '0';
        tabela[i] = pow(2, tamanho - i - 1);
    }

    printf("=====Tabela=====\n");

    for (int i = 0; i < tamanho; i++) {

        printf("| %d ",tabela[i]);
        decimal = decimal + (binario[i] * tabela[i]);
    }

    printf("\n");

    for (int i = 0; i < tamanho; i++) {

        if(tabela[i] < 10){
           printf("| %d ",binario[i]);
        }
        else{
            printf("| %d  ",binario[i]);
        }
        
    }

    printf("\n\nDecimal: %d\n", decimal);
    return decimal;
}

int main() {

    int numero,tipo;
    char entrada[101];

    bool Continuar = true;

    while (Continuar) {
        printf(" Conversao de numeros\n");
        printf("Digite o codigo do tipo de operacao que deseja realizar:\n");
        printf("1 - Decimal para Binario\n");
        printf("2 - Binario para Decimal\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &tipo);

        if (tipo == 0) {
            printf("\nSaindo do programa...\n");
            Continuar = false;
            break;
        }

        system("cls");

        switch (tipo) {
            case 1:
                printf("Digite um numero decimal: ");
                scanf("%d", &numero);

                binario(numero);

                break;
            case 2:
                
                printf("Digite um numero binario: ");
                scanf("%100s", &entrada);

                decimal(entrada);
                break;
            default:
                printf("Erro! Escolha um codigo entre 0 e 2!\n");
                
                printf("Pressione ENTER para continuar...");
                getchar();
                getchar();
                system("cls");
                continue;
        }
            printf("\n");

            printf("Pressione ENTER para continuar...");
            getchar();
            getchar();
            system("cls");   
    }

    return 0;
}