// Trabalho 1 - ICI - Nicole Arthur 

#include <stdio.h>
#include <string.h>
#define n 200
#define num 500
#define tam_nome 50

struct cadastro {
    char nome[n];
    int codigo;
    char informacoes[num];
    float preco;
    char lancamento[11];
    int unidades[5];
};

int main (){
    int opcoes, contador, op_visualizar, busca_codigo, op_editar, editar_codigo, op_excluir, excluir_codigo;
    int i, u, a, j, ano, ordem_decrescente[tam_nome], ano_vetor, p;
    int index;
    struct cadastro produto[n];
    char busca_nome[n], editar_nome[n], excluir_nome[n], prod[n][tam_nome], tn[tam_nome];
    
    i = 0;
    contador = 0;

    //Criando o menu de operacoes:

    do{
    
        printf("\nMENU DE OPERACOES \n");
        printf("1. Cadastrar novos produtos. \n");
        printf("2. Visualizar as informacoes de um produto cadastrado. \n");
        printf("3. Editar as informacoes de um produto cadastrado. \n");
        printf("4. Visualizar todos os produtos em ordem alfabetica. \n");
        printf("5. Visualizar os produtos, e as respectivas unidades vendidas, em ordem decrescente de vendas, para determinado ano. \n");
        printf("6. Excluir produto cadastrado. \n");
        printf("7. Sair. \n");
        
        printf("\nSelecione a opcao desejada. Digite 1, 2, 3, 4, 5, 6 ou 7 \nOpção: ");
        scanf("%d%*c", &opcoes);
        
        while (opcoes < 1 || opcoes > 7){
            printf("\nPara selecionar a opcao desejada, digite apenas numeros inteiros entre 1 e 7. \n");
            scanf("%d%*c", &opcoes);
        }
        
    //Cadastrar novos produtos:

        if (opcoes == 1) {
            
            printf("\n\n");
            printf("CADASTRANDO NOVOS PRODUTOS");
            
            printf("\nNome do produto: ");
            fgets(produto[i].nome, n, stdin);
            printf("Codigo do produto: ");
            scanf("%d%*c", & produto[i].codigo);
            printf("Informacoes adicionais: ");
            fgets(produto[i].informacoes, num, stdin);
            printf("Preco atual: R$");
            scanf("%f%*c", & produto[i].preco);
            printf("Data de lancamento no mercado (dia/mes/ano): ");
            fgets(produto[i].lancamento, 11, stdin);
            printf("Unidades comercializadas em: \n");
            printf("\t 2018: ");
            scanf("%d%*c", & produto[i].unidades[0]);
            printf("\t 2019: ");
            scanf("%d%*c", & produto[i].unidades[1]);
            printf("\t 2020: ");
            scanf("%d%*c", & produto[i].unidades[2]);
            printf("\t 2021: ");
            scanf("%d%*c", & produto[i].unidades[3]);
            printf("\t 2022: ");
            scanf("%d%*c", & produto[i].unidades[4]);
            
            contador += 1;
            i += 1;
            
            printf("\n");
            
            opcoes = 0;
        }
        
        //Visualizar as informações de um produto cadastrado:

        if (opcoes == 2) {
            
            index = 0;
            printf("\n");
            printf("VISUALIZANDO AS INFORMACOES DE UM PRODUTO CADASTRADO\n");
            printf("1. Buscar produto por nome. \n");
            printf("2. Buscar produto por codigo. \n");
            
            printf("\nSelecione a opcao desejada. Digite 1 ou 2. \nOpção: ");
            scanf("%d%*c", &op_visualizar);
            
            while (op_visualizar != 1 && op_visualizar != 2){
                printf("\nPara selecionar a opcao desejada, digite apenas 1 ou 2. \n");
                scanf("%d%*c", &op_visualizar);
            }
            
            printf("\n");
            
            if(op_visualizar == 1){
                printf("Nome do produto: ");
                fgets(busca_nome, n, stdin);
                
                printf("\n");
                
                for (u = 0; u < contador; u++){
                    if(strcmp(produto[u].nome, busca_nome) == 0){
                        printf("Nome do produto: %s", produto[u].nome);
                        printf("Codigo do produto: %d \n", produto[u].codigo);
                        printf("Informacoes adicionais: \n %s", produto[u].informacoes);
                        printf("Preco atual: R$%.2f \n", produto[u].preco);
                        printf("Data de lancamento no mercado (dia/mes/ano): %s \n", produto[u].lancamento);
                        printf("Unidades comercializadas em: \n");
                        printf("\t 2018: %d", produto[u].unidades[0]);
                        printf("\t 2019: %d", produto[u].unidades[1]);
                        printf("\t 2020: %d", produto[u].unidades[2]);
                        printf("\t 2021: %d", produto[u].unidades[3]);
                        printf("\t 2022: %d", produto[u].unidades[4]);
                    } else {
                        index += 1;
                    }
                }

                if (index == contador) {
                    printf("PRODUTO NÃO CADASTRADO!\n!");
                }
            }
            
            if(op_visualizar == 2){
                printf("Codigo do produto: ");
                scanf("%d%*c", & busca_codigo);
                
                for (u=0; u<contador; u++){
                    if((busca_codigo - produto[u].codigo) == 0){
                        printf("\nNome do produto: %s", produto[u].nome);
                        printf("Codigo do produto: %d \n", produto[u].codigo);
                        printf("Informacoes adicionais: \n %s", produto[u].informacoes);
                        printf("Preco atual: R$%.2f \n", produto[u].preco);
                        printf("Data de lancamento no mercado (dia/mes/ano): %s \n", produto[u].lancamento);
                        printf("Unidades comercializadas em: \n");
                        printf("\t 2018: %d", produto[u].unidades[0]);
                        printf("\t 2019: %d", produto[u].unidades[1]);
                        printf("\t 2020: %d", produto[u].unidades[2]);
                        printf("\t 2021: %d", produto[u].unidades[3]);
                        printf("\t 2022: %d \n", produto[u].unidades[4]);
                    } else {
                        index += 1;
                    }
                }
                if (index == contador) {
                    printf("PRODUTO NÃO CADASTRADO!\n!");
                }
            }        
            opcoes = 0;
            printf("\n");
        }
        
//Editar as informações de um produto cadastrado:

        if (opcoes==3){
            
            printf("\n");
            printf("EDITANDO AS INFORMACOES DE UM PRODUTO CADASTRADO\n");
            printf("1. Selecionar produto por nome. \n");
            printf("2. Selecionar produto por codigo. \n");
            
            printf("\nSelecione a opcao desejada. Digite 1 ou 2. \n");
            scanf("%d%*c", &op_editar);
            
            while (op_editar!=1 && op_editar!=2){
            printf("\nPara selecionar a opcao desejada, digite apenas 1 ou 2. \n");
            scanf("%d%*c", &op_editar);
            }
            
            printf("\n");
            
            if(op_editar==1){
                printf("Nome do produto: ");
                fgets(editar_nome, n, stdin);
                printf("\n");
                
                for (u=0; u<contador; u++){
                    if(strcmp(produto[u].nome, editar_nome) == 0){
                        printf("Entre com as informacoes atualizadas. \n");
                        
                        printf("Nome do produto: ");
                        fgets(produto[u].nome, n, stdin);
                        printf("Codigo do produto: ");
                        scanf("%d%*c", & produto[u].codigo);
                        printf("Informacoes adicionais: \n");
                        fgets(produto[u].informacoes, num, stdin);
                        printf("Preco atual: R$");
                        scanf("%f%*c", & produto[u].preco);
                        printf("Data de lancamento no mercado (dia/mes/ano): ");
                        fgets(produto[u].lancamento, 11, stdin);
                        printf("Unidades comercializadas em: \n");
                        printf("\t 2018: ");
                        scanf("%d%*c", & produto[u].unidades[0]);
                        printf("\t 2019: ");
                        scanf("%d%*c", & produto[u].unidades[1]);
                        printf("\t 2020: ");
                        scanf("%d%*c", & produto[u].unidades[2]);
                        printf("\t 2021: ");
                        scanf("%d%*c", & produto[u].unidades[3]);
                        printf("\t 2022: ");
                        scanf("%d%*c", & produto[u].unidades[4]);
                        
                        break;
                    } else {
                        index += 1;
                    }
                }
                if (index == contador) {
                    printf("PRODUTO NÃO CADASTRADO!\n!");
                }
            }
            
            if(op_editar==2){
                printf("Codigo do produto: ");
                scanf("%d%*c", & editar_codigo);
                printf("\n");
                
                for (u=0; u<contador; u++){
                    if((editar_codigo - produto[u].codigo) == 0){
                        printf("Entre com as informacoes atualizadas. \n");
                        
                        printf("Nome do produto: ");
                        fgets(produto[u].nome, n, stdin);
                        printf("Codigo do produto: ");
                        scanf("%d%*c", & produto[u].codigo);
                        printf("Informacoes adicionais: \n");
                        fgets(produto[u].informacoes, num, stdin);
                        printf("Preco atual: R$");
                        scanf("%f%*c", & produto[u].preco);
                        printf("Data de lancamento no mercado (dia/mes/ano): ");
                        fgets(produto[u].lancamento, 11, stdin);
                        printf("Unidades comercializadas em: \n");
                        printf("\t 2018: ");
                        scanf("%d%*c", & produto[u].unidades[0]);
                        printf("\t 2019: ");
                        scanf("%d%*c", & produto[u].unidades[1]);
                        printf("\t 2020: ");
                        scanf("%d%*c", & produto[u].unidades[2]);
                        printf("\t 2021: ");
                        scanf("%d%*c", & produto[u].unidades[3]);
                        printf("\t 2022: ");
                        scanf("%d%*c", & produto[u].unidades[4]);
                        
                        break;
                    } else {
                        index += 1;
                    }
                }
                if (index == contador) {
                    printf("PRODUTO NÃO CADASTRADO!\n!");
                }
            }
            
            opcoes = 0;
            printf("\n");
            
        }
        
//Visualizar todos os produtos em ordem alfabetica:
 
        if (opcoes==4){
            
            printf("\n");
            printf("VISUALIZANDO TODOS OS PRODUTOS EM ORDEM ALFABETICA\n");
            
            for(a=0; a<contador; a++){
                strcpy(prod[a], produto[a].nome);
            }
            
            for (u = 0; u < contador; u++) {
                for (j = u + 1; j < contador; j++) {
                    if (strcmp(prod[u], prod[j]) > 0) {
                        strcpy(tn, prod[u]);
                        strcpy(prod[u], prod[j]);
                        strcpy(prod[j], tn);
                    }
                }
            }
            
            printf("\nProdutos ordenados alfabeticamente:\n\n");
            
            for (u = 0; u < contador; u++) {
                printf("%s", prod[u]);
            }
            
            printf("\n");
        }
        
        //Visualizar os produtos, e as respectivas unidades vendidas, em ordem decrescente de vendas, para determinado ano:

        if (opcoes==5){
            
            printf("\n");
            printf("VISUALIZANDO OS PRODUTOS E UNIDADES VENDIDAS EM DETERMINADO ANO, EM ORDEM DECRESCENTE DE VENDAS\n\n");
            printf("Entre com o ano para o qual voce deseja visualizar as unidades vendidas. \n");
            scanf("%d%*c", & ano);
            
            while (ano<2018 || ano>2022){
            printf("\nInformacoes disponiveis apenas para os ultimos 5 anos. Escolha um ano de 2018 a 2022. \n");
            scanf("%d%*c", & ano);
            }
            
            if (ano==2018){
                ano_vetor = 0;
            }
            else if (ano==2019){
                ano_vetor=1;
            }
            else if (ano==2020){
                ano_vetor=2;
            }
            else if (ano==2021){
                ano_vetor=3;
            }
            else {
                ano_vetor=4;
            }
            
            for(a=0; a<contador; a++){
                ordem_decrescente[a] = produto[a].unidades[ano_vetor];
            }
            
            for (u = 0; u < contador; u++) {
                for (j = u + 1; j < contador; j++) {
                    if (ordem_decrescente[u] - ordem_decrescente[j]<0){
                        p = ordem_decrescente[u];
                        ordem_decrescente[u] = ordem_decrescente[j];
                        ordem_decrescente[j] = p;
                    }
                }
            }
            
            printf("\nOrdem decrescente de vendas para o ano de %d:\n\n", ano);
            printf("Unidades vendidas \tProduto\n");
            
            for (u = 0; u < contador; u++) {
                for (a = 0; a < contador; a++){
                    if(ordem_decrescente[u]==produto[a].unidades[ano_vetor]){
                            printf("\t%d\t\t%s", produto[a].unidades[ano_vetor], produto[a].nome);
                    }
                }
            }
            
            printf("\n");
            
        }
        
        //Excluir produto cadastrado:

        if (opcoes==6){
        
            printf("\n");
            printf("EXCLUINDO UM PRODUTO\n");
            
            printf("1. Selecionar produto por nome. \n");
            printf("2. Selecionar produto por codigo. \n");
            
            printf("\nSelecione a opcao desejada. Digite 1 ou 2. \n");
            scanf("%d%*c", &op_excluir);
            
            while (op_excluir!=1 && op_excluir!=2){
            printf("\nPara selecionar a opcao desejada, digite apenas 1 ou 2. \n");
            scanf("%d%*c", &op_excluir);
            }
            
            printf("\n");
            
              if(op_excluir==1){
                printf("Nome do produto: ");
                fgets(excluir_nome, n, stdin);
                printf("\n");
                
                for (u=0; u<contador; u++){
                    if(strcmp(produto[u].nome, excluir_nome) == 0) {
                        if(u < contador-1) {
                            for (a=u; a<contador; a++){
                            strcpy(produto[a].nome, produto[a+1].nome);
                            produto[a].codigo = produto[a+1].codigo;
                            strcpy(produto[a].informacoes, produto[a+1].informacoes);
                            produto[a].preco = produto[a+1].preco;
                            strcpy(produto[a].lancamento, produto[a+1].lancamento);
                            produto[a].unidades[0] = produto[a+1].unidades[0];
                            produto[a].unidades[1] = produto[a+1].unidades[1];
                            produto[a].unidades[2] = produto[a+1].unidades[2];
                            produto[a].unidades[3] = produto[a+1].unidades[3];
                            produto[a].unidades[4] = produto[a+1].unidades[4];
                            }
                        }
                        
                        contador = contador - 1;
                        i=i-1;
                        printf("Produto excluído.\n");
                        printf("\n");
                        
                    }  else {
                        index += 1;
                    }
                }
                if (index == contador) {
                    printf("PRODUTO NÃO CADASTRADO!\n");
                }
            }
            
            if(op_excluir==2){
                printf("Codigo do produto: ");
                scanf("%d%*c", & excluir_codigo);
                printf("\n");
                
                for (u=0; u<contador; u++){
                    if(excluir_codigo == produto[u].codigo){
                        if(u < contador-1){
                        
                            for (a=u; a<contador; a++){
                                strcpy(produto[a].nome, produto[a+1].nome);
                                produto[a].codigo = produto[a+1].codigo;
                                strcpy(produto[a].informacoes, produto[a+1].informacoes);
                                produto[a].preco = produto[a+1].preco;
                                strcpy(produto[a].lancamento, produto[a+1].lancamento);
                                produto[a].unidades[0] = produto[a+1].unidades[0];
                                produto[a].unidades[1] = produto[a+1].unidades[1];
                                produto[a].unidades[2] = produto[a+1].unidades[2];
                                produto[a].unidades[3] = produto[a+1].unidades[3];
                                produto[a].unidades[4] = produto[a+1].unidades[4];
                            }
                        }
                        contador = contador - 1;
                        i=i-1;
                        printf("Produto excluído.\n");
                        printf("\n");
                    } else {
                        index += 1;
                    }
                }
                if (index == contador) {
                    printf("PRODUTO NÃO CADASTRADO!\n");
                }
            }
        }
    } while(opcoes != 7);
    
    //Sair:
    
    printf("\nOperacao finalizada com sucesso. Sistema atualizado.\n");
    
    return 0;
}