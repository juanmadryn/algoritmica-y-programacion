/* Compilat en Turbo C++ 4.5 per a Windows. */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>


/* Segons la direccio, tenim uns graus o uns altres: */
#define DALT_DTA 0
#define DALT_ERA 1
#define BAIX_DTA 2
#define BAIX_ERA 3

#define X_TOPE 80
#define Y_TOPE 23

#define N_PILOTES (X_TOPE * Y_TOPE) / 3
#define N_PILOTES_MIN 1


void inicialitza_pelota(int *x, int *y, int *graus);
void mou_pelota(int *x, int *y, int *graus);
void mostra_pelota(int x, int y);
void esborra_pelota(int x, int y);
void retard();
/* void cursor_off(); */

void gotoxy(int x, int y) { 
    printf("%c[%d;%df", 0x1B, y, x); 
} 

int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void main()
{
	 int x[N_PILOTES], y[N_PILOTES], graus[N_PILOTES], i, n_pelotas = N_PILOTES_MIN, sortir = 0, tecla;

	 srand((int)time(NULL)); /* Es fa per utilitzar despres rand(). */

	 for (i = 0; i < n_pelotas; i++) { inicialitza_pelota(&x[i], &y[i], &graus[i]); }

	 /* Mentre no es premi cap tecla: */
	 while (!sortir)
	 {
			for (i = 0; i < n_pelotas; i++)
			{
				esborra_pelota(x[i], y[i]);
				mou_pelota(&x[i], &y[i], &graus[i]);
				mostra_pelota(x[i], y[i]);
			}

			gotoxy(0, 25); printf("[S] = Salir, [+] = Inc. pelota, [-] = Dec. pelota, Pelotas: %d (max. %d)", n_pelotas, N_PILOTES);

			/* Retarda el moviment de la bola: */
			retard();

			if(kbhit())
			{
				tecla=getchar();
				switch(tecla)
				{
					 case '+':
								if (n_pelotas < N_PILOTES)
								{
									n_pelotas++;
									inicialitza_pelota(&x[n_pelotas-1], &y[n_pelotas-1], &graus[n_pelotas-1]);
								}
								break;
					 case '-':
								if (n_pelotas > N_PILOTES_MIN)
								{
									n_pelotas--;
									esborra_pelota(x[n_pelotas], y[n_pelotas]);
								}
								break;
					 case 's': case 'S': sortir = 1; break;
				}
			}

	 }

	 /* Finalitza el programa: */
	 return;
}


/* Funcio que inicialitza la pelota: */
void inicialitza_pelota(int *x, int *y, int *graus)
{
	 /* Posicio inicial de la pelota (aleatoria): */
	 *x = rand() % X_TOPE + 1;
	 *y = rand() % Y_TOPE + 1;
	 *graus = rand() % 4; /* Graus (aleatoris). */

	 return;
}


/* Funcio que mou la pelota: */
void mou_pelota(int *x, int *y, int *graus)
{


			 switch (*graus)
			 {
					  case DALT_DTA:
							 ++*x; --*y;
							 if (*x >= X_TOPE && *y <= 1) { *graus = BAIX_ERA; }
							 else if (*x >= X_TOPE) { *graus = DALT_ERA; }
							 else if (*y <= 1) { *graus = BAIX_DTA; }
					  break;
					  case DALT_ERA:
							 --*x; --*y;
							 if (*x <= 1 && *y <= 1) { *graus = BAIX_DTA; }
							 else if (*x <= 1) { *graus = DALT_DTA; }
							 else if (*y <= 1) { *graus = BAIX_ERA; }
					  break;
					  case BAIX_DTA:
							 ++*x; ++*y;
							 if (*x >= X_TOPE && *y >= Y_TOPE) { *graus = DALT_ERA; }
							 else if (*x >= X_TOPE) { *graus = BAIX_ERA; }
							 else if (*y >= Y_TOPE) { *graus = DALT_DTA; }
					  break;
					  case BAIX_ERA:
							 --*x; ++*y;
							 if (*x <= 1 && *y >= Y_TOPE) { *graus = DALT_DTA; }
							 else if (*x <= 1) { *graus = BAIX_DTA; }
							 else if (*y >= Y_TOPE) { *graus = DALT_ERA; }
					  break;
			 }
}


/* Funcio que mostra la pelota: */
void mostra_pelota(int x, int y)
{
			 char pelota = 'O'; /* El caracter que tindra la pelota. */

			 /* Posiciona el cursor on es dibuixara la pelota: */
			 gotoxy(x, y);
			 /* Alterna l'aspecte de la pelota: */
			 pelota = (pelota == 'O') ? 'o' : 'O';
			 /* Mostra la pelota: */
			 printf("%c", pelota);
}


void esborra_pelota(int x, int y)
{
			 /* Esborra la pantalla: */
			 gotoxy(x, y);
			 printf(" ");
}


/* Funcio que oculta el cursor (requereix dos.h): */
/*
void cursor_off()
{
	  union REGS inregs, outregs;
	  inregs.h.ah=1;
	  inregs.h.ch=0x20;
	  inregs.h.cl=0;
	  int86(0x10,&inregs,&outregs);
}
*/


/* Funcio que fa retardar el sistema: */
void retard()
{
	  long x;
	  for (x=0; x<=9999999L; x++) {  }
}