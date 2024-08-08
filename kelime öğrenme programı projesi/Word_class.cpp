#include <iostream>
#include "Word_class.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <clocale>


using namespace std;

//////////////////////////////////////////////////////

    Word::Word(string whole)
    {
        this->whole = whole;
    }
    Word::Word(string whole,string word_en)
    {
        this->whole = whole;
        this->word_en = word_en;
    }
    Word::Word(string whole,string word_en,string word_tr)
    {
        this->whole = whole;
        this->word_en = word_en;
        this->word_tr[0] = word_tr[0];
    }

//////////////////////////////////////////////////////

    void Word::set_whole(string whole)
    {
        this->whole = whole;
        //cout << "whole kuruldu.";
    }
    void Word::set_word_en(string word_en)
    {
        this->word_en = word_en;
    }
    void Word::set_word_tr(string word_tr[10])
    {
        for(int i = 0; i < tr_muhtemel_sayi; i++)
        {
            this->word_tr[i] = word_tr[i];    
        }
    }
    void Word::set_tr_muhtemel_sayi(int tr_muhtemel_sayi)
    {
        this->tr_muhtemel_sayi = tr_muhtemel_sayi;           
    }
    void Word::set_line(int line)
    {
        this->line = line;
    }

///////////////////////////////////////////////////////

	string Word::get_whole()
    {
        return whole;
    }
	string Word::get_word_en()
    {
        return word_en;        
    }
	string Word::get_word_tr()
    {
        int r;
        srand(time(NULL));
        r = rand()%get_line();
        return word_tr[r];        
    }
    unsigned int Word::get_tr_muhtemel_sayi()
    {
        return tr_muhtemel_sayi;        
    }
    unsigned int Word::get_line()
    {
        return line;
    }

/////////////////////////////////////////////////////
   
    bool Word::is_it_true(string guess)
    {
        for(int i = 0; i < get_tr_muhtemel_sayi(); i++)
        {
            if(word_tr[i] == guess)
            {
                return true;
            }
        }
        return false;
    }

    void Word::parcala()
    {
        set_tr_muhtemel_sayi(0);

        string en, tr;
        int virgul_indis[10] = {0};

        //cout <<endl<< "PARÇALANIN İÇİNDEKİ whole = "<<get_whole()<<endl;
        //cout << "uzunluğu: "<< whole.length()<<endl;

        //cout <<"tüm boyut = "<< whole.length()<<endl;
        //getchar();

        for(int i = 0; i < whole.length(); i++)//sanki bu haliyle coderunner'da çalışmaz.
        {
            if(whole.at(i) == '=')
            {
                set_word_en(whole.substr(0, i));
                set_whole(whole.substr(i+1, whole.length()-1));// eşitleme ile de yapabilirdik ör/  word_tr = ... gibi
                //cout << get_whole()<<endl;
                //getchar();
            }

            
        }
        for(int i = 0; i < whole.length(); i++)
        {
            if(whole.at(i) == ',')
            {
                word_tr[tr_muhtemel_sayi] = whole.substr(0,i);
                tr_muhtemel_sayi++;
                whole.erase(0,i+1);
                i = 0;
                //getchar();
            }
        }
        word_tr[tr_muhtemel_sayi] = whole;

        tr_muhtemel_sayi++;

        //cout <<"tüm boyut = "<< whole.length()<<"muhtemel = "<<get_tr_muhtemel_sayi() <<endl;
        //getchar();
  



    }

    void Word::print_to_answers(string guess, int true_or_false)
    {
        cout << get_word_en() << "'in Cevapları:"<<endl;
        for(int i = 0; i < get_tr_muhtemel_sayi(); i++)
        {
            cout << i+1 << ") ";
            if(true_or_false = 1)
            {
                if(word_tr[i] == guess)
                {
                    for(int j = 0; j < guess.length(); j++)
                    {
                        guess[j] = toupper(guess[j]);
                        //cout << guess[j];
                        //cout << (int)guess[j];
                        
                        //getchar();
                    }

                    cout << guess<<" (senin yanıtın)"<<endl;
                    continue;
                }
                else
                {
                    word_tr[i][0] = toupper(word_tr[i][0]);
                }
            }
            cout << word_tr[i]<<endl;
        }
    }
    /*

*/