#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

struct node
{
    char no[5],nama[50],posisi[20];
    struct node *next;
}*front=NULL,*rear,*temp;

void Enqueue()
{
    temp=new node;
    cout<<"Masukkan Data pemain sepak bola"<<endl;
    cout<<"No punggung : ";fflush(stdin);gets(temp->no);
    cout<<"Nama        : ";gets(temp->nama);
    cout<<"Posisi      : ";gets(temp->posisi);
    temp->next=NULL;
    if(front==NULL){
        front=rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
    system("cls");
}

void Dequeue()
{
    if(front==NULL)
    {
        cout<<"Antrian masih kosong\n\n";
        system("pause");
        system("cls");
    }
    else
    {
        temp=front;
        front=front->next;
        delete(temp);
        cout<<"Dequeue SUKSES!!"<<endl<<endl;
        system("pause");
        system("cls");
    }
}

void Tampil()
{
    if(front==NULL)
    {
        cout<<"Tidak ada antrian\n\n";
        system("pause");
        system("cls");
    }
    else
    {
        temp=front;
            cout<<"          ISI ANTRIAN"<<endl;
            cout<<"-------------------------------"<<endl;
        while(temp!=NULL)
        {
            cout<<temp->no<<" -> "<<temp->nama<<" -> "<<temp->posisi<<endl;
            temp=temp->next;
        }
        cout<<endl;
        system("pause");
        system("cls");
    }
}

int main()
{
    int pilih;
    do
    {
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Tampil"<<endl;
        cout<<"4. Exit"<<endl<<endl;
        cout<<"PILIH(1-4): ";
        cin>>pilih;
        cout<<endl;
        switch(pilih)
        {
            case 1:
                Enqueue();
            break;
            case 2:
                Dequeue();
            break;
            case 3:
                Tampil();
            break;
            case 4:
                exit(0);
            break;
            default:
            cout<<"SALAHHHH!!!!"<<endl;
            system("pause");
            system("cls");
            break;
        }
    }while(pilih!=4);

    return 0;
}
