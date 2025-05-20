//Tasyakur Maulana Istna
//124240053
#include <iostream>
using namespace std;

struct Pesanan {
    string nama;
    string jenisRoti;
    int totalHarga;
};

struct nodeQueue {
    Pesanan info;
    nodeQueue *next;
};

nodeQueue *depan, *belakang;

void buatQueue() {
    depan = NULL;
    belakang = NULL;
}

bool queueKosong() {
    return depan == NULL;
}

void enqueue(Pesanan IB) {
    nodeQueue *NB = new nodeQueue;
    NB->info = IB;
    NB->next = NULL;

    if (queueKosong()) {
        depan = NB;
    } else {
        belakang->next = NB;
    }
    belakang = NB;
    cout << "Pesanan " << IB.nama << " dimasukkan ke antrean.\n";
}

Pesanan dequeue() {
    if (queueKosong()) {
        cout << "Antrean kosong.\n";
        return {};
    } else {
        nodeQueue *hapus = depan;
        Pesanan p = hapus->info;
        depan = depan->next;
        if (depan == NULL) belakang = NULL;
        delete hapus;
        return p;
    }
}

void tampilQueue() {
    nodeQueue *bantu = depan;
    if (queueKosong()) {
        cout << "Antrean kosong.\n";
        return;
    }
    int i = 1;
    cout << "\nDaftar Antrean:\n";
    while (bantu != NULL) {
        cout << "\n===============================\n";
        cout << "Antrean ke-" << i++ << endl;
        cout << "-------------------------------\n";
        cout << "Nama        :" << bantu->info.nama << endl;
        cout << "Jenis Roti  :" << bantu->info.jenisRoti << endl;
        cout << "Total Harga :" << bantu->info.totalHarga;
        bantu = bantu->next;
    }
    cout << "\n===============================\n";

}

struct nodeStack {
    Pesanan info;
    nodeStack *next;
};

nodeStack *awal, *top;

void buatStack() {
    awal = top = NULL;
}

bool stackKosong() {
    return awal == NULL;
}

void push(Pesanan IB) {
    nodeStack *newnode = new nodeStack();
    newnode->info = IB;
    newnode->next = NULL;
    if (stackKosong()) {
        awal = top = newnode;
    } else {
        top->next = newnode;
        top = newnode;
    }
}

void pop() {
    if (stackKosong()) {
        cout << "kosong kocak\n";
        return;
    } else {
        nodeStack *bantu = awal;
        while (bantu->next != top) bantu = bantu->next;
        nodeStack *hapus = top;
        bantu->next = NULL;
        top = bantu;
        delete hapus;
    }
}

void ambilantrean() {
    Pesanan p;
    cout << "Nama pelanggan: ";
    getline(cin, p.nama);
    cout << "Jenis roti: ";
    getline(cin, p.jenisRoti);
    cout << "Total harga: ";
    cin >> p.totalHarga;
    cin.ignore();
    enqueue(p);
}

void layanipembeli() {
    if (queueKosong()) {
        cout << "Antrean kosong.\n";
    } else {
        Pesanan p = dequeue();
        push(p);
        cout << "Melayani pesanan dari " << p.nama << endl;
    }
}

void tampilStack() {
    nodeStack *bantu = awal;
    if (stackKosong()) {
        cout << "Belum ada pesanan yang dilayani.\n";
        return;
    }
    int i = 1;
    cout << "\nRiwayat Pesanan Dilayani:";
    while (bantu != NULL) {
        cout << "\n===============================\n";
        cout << "Riwayat Pesanan ke-" << i++ << endl;
        cout << "-------------------------------\n";
        cout << "Nama        :" << bantu->info.nama << endl;
        cout << "Jenis Roti  :" << bantu->info.jenisRoti << endl;
        cout << "Total Harga :" << bantu->info.totalHarga;
        bantu = bantu->next;
    }
    cout << "\n===============================\n";
}

void batalkanPesanan() {
    if (queueKosong()) {
        cout << "Tidak ada pesanan untuk dibatalkan.\n";
        return;
    }
    cout << "Pesanan terakhir : " << belakang->info.nama << endl;
    char konfirmasi;
    cout << "Apakah Anda yakin ingin membatalkan pesanan ini? (y/n) : ";
    cin >> konfirmasi; 
    cin.ignore();
    if (konfirmasi != 'y' && konfirmasi != 'Y') {
        cout << ">>> Pembatalan dibatalkan oleh pengguna.";
        return;
    }
    if (depan == belakang) {
        cout << "Pesanan dari " << depan->info.nama << " dibatalkan.\n";
        delete depan;
        depan = belakang = NULL;
        return;
    }

    nodeQueue *bantu = depan;
    while (bantu->next != belakang) {
        bantu = bantu->next;
    }
    cout << "Pesanan dari " << belakang->info.nama << " dibatalkan.\n";
    delete belakang;
    belakang = bantu;
    belakang->next = NULL;
}

int main() {
    buatQueue();
    buatStack();
    int pilihan;
    do {
        cout << "\n====================================================\n";
        cout << "        Sistem Antrean Toko Roti 'Maul Manis'        \n";
        cout << "====================================================\n";
        cout << "1. Ambil Antrean\n";
        cout << "2. Layani Pembeli\n";
        cout << "3. Tampilkan Antrean\n";
        cout << "4. Batalkan Pesanan Terakhir\n";
        cout << "5. Tampilkan Riwayat Pesanan\n";
        cout << "6. Keluar\n";
        cout << "----------------------------------------------------\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1:
                ambilantrean();
                break;
            case 2:
                layanipembeli();
                break;
            case 3:
                tampilQueue();
                break;
            case 4:
                batalkanPesanan();
                break;
            case 5:
                tampilStack();
                break;
            case 6:
                cout << "Terima kasih, program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 6);

    return 0;
}
