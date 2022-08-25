
#include <iostream>
#include "Song.h"
#include "string"

Song::Song() {}
void Song::setRadio(const std::string& tree) {
    radio=tree;
}
void Song::setNamesong(const std::string& songs) {
    name_song=songs;
}
void Song::setNameArtis(const Name& artis) {
    name_artist=artis;
}
void Song::setNameSinger(const Name& sin) {
    name_singer=sin;
}
void Song::setTemas(const int& theme) {
    temas=theme;
}
std::string Song::getRadio()const {
    return radio;
}
std::string Song::getNamesong()const {
    return name_song;
}
Name Song::getNameSinger()const {
    return name_singer;
}
Name Song::getNameArtis()const {
    return name_artist;
}
int Song::getTemas()const {
    return temas;
}
std::string Song::ToString()const {
    std::string z;
    z += " ";
    z += name_song;
    z += "\t ";
    z += name_artist.ToString();
    z += "\t ";
    z += name_singer.ToString();
    z += "\t ";
    z += std::to_string(getTemas());
    z += "\t ";
    z += radio;
    z += ".MP3";
    return z;
}
int Song::comparai(const Song& hi, const Song& ho) {
    return
    hi.name_singer.ToString().compare(ho.name_singer.ToString());
}
int Song::comparat(const Song& hi, const Song& ho) {
    return hi.name_song.compare(ho.name_song);
}
int Song::comparai(Song *hi, Song *ho) {
    return hi->name_singer.ToString().compare(ho->name_singer.ToString());
}
int Song::comparat(Song *hi, Song *ho) {
    return hi->name_song.compare(ho->name_song);
}

