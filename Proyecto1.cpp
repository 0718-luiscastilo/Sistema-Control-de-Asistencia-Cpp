#include <iostream>
#include "Empleado.h"
#include "funciones.h"

int main()
{
    const int MAX_EMPLEADOS =20;
    int cantidadEmpleados = 0;
    Empleado* empleados[MAX_EMPLEADOS] = {nullptr};
    int opcion;
    do{
        opcion = mostrarMenu();
        switch (opcion){
        case 1:
            std::cout << "Rgistrar Asistencia.\n";
            break;
        case 2:
            std::cout << "Mostrar todas las Asistencias..\n";
            break;
        case 3:
            std::cout << "Mostrar todas las faltas.\n";
            break;
        case 4:
            std::cout << "Buscar por codigo.\n";
            break;
        case 5:
            std::cout << "Mostrar Empleados Administrativos.\n";
            break;
        case 6:
            std::cout << "Mostrar Empleados Operativos\n";
            break;
        case 7:
            std::cout << "Cambio de Estado.\n";
            break;
        case 8:
            std::cout << "Cambio de Area\n";
            break;
        case 9:
            std::cout << "Cambio de Departamento.\n";
            break;
        case 10:
            std::cout << "Gracias por utilizar el sistema.\n";
            break;
        default:
            std::cout << "===== Opción inválida. =====" << std::endl;
            break;
        }
        std::cout << '\n';

    }while (opcion !=10);
    for(int i = 0; i < cantidadEmpleados    ; i++){
        delete empleados[i];
        empleados[i] = nullptr;
    }

    return 0;
}