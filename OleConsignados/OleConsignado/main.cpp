#define WINVER 0x0500
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>

using namespace std;

char *vetor[5000];
int x = GetSystemMetrics(SM_CXSCREEN);
int y = GetSystemMetrics(SM_CYSCREEN);
int y_form = 0;
int qnt = 1;

char tmp[100];//Temporario de comparação
char status[100];//temporario Status ara Final
bool baixa = true;

int carrega_contatos();
void move(int x, int y);
void click();
void dbclick();
void triclick();
void copiar();
void clickSegura();
void clickSolta();
void resgata();
void copia_informacoes();
int verificarTipoFormulario();
void finale();
void add_banco(string numero, string nome, string situacao, string endereco, string num, string uf, string bairro, string cidade, string cep, string cpf, string rg, string matricula, string civil, string produto, string orgao, string agente, string data, string bruto, string liberado, string parcela, string qnt);

char *info = 0;


int main(){

    printf("Resolução: %d x %d\n",x , y);

    //carrega_contatos();


    //inicio descartar apenas selecionar navegador
    move(415,1058);//posição Icone no WINDOWS 10
    click();
    //

    x = x/2;//Medias Monitor
    y = y/2;//Medias Monitor
    move(x,y);//Centralização de Monitor

    move(x,0);//topo

    /*Verificar se existe FUNÇÃO*/
    //y = 300+(22*10);//Posição fixa primeiro registro
    y = 300;//Posição fixa primeiro registro

    for (int z=0; z< 25; z++){

       if (y > 480){//chegou final da lista

            printf("Chegou final da lista...");

                move (1340, 495);//vai na barra de rolagem

                for(int c = 1; c <= qnt; c++){//quantidades de vezes que rolagem vai baixar
                    click();//baixa
                    Sleep(500);//aguarda
                }

            if (baixa){
                //move(640, 464);
                move(x-325,464);//posicionar registro
                baixa = false;
            }else{
                //move(640, 486);
                move(x-325,486);//posicionar registro
                baixa = true;
                qnt++;
            }
            click();//baixa

            Sleep(2000);//aguarda

            copia_informacoes();


          }else{//normal

               //SELECIONA NUMERO PROPOSTA
               //move(x-380,y);//primeiro registro + posição abaixo...
               //clickSegura();
               //move(x-300,y);//primeiro registro + posição abaixo...
               //clickSolta();
               //Sleep(1000);
               //copiar();
               //resgata();
               //SELECIONA NUMERO PROPOSTA

               if(info == "0"){
                   Sleep(60000);
                   printf("1 minuto para Atualização...");

                   move(x-20,565);//botão Atualizar
                   click();
                   Sleep(50);
                   click();
                   Sleep(4000);

               }else{

                    /*faz verificação se tem repetição*/
                      //  printf("%s",info);
                    /*faz verificação se tem repetição*/

                    //system("PAUSE");


                    move(x-325,y);//primeiro registro
                    click();
                    Sleep(1000);

                    copia_informacoes();
                    y = y+22;// Posição Y par aproximo registro da lista
                  }

                  finale();
                  info = 0;
           }

    }

    system("PAUSE");
    return(0);
}


