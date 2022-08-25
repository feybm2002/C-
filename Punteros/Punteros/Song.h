#ifndef SONG_H_INCLUDED
#define SONG_H_INCLUDED
#include <iostream>
#include <string>
#include "Name.h"
class Song{
private:
    std::string radio;
    std::string name_song;
    Name name_artist;
    Name name_singer;
    int temas;
public:
    Song();
    void setRadio(const std::string&);
    void setNamesong(const std::string&);
    void setNameArtis(const Name&);
    void setNameSinger(const Name&);
    void setTemas(const int&);
    std::string getRadio()const;
    std::string getNamesong()const;
    Name getNameArtis()const;
    Name getNameSinger()const;
    int getTemas()const;
    std::string ToString()const;
    static int comparai(const Song& hi, const Song& ho);
    static int comparat(const Song& hi, const Song& ho);
    static int comparai(Song *hi, Song *ho);
    static int comparat(Song *hi, Song *ho);
};
#endif // SONG_H_INCLUDED
