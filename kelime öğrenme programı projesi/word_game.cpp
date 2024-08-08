#include <iostream>
#include "Word_class.cpp"
#include <string>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>


using namespace std;
// GÖRKEM LALE
// Başlama tarihi 30.04.2023 Saat 14.02 Bismillah :)

void animation(); // Girişte animasyon tarzı bir şeyler basıyor.
void choice(); // Programla ne yapmak istiyoruz. Rastgele mod mu? 10'lu mod mu?
int compare_answer_and_guess(Word,int); //Cevap ve tahmini bu fonksiyon sayesinde karşılaştırıyoruz.
void file_control(string); //Dosya var mı yok mu onu kontrol ediyor. Yoksa oluşturuyor.
	void game(int);// Programı başlatınca göreceğimiz 1 ve 2. modları oynatan kod.(Rastgele, onlu mod). 
		int line_calc(); // Dosyadaki satır sayısını çeviriyor. Bu sayede herhangi bir satırdaki kelimeyi sorabiliyoruz.
		string sentence_finder(fstream, int); // bir üstteki fonskiyonda çıkan satır sayısıyla mod alıp ürettiğimiz rastgele sayının bulunduğu satırdaki kelimeleri sormamızı sağlıyor.
		Word rando_m(int); // Bu fonksiyon sayesinde parcala() metoduyla da aldığımız satırı ingilizcec ve türkçe anlamlarına parçalıyoruz. Ve ilgili nesneyi döndürüyor. 
		void ekle(); // Önceki kelimeleri öğrendiniz mi? Sıkıcı mı olmaya başladı. Yeni kelimeler eklemeye ne dersiniz.
		//Not üstteki fonksiyonun açıklamasını yazarken neden kelime silme fonksiyonu yazmadım diye bir soru sordum kendime. Aslında puanlama sistemi de yapacaktım.
		//Fakat bu minnak projemi siz ile paylaşmanın heyacanına yenik düşüyorum. Umarım begenirsiniz.


//Word profil[10];
int main()
{
system("clear");
animation();
choice();

	return 0;
}

void animation()
{
	cout << "Word Game is starting." << endl;
	usleep(100000);
	system("clear");
	cout << "Word Game is starting.." << endl;
	usleep(100000);
	system("clear");
	cout << "Word Game is starting..." << endl;
	usleep(100000);
	system("clear");
	cout << "Word Game is starting...." << endl;
	usleep(100000);
	system("clear");
	cout << "Word Game is starting....." << endl;
	usleep(100000);
	system("clear");
	cout << "Word Game is starting......" << endl;
	usleep(100000);
	system("clear");
	cout << "Word Game is starting.....:" << endl;
	usleep(100000);
	system("clear");
	cout << "Word Game is starting....::" << endl;
	usleep(100000);
	system("clear");
	cout << "Word Game is starting...:::" << endl;
	usleep(100000);
	system("clear");
	cout << "Word Game is starting..::::" << endl;
	usleep(100000);
	system("clear");
	cout << "Word Game is starting.:::::" << endl;
	usleep(100000);
	system("clear");
	cout << "Word Game is starting::::::" << endl;
	usleep(100000);
	system("clear");
	cout << "Word Game is starting :::::" << endl;
	usleep(100000);
	system("clear");
	cout << "Word Game is starting  ::::" << endl;
	usleep(100000);
	system("clear");
	cout << "Word Game is starting   :::" << endl;
	usleep(100000);
	system("clear");
	cout << "Word Game is starting    ::" << endl;
	usleep(100000);
	system("clear");
	cout << "Word Game is starting     :" << endl;
	usleep(100000);
	system("clear");
	cout << "Word Game is starting   " << endl;
	
}

void file_control(string name_of_file)
{
	fstream dosya_ac;

	if(dosya_ac.is_open())
	{
		dosya_ac.open("word_note.txt", ios::out);
		
		if(dosya_ac.is_open())
		cout << "Dosya oluşturuldu" << endl;
		getchar();
		
		dosya_ac.close();
	}

}

