#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class Word
{
private:
	string whole;//tüm satırı alıyor. Sonrasında da parcala() fonksiyonuyla türkçe kelimeleri buradan çekiyoruz(bkz erase)
	string word_en;//kelimenin ingilizce kısmı
	string word_tr[10];//kelimenin tüm türkçe anlamları
	unsigned int tr_muhtemel_sayi = 0; //türkçe kelimeler arasındaki virgül sayısını hesaplayıp bir fazlasıyla kelime sayısını taşıyan değişken
	unsigned int line = 0; // satır sayısı(bunu kullandım mı onu dahi hatırlamıyorum :) )
public:
	//Constructors
	Word(){};
	Word(string);
	Word(string,string);
	Word(string,string,string);

	// setter functions
    void set_whole(string);
    void set_word_en(string);
    void set_word_tr(string[10]);
    void set_tr_muhtemel_sayi(int);
    void set_line(int);

    //getter functions
	string get_whole();
	string get_word_en();
	string get_word_tr();
    unsigned int get_tr_muhtemel_sayi();
    unsigned int get_line();

    bool is_it_true(string);    //tahmin ve muhtemel tüm türkçe anlamları karşılaştırıp mantıksal cevap döndüren metod
    void parcala();				//satırın hepsini ingilizce ve tüm türkçe anlamlara parçalayan metod
    void print_to_answers(string,int);	//doğru veya yanlış bilince ingilizce kelimenin tüm türkçe anlamlarını basan metod.
    //not 39. satırdaki metod doğru yanıt verdiğimiz zaman kullanıcının diğer anlamları da öğrenmesi için bir kere çalışır.
    // Ve verdiğimiz yanıtı büyük harfle basar. Yanlış yanıtta çalışınca böyle bir şey söz konusu değildir.
    //bu fonskiyonda bir şeyde çok zorlandım. Türkçe karakterleri toupper ile büyütemiyorum. sadece i, I oluyor. onun dışında harfi değiştiremiyor. :) Ben de boş verdim.

};