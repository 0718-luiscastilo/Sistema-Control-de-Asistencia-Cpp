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
            registrarEmpleado(empleados,cantidadEmpleados, MAX_EMPLEADOS);
            break;
        case 2:
            registrarAsistencia(empleados, cantidadEmpleados);
            break;
        case 3:
            mostrarAsistenciasEmpleado(empleados,cantidadEmpleados);
            break;
        case 4:
            mostrarFaltasEmpleado(empleados,cantidadEmpleados);
            break;
        case 5:
            buscarEmpleadoPorCodigo(empleados,cantidadEmpleados);
            break;
        case 6:
            mostrarEmpleadosAdministrativos(empleados, cantidadEmpleados);
            break;
        case 7:
            mostrarEmpleadosOperativos(empleados, cantidadEmpleados);
            break;
        case 8:
            cambiarEstado(empleados,cantidadEmpleados);
            break;
        case 9:
            std::cout << "Cambio de Area\n";
            break;
        case 10:
            std::cout << "Cambio de Departamento.\n";
            break;
        case 11:
            std::cout << "Gracias por utilizar el sistema.\n";
            break;
        default:
            std::cout << "===== Opción inválida. =====" << std::endl;
            break;
        }
        std::cout << '\n';

    }while (opcion !=11);
    for(int i = 0; i < cantidadEmpleados    ; i++){
        delete empleados[i];
        empleados[i] = nullptr;
    }

    return 0;
}