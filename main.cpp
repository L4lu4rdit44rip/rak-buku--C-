#include <iostream>
#include <fstream>
using namespace std;

int pilihan;
int peminjamanbuku(int jumlah);
int peminjam(int staatus);
int peminjam(string status);
fstream file;
fstream filee;
string idp,pilih,transaksi,buku;
int i=0;
    string Tabel[1][14] {{"Pogstdi","Jan","Feb","Mar","Apr","Mei","Jun","Jul","Ags","Sep","Oct","Nov","Dec","Total"}};
    int Mahasiswa[5][14]{{101219, 2,  6,  7,  2,  3,  5,  4,  5,  4,  5,  2,  1,  46},
                         {103219, 3,  2,  4,  5,  1,  2,  4,  7,  5,  3,  4,  2,  42},
                         {102219, 5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  60},
                         {105219, 10, 15, 45, 23, 54, 34, 67, 88, 95, 78, 23, 32, 564}};
    string total[1][14]{{"Total ", "20", "28", "61", "35", "63", "46", "80", "105", "109", "91", "34", "40", "  "}};



int main()
{
    int pilihmenu;

    cout<<"Apa yang ingin anda lakukan?\n1.Input buku\n2.Pinjam buku\n3.Hapus buku\n4.Tampilkan buku yang dipinjam oleh peminjam\n5.Tampilkan buku yang ada\n6.Tampilkan semua data buku\n pilihan :";cin>>pilihmenu;//
    string IDpeminjam;

    file.open("transaksibuku.txt");
    int qi=0;
    while( qi<14)
    {
        file<<Tabel[0][qi]<<" ";
        cout<<Tabel[0][qi]<<" ";
        qi++;
    }
    cout<<endl;
    for(i=0;i<4;i++){
            cout<<endl;
        for(int ji=0;ji<14;ji++){
            file<<Mahasiswa[i][ji]<<"   ";
            cout<<Mahasiswa[i][ji]<<"   ";}
            }
            cout<<endl;
    for(int po=0;po<14;po++){
            cout<<total[0][po]<<"   ";}


    file.close();
    string buku,nseribuku,idpmnjm,bulan,status,judulbuku;
    int tanggalkmbali,tangglpinjam,tnglpngmblian;
    int i=0;


    if(pilihmenu==1)
{    cout<< "Seri\tJudul \tStatus\n";
    file.open("buku.txt");
    while (!file.eof()){
            getline (file,buku);
            cout<<buku<<endl;}
    file.close();
    //input buku//

    int q;
    cout<<"Masukkan input buku :";cin>>q;

    while(q>0){
    cout<<"----------------DATA BUKU---------------- \n";
    cout<<"Nomor Seri buku  :";cin>>nseribuku;
    cout<<"judul buku       :";cin>>judulbuku;
    cout<<"Status           :";cin>>status;
    file.open("buku.txt",ios::app);
    file<<nseribuku<<"\t"<<judulbuku<<"\t"<<status<<"\n";
    file.close();
    q--;}
    cout<<endl;cout<<endl;
    cout<<endl;cout<<endl;


    ////

    cout<< "==========BUKU==========="<<endl;
    cout<< "No.Seri \t Judul \t Status \n";
    file.open("buku.txt");
    while (!file.eof()){
            getline (file,buku);
            cout<<buku<<endl;}
    file.close();

    cout<<endl;
    filee.open("transaksi.txt",ios::app);
    filee.close();
}
    else if(pilihmenu==2)
{

    filee.open("transaksi.txt",ios::app);
    cout<<"----------Peminjaman BUKU----------"<<endl;
    cout<<"Nomor seri buku  :";cin>>nseribuku;
    cout<<"ID Peminjam      :";cin>>idpmnjm;
    cout<<"Tanggal          :";cin>>tangglpinjam;

    if(tangglpinjam<28)
    {
        tanggalkmbali=tangglpinjam+3;
        cout<<"tanggal kembali pada tanggal :"<<tanggalkmbali;
    }
    else
    {
        tanggalkmbali=tangglpinjam-30;
        cout<<"tanggal kembali pada tanggal :"<<tanggalkmbali<<" pada bulan berikutnya";
    }

    filee<<nseribuku<<"\t"<<idpmnjm<<"\t"<<tangglpinjam<<"\t"<<tanggalkmbali<<"\n";
    filee.close();


    string nomorseri[100];
    string jdlbuku[100];
    string stats[100];
    char huruf[100];
    file.open("buku.txt");
    file.ignore(1000,'\n');
    while (!file.eof())
    {
        file.getline(huruf,100,'\t');
        nomorseri[i]=huruf;
        file.getline(huruf,100,'\t');
        jdlbuku[i]=huruf;
        file.getline(huruf,100,'\n');
        stats[i]=huruf;
        ++i;

    }
    for(int m=0;m<i; m++){
        nomorseri[m];
    }
    for(int u=0; u<i; u++){
        jdlbuku[u];
    }
    for(int s=0; s<i; s++){
        stats[s];
    }

    cout<<endl;;cout<<endl;
    //Pinjam buku//


    cout<<"Buku dengan nomor seri buku yang akan dipinjam  :"<<nseribuku;

    file.open("buku.txt");
    for(int a=0;a<i;a++)
    {
        if(nomorseri[a]== nseribuku)
        {
            stats[a]="dipinjam";
            cout<<endl;cout<<endl;
            cout<< "=================BUKU====================\n";
            cout<< "No.Seri\tJudul\tStatus\n";
                  for (int h=0; h<i; h++){
                file<<nomorseri[h]<<"\t"<<jdlbuku[h]<<"\t"<<stats[h]<<"\n";
                cout<<nomorseri[h]<<"\t"<<jdlbuku[h]<<"\t"<<stats[h]<<"\n";
                file.close();
                }
        }
    }
}
     //Hapus Buku//

else if (pilihmenu==3)
{
        string nomorseri[100];
    string jdlbuku[100];
    string stats[100];
    char huruf[100];
    file.open("buku.txt");
    file.ignore(1000,'\n');
    while (!file.eof())
    {
        file.getline(huruf,100,'\t');
        nomorseri[i]=huruf;
        file.getline(huruf,100,'\t');
        jdlbuku[i]=huruf;
        file.getline(huruf,100,'\n');
        stats[i]=huruf;
        ++i;

    }
    for(int m=0;m<i; m++){
        nomorseri[m];
    }
    for(int u=0; u<i; u++){
        jdlbuku[u];
    }
    for(int s=0; s<i; s++){
        stats[s];
    }
    cout<< "Masukkan Nomor Seri Buku yang akan di hapus = ";cin>>huruf;
    file.open("buku.txt");
    for(int b=0; b<i; b++)
    {
        if( nomorseri[b]== huruf)
            {
             cout<< "Buku dengan No.seri buku "<<huruf<<"\t(akan di hapus)";
             nomorseri[b]="-";
             jdlbuku[b]="-";
             stats[b]="-";
             cout<<endl;cout<<endl;
             cout<< "=================BUKU====================\n";
             cout<< "No.Seri\tJudul\tStatus\n";
             for( int l=0; l<i; l++){
                file<<nomorseri[l]<<"\t"<<jdlbuku[l]<<"\t"<<stats[l]<<"\n";
                cout<<nomorseri[l]<<"\t"<<jdlbuku[l]<<"\t"<<stats[l]<<"\n";
                }
            }

    }
    file.close();
}
else if(pilihmenu==4)
{
    int jumlah,staatus;
    filee.open("transaksi.txt");
    cout<<"nseri\tidpmnjm\tpinjam\tkembali\n";
    while (!filee.eof()){
            getline (filee,transaksi);
            cout<<transaksi<<endl;}
    filee.close();
    //Jumlah peminjam buku//
    cout<<"masukkan ID :";cin>>idp;
    cout<<"maka banyak buku yang dipinjam sebanyak :"<<peminjamanbuku(jumlah)<<endl;

}
else if(pilihmenu==5)
{
    int staatus,pilih;

    filee.open("transaksi.txt");
    cout<<"nseri\tidpmnjm\tpinjam\tkembali\n";
    while (!filee.eof()){
            getline (filee,transaksi);
            cout<<transaksi<<endl;}
    filee.close();
    cout<<"Masukkan info yang dinginkan :\n1.available\n2.dipinjam\n Masukkan pilihan :";cin>>pilih;
    cout<<"banyak buku yang ada :"<<peminjam(staatus);
}


    else if(pilihan==6)
{
    string Tabel[1][14]{{"PrD\t","Jan","Feb","Mar","Apr","Mei","Jun","Jul","Ags","Sep","Oct","Nov","Dec","Total"}};
    file.open("transaksibuku.txt",ios::app);
    int qi=0;
    while( qi<14)
    {
        file<<Tabel[0][qi]<<" ";
        //cout<<Tabel[0][qi]<<" ";//
        qi++;
    }
    file.close();

}

}
int peminjamanbuku(int jumlah)
{
    string seri[100];
    string id[100];
    string pinjam[100];
    string kembali[100];
    char huruf[100];
    filee.open("transaksi.txt");
    filee.ignore(1000,'\n');
    while (!filee.eof())
    {
        filee.getline(huruf,100,'\t');
        seri[i]=huruf;
        filee.getline(huruf,100,'\t');
        id[i]=huruf;
        filee.getline(huruf,100,'\t');
        pinjam[i]=huruf;
        filee.getline(huruf,100,'\n');
        kembali[i]=huruf;
        ++i;
    }
    for(int q=0;q<10;q++)
    {
        jumlah=0;
        for(int w=0;w<i;w++)
        {
            if(idp == id[w])
                jumlah++;
        }
    }
    return jumlah;

}

int peminjam(int staatus)
{
    string nomorseri[100];
    string jdlbuku[100];
    string stats[100];
    char huruf[100];
    file.open("buku.txt");
    file.ignore(1000,'\n');
    while (!file.eof())
    {
        file.getline(huruf,100,'\t');
        nomorseri[i]=huruf;
        file.getline(huruf,1000,'\t');
        jdlbuku[i]=huruf;
        file.getline(huruf,100,'\n');
        stats[i]=huruf;
        ++i;

    for(int k=0;k<10;k++)
    {
        staatus=0;
        for(int y=0;y<i;y++)
        {
            if(pilih==stats[y])
                staatus++;
        }
    }
    return staatus;
}

}



