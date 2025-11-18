#include <iostream>
using namespace std;

struct Spaceship_Data
{
    string name;
    int healthpoints = 100;
    int crew_count;
    int persen_bensin;
    int hull_integrity;
};
int bensinDipakai = 0;
int tambahanHull = 0;
int crewMati = 0;

void InputDataSpaceship(Spaceship_Data data[], int N);
void DataSpaceship(Spaceship_Data data[], int N);
void IsiUlangBensin(Spaceship_Data data[], int N);
void PerbaikiKapal(Spaceship_Data data[], int N);
void MulaiMisi(Spaceship_Data data[], int N);
void RekapMisi(Spaceship_Data data[], int N);

int main()
{
    int N;
    int pilihan;
    cout << "===== SPACESHIP SYSTEM =====" << endl;
    cout << "Berapa jumlah Spaceship : ";
    cin >> N;

    Spaceship_Data data[100];

    InputDataSpaceship(data, N);

    do
    {
        DataSpaceship(data, N);
        cout << endl;
        cout << "=====SPACESHIP SYSTEM=====\n";
        cout << "1. Mulai misi\n";
        cout << "2. Isi ulang bensin\n";
        cout << "3. Perbaiki Kapal\n";
        cout << "4. Liat rekap misi\n";
        cout << "5. Exit\n";
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            MulaiMisi(data, N);
            break;

        case 2:
            IsiUlangBensin(data, N);
            break;

        case 3:
            PerbaikiKapal(data, N);
            break;

        case 4:
            RekapMisi(data, N);
            break;

        case 5:
            cout << "Program selesai\n";
            break;

        default:
            cout << "Pilihan tidak valid\n";
            break;
        };
    } while (pilihan != 5);
    return 0;
};

void InputDataSpaceship(Spaceship_Data data[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Spaceship " << i + 1 << endl;
        cin.ignore();
        cout << "Isi nama : ";
        getline(cin, data[i].name);
        cout << "Isi jumlah crew : ";
        cin >> data[i].crew_count;
        cout << "Isi jumlah bensin (%) : ";
        cin >> data[i].persen_bensin;
        cout << "Isi daya tahan kapal (%) : ";
        cin >> data[i].hull_integrity;
    };
    cout << endl;
};

void DataSpaceship(Spaceship_Data data[], int N)
{
    cout << "\n====Status Fleet====\n";
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << ". "
             << data[i].name << " | " << "Health kapal : "
             << data[i].healthpoints << "%" << " | " << "Crew : "
             << data[i].crew_count << " | " << "Bensin : "
             << data[i].persen_bensin << "%" << " | " << "Hull : "
             << data[i].hull_integrity << "%" << endl;
    };
};