void choice()
{
	int sec;
	main_menu:
	system("clear");
	cout << "Hoşgeldin :D" << endl 
	<<"Bir mod seç!" << endl
	<< "(1) Rastgele Mod"<< endl
	<< "(2) 10'lu Mod" << endl
	<< "(3) Kelime ekle" << endl
	<< "(0) Çık"<<endl<<">";
	secim:
	cin >> sec;	
	if(sec == 3)
	{
		ekle();
	}
	else if(sec == 0) exit(0);

	else if(sec == 1 || 2)
	{
	game(sec);
	}
	else
	{
		cout << "Lütfen geçerli bir değer giriniz.";
		system("clear");
		goto secim;
	}
	goto main_menu;


}
	int compare_answer_and_guess(Word w, int mod)
	{
		int devam, tekrar;
		string guess;
		tekrar:
		system("clear");
		
			cout << w.get_word_en()<<" kelimesinin anlamı nedir?"<<endl
			<<">";
			getline(cin, guess);

			if(w.is_it_true(guess))
				{	
					system("clear");
					cout << "Doğru tahmin :)"<<endl
					<<"(1) Devam et"<<endl<<"(0) Ana menüye dön"<< endl <<"(-1) Uygulamadan çık"<<endl;
					if(mod == 2)
					{
						cout << "(10) Yeni onluk"<<endl;
					}
					cout <<">";
					cin >> devam;
					getchar();
					//w = {"","",""};
					
						if(devam == 1)
						{
							system("clear");
							w.print_to_answers(guess,1);
							getchar();
							return 1;
						}
						//sıfır girince zaten fonksiyon sonlandığı için return oluyoruz ana menuye
						if(devam == -1) exit(0);
						if(devam == 10)
						{
							return 10;
						}
				}

				else
				{
					cout << "Maalesef yanlış tahmin :)"<<endl
					<<"Ama üzülme, istersen bir daha deneyebilirsin :)"<<endl
					<<"(1) Tekrar denemek için"<<endl<<"(2) Cevapları görmek için"<<endl<<">";
					cin >> tekrar;
					getchar();

						if(tekrar == 1)
							goto tekrar;
						else if(tekrar == 2)
						{
							system("clear");
							w.print_to_answers(guess,0);
							getchar();
							goto tekrar;
						}
					
				}
		return 0;
	}

			string sentence_finder(string name_of_file, int random)
			{
				fstream f_sentence;
				f_sentence.open(name_of_file, ios::in);
				string sentence;
				for(int i = 0; i < random+1; i++)
				{
					getline(f_sentence, sentence);
					//cout << sentence << " sentence: "<< i<<endl;
				}
				return sentence;
			}

	void game(int mod)
	{
		system("clear");
		string sentence;
		int devam = 0;
		int is_line_same[10];
			Word w;
		//cout << "game'in içindeyiz"<<endl;


		getchar();
		
		if(mod == 1)
		{
			devam1:
			w = rando_m(mod);
			devam =compare_answer_and_guess(w,mod);
			if(devam == 1)
			{
				goto devam1;
			}
			if(devam == 0)
			{
				return;
			}

		}


		if(mod == 2)
		{
			fstream decimal_file;
			decimal_file.open("decimal.txt", ios::in);
			devam2:
			rando_m(mod);
			devam3:
			for(int i = 0; i < 10; i++)
			{
				same_smasher:
				is_line_same[i] = (rand()%10);
					for(int j = 0; j < i; j++)
					{
						if(is_line_same[i] == is_line_same[j])
						{
							goto same_smasher;
						}
					}
			}
			string s1 = "decimal.txt";
			for(int i = 0; i < 10; i++)
			{
				sentence = sentence_finder(s1,is_line_same[i]);
				w.set_whole(sentence);				
				//cout <<w1.get_whole()<< endl;
				w.parcala();
				//cout << w1.get_word_en()<< "------------"<< w1.get_word_tr()<< endl;

				devam = compare_answer_and_guess(w,mod);
				
				if(devam == 1)
				{
					continue;
				}
				if(devam == 0)
				{
					return;
				}
				if(devam == 10)
				{
					goto devam2;
				}
			}



			goto devam3;
		}

			
		system("clear");
	}

		int line_calc()
		{
			int line = 0;
			string sline;

			fstream fline_calc;
			fline_calc.open("word_note.txt", ios::in);

			while(getline(fline_calc, sline))
			{
				line++;
			}
			fline_calc.close();
			return line;
		}

		Word rando_m(int mod)
		{
			fstream decim_al;
			Word w1;

			int is_line_same[10] = {0};
		
			int random = 0;
			srand(time(NULL));

			int line;
			line = line_calc();

			//cout <<endl<<endl<<"line = "<< line << endl;
			//getchar();
			
			string sentence;
			
			file_control("word_note.txt");
			fstream word_scanner;
			word_scanner.open("word_note.txt", ios::in);
			if(mod == 1)
			{
				random = (rand()%line);
				//cout << "random sayi = "<<random<<endl;
				
				sentence = sentence_finder("word_note.txt", random);
				w1.set_whole(sentence);				
				//cout <<w1.get_whole()<< endl;
				w1.parcala();
				//cout << w1.get_word_en()<< "------------"<< w1.get_word_tr()<< endl;				

			}
			if(mod == 2)
			{

				file_control("decimal.txt");
				decim_al.open("decimal.txt", ios::out);
				for(int i = 0; i < 10; i++)
				{
					same_smasher:
					is_line_same[i] = (rand()%line);
					for(int j = 0; j < i; j++)
					{
						if(is_line_same[i] == is_line_same[j])
						{
							goto same_smasher;
						}
					}
					sentence = sentence_finder("word_note.txt", is_line_same[i]);
					decim_al << sentence << endl;
				}
				decim_al.close();
				return w1;
			}
			

			word_scanner.close();
			return w1;	
		}

void ekle()
{
	system("clear");
	getchar();
	string ing, tur;

	fstream f_append;
	f_append.open("word_note.txt", ios::out | ios::app);

	cout <<"Eklemek istediğiniz kelimenin önce ingilizcesini sonra da istediğiniz kadar türkçe anlamını girebilirsiniz :)"
	<<endl<<"Devam etmek için ENTER"<<endl<<">";
	getchar();

	system("clear");

	cout << "Eklemek istediğiniz ingilizce kelime nedir?"<<endl<<">";

	getline(cin, ing);

	f_append << endl << ing<<"=";

	int turkce_eklemeye_devam, i = 1;
	while(turkce_eklemeye_devam)
	{
		system("clear");
		cout << "Eklemek istediğiniz "<<i<<". anlamı girin."<< endl <<">";
		getline(cin, tur);

		f_append << tur;

		cout << "(1) Eklemeye devam et"<<endl<<"(0) Ana menüye dön"<<endl<<"(-1) Uygulamadan çık"<<endl<<">";
		cin >> turkce_eklemeye_devam;
		getchar();
		
		if(turkce_eklemeye_devam == 0)
		{
			return;
		}

		if(turkce_eklemeye_devam == -1) exit(-1);

		if(turkce_eklemeye_devam == 1)
		{
			f_append << ",";
			i++;
			continue;
		}
	}



}