void copia_informacoes(){

    //Divergencia de Y em relatorio --> Base no TOPO
    int divergencia = 25;//caso tenha divergencia no arquivoi pelo topo// senão deixr zero

    move(0,0);

    move(36,divergencia+137);
    dbclick();
    copiar();
    resgata();


     if (strcmp(info,"500 ")==0){
            printf("Error!....\n");
            system("PAUSE");
    }else{

        for (int c = 0; c<10; c++){
           if (strcmp(info,"BONSUCESSO ")==0){
                break;
            }else{
                Sleep(3000);
                printf("Provavel carregamento! aguardando....\n");
                move(36,divergencia+137);
                dbclick();
                copiar();
                resgata();
            }

        }


    }

    move(175,divergencia+200);//Numero da Proposta
    dbclick();
    copiar();
    resgata();
    //printf("Numero da Proposta --> %s\n",info);
    string numero = info;

    //nome
    click();
    move(74,divergencia+212);//inicio seleção nome
    clickSegura();
    move(246,divergencia+212);//final seleção nome
    clickSolta();
    copiar();
    resgata();
    //printf("Nome Cliente --> %s\n",info);
    string nome = info;


    /*Verificação para nome de cliente de conter (numero) apos o nomde do cliente o formulario sera mais alto*/
    //essa função verifica se o formulario houve alguma alteração devido ao tamanho do nome do cliente FULANO DE TAL (123123123) os parenteses com o numero pode estar na linha abaixo desconfigurando toda a pesquisa
    y_form = verificarTipoFormulario();//a veriavel info é global sera usada dentro desta função
    //printf("y --> %i\n",y_form);
    //nome

    //Situação
    move(545,divergencia+216);//Dituação não sofre mudanã de varificarTipoFormularo
    dbclick();
    copiar();
    resgata();
    strcpy(status, info);//Status para final
    //printf("Situação --> %s\n",info);
    string situacao = info;

    //Situação


    //Endereço
    move(57,divergencia+y_form+285);
    clickSegura();
    move(253,divergencia+y_form+285);
    clickSolta();
    copiar();
    resgata();
    string endereco = info;

    //printf("Endereço --> %s\n",info);

    //Endereço

    //Numero
    move(279,divergencia+y_form+290);
    dbclick();
    copiar();
    resgata();
    string num = info;

    //printf("Numero --> %s\n",info);
    //Numero


    //UF
    move(532,divergencia+y_form+290);
    dbclick();
    copiar();
    resgata();
    string uf = info;

    //printf("UF --> %s\n",info);
    //UF


    //Bairro
    //move(64,y_form+300);
    move(38,divergencia+y_form+300);
    clickSegura();
    move(240,divergencia+y_form+300);
    clickSolta();
    //dbclick();
    copiar();
    resgata();
    string bairro = info;

    //printf("Bairro --> %s\n",info);
    //Bairro

    //Cidade
    //move(300,y_form+300);
    move(293,divergencia+y_form+300);
    clickSegura();
    move(480,divergencia+y_form+300);
    clickSolta();
    //dbclick();
    copiar();
    resgata();
    string cidade = info;

    //printf("Cidade --> %s\n",info);
    //Cidade

    //Cep
    click();
    move(530,divergencia+y_form+300);//inicio seleção nome
    clickSegura();
    move(590,divergencia+y_form+300);//final seleção nome
    clickSolta();
    copiar();
    resgata();
    string cep = info;

    //printf("CEP --> %s\n",info);
    //Cep


    //CPF
    click();
    move(30,divergencia+y_form+310);//inicio seleção nome
    clickSegura();
    move(108,divergencia+y_form+310);//final seleção nome
    clickSolta();
    copiar();
    resgata();
    string cpf = info;

    //printf("CPF --> %s\n",info);
    //CPF


    //RG
    click();
    move(276,divergencia+y_form+310);//inicio seleção nome
    clickSegura();
    move(420,divergencia+y_form+310);//final seleção nome
    clickSolta();
    copiar();
    resgata();
    string rg = info;

    //printf("RG --> %s\n",info);
    //RG


    //Matricula
    move(586,divergencia+y_form+310);
    dbclick();
    copiar();
    resgata();
    string matricula = info;

    //printf("Matricula --> %s\n",info);
    //Matricula


    //estado civil
    click();
    move(80,divergencia+y_form+333);//inicio seleção estado civil
    clickSegura();
    move(155,divergencia+y_form+333);//final seleção estado civil
    clickSolta();
    copiar();
    resgata();
    string civil = info;

    //printf("estado civil --> %s\n",info);
    //RG


    //Produto
    move(50,divergencia+y_form+475);//inicio seleção produto
    clickSegura();
    move(245,divergencia+y_form+475);//final seleção produto
    clickSolta();
    copiar();
    resgata();
    string produto = info;

    //printf("Produto --> %s\n",info);
    //Produto


    //Produto
    move(317,divergencia+y_form+505);//inicio seleção Orgao
    dbclick();
    //clickSegura();
    //move(500,divergencia+y_form+505);//final seleção Orgao
    //clickSolta();
    copiar();
    resgata();
    string orgao = info;

    printf("ORGAO --> %s\n",orgao.c_str());
    //Produto


    //Agente
    move(560,divergencia+y_form+490);//inicio seleção agente
    clickSegura();
    move(730,divergencia+y_form+490);//final seleção agente
    clickSolta();
    copiar();
    resgata();
    string agente = info;

    //printf("Agente --> %s\n",info);
    //Agente


    //Data
    move(63,divergencia+y_form+565);//inicio seleção data
    clickSegura();
    move(150,divergencia+y_form+565);//final seleção data
    clickSolta();
    copiar();
    resgata();
    string data = info;

    //printf("Data Base --> %s\n",info);
    //Data


    //Valor Bruto
    move(300,divergencia+y_form+575);//inicio seleção valor bruto
    clickSegura();
    move(460,divergencia+y_form+575);//final seleção valor bruto
    clickSolta();
    copiar();
    resgata();
    string bruto = info;

    //printf("Valor Bruto --> %s\n",info);
    //Valor Bruto


    //Valor liberado
    move(73,divergencia+y_form+575);//inicio seleção valor liberado
    clickSegura();
    move(200,divergencia+y_form+575);//final seleção valor liberado
    clickSolta();
    copiar();
    resgata();
    string liberado = info;

    //printf("Valor Liberado --> %s\n",info);
    //Valor liberado


    //Valor Parcela
    move(310,divergencia+y_form+585);//inicio seleção parcela
    clickSegura();
    move(410,divergencia+y_form+585);//final seleção parcela
    clickSolta();
    copiar();
    resgata();
    string parcela = info;

    //printf("Valor Parcela --> %s\n",info);
    //Valor Parcela


    //Qnt Parcela
    move(315,divergencia+y_form+595);//inicio seleção quantidade de parcela
    clickSegura();
    move(410,divergencia+y_form+595);//final seleção quantidade de parcela
    clickSolta();
    copiar();
    resgata();
    string qnt = info;

    //printf("Qnt Parcela --> %s\n",info);
    //Qnt Parcela


    add_banco(numero, nome, situacao, endereco, num, uf, bairro, cidade, cep, cpf, rg, matricula, civil, produto, orgao, agente, data, bruto, liberado, parcela, qnt);


    finale();

}


