#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX_STACK 5
#define MAX_QUEUE 5

struct {
    char top;
    char data[MAX_STACK][MAX_STACK];

} tumpuk;

struct Queue{
    int data[MAX_QUEUE];
    int head;
    int tail;
} antrian;

//stack
void inisialisasi()
{
    tumpuk.top = -1;
}

int IsFull()
{
    if(tumpuk.top == MAX_STACK) return 1; else return 0;
}

int IsEmpty()
{
    if(tumpuk.top == -1) return 1; else return 0;
}

void Push(char item[MAX_STACK])
{
    tumpuk.top++;
    strcpy(tumpuk.data[tumpuk.top],item);
}

void Pop()
{
    printf("Data yang terambil = %s\n", tumpuk.data[tumpuk.top]);
    tumpuk.top--;
}

void Clear()
{
    tumpuk.top = -1;
}

void TampilStack()
{
    for(int i=tumpuk.top; i>=0; i--)
    {
        printf ("Data Stack ke %d : %s\n", i, tumpuk.data[i]);
    }
}

//queue
 void Create()
{
antrian.head=antrian.tail=-1;
}

int isEmpty()
{  if(antrian.tail==-1)
    return 1;
    else
    return 0;
}

int isFull()
{ if(antrian.tail==MAX_QUEUE-1) return 1;
  else return 0;
}

void Enqueue(int data)
{if(isEmpty()==1)
  {antrian.head=antrian.tail=0;
   antrian.data[antrian.tail]=data;
   printf("%d masuk!",antrian.data[antrian.tail]);
   } else
  if(isFull()==0)
  {antrian.tail++;
   antrian.data[antrian.tail]=data;
   printf("%d masuk!",antrian.data[antrian.tail]);
  }
 }

 int Dequeue()
{
  int i;
  int e = antrian.data[antrian.head];
  for(i=antrian.head;i<=antrian.tail-1;i++)
  { antrian.data[i] = antrian.data[i+1]; }
  antrian.tail--;
  printf ("Data yang keluar : %d", e);
  return e;
    }


void clear()
{antrian.head=antrian.tail=-1;
printf("Data sudah dihapus");}

void Tampil()
{ if(isEmpty()==0)
  { for(int i=antrian.head;i<=antrian.tail;i++)
    { printf("Data ke %d = %d\n",i,antrian.data[i]);
     }
   }else printf("Data kosong!\n");
}

void menu2_queue()
{
    fflush(stdin);
   system ("Color F8");
   int pilihan;
   Create();
   int datainput;
   do{
          system ("cls");
          fflush (stdin);
          printf("1. Enqueue Int\n");
          printf("2. Dequeue Int\n");
          printf("3. Print Queue\n");
          printf("4. Delete Queue\n");
          printf("5. Return to Menu Utama\n");
          printf("Pilihan anda: ");
          scanf("%d",&pilihan);
          fflush (stdin);
          system ("cls");
          switch(pilihan)
          {
          case 1: if(isFull() != 1)
                    {
                        printf("Data yang ingin diinput = ");
                        scanf("%d",&datainput);
                        fflush (stdin);
                        Enqueue(datainput);
                    }
                   else printf("\nStack penuh\n");
                   printf ("\nPress any key to continue . . .");
                   getch ();
           break;
           case 2: if(isEmpty() != 1)
                        Dequeue();
                   else
                        printf("\nData yang keluar : 0\n");
                        printf ("\nPress any key to continue . . .");
                   getch ();
           break;
           case 3: if(isEmpty() != 1)
                        Tampil();
                   else
                        printf("Tidak ada data dalam antrian!\n");
                        printf ("Press any key to continue . . .");
                    getch ();
           break;
           case 4: clear();
                        printf ("\nPress any key to continue . . .");
                        getch ();
           break;
           case 5: main(); break;
           }

        }
        while(pilihan != 5);
}


void menu1_stack()
{
    fflush(stdin);
    system ("Color F8");
    system ("cls");
    int pil;
    char item[50];
    inisialisasi();
    do{
        system("cls");
        fflush (stdin);
        printf("1. Push Stack\n");
        printf("2. Pop Stack\n");
        printf("3. Print Stack\n");
        printf("4. Delete Stack\n");
        printf("5. Return Main Menu\n");
        printf("Pilihan anda: ");
        scanf ("%d", &pil);
        fflush (stdin);
        system("cls");
        switch (pil)
        {
            case 1 :
                if (IsFull()!= 1){
                printf ("Data yang ingin di input : "); scanf (" %[^\n]", &item);
                Push(item);
            }
            else
                printf("\nSudah penuh!\n");
                printf ("Press any key to continue . . .");
            break;
            case 2 :
                if (IsEmpty() != 1){
                    Pop();
            }
                    else
                        printf ("\nStack Masih Kosong!\n");
                        printf ("Press any key to continue . . .");
                    break;
            case 3 :
                if(IsEmpty() != 1){
                        TampilStack();
            }
                    else
                        printf ("\nMasih Kosong!\n");
                        printf ("Press any key to continue . . .");
                    break;

            case 4 :
                    Clear();
                        printf ("\nData Sudah Hapus!\n");
                        printf ("Press any key to continue . . .");
            break;
            case 5 : main(); break;

        }
        getch();

    }while (pil!=5);
}

void main()
{
    system ("Color F8");
    system ("cls");

    int position=1;
    int keyPressed=0;

    while(keyPressed != 13){
        system("cls");
        printf("\n\n");
        printf (" ============================\n");
        printf ("  Tugas Quiz Stack and Queue \n");
        printf (" ============================\n");

        arrowHere(1,position); printf ("\t1. Stack String\n");
        arrowHere(2,position); printf ("\t2. Queue Integer\n");
        arrowHere(3,position); printf ("\t3. Exit Program\n");
        printf (" ============================\n");

        keyPressed = getch();

        if (keyPressed == 80 && position != 5){
            position++;
        }
        else if (keyPressed == 72 && position != 1){
            position--;
        }
        else {
            position == position;
        }

    }
        switch (position){
            case 1 : menu1_stack();
                break;
            case 2 : menu2_queue();
                break;
            case 3 :
                system("cls");
                printf ("TERIMA KASIH");
                break;

        }

}

void arrowHere (int realPosition , int arrowPosition)
{
    if( realPosition == arrowPosition){
        printf (" ==>");
    }
    else{
        printf ("  ");
    }
}
