#pragma once
#include <string>
#include <iostream>
#include "Empleado.h"

class EmpleadoAdministrativo : public Empleado{
    private:
    std::string departamento;
    std::string puesto;
    int nivelAcceso;

    public:
    EmpleadoAdministrativo(std::string codigo, std::string nombre,int faltas,std::string estado,
    std::string departamento, std::string puesto, int nivelAcceso): Empleado(codigo, nombre,faltas,estado){
        this->departamento = departamento;
        this->puesto = puesto;
        this->nivelAcceso = nivelAcceso;

    }
    EmpleadoAdministrativo(): Empleado(){
        departamento ="Sin departamento";
        puesto ="Sin puesto";
        nivelAcceso = 1;
    }
    void establecerDepartamento(const std::string& setdepartamento){
        departamento = setdepartamento;
    }
    void establecerPuesto(const std::string& setpuesto){
        puesto = setpuesto;
    }
    void establecernivelAcceso(int setNivelAcceso){
        if (setNivelAcceso >= 1 && setNivelAcceso <= 3){
            nivelAcceso = setNivelAcceso;
        }
    }
    void cambioDepartamento(std::string nuevoDepartamento){
        establecerDepartamento(nuevoDepartamento);
        std::cout << "El cambio de departamento se realizo exitosamente" << '\n';

    }
    std::string obtenerDepartamento() const{
            return departamento;
    }
    std::string obtenerPuesto() const{
        return puesto;
    }
    int obtenernivelAcceso() const{
            return nivelAcceso;
    }
    
    
    void mostrarInformacion() const override{
        std::cout << "---------------------------" << '\n';
        Empleado::mostrarInformacion();
        std::cout << "Departamento: " << departamento << '\n';
        std::cout << "Puesto: " << puesto << '\n';
        std::cout << "Nivel de Acceso: " << nivelAcceso << '\n';
    }
};