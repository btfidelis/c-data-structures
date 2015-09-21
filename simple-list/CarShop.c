#include <stdio.h>
#include <stdlib.h>

typedef struct Veiculos {
    unsigned int codigo;
    char placa[10];
    char marca[50];
    char modelo[20];
    unsigned int ano;
    float valor;

    struct Veiculos* prox;

}t_veiculos;

typedef struct Descritor {
    t_veiculos* inicio;
    unsigned int veiculos;
    float valor_vendidos;
}desc_veiculos;


/**
* Retorna a posição de memoria de um novo veiculo
*/
t_veiculos* new_veiculo();

/**
* Lista os veiculos cadastrados
*/
void listar_veiculos(t_veiculos* inicio);

/**
* Retorna o endereço de memoria do veiculo com a placa
* igual
*/
t_veiculos* buscar_veiculo(t_veiculos* inicio, char* placa);

/**
* Adiciona um novo veiculo
*/
void add_veiculo(desc_veiculos* desc, t_veiculos* carro);

/**
* Solicita os dados para um novo veiculo
*/
void dados_veiculo(t_veiculos* carro);

/**
* Solicita os dados e remove o veiculo
*/
void del_veiculo(desc_veiculos* desc, t_veiculos* carro);

/**
* Vende um veiculo conforme a placa informada
*/
void vender_veiculo(desc_veiculos* desc, char* placa);

/**
* Mostra o menu do programa
*/
void mostra_menu(desc_veiculos d);

/**
* Itera até o final da lista
*/
void veiculos_end();

int main()
{
    desc_veiculos desc;
    desc.inicio = NULL;
    desc.veiculos = 0;
    int sair = 0;
    int opt;
    char procuraPlaca[100];

//    add_veiculo(&desc, new_veiculo());

    while(!sair) {
        mostra_menu(desc);

        scanf("%d", &opt);

        switch(opt) {
            case 1:
                add_veiculo(&desc, new_veiculo());
                break;
            case 2:
                listar_veiculos(desc.inicio);
                break;
            case 3:
                fflush(stdin);
                printf("\nInforme a placa do carro: ");
                gets(procuraPlaca);
                vender_veiculo(&desc, procuraPlaca);
                break;
            case 4:
                sair = 1;
                break;
            default:
                printf("Opcao invalida");
                break;
        }
    }

    return 0;
}

t_veiculos* new_veiculo()
{
    return (t_veiculos *) malloc(sizeof(t_veiculos));
}

void listar_veiculos(t_veiculos* inicio)
{
    t_veiculos* it = inicio;

    while (it) {
        printf("Codigo: %d \n", it->codigo);
        printf("Placa: %s \n", it->placa);
        printf("Marca: %s \n", it->marca);
        printf("Modelo: %s \n", it->modelo);
        printf("Ano: %d \n", it->ano);
        printf("Valor: R$ %.2f \n", it->valor);

        printf("\n\n---------------\n\n");

        it = it->prox;
    }
}

t_veiculos* buscar_veiculo(t_veiculos* inicio, char* placa)
{
    t_veiculos* it = inicio;

    while (it) {
        if (!strcmp(it->placa, placa)) {
            return it;
        }
        it = it->prox;
    }

    return NULL;
}

void add_veiculo(desc_veiculos* desc, t_veiculos* carro)
{
    if (carro) {
        dados_veiculo(carro);

        if (desc->inicio == NULL) {
            desc->inicio = carro;
        } else {
            t_veiculos* it = desc->inicio;

            veiculos_end(&it);

            it->prox = carro;
        }

        desc->veiculos++;
        system("cls");
        printf("\nVeiculo Adicionado");
    }
}

void dados_veiculo(t_veiculos* carro)
{
    printf("\nDigite o codigo do veiculo: ");
    scanf("%d", &carro->codigo);
    fflush(stdin);

    printf("\nDigite a placa do veiculo: ");
    gets(carro->placa);

    fflush(stdin);
    printf("\nDigite a marca do veiculo: ");
    gets(carro->marca);

    fflush(stdin);
    printf("\nDigite o modelo do veiculo: ");
    gets(carro->modelo);

    fflush(stdin);
    printf("\nDigite o ano do veiculo: ");
    scanf("%d", &carro->ano);

    fflush(stdin);
    printf("\nDigite o valor do veiculo: ");
    scanf("%f", &carro->valor);

    carro->prox = NULL;

    system("cls");
    printf("carro adicionado");
}


void veiculos_end(t_veiculos** it)
{
    while( (*it)->prox ) {
        *it = (*it)->prox;
    }
}

void del_veiculo(desc_veiculos* desc, t_veiculos* carro)
{
    t_veiculos* it = desc->inicio;

    if (carro == desc->inicio) {
        desc->inicio = carro->prox;
    } else {
        while (it->prox != carro) {
            it = it->prox;
        }

        it->prox = carro->prox;
    }

    free(carro);
    desc->veiculos--;

    printf("\n Veiculo removido");
}


void vender_veiculo(desc_veiculos* desc, char* placa)
{
    t_veiculos* carro = buscar_veiculo(desc->inicio, placa);
    t_veiculos* it = desc->inicio;

    if (carro) {
        desc->valor_vendidos += carro->valor;
        del_veiculo(desc, carro);
    } else {
        printf("\nVeiculo nao encontrado");
    }
}

void mostra_menu(desc_veiculos d)
{
    printf("\t\t MENU\n\n");
    printf("1 - Cadastrar Veiculo (total cadastrados: %d)\n", d.veiculos);
    printf("2 - Listar Veiculos\n");
    printf("3 - Vender veiculo (total vendidos no dia: %.2f)\n", d.valor_vendidos);
    printf("4 - Sair\n");
    printf("\nDigite uma opcao: ");
}







