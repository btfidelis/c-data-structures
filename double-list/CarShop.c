/**
* @author Bruno Fidelis
* @author Gerson Martins
*/

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
    struct Veiculos* ant;

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
* Mostra o valor total de carros cadastrados
*/
void total_veiculos(t_veiculos* inicio);

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
                total_veiculos(desc.inicio);
                break;
            case 5:
                sair = 1;
                break;
            default:
                printf("Opcao invalida");
                system("cls");
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
     t_veiculos * carro = inicio;
        if(carro==NULL){
            system("CLS");
            printf("************************************************\n");
            printf("*             Veiculos cadastrados             *\n");
            printf("************************************************\n");
            printf("************************************************\n");
            printf("*       Nao existem veiculos cadastrados       *\n");
            printf("************************************************\n");
            system("pause");
            system("cls");
        }else{
            system("CLS");
            printf("************************************************\n");
            printf("*             veiculos cadastrados             *\n");
            printf("************************************************\n");

                while(carro != NULL){

                    printf("************************************************\n");
                    printf("*   Codigo: %d\n", carro->codigo);
                    printf("*   Placa: %s\n", carro->placa);
                    printf("*   Marca: %s\n", carro->marca);
                    printf("*   Modelo: %s\n", carro->modelo);
                    printf("*   Ano: %d\n", carro->ano);
                    printf("*   Valor: R$ %.2f\n", carro->valor);
                    printf("************************************************\n");

                    carro = carro->prox;
                }
                system("PAUSE");
                system("cls");
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

void add_veiculo(desc_veiculos* desc, t_veiculos* newCar)
{
    dados_veiculo(newCar);

    if (buscar_veiculo(desc->inicio, newCar->placa)) {
        printf("\nEste veiculo ja esta cadastrado\n");
        return;
    }

    if(desc->inicio == NULL){
        desc->inicio = newCar;

        desc->veiculos++;
        return;

    }else{
        t_veiculos * car = desc->inicio;
        t_veiculos * aux;

        while(car != NULL){
            if(newCar->valor < car->valor){

                    aux = newCar;
                    aux->ant = car->ant;
                    aux->prox = car;
                    car->ant = aux;

                    desc->inicio = newCar;
                    desc->veiculos++;
                    break;
            }else{
                if(car->prox != NULL){

                    if(newCar->valor < car->prox->valor){
                        aux = newCar;
                        aux->ant = car;
                        aux->prox = car->prox;
                        car->prox = aux;
                        desc->veiculos++;
                        break;
                    }
                    }else{
                      if(car->prox == NULL){
                         newCar->ant = car;
                         car->prox = newCar;
                         desc->veiculos++;
                         break;
                     }
                   }
                }
             car = car->prox;
            }

            printf("Carro cadastrado!\n");
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
    carro->ant  = NULL;

    system("cls");
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
    t_veiculos* aux = NULL;

    if (carro == desc->inicio) {
        carro->ant = NULL;
        desc->inicio = carro->prox;

    } else if (carro->prox == NULL){
        carro->ant->prox = NULL;
    } else {
        carro->ant->prox = carro->prox;
        carro->prox->ant = carro->ant;
    }

    free(carro);
    desc->veiculos--;

    system("cls");
    printf("\nVeiculo removido");
}


void vender_veiculo(desc_veiculos* desc, char* placa)
{
    t_veiculos* carro = buscar_veiculo(desc->inicio, placa);
    t_veiculos* it = desc->inicio;

    if (carro) {
        desc->valor_vendidos += carro->valor;
        del_veiculo(desc, carro);
    } else {
        system("cls");
        printf("\nVeiculo nao encontrado");
    }
}

void mostra_menu(desc_veiculos d)
{
    printf("\t\t MENU\n\n");
    printf("1 - Cadastrar Veiculo (total cadastrados: %d)\n", d.veiculos);
    printf("2 - Listar Veiculos\n");
    printf("3 - Vender veiculo (total vendidos no dia: %.2f)\n", d.valor_vendidos);
    printf("4 - Mostrar valor total dos veiculos\n");
    printf("5 - Sair\n");
    printf("\nDigite uma opcao: ");
}

void total_veiculos(t_veiculos* inicio)
{
    t_veiculos* it = inicio;
    float total = 0;

    while(it) {
        total += it->valor;
        it = it->prox;
    }

    system("cls");
    printf("Valor total dos carros cadastrados: %.2f\n", total);
    system("pause");
    system("cls");
}