void add_banco(string numero, string nome, string situacao, string endereco, string num, string uf, string bairro, string cidade, string cep, string cpf, string rg, string matricula, string civil, string produto, string orgao, string agente, string data, string bruto, string liberado, string parcela, string qnt){

    MYSQL conexao;

    mysql_init(&conexao);
    if ( mysql_real_connect(&conexao, "localhost", "root", "", "grupolhasa_sistema", 0, NULL, 0) ){
       cout << "\nConexao ao banco realizada com sucesso!\n" << endl;
    }
    else{
        cout << "Falha de conexao\n" << endl;
        cout << mysql_errno(&conexao) << endl;
        cout << mysql_error(&conexao) << endl;
    }

    int ret;
    string sql = "INSERT INTO cad_proposta ( nome_cliente, cad_orgao_id, cad_financeira_id, aux_tipo_coeficiente_id, aux_status_conferencia_id, numero_proposta, sis_usuario_id, cad_controle_carga_id, aux_situacao_banco_id, cad_representante_id, aux_status_comissao_id, valor_liberado, valor_recompra, valor_parcela, plano, valor_financiado, dt_envio) VALUES ('";
    //strcat(sql, nome);
    sql = sql + nome + "',";
    sql = sql + orgao.c_str() +", 17, 1, 4, ";
    sql = sql + numero.c_str() +",1,666,";
    //154

    if (strcmp (situacao.c_str(), "APROVADA") == 0){
        situacao = "203";
    }

    if (strcmp (situacao.c_str(), "LIBERADA") == 0){
        situacao = "203";
    }

    if (strcmp (situacao.c_str(), "REPROVADA") == 0){
        situacao = "239";
    }

    sql = sql + situacao.c_str() +",2,1,10,10,5,1,10,'2014-11-18')";

    //strcat(sql, resto);
    ret = mysql_query(&conexao,sql.c_str());

    if ( mysql_errno( &conexao ) || mysql_warning_count( &conexao ) ){
       cout << "Erro" << endl;
    }else{
       cout << "OK" << endl;
    }

    system("PAUSE");

}

void finale(){



    INPUT ip;
	ip.type = INPUT_KEYBOARD;

	for(int c = 0; c <60 ; c++){
        Sleep(50);
        // Press the "DOWN" key
        ip.ki.wVk = VK_DOWN;
        ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

        // Release the "DOWN" key
        ip.ki.wVk = VK_DOWN;
        ip.ki.dwFlags = KEYEVENTF_KEYUP;//Flag
        SendInput(1, &ip, sizeof(INPUT));
	}


	if (strcmp(status,"ANDAMENTO")==0){
        move(430,960);
	}else{
        move(432,1005);
	}
	click();

    move(435,1000);//caso não tenha lista
    click();

    Sleep(3000);
 //system("PAUSE");

}

int verificarTipoFormulario(){


    char *nome = info;// conversção
    strcpy(tmp, &nome[0]);//copia
    printf("Tamanho --> %i\n",strlen(tmp));//log
    y_form = 0;//Mudança de coordenada
    for (int c = 0; c < strlen(tmp); c++){//comparação char achar
        if (tmp[c] == '('){
          //printf("%c %s\n", tmp[c], "sim");//se existir volta a ser y = 0;
          y_form = -10;//mudança da coordenada y
        }
    }
    return y_form;
    //printf("y --> %i\n",y);//log

}


int carrega_contatos(){// Conexão com Banco e Carregamento de Contatos

    MYSQL conexao;

    mysql_init(&conexao);
    if ( mysql_real_connect(&conexao, "localhost", "root", "", "grupolhasa_sistema", 0, NULL, 0) ){
       cout << "\nConexao ao banco realizada com sucesso!\n" << endl;
    }
    else{
        cout << "Falha de conexao\n" << endl;
        cout << mysql_errno(&conexao) << endl;
        cout << mysql_error(&conexao) << endl;
    }

        int ret;
        ret = mysql_query(&conexao,"SELECT id, nome_representante, celular FROM cad_representante where ativo = 1 AND celular != '' limit 5000");

        MYSQL_RES *result;
        result = mysql_store_result(&conexao);

        MYSQL_FIELD *rs;
        rs = mysql_fetch_fields(result);

        MYSQL_ROW lin;
        int c = 0;


        cout << "Consultando numeros, aguarde... \n" << endl;

        int x = 0;
        while((lin = mysql_fetch_row(result)) != NULL) {
             //printf("%d\t%s\n",c++,lin[2]);
                cout << lin[2] << " - " << lin[1] << endl;

                vetor[x] = lin[2];
                x++;
        }

        cout << "Concluido! \n" << endl;

        mysql_close(&conexao);

}

void move(int x, int y){//Movimento/Posição Cursor
     Sleep(1000);
     SetCursorPos(x,y);
}

void click(){ //Click
    Sleep(200);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0,0, 0,0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0,0, 0,0);
}

void clickSegura(){ //click Segura
    Sleep(200);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0,0, 0,0);
}

void clickSolta(){ //click Solta
    Sleep(200);
     mouse_event(MOUSEEVENTF_LEFTUP, 0,0, 0,0);
}

void dbclick(){ //Double Click
    Sleep(200);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0,0, 0,0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0,0, 0,0);
    Sleep(50);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0,0, 0,0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0,0, 0,0);
}

void triclick(){ //Triple Click
    Sleep(200);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0,0, 0,0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0,0, 0,0);
    Sleep(50);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0,0, 0,0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0,0, 0,0);
    Sleep(50);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0,0, 0,0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0,0, 0,0);
}

void copiar(){//Ctrl + C

	INPUT ip;
	ip.type = INPUT_KEYBOARD;

	Sleep(50);
	// Press the "Ctrl" key
	ip.ki.wVk = VK_CONTROL;
	ip.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &ip, sizeof(INPUT));

	// Press the "C" key
	ip.ki.wVk = 'C';
	ip.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &ip, sizeof(INPUT));

	// Release the "C" key
	ip.ki.wVk = 'C';
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));

	// Release the "Ctrl" key
	ip.ki.wVk = VK_CONTROL;
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));

}

void BailOut(char *msg){
  fprintf(stderr, "Exiting: %s\n", msg);
  exit(1);
}

void resgata(){ //Ctrl + V

    Sleep(400);
	HANDLE h;

	if (!OpenClipboard(NULL))
	BailOut("Can't open clipboard");

	h = GetClipboardData(CF_TEXT);
	info = (char *)h;

	CloseClipboard();


	//std::cout << numero << std::endl;

}
