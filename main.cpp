#include <stdio.h> //Biblioteki u¿yte w programie//
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h> 
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream> 
#include <wingdi.h>
#include <mmsystem.h> //Dodatek do dzwieku!//

#define LEFT 1 //Definicja klawiszy potrzebnych do gry//
#define RIGHT 2
#define UP 3
#define DOWN 4

//Z Czego korzystalem?//
// Jak dodac kolory w konsoli ? - https://cpp0x.pl/kursy/Kurs-WinAPI-C++/Roznosci/Kolory-w-konsoli/374 //
// Snake - https://www.youtube.com/watch?v=E_-lMZDi7Uw&t //
//T-Rex Runner - https://www.youtube.com/watch?v=BIkayFNnHgU&t//
//Guessing Game - https://www.youtube.com/watch?v=xJ4jhhOtyAk //

using namespace std;

bool shutDown; //zmienne wykorzystywane w calosci programu//
int t,speed=40;

int snake(); // funkcje//
int Dinozaur();
void StartScreen();
void Instructions();
void InstructionsD();
void StartScreenD();
int Maszyna(); 
int Guessing();

//Wybor gry//
int main(){
	
		cout << "------------------------------------------------\n" //Dane o tworcy calosci programu//
		<< "Autor: Tymoteusz Maj"
		<< "\nNumer indeksu : 401370"
		<< "\nGeoinformacja"
		<< "\nGrupa 1" << endl;
		cout << "------------------------------------------------\n" << endl;
	
		
		
		Maszyna();		
		
}
int Maszyna (){
		int wybor;
	cout << "\t\t Witaj w konsoli do gier!\n" << endl;
		
cout << "[1] Snake Game " << endl;
cout << "[2] T-Rex Runner " << endl;
cout << "[3] Guessing Game " << endl;
cin >> wybor;

	if (wybor==1) // Prosty wybor Gry
	{
		cout << "Wybrano gre numer 1. " << endl;
		system("pause");
	PlaySound(TEXT("Dancin.wav"), NULL, SND_FILENAME | SND_ASYNC);// - wstawienie dzwieku //
		snake()	;
			}	


	if (wybor==2)
	{
	
	cout << "Wybrano gre numer 2. " << endl;
	system("pause");
	PlaySound(TEXT("Sandstorm.wav"), NULL, SND_FILENAME | SND_ASYNC);// - wstawienie dzwieku//
	Dinozaur();
			}
	if (wybor==3)
	{
	cout << "Wybrano gre numer 3. " << endl;
	system("pause");
	PlaySound(TEXT("Best Friend.wav"), NULL, SND_FILENAME | SND_ASYNC);// - wstawienie dzwieku//
	Guessing();
				}
	else
	{
		cout<<"Wybor nie prawid³owy! - Zakonczenie dzialania programu";
	}
	
		
		
}
//Snake - Bazuje na tutorialu NVitanovic (YouTube)//
void textcolor(int fc,int bc=-1){
	if(fc<0 || fc>15)
		return;
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	if(bc>=0 && bc<16)
		SetConsoleTextAttribute(h,fc|bc*16);
	else
		SetConsoleTextAttribute(h,fc); //Przypisanie koloru do tekstu//
}
void textcolor(char *fc,char *bc=""){
	int x,y=16;
	char *colors[]={"Black","Blue","Green","Aqua","Red","Purple","Yellow","White","Gray",
	"LightBlue","LightGreen","LightAqua","LightRed","LightPurple","LightYellow","BrightWhite"};
	for(x=0;x<16;x++)
		if(strcmpi(colors[x],fc)==0)
			break;
	if(strlen(bc)>0)
		for(y=0;y<16;y++)
			if(strcmpi(colors[y],bc)==0)
				break;
	textcolor(x,y); //Definicja kolorow//
}
void textcolor(char *fc,int bc){
	int x;
	char *colors[]={"Black","Blue","Green","Aqua","Red","Purple","Yellow","White","Gray",
	"LightBlue","LightGreen","LightAqua","LightRed","LightPurple","LightYellow","BrightWhite"};
	for(x=0;x<16;x++)
		if(strcmpi(colors[x],fc)==0)
			break;
	textcolor(x,bc); //Przypisanie koloru po X//
}
void textcolor(int fc,char *bc){
	int y;
	char *colors[]={"Black","Blue","Green","Aqua","Red","Purple","Yellow","White","Gray",
	"LightBlue","LightGreen","LightAqua","LightRed","LightPurple","LightYellow","BrightWhite"};
	if(strlen(bc)>0)
		for(y=0;y<16;y++)
			if(strcmpi(colors[y],bc)==0)
				break;
	textcolor(fc,y); //Przypisanie kolorou po Y//
}
void gotoxy(int x, int y){
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //Przemieszczanie sie po planszy//
} 
void getup(){
	HANDLE hout; 
	CONSOLE_CURSOR_INFO cursor;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cursor.dwSize=1;
	cursor.bVisible=false;
	SetConsoleCursorInfo(hout, &cursor);
	system("mode con:cols=80 lines=25");
	system("Snake Game");
	system("cls");
	textcolor("LightPurple");
	printf("\n  %c",218);
	int x;
	for(x=0;x<75;x++)
		printf("%c",196);
	printf("%c  ",191);
	for(x=0;x<17;x++){
		gotoxy(2,x+2);
		printf("%c",179);
		gotoxy(78,x+2);
		printf("%c ",179);
	}
	printf("  %c",192);
	for(x=0;x<75;x++)
		printf("%c",196);
	printf("%c  ",217);
	printf(" %c",218);
	for(x=0;x<21;x++)
	printf("%c",196);
	printf("%c\n",191);
	printf("  %c S N A K E   G A M E %c\n",179,179);
	printf("  %c",192);
	for(x=0;x<21;x++)
		printf("%c",196);
	printf("%c",217);
	
	gotoxy(59,20);
	printf("%c",218);
	for(x=0;x<18;x++)
		printf("%c",196);
	printf("%c",191);
	gotoxy(59,21);
	printf("%c PUNKTY : 100     %c",179,179);
	gotoxy(59,22);
	printf("%c STATUS: W grze %c",179,179);
	gotoxy(59,23);
	printf("%c",192);
	for(x=0;x<18;x++)
		printf("%c",196);
	printf("%c",217);
	gotoxy(28,20);
	printf("[X] Opusc Gre");
	gotoxy(28,21);
	printf("[SPACJA] Pauza");
	gotoxy(10,23);

	//Ustawienia interfejsu gry (kolor/ulozenie klawiszy itd)//
}
void score(int sc){
	gotoxy(69,21);
	printf("%6d",sc*10); //System wyswietlania punktow//
}
void status(char *s,int c=7){
	gotoxy(69,22);
	textcolor(c);
	int x;
	for(x=0;x<strlen(s);x++)
		printf("%c",s[x]);
	for(;x<8;x++)
		printf(" ");
	textcolor(7); //Ustawienia aktywnego statusu gry//
}
int snake(){
	//Caly proces dzialania gry - snaka//
		do {
		StartScreen();
		string input;
		cin >> input;
		if (input == "s")
		{
		
			getup(); // Caly system dzialania gry, krok po kroku//
			system("pause");
	register int flow,size,i,xb,yb;
	int speed,restart=1,tmp,xpos[100],ypos[100],scr;
	srand(time(NULL));
	while(true){
		if(restart){
			status("W grze",10);
			for(int k=1;k<75;k+=2)
				for(int j=0;j<17;j++){
					gotoxy(k+3,j+2);
					printf(" ");
				}
			size=5;	
			speed=200;
			scr=0;
			score(scr);
			flow=RIGHT;
			xpos[0]=20;
			for(i=0;i<size;i++){
				xpos[i]=xpos[0]-i*2;
				ypos[i]=10;
			}
			for(i=0;i<size;i++){
				gotoxy(xpos[i],ypos[i]);
				printf("o");
			}
			for(tmp=1;true;){
				do{
					xb=rand()%75+3;
				}while(xb%2!=0);
				yb=rand()%17+2;
				for(i=0;i<size;i++)
					if(xb==xpos[i] && yb==ypos[i]){
						tmp=0; break;
					}
				if(tmp)
					break;
			}
			gotoxy(xb,yb);
			textcolor("lightgreen");
			printf("@");
			textcolor(7);
			restart=0;
		}
		while(!kbhit() && !restart)	{
			if(xpos[0]==xb && ypos[0]==yb){
				for(tmp=1;true;){
					do{
						xb=rand()%75+3;
					}while(xb%2!=0);
					yb=rand()%17+2;
					for(i=0;i<size;i++)
						if(xb==xpos[i] && yb==ypos[i]){
							tmp=0; break;
						}
					if(tmp)
						break;
				}
				gotoxy(xb,yb);
				textcolor("lightgreen");
				printf("@");
				textcolor(7);
				size++;
				scr++;
				speed-=3;
				score(scr);
			}
			gotoxy(xpos[size-1],ypos[size-1]);
			for(i=size-1;i>0;i--){				
				xpos[i]=xpos[i-1];
				ypos[i]=ypos[i-1];
			}
			switch(flow){
				case RIGHT :xpos[i]+=2; break;
				case LEFT :	xpos[i]-=2; break;
				case UP :	ypos[i]-=1; break;
				case DOWN :	ypos[i]+=1; 
			}
			tmp=1;
			for(i=1;i<size;i++)
				if(xpos[i]==xpos[0] && ypos[i]==ypos[0]){
					tmp=0;
					break;
				}
			if(xpos[0]>76 || xpos[0]<4 || ypos[0]<2 ||ypos[0]>18)
				tmp=0;
			if(tmp){
				printf(" ");
				gotoxy(xpos[0],ypos[0]);
				printf("O");	
				gotoxy(xpos[1],ypos[1]);
				printf("o");	
			}
			else{
				textcolor("LIGHTRED");
				printf("o");
				gotoxy(xpos[1],ypos[1]);
				printf("O");
				for(i=2;i<size;i++){
					gotoxy(xpos[i],ypos[i]);
					printf("o");
				}
				textcolor(7);
				status("GAMEOVER",12);
				restart=1;
				getch();
			}
			//ustawienia predkosci(speed);
			Sleep(speed);
		}
		char ch=getch();
		switch(tolower(ch)){
			case 'x' : 	system("cls");
						return 0;
			case ' ' : status("Paused"); 
						while(true){
							char z=getch();
							if(z=='x')
								return 0;
							if(z==' ')
								break;
						}
						status("W grze",10);
						break;
			case -32: {
				char chh=getch();
				if(chh==72 && flow!=DOWN)
					flow=UP;
				else if(chh==80 && flow!=UP)
					flow=DOWN;
				else if(chh==75 && flow!=RIGHT)
					flow=LEFT;
				else if(chh==77 && flow!=LEFT)
					flow=RIGHT;
				break;
			}
		}
	}
		}
		else if (input == "i") //Przejscie do instrukcji gry//
			Instructions();
		else if (input == "q") //Oposc program//
			shutDown = true;
	} while (shutDown == false);

	return 0;
	
	
	
	
	StartScreen();
	
}
void StartScreen(){
		system("cls"); //Menu wyboru przed gra//
	cout <<"------------------------------------------------" << endl; 
	cout << "Witam w konsolowej wersji popularnej gry SNAKE!"
		<< "\nProgram zostal napisany zgodnie z poradniekiem uzytkownika  NVitanovic (YouTube) - oraz przeszedl lekkie modyfikacje"
		<< "\n\n[S] Rozpocznij gre!"
		<< "\n\n[Q] Wyjdz z programu."
		<< "\n\n[I] Instrukcja gry."<< endl;
		cout <<"------------------------------------------------" << endl;
}
void Instructions(){
	system("cls"); //Instrukcja//
	cout << "\n[Strzalka w gore] Poruszanie sie w GORE."
		<< "\n[Strzalka w lewo] Poruszanie sie w LEWO."
		<< "\n[Strzalka w dol] Poruszanie sie w DOL."
		<< "\n[Strzalka w prawo] Poruszanie sie w PRAWO."
		<< "\n\n[X] Opusc obecnie trwajaca rozgrywke"
		<< "\n[Spacja] Pauza"
		<< "\n\n          Co konczy gre ?"
		<< "\n[1] Wpadniecie w linie ograniczajace pole!"
		<< "\n[2] Zmiana kierunku poruszania sie na przeciwny!"
		<< "\n[3] Wejscie w samego siebie!"
		<< "\n\n\n[M] Powrot do Menu\n";
	string input;
	cin >> input;
	if (input == "m")
		StartScreen();
}
//T-Rex Runner - Bazuje na tutorialu Angulars (YouTube)//
void gotoxyD(int x, int y){
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //Ustawienia pozycji w grze T-Rex Runner//
} 
void delay(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock()); //Ustawienia zegara - opoznienie i przyspieszenie gry//
}
void getupD(){
	system("cls"); //Interfejs gry//
	gotoxyD(10,2);
	textcolor("Yellow");
	printf("[X] Opusc Gre / [SPACJA} SKOK");
	gotoxyD(62,2);
	textcolor("Yellow");
	printf("PUNKTY : ");
	gotoxyD(1,25);
	for(int x=0;x<79;x++)
	printf("ß");
}
void ds(int jump=0){
	static int a=1; //Grafika(?) Dinozaura//

	if(jump==0)
		t=0;
	else if(jump==2)
		t--;
	else t++;
	gotoxyD(2,14-t);
	printf("                    ");
	gotoxyD(2,15-t);
	textcolor("LightGreen");
	printf("         O O        ");
	gotoxyD(2,16-t);
	textcolor("LightGreen");
	printf("         OoOoooo    ");
	gotoxyD(2,17-t);
	textcolor("LightGreen");
	printf("         oo  oooooo  ");
	gotoxyD(2,18-t);
	textcolor("LightGreen");
	printf("         oooooooo   ");
	gotoxyD(2,19-t);
	textcolor("LightGreen");
	printf(" o      Oooooooo ");
	gotoxyD(2,20-t);
	textcolor("LightGreen");
	printf(" ooO  OoooooooOOO ");
	gotoxyD(2,21-t);
	textcolor("LightGreen");
	printf("  ooooooooooo  O ");
	gotoxyD(2,22-t);
	textcolor("LightGreen");
	printf("   OoooooooO     ");
	gotoxyD(2,23-t);
	if(jump==1 || jump==2){
		textcolor("LightGreen");
	printf("    ooO Oo       ");
	gotoxyD(2,24-t);
	textcolor("LightGreen");
	printf("    oO   oO      ");
	}else if(a==1)
	{
		textcolor("LightGreen");
	printf("    OooO  OOO    ");
	gotoxyD(2,24-t);
	textcolor("LightGreen");
	printf("      oO         ");
	a=2;
	}
	else if(a==2)
	{
		textcolor("LightGreen");
	printf("     OoO Oo      ");
	gotoxyD(2,24-t);
	textcolor("LightGreen");
	printf("          oO     ");
	a=1;
	}
	gotoxyD(2,25-t);
	if(jump!=0){
		printf("                ");
	}
	else
	{
		textcolor("Grey");
		printf("ßßßßßßßßßßßßßßßßß");
	}
	delay(speed);
}
void obj(){
	static int x=0,scr=0; //Grafika(?) Krzewu
	if(x==56 && t<4)
	{
	scr=0;
	speed=40;
	gotoxyD(36,8);
	textcolor("Red");
	printf("Koniec Gry");
	getch();
	gotoxyD(36,8);
	printf("           ");
	}
	gotoxyD(74-x,20);
	textcolor("LightRed");
	printf("#    # ");
	gotoxyD(74-x,21);
	textcolor("LightRed");
	printf("#    # ");
	gotoxyD(74-x,22);
	textcolor("LightRed");
	printf("###### ");
	gotoxyD(74-x,23);
	textcolor("LightRed");
	printf("  #  ");
	gotoxyD(74-x,24);
	textcolor("LightRed");
	printf("  #  ");
	x++;
	if(x==73)
	{
	x=0;
	scr++;
	gotoxyD(70,2);
	printf("     ");
	gotoxyD(70,2);
	textcolor("Yellow");
	printf("%d",scr);
	if(speed>20) //Opoznienie//
		speed--;
	}
}
int Dinozaur(){
	do { //przebieg gry//
		StartScreenD();
		string input;
		cin >> input;
		if (input == "s")
		{
	system("mode con: lines=29 cols=82");
	char ch;
	int i;
	getupD();
	while(true)
	{
		while(!kbhit())
		{
			ds();
			obj();
		}
		ch=getch();
		if(ch==' ')
		{
			for(i=0;i<10;i++)
			{
			ds(1);
			obj();
			}
			for(i=0;i<10;i++)
			{
			ds(2);
			obj();
			}
		}
		else if (ch=='x')
			return(0);
	} 
}
		else if (input == "i") //Instrukcja//
			InstructionsD();
		else if (input == "q") //Wyjscie z gry//
			shutDown = true;
	} while (shutDown == false);

	return 0;
	
	
	
	
}
void StartScreenD(){
	system("cls"); //Menu wyboru przed gra//
	cout <<"------------------------------------------------" << endl; 
	cout << "Witam w konsolowej wersji popularnej gry T-Rex Runner!"
		<< "\nProgram zostal napisany zgodnie z poradniekiem uzytkownika  Angulars (YouTube) - oraz przeszedl lekkie modyfikacje"
		<< "\n\n[S] Rozpocznij gre!"
		<< "\n\n[Q] Wyjdz z programu."
		<< "\n\n[I] Instrukcja gry."<< endl;
		cout <<"------------------------------------------------" << endl;
	
	
}
void InstructionsD(){
	system("cls"); //Instrukcja gry//
	cout <<"------------------------------------------------" << endl; 
	cout << "\n[SPACJA] SKOK."
		<< "\n[X] OPUSC GRE."
		<< "\n\n          Co konczy gre ?"
		<< "\n[1] Wpadniecie w krzak"
		<< "\n\n\n[M] Powrot do Menu\n";
		cout <<"------------------------------------------------" << endl; 
	string input;
	cin >> input;
	if (input == "m")
		StartScreenD();
}
//Guessing Game - Bazuje na tutorialu Mike Dane (YouTube)//
void PrintIntroduction(int Difficulty) {
   	cout << "Poziom " << Difficulty; //Wypisanie instrukcji//
  	cout << "\nAby przejsc dalej musisz podac prawidlowy kod.\n";
  	cout << "Mnozenie przez 0 nie zeruje calosci kodu \n\n";
}
bool PlayGame(int Difficulty) {
    PrintIntroduction(Difficulty); //Granie

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Podanie czego oczekujemy
   	cout << endl;
   	textcolor("LightBlue");
    cout << "+ W kodzie sa 3 cyfry";
    cout << "\n+ Jego elementy po dodaniu sa rowne: " << CodeSum;  
    cout << "\n+ Kiedy je pomnozymy otrzymamy: " << CodeProduct << std::endl;  

    // Magazynowanie odpowiedzi uzytkownika
    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum) {
    		textcolor("Green");
        cout << "\n*** Dobra robota, tak trzymaj! ***";
        system("pause");
        system("cls");
        return true;
    }
    else
    {
    		textcolor("Red");
        cout << "\n*** Wprowadzono zly kod! Sproboj ponownie. ***";
        return false;
    }
}
int Guessing(){
	system("cls");
	cout<<"Witaj w grze logicznej!\n"
  	<< "Twoim zdaniem jest zgadywanie odpowiednich cyfr (kodu) zgodnie z zalozeniami \n"
  	<<"Jezeli ci sie to uda --> przejdziesz dalej, jezeli sie pomylisz dostaniesz druga szanse.\n"
  	<<"[Cyfry podawaj pojedynczo oraz zatwierdzaj je [ENTEREM]";
  	
  	cout <<"Projekt inspirowany praca Mike Dane (YouTube) - Tutorial 21 \n\n";
  	
    srand(time(NULL)); //Losowanie kodu//
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    
    while (LevelDifficulty <= MaxDifficulty)  //Przebieg gry//
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();
        cin.ignore();

        if (bLevelComplete) {
            ++LevelDifficulty;
        }
    }
	textcolor("Green");
    cout << "\n\n*** Dobra robota! Udalo ci sie ukonczyc cale wyzwanie! ***\n";
    return 0;
}
