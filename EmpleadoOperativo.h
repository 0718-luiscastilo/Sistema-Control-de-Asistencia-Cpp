#pragma once
#include <string>
#include <iostream>
#include "Empleado.h"

class EmpleadoOperativo : public Empleado{
    private:
    std::string area;
    int turno;
    std::string maquinaAsignada;

    public:
    EmpleadoOperativo(std::string codigo, std::string nombre,int faltas,std::string estado,
    std::string area, int turno, std::string maquinaAsignada): Empleado(codigo, nombre,faltas,estado){
        this->area = area;
        this->turno = turno;
        this->maquinaAsignada = maquinaAsignada;

    }
    EmpleadoOperativo(): Empleado(){
        area ="Sin Area";
        turno =1;
        maquinaAsignada = "Sin Maquina";
    }
    void establecerArea(const std::string& setArea){
        area = setArea;
    }
    void estableceTurno(int setTurno){
        if (setTurno >= 1 && setTurno <= 3){
            turno = setTurno;
        }
    }
    void establecerMaquinaAsignada(const std::string& setmaquinaAsignada){
        maquinaAsignada = setmaquinaAsignada;
    }

    std::string obtenerArea() const{
            return area;
    }
    int obtenerTurno() const{
        return turno;
    }
    std::string obtenerMaqunaAsignada() const{
        return maquinaAsignada;
    }
    void cambioArea(const std::string& nuevaArea){
        establecerArea(nuevaArea);
        std::cout << "El cambio de area se realizo exitosamente" << '\n';
    }
    void mostrarInformacion() const{
        
        Empleado::mostrarInformacion();
        std::cout << "Area: " << area << '\n';
        std::cout << "Turno: " << turno << '\n';
        std::cout << "Maquina Asignada: " << maquinaAsignada << '\n';
        std::cout << "---------------------------" << '\n';
    }
};