void IsiUlangBensin(Spaceship_Data data[], int N)
{
    string cariNama;
    int tambahanbensin;
    bool ditemukan = false;

    cin.ignore();
    cout << "Nama kapal yang ingin diisi ulang : ";
    getline(cin, cariNama);

    for (int i = 0; i < N; i++)
    {
        if (data[i].name == cariNama)
        {
            cout << "Jumlah bensin yang ingin ditambahkan : ";
            cin >> tambahanbensin;

            data[i].persen_bensin += tambahanbensin;
            if (data[i].persen_bensin > 100)
                data[i].persen_bensin = 100;

            cout << "Bensin berhasil ditambahkan!\n";
            cout << "Sekarang bensin untuk " << data[i].name << " adalah " << data[i].persen_bensin << "%" << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
    {
        cout << "Tidak ada kapal dengan nama " << cariNama << endl;
    }
}

void PerbaikiKapal(Spaceship_Data data[], int N)
{
    string cariNama;
    int Pilihan;
    bool ditemukan = false;

    cin.ignore();
    cout << "Nama kapal yang ingin diperbaiki : ";
    getline(cin, cariNama);
    for (int i = 0; i < N; i++)
    {
        if (cariNama == data[i].name)
        {
            cout << "=====ITEM=====\n";
            cout << "1. Palu (+10%)\n";
            cout << "2. Drill (+30%)\n";
            cout << "3. Robot (+100%)\n";
            cout << "Nomor item yang ingin digunakan : ";
            cin >> Pilihan;

            switch (Pilihan)
            {
            case 1:
                data[i].hull_integrity += 10;
                tambahanHull += 10;
                break;

            case 2:
                data[i].hull_integrity += 30;
                tambahanHull += 30;
                break;

            case 3:
                data[i].hull_integrity += 100;
                tambahanHull += 100;
                break;

            default:
                cout << "Item tidak valid!\n";
                return;
            }

            if (data[i].hull_integrity > 100)
                data[i].hull_integrity = 100;

            cout << "Perbaikan berhasil!\n";
            cout << "Daya tahan kapal " << data[i].name << " sekarang adalah " << data[i].hull_integrity << "%" << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
    {
        cout << "Tidak ada kapal dengan nama " << cariNama << endl;
    }
}

void MulaiMisi(Spaceship_Data data[], int N)
{
    int PilihanMisi, planet;
    string cariNama;
    bool ditemukan = false;
    cin.ignore();
    cout << "Pilih nama kapal yang akan digunakan : ";
    getline(cin, cariNama);

    for (int i = 0; i < N; i++)
    {
        if (cariNama == data[i].name)
        {
            ditemukan = true;

            if (data[i].persen_bensin < 30)
            {
                cout << "Bensin anda minimal 30% untuk memulai misi!\n";
                return;
            }

            cout << "\n===== PILIH PLANET TUJUAN =====\n";
            cout << "1. Tessara IV - Planet Spora\n";
            cout << "2. Virellon IX - Gurun Kristal\n";
            cout << "3. Otrion Prime - Dunia Es Abadi\n";
            cout << "4. Zephyra Delta - Inti Badai Plasma\n";
            cout << "Pilihan Planet : ";
            cin >> planet;
            cout << endl;

            switch (planet)
            {
            case 1:
                cout << "Anda tiba di Tessara IV, planet dipenuhi jamur bercahaya.\n";
                cout << "Bensin terpakai 50%.\n";
                data[i].persen_bensin -= 50;
                bensinDipakai += 50;
                cout << "Anda bertemu Boss: Vaelora, Ratu Spora!\n";
                break;

            case 2:
                cout << "Anda tiba di Virellon IX, gurun luas dengan badai kristal.\n";
                cout << "Bensin terpakai 40%.\n";
                data[i].persen_bensin -= 40;
                bensinDipakai += 40;
                cout << "Anda bertemu Boss: Karthor, Titan Kristal!\n";
                break;

            case 3:
                cout << "Anda tiba di Otrion Prime, planet beku bersalju.\n";
                cout << "Bensin terpakai 35%.\n";
                data[i].persen_bensin -= 35;
                bensinDipakai += 35;
                cout << "Anda bertemu Boss: Freyl, Penjaga Es Abadi!\n";
                break;

            case 4:
                cout << "Anda tiba di Zephyra Delta, badai plasma menyelimuti langit.\n";
                cout << "Bensin terpakai 60%.\n";
                data[i].persen_bensin -= 60;
                bensinDipakai += 60;
                cout << "Boss terakhir: Solaris, Penguasa Petir Plasma!\n";
                break;

            default:
                cout << "Planet tidak valid.\n";
                return;
            }

            cout << "\nApa yang ingin anda lakukan?\n";
            cout << "1. Lawan Boss (-20 crew, -25 HP)\n";
            cout << "2. Lari\n";
            cout << "Pilihan : ";
            cin >> PilihanMisi;

            switch (PilihanMisi)
            {
            case 1:
                cout << "Pertarungan hebat terjadi...\n";
                cout << "Anda berhasil mengalahkan boss!\n";
                data[i].crew_count -= 20;
                data[i].healthpoints -= 25;
                crewMati += 20;
                break;

            case 2:
                cout << "Anda berhasil kabur dengan aman.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
                break;
            }

            if (data[i].persen_bensin < 0)
                data[i].persen_bensin = 0;
            if (data[i].crew_count < 0)
                data[i].crew_count = 0;
            if (data[i].healthpoints < 0)
                data[i].healthpoints = 0;
            if (data[i].hull_integrity < 0)
                data[i].hull_integrity = 0;

            cout << "\nAnda kembali dari misi!\n";
            cout << "=====Status terbaru kapal=====\n";
            cout << data[i].name << " | Health: " << data[i].healthpoints
                 << "% | Crew: " << data[i].crew_count
                 << " | Bensin: " << data[i].persen_bensin
                 << "% | Hull: " << data[i].hull_integrity << "%" << endl;
            break;
        }
    }

    if (!ditemukan)
    {
        cout << "Nama kapal tidak ditemukan\n";
    }
}

void RekapMisi(Spaceship_Data data[], int N)
{
    cout << "\n===== REKAP MISI =====\n";
    cout << "Total bensin terpakai : " << bensinDipakai << "%\n";
    cout << "Total crew yang gugur : " << crewMati << " orang\n";
    cout << "Total perbaikan hull : +" << tambahanHull << "%\n";

    cout << "\n===== STATUS SETIAP KAPAL =====\n";
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << ". " << data[i].name << endl;
        cout << "   - Crew tersisa      : " << data[i].crew_count << endl;
        cout << "   - Bensin tersisa    : " << data[i].persen_bensin << "%" << endl;
        cout << "   - Hull integrity    : " << data[i].hull_integrity << "%" << endl;
        cout << "   - Health points     : " << data[i].healthpoints << "%" << endl;
        cout << endl;
    }

    cout << "=============================\n";
}