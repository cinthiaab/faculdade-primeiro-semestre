/* Grupo 3
Cinthia Alves Barreto
Igor Matos Gaeta
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Declara��o de constantes
#define Andar 20
#define Apart 14

typedef struct endereco{
    char rua[50];
    char cidade[30];
    int num;
    char compl[20];
    char CEP[9];
}tipoEndereco;

typedef struct hospede{
    char nome[70];
    tipoEndereco endereco;
    char cpf[13];
    int idade;
    char email[40];
}hosp;

//Prot�tipos das fun��es chamadas dentro da fun��o main
void MapaInicializacao(char hotel[Andar][Apart]);
void Menu();
void checkInHospede(char hotel[Andar][Apart]);
void checkOutHospede(char hotel[Andar][Apart]);
void reservaApart(char hotel[Andar][Apart]);
void cancelaReserva(char hotel[Andar][Apart]);
void mapaHotel(char hotel[Andar][Apart]);
void taxaOcupacao(char hotel[Andar][Apart]);
void infoHospede(char hotel[Andar][Apart]);
int validarCPF(char cpf[13]);
void fclear();

int main(){
    //Declara��o das varaveis locais da fun��o main
    int opcao;
    char hotel[Andar][Apart];

    setlocale(LC_ALL, "Portuguese");//Utiliza��o da acentua��o da L�ngua Portuguesa

    MapaInicializacao(hotel);//chamada da fun��o que inicializa a matriz do do hotel

    do{
        Menu();//chamada da fun��o que imprime na tela as op��es que podem ser utilizadas
        scanf("%d", &opcao);//Leitura da op��o escolhida
        printf("\n");
        switch(opcao){
            case 1: checkInHospede(hotel);//Op��o 1: chamada da fun��o que realiza o Check-in do hospede
            break;
            case 2: checkOutHospede(hotel);//Op��o 2: chamada da fun��o que realiza o Check-out do hospede
            break;
            case 3: reservaApart(hotel);//Op��o 3: chamada da fun��o que realiza a reserva de apartamento
            break;
            case 4: cancelaReserva(hotel);//Op��o 4: chamada da fun��o que realiza o cancelamento da reserva
            break;
            case 5: mapaHotel(hotel);//Op��o 5: chamada da fun��o que imprime na tela o mapa de ocupa��es e reservas do hotel
            break;
            case 6: infoHospede(hotel); //Op��o 6: chamada da fun��o que permite adicionar informa��es do h�spede
            break;
            case 7: taxaOcupacao(hotel);//Op��o 7: chamada da fun��o que mostra a taxa de ocupa��o do hotel
            break;
            case 8: //Op��o 8: fim do programa
            break;
            default: printf("Aten��o! Essa op��o � inv�lida.\n");//Caso a op��o escolhida n�o estiver no switch case, essa mensagem ser� impressa.
            }
    }while(opcao!=8);//A op��o 8 � a sentinela, quando ela � escolhida termina o programa

    return(0);
}
void MapaInicializacao(char hotel[Andar][Apart]){
    int i, j; //vari�veis locais utilizadas para indicar as linha e as coluna da matriz

    //Inicializa��o da matriz que representa o status de cada apartamento
    for(i=Andar-1; i>=0; i--){
        for(j=0; j<Apart; j++){
            hotel[i][j]='.';//Todos os apartamentos est�o desocupados
        }
    }
}
void Menu(){
    printf("\t\n------------------ MENU DO HOTEL ------------------\n\n");
    printf("\t(1) - Check-in de h�spede\n");
    printf("\t(2) - Check-out de h�spede\n");
    printf("\t(3) - Reserva de apartamento\n");
    printf("\t(4) - Cancelar reserva\n");
    printf("\t(5) - Mapa de ocupa��o e reservas do hotel\n");
    printf("\t(6) - Informacoes do hospede\n");
    printf("\t(7) - Taxa de ocupa��o e reservas do hotel\n");
    printf("\t(8) - Sair do menu\n");
    printf("\nEscolha uma das op��es do Menu acima: ");
}
void checkInHospede(char hotel[Andar][Apart]){
    int x, y, k;
    // x � a vari�vel do andar, y � a vari�vel do apartamento e k � a sentinela utilizada no comando do-while

    printf("\n----------------CHECK-IN DE H�SPEDE----------------\n\n");

    do{
    printf("Insira o andar: ");
    scanf("%d", &x);
    printf("Insira o apartamento: ");
    scanf("%d", &y);

    //Subtrai-se 1 das variaveis x e y, devido a forma da matriz, iniciada sempre no 0
    x=x-1;
    y=y-1;

    if(hotel[x][y] == 'R'){//Verifica��o do status do apartamento: se o apartamento n�o estiver Ocupado, o if ser� feito, caso contrario, o else ser� feito
        printf("\nCheck-in realizado com sucesso.");
        hotel[x][y]= 'O';//Mudan�a do status do apartamento de Reservado para Ocupado
        k=2;
        } else if(hotel[x][y] == 'O'){ // N�o permite fazer check-in em apartamento ocupado
        printf("\nEste apartamento j� est� ocupado. \n\n");
        printf("\t(1) - Escolher outro apartamento.\n");
        printf("\t(2) - Voltar ao Menu.\n");
        printf("\nEscolha uma das op��es acima: ");
        scanf("%d", &k);
        } else if(hotel[x][y] == '.'){ // N�o permite faer check-in se o apartamento n�o estiver reservado
        printf("\nEste apartamento n�o est� reservado. \n\n");
        printf("\t(1) - Escolher outro apartamento.\n");
        printf("\t(2) - Voltar ao Menu.\n");
        printf("\nEscolha uma das op��es acima: ");
        scanf("%d", &k);
        }
    }while(k==1);//quando k for diferente de 1, essa fun��o terminar�
    printf("\n");
}
void checkOutHospede(char hotel[Andar][Apart]){
    int x, y;// x � a vari�vel do andar, y � a vari�vel do apartamento
    printf("\n----------------CHECK-OUT DE H�SPEDE----------------\n\n");

    printf("Insira o andar: ");
    scanf("%d", &x);
    printf("Insira o apartamento: ");
    scanf("%d", &y);

    //Subtrai-se 1 das variaveis x e y, devido a forma da matriz, iniciada sempre no 0
    x=x-1;
    y=y-1;

    if(hotel[x][y] == 'O'){
        printf("\nCheck-out realizado com sucesso.\n");
        hotel[x][y]= '.';

        }else{
            printf("\nEste apartamento n�o est� ocupado. \n");
        }

}
void reservaApart(char hotel[Andar][Apart]){
    int x, y, k;
    // x � a vari�vel do andar, y � a vari�vel do apartamento e k � a sentinela utilizada no comando do-while

    printf("\n---------------RESERVA DE APARTAMENTO---------------\n\n");

    do{
    printf("Insira o andar: ");
    scanf("%d", &x);
    printf("Insira o apartamento: ");
    scanf("%d", &y);

    //Subtrai-se 1 das variaveis x e y, devido a forma da matriz, iniciada sempre no 0
    x=x-1;
    y=y-1;

    if(hotel[x][y] == '.'){//Verifica��o do status do apartamento: se o apartamento estiver Desocupado, o if ser� feito, caso contrario, o else ser� feito
        printf("\nReserva realizada com sucesso.\n");
        hotel[x][y]= 'R';//Mudan�a do status do apartamento de Desocupado para Reservado
        k=2;
        }else{
            printf("\nEste apartamento n�o pode ser reservado. \n\n");
            printf("\t(1) - Escolher outro apartamento.\n");
            printf("\t(2) - Voltar ao Menu.\n");
            printf("\nEscolha uma das op��es acima: ");
            scanf("%d", &k);
        }
    }while(k==1);//quando k for diferente de 1, essa fun��o terminar�
}
void cancelaReserva(char hotel[Andar][Apart]){
    int x, y;
    // x � a vari�vel do andar, y � a vari�vel do apartamento

    printf("\n----------------CANCELAR UMA RESERVA----------------\n\n");


    printf("Insira o andar: ");
    scanf("%d", &x);
    printf("Insira o apartamento: ");
    scanf("%d", &y);

    //Subtrai-se 1 das variaveis x e y, devido a forma da matriz, iniciada sempre no 0
    x=x-1;
    y=y-1;

    if(hotel[x][y] == 'R'){//Verifica��o do status do apartamento: se o apartamento estiver Reservado, o if ser� feito, caso contrario, o else ser� feito
        printf("\nReserva cancelada com sucesso.\n");
        hotel[x][y]= '.';//Mudan�a do status do apartamento de Reservado para Desocupado
        }else{
            printf("\nEste apartamento n�o possui reserva. \n");
        }
}
void mapaHotel(char hotel[Andar][Apart]){
    int i, j; // i � a vari�vel do andar e j � a vari�vel do apartamento, ambas utilizadas no comando for

    printf("\n------------------MAPA DE OCUPA��O E RESERVAS DO HOTEL------------------\n\n");
    printf("\nApto ->  \t");
    for(j=1; j<=Apart; j++){
        printf(" %2d ", j);
    }
    printf("\n");

    for(i=Andar-1; i>=0; i--){
        printf("\nAndar %2d\t", i+1);
        for(j=0; j<Apart; j++){
                printf(" %2c ", hotel[i][j]);
        }
    }
        printf("\n");
}
void infoHospede(char hotel[Andar][Apart]){
    int k, x, y, o, p;
    hosp h[Andar][Apart];
    char cpf[13];

    printf("\n---------------INFORMA��ES DO H�SPEDE--------------\n\n");
    do{
        printf("\n\t(1) - Inserir informa��es.\n");
        printf("\t(2) - Verificar informa��es.\n");
        printf("\t(3) - Limpar dados.\n");
        printf("\t(4) - Voltar para o menu.\n");
        printf("\nEscolha uma das op��es acima: ");
        scanf("%d", &k);
        printf("\n");
        switch(k){ // inserir info (case 1), verificar info(case 2), limpar dados(case 3)
            case 1:     do{
                        printf("\tInsira o andar: ");
                        scanf("%d", &x);
                        printf("\tInsira o apartamento: ");
                        scanf("%d", &y);
                        x = x-1;
                        y = y-1;

                        if (hotel[x][y]=='R' || hotel[x][y]=='O'){
                            fclear();
                            printf("\nInsira seu nome completo:");
                            gets(h[x][y].nome);

                            printf("Insira sua idade: ");
                            scanf("%d", &h[x][y].idade);
                            fclear();

                            do{
                            printf("Insira seu CPF XXXXXXXXX-XX: ");
                            gets(h[x][y].cpf);

                            o = validarCPF(h[x][y].cpf);
                            }while(o==2);

                            printf("Insira o nome da cidade: ");
                            gets(h[x][y].endereco.cidade);

                            printf("Insira o nome da rua: ");
                            gets(h[x][y].endereco.rua);

                            printf("Insira o numero da residencia (Apenas n�meros): ");
                            scanf("%d", &h[x][y].endereco.num);
                            fclear();

                            printf("Insira o complemento: ");
                            gets(h[x][y].endereco.compl);

                            printf("Insira o CEP: ");
                            gets(h[x][y].endereco.CEP);

                            printf("Insira seu e-mail: ");
                            gets(h[x][y].email);

                            printf("\n\tTodas as informa��es foram preenchidas com sucesso!");
                            p=2;
                        }else {
                            printf("\nEste apartamento n�o esta ocupado nem reservado. \n\n");
                            printf("\t(1) - Escolher outro apartamento.\n");
                            printf("\t(2) - Voltar ao Menu.\n");
                            printf("\nEscolha uma das op��es acima: ");
                            scanf("%d", &p);
                        }
                    }while(p!=2);
            break;
            case 2: printf("\tInsira o andar: ");
                    scanf("%d", &x);
                    printf("\tInsira o apartamento: ");
                    scanf("%d", &y);
                    x = x-1;
                    y = y-1;
                    printf("\n\t---------------> CADASTRO DO H�SPEDE <---------------\n");
                    printf("\n\tNome completo: %s", h[x][y].nome);
                    printf("\tIdade: %d anos", h[x][y].idade);
                    printf("\n\tCPF: %s", h[x][y].cpf);
                    printf("\tCidade: %s", h[x][y].endereco.cidade);
                    printf("\n\tEndere�o: %s, n�%d, %s", h[x][y].endereco.rua, h[x][y].endereco.num, h[x][y].endereco.compl);
                    printf("\n\tCEP: %s", h[x][y].endereco.CEP);
                    printf("\tE-mail: %s\n", h[x][y].email);
                    printf("\n\t----------------------------------------------------\n");

            break;
            case 3:
                        printf("\tInsira o andar: ");
                        scanf("%d", &x);
                        printf("\tInsira o apartamento: ");
                        scanf("%d", &y);

                        x = x-1;
                        y = y-1;
                        h[x][y].nome[0]='\0';
                        h[x][y].idade=0;
                        h[x][y].cpf[0]='\0';
                        h[x][y].endereco.cidade[0]='\0';
                        h[x][y].endereco.rua[0]='\0';
                        h[x][y].endereco.num=0;
                        h[x][y].endereco.compl[0]='\0';
                        h[x][y].endereco.CEP[0]='\0';
                        h[x][y].email[0]='\0';

                        printf("\n\tTodos os dados foram limpos!\n");
            break;
            default: printf("Aten��o! Essa op��o � inv�lida.\n");
        }
    }while(k!=4);

}
int validarCPF(char cpf[13]){
    int d[11];
    int k;
    int soma1=0, soma2=0,soma3;
    int resto1, resto2;
    int d9, d10;
    int o;

    for(k = 0; k < 11; k++){
    if(k < 9) d[k]=cpf[k]-48;
    else d[k]=cpf[k+1]-48;
    }
    for(k=0; k<9; k++){
    soma1 = soma1 + (10-k)*d[k];
    }
    resto1= soma1%11;
    if(resto1<2){
    d9=0;
    } else {
    d9=11-resto1;
    }
    for(k=0; k<9; k++){
    soma2 = soma2 + (11-k)*d[k];
    }
    soma3 = soma2+2*d9;
    resto2= soma3%11;
    if(resto2<2){
    d10=0;
    } else {
    d10=11-resto2;
    }
    if(d9==d[9] || d10==d[10]){
    printf("O seu CPF � v�lido.\n");
    o=1;
    } else{
    printf("O seu CPF � inv�lido.");
    o=2;
    }
    return (o);
}
void taxaOcupacao(char hotel[Andar][Apart]){
    int x=0, i, j; //x->contador , i-> andar e j-> apartamento
    float taxa; //taxa de ocupa��o do hotel

    for(i=0; i<20; i++){
        for(j=0; j<14; j++){
            if(hotel[i][j]=='O'){x++;}
        }
    }
    taxa=x/(20.0*14);
    printf("A taxa de ocupa��o do hotel � de %.2f porcento.", taxa);
}
void fclear(){
    char carac;
    while( (carac = fgetc(stdin))!= EOF && carac != '\n') {}
}
