#include <string>
#include <iostream>
#include <limits>
#include "Empleado.h"
#include "EmpleadoOperativo.h"
#include "EmpleadoAdministrativo.h"

int mostrarMenu(){
    int op;
    while(true){
        std::cout << "=================================\n";
        std::cout << "SISTEMA DE GESTION DE ASISTENCIA" << std::endl;
        std::cout << "=================================\n";
        std::cout << "1.- Registrar Asistencia" << std::endl;
        std::cout << "2.- Mostrar todas las Asistencias." << std::endl;
        std::cout << "3.- Mostrar todas las faltas." << std::endl;
        std::cout << "4.- Buscar por codigo." << std::endl;
        std::cout << "5.- Mostrar Empleados Administrativos." << std::endl;
        std::cout << "6.- Mostrar Empleados Operativos." << std::endl;
        std::cout << "7.- Cambio de Estado." << std::endl;
        std::cout << "8.- Cambio de Area" << std::endl;
        std::cout << "9.- Cambio de Departamento." << std::endl;
        std::cout << "10.- Salir. " << std::endl;
        std::cout << "\nSeleccione una opcion: ";
        if(!(std::cin >>op)){
            std::cout << "Error: Debe escoger un numero.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if(op<1|| op>10){
            std::cout << "\nError: Seleccione una opción entre 1 y 10.\n\n";
            continue;
        }
        return op;
    }
}