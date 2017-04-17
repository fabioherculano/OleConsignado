#define WINVER 0x0500
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
//#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>


/* Ole Consignado */

int x = GetSystemMetrics(SM_CXSCREEN);
int y = GetSystemMetrics(SM_CYSCREEN);

void move(int x, int y);
void click();
void dbclick();
void triclick();
void copiar();
void clickSegura();
void clickSolta();
void resgata();

char *info = 0;

int main(int argc, char** argv) {

printf("Resolução: %d x %d\n",x , y);


//inicio descartar apenas selecionar navegador
move(415,1058);//topo
click();
//

x = x/2;
y = y/2;
move(x,y);//Centralização de Monitor

move(x,0);//topo
move(x-325,300);//primeiro registro
click();
move(0,0);
move(175,200);//Numero da Proposta
dbclick();
copiar();
resgata();
printf("Numero da Proposta --> %s\n",info);


//nome
click();
move(74,212);//inicio seleção nome
clickSegura();
move(246,212);//final seleção nome
clickSolta();	
copiar();
resgata();
printf("Nome Cliente --> %s\n",info);
//nome

//Situação
move(545,216);
dbclick();
copiar();
resgata();
printf("Situação --> %s\n",info);
//Situação


//Endereço
move(57,285);
clickSegura();
move(253,285);
clickSolta();	
copiar();
resgata();
printf("Endereço --> %s\n",info);
//Endereço

//Numero
move(279,290);
dbclick();
copiar();
resgata();
printf("Numero --> %s\n",info);
//Numero


//UF
move(532,290);
dbclick();
copiar();
resgata();
printf("UF --> %s\n",info);
//UF	


//Bairro
move(64,300);
dbclick();
copiar();
resgata();
printf("Bairro --> %s\n",info);
//Bairro

//Cidade
move(300,300);
dbclick();
copiar();
resgata();
printf("Cidade --> %s\n",info);
//Cidade

//Cep
click();
move(530,300);//inicio seleção nome
clickSegura();
move(590,300);//final seleção nome
clickSolta();	
copiar();
resgata();
printf("CEP --> %s\n",info);
//Cep


//CPF
click();
move(30,310);//inicio seleção nome
clickSegura();
move(108,310);//final seleção nome
clickSolta();	
copiar();
resgata();
printf("CPF --> %s\n",info);
//CPF


//RG
click();
move(276,310);//inicio seleção nome
clickSegura();
move(420,310);//final seleção nome
clickSolta();	
copiar();
resgata();
printf("RG --> %s\n",info);
//RG


//Matricula
move(586,310);
dbclick();
copiar();
resgata();
printf("Matricula --> %s\n",info);
//Matricula


//RG
click();
move(80,333);//inicio seleção nome
clickSegura();
move(155,333);//final seleção nome
clickSolta();	
copiar();
resgata();
printf("Nascimento --> %s\n",info);
//RG




	return 0;
}

void move(int x, int y){//Move
     Sleep(1000);
     SetCursorPos(x,y);
}

void click(){ //Click
    Sleep(200);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0,0, 0,0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0,0, 0,0); 
}

void clickSegura(){ //Click
    Sleep(200);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0,0, 0,0);
}

void clickSolta(){ //Click
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

void triclick(){ //Double Click
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

void copiar(){

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

void resgata(){

    Sleep(400);
	HANDLE h;
	
	if (!OpenClipboard(NULL))
	BailOut("Can't open clipboard");
	
	h = GetClipboardData(CF_TEXT);
	info = (char *)h;
	
	CloseClipboard();

	
	//std::cout << numero << std::endl;
         
}



