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

char tmp[100];//Temporario de compara��o
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

char *info = 0;


int main(){

    printf("Resolu��o: %d x %d\n",x , y);

    //carrega_contatos();


    //inicio descartar apenas selecionar navegador
    move(415,1058);//posi��o Icone no WINDOWS 10
    click();
    //

    x = x/2;//Medias Monitor
    y = y/2;//Medias Monitor
    move(x,y);//Centraliza��o de Monitor

    move(x,0);//topo

    /*Verificar se existe FUN��O*/
    //y = 300+(22*10);//Posi��o fixa primeiro registro
    y = 300;//Posi��o fixa primeiro registro

    for (int z=0; z<15; z++){

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
               //move(x-380,y);//primeiro registro + posi��o abaixo...
               //clickSegura();
               //move(x-300,y);//primeiro registro + posi��o abaixo...
               //clickSolta();
               //Sleep(1000);
               //copiar();
               //resgata();
               //SELECIONA NUMERO PROPOSTA

               if(info == "0"){
                   Sleep(60000);
                   printf("1 minuto para Atualiza��o...");

                   move(x-20,565);//bot�o Atualizar
                   click();
                   Sleep(50);
                   click();
                   Sleep(4000);

               }else{

                    /*faz verifica��o se tem repeti��o*/
                      //  printf("%s",info);
                    /*faz verifica��o se tem repeti��o*/

                    //system("PAUSE");

                    move(x-325,y);//primeiro registro
                    click();
                    Sleep(1000);

                    copia_informacoes();
                    y = y+22;// Posi��o Y par aproximo registro da lista
                  }

                  finale();
                  info = 0;
           }




    }



    system("PAUSE");
    return(0);
}


void copia_informacoes(){

    move(0,0);

    move(36,137);
    dbclick();
    copiar();
    resgata();


     if (strcmp(info,"500 ")==0){
            printf("Deu merda!....\n");
            system("PAUSE");
    }else{

        for (int c = 0; c<10; c++){
           if (strcmp(info,"BONSUCESSO ")==0){
                break;
            }else{
                Sleep(3000);
                printf("Provavel carregamento! aguardando....\n");
                move(36,137);
                dbclick();
                copiar();
                resgata();
            }

        }


    }

    move(175,200);//Numero da Proposta
    dbclick();
    copiar();
    resgata();
    printf("Numero da Proposta --> %s\n",info);


    //nome
    click();
    move(74,212);//inicio sele��o nome
    clickSegura();
    move(246,212);//final sele��o nome
    clickSolta();
    copiar();
    resgata();
    printf("Nome Cliente --> %s\n",info);


    /*Verifica��o para nome de cliente de conter (numero) apos o nomde do cliente o formulario sera mais alto*/
    //essa fun��o verifica se o formulario houve alguma altera��o devido ao tamanho do nome do cliente FULANO DE TAL (123123123) os parenteses com o numero pode estar na linha abaixo desconfigurando toda a pesquisa
    y_form = verificarTipoFormulario();//a veriavel info � global sera usada dentro desta fun��o
    printf("y --> %i\n",y_form);
    //nome

    //Situa��o
    move(545,216);//Ditua��o n�o sofre mudan� de varificarTipoFormularo
    dbclick();
    copiar();
    resgata();
    strcpy(status, info);//Status para final
    printf("Situa��o --> %s\n",info);
    //Situa��o


    //Endere�o
    move(57,y_form+285);
    clickSegura();
    move(253,y_form+285);
    clickSolta();
    copiar();
    resgata();
    printf("Endere�o --> %s\n",info);

    //Endere�o

    //Numero
    move(279,y_form+290);
    dbclick();
    copiar();
    resgata();
    printf("Numero --> %s\n",info);
    //Numero


    //UF
    move(532,y_form+290);
    dbclick();
    copiar();
    resgata();
    printf("UF --> %s\n",info);
    //UF


    //Bairro
    move(64,y_form+300);
    dbclick();
    copiar();
    resgata();
    printf("Bairro --> %s\n",info);
    //Bairro

    //Cidade
    move(300,y_form+300);
    dbclick();
    copiar();
    resgata();
    printf("Cidade --> %s\n",info);
    //Cidade

    //Cep
    click();
    move(530,y_form+300);//inicio sele��o nome
    clickSegura();
    move(590,y_form+300);//final sele��o nome
    clickSolta();
    copiar();
    resgata();
    printf("CEP --> %s\n",info);
    //Cep


    //CPF
    click();
    move(30,y_form+310);//inicio sele��o nome
    clickSegura();
    move(108,y_form+310);//final sele��o nome
    clickSolta();
    copiar();
    resgata();
    printf("CPF --> %s\n",info);
    //CPF


    //RG
    click();
    move(276,y_form+310);//inicio sele��o nome
    clickSegura();
    move(420,y_form+310);//final sele��o nome
    clickSolta();
    copiar();
    resgata();
    printf("RG --> %s\n",info);
    //RG


    //Matricula
    move(586,y_form+310);
    dbclick();
    copiar();
    resgata();
    printf("Matricula --> %s\n",info);
    //Matricula


    //RG
    click();
    move(80,y_form+333);//inicio sele��o nome
    clickSegura();
    move(155,y_form+333);//final sele��o nome
    clickSolta();
    copiar();
    resgata();
    printf("Nascimento --> %s\n",info);
    //RG

    finale();

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
    Sleep(3000);
 //system("PAUSE");

}

int verificarTipoFormulario(){


    char *nome = info;// convers��o
    strcpy(tmp, &nome[0]);//copia
    printf("Tamanho --> %i\n",strlen(tmp));//log
    y_form = 0;//Mudan�a de coordenada
    for (int c = 0; c < strlen(tmp); c++){//compara��o char achar
        if (tmp[c] == '('){
          //printf("%c %s\n", tmp[c], "sim");//se existir volta a ser y = 0;
          y_form = -10;//mudan�a da coordenada y
        }
    }
    return y_form;
    //printf("y --> %i\n",y);//log

}


int carrega_contatos(){// Conex�o com Banco e Carregamento de Contatos

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

void move(int x, int y){//Movimento/Posi��o Cursor
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
