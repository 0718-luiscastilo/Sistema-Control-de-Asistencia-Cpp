#pragma once
#include <string>
#include <iostream>

class Empleado{
    private:
    std::string codigo;
    std::string nombre;
    char asistencias[5];
    int faltas;
    std::string estado;

    public: 
    Empleado(std::string codigo, std::string nombre,int faltas,std::string estado){
        this->codigo = codigo;
        this->nombre = nombre;
        this->faltas = faltas;
        this->estado = estado;
        for (int i = 0; i < 5; i++){
            asistencias[i] = '-';
        }
    }
    Empleado(){
        codigo = "SIN-CODIGO";
        nombre = "Sin nombre";
        for (int i = 0; i < 5; i++){
            asistencias[i] = '-';
        }
        faltas = 0;
        estado = "Sin clasificar";
    }

    void establecerCodigo(const std::string& setcodigo){
        codigo = setcodigo;
    }
    void establecerNombre(const std::string& setnombre){
        nombre = setnombre;
    }
    void establecerAsistencia(int dia, char asistencia){
        if (dia >= 0 && dia < 5){
            asistencias[dia] = asistencia;
        }
    }
    void establecerFaltas(const int setfaltas){
        if (setfaltas >= 0){
            faltas = setfaltas;
         }
    }
    void establecerEstado(const std::string& setestado){
        estado = setestado;
    }
    std::string obtenerCodigo() const {
        return codigo;
    }
    std::string obtenerNombre() const{
        return nombre;
    }
    char obtenerAsistencia(int dia) const{
        if (dia >= 0 && dia < 5){
            return asistencias[dia];
        }
        return '-';
    }
    int obtenerFaltas() const{
        return faltas;
    }
    std::string obtenerEstado() const{
        return estado;
    }
    void mostrarInformacion() const{
        std::cout << "---------------------------" << '\n';
        std::cout << "Codigo: " << codigo << '\n';
        std::cout << "Nombre: " << nombre << '\n';
        std::cout << "Asistencias: ";
        for (int i = 0; i < 5; i++){
            std::cout << asistencias[i] << " ";
        }
        std::cout << '\n';
        std::cout << "Faltas: " << faltas << '\n';
        std::cout << "Estado: " << estado << '\n';
        std::cout << "---------------------------" << '\n';
    }

    virtual ~Empleado() = default;
};
