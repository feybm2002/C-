#include <iostream>
#include "Cancion.h"
#include "string"
Cancion::Cancion() {}
void Cancion::setRadio(const std::string& tree) {
    radio=tree;
}
void Cancion::setNamesong(const std::string& songs) {
    name_song=songs;
}
void Cancion::setNombreartis(const Nombre& artis) {
    nombre_artista=artis;
}
void Cancion::setNombrecanta(const Nombre& can) {
    nombre_cantante=can;
}
void Cancion::setTemas(const int& theme) {
    temas=theme;
}
std::string Cancion::getRadio()const {
    return radio;
}
std::string Cancion::getNamesong()const {
    return name_song;
}
Nombre Cancion::getNombreartis()const {
    return nombre_artista;
}
Nombre Cancion::getNombrecanta()const {
    return nombre_cantante;
}
int Cancion::getTemas()const {
    return temas;
}
std::string Cancion::ToString()const {
    std::string z;
    z += " ";
    z += name_song;
    z += "\t ";
    z += nombre_artista.ToString();
    z += "\t ";
    z += nombre_cantante.ToString();
    z += "\t ";
    z += std::to_string(getTemas());
    z += "\t ";
    z += radio;
    z += ".mp3";
    return z;
}
int Cancion::comparai(const Cancion& hi, const Cancion& ho) {
    return
    hi.nombre_cantante.ToString().compare(ho.nombre_cantante.ToString());
}
int Cancion::comparat(const Cancion& hi, const Cancion& ho) {
    return hi.name_song.compare(ho.name_song);
    }
