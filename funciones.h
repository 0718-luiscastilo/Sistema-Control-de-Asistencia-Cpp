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
        std::cout << "1.- Registrar Empleado" << std::endl;
        std::cout << "2.- Registrar Asistencia" << std::endl;
        std::cout << "3.- Mostrar Asistencias de Empleado." << std::endl;
        std::cout << "4.- Mostrar Faltas de Empleado." << std::endl;
        std::cout << "5.- Buscar empleado por codigo." << std::endl;
        std::cout << "6.- Mostrar Empleados Administrativos." << std::endl;
        std::cout << "7.- Mostrar Empleados Operativos." << std::endl;
        std::cout << "8.- Cambio de Estado." << std::endl;
        std::cout << "9.- Cambio de Area" << std::endl;
        std::cout << "10.- Cambio de Departamento." << std::endl;
        std::cout << "11.- Salir. " << std::endl;
        std::cout << "\nSeleccione una opcion: ";
        if(!(std::cin >>op)){
            std::cout << "Error: Debe escoger un numero.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if(op<1|| op>11){
            std::cout << "\nError: Seleccione una opción entre 1 y 11.\n\n";
            continue;
        }
        return op;
    }
}
void registrarEmpleado(Empleado* empleados[], int& cantidadEmpleados, int MAX_EMPLEADOS){
    if (cantidadEmpleados >= MAX_EMPLEADOS){
        std::cout << "No hay espacio para registrar mas empleados.\n";
        return;
    }
    int tipo;
    std::cout << "\n===== REGISTRAR EMPLEADO =====\n";
    std::cout << "1. Empleado Administrativo\n";
    std::cout << "2. Empleado Operativo\n";
    std::cout << "Seleccione el tipo de empleado: ";
    std::cin >> tipo;
    while (tipo != 1 && tipo != 2){
        std::cout << "Error: seleccione 1 o 2: ";
        std::cin >> tipo;
    }
    std::string codigo;
    std::string nombre;
    int faltas = 0;
    std::string estado = "Activo";
    std::cout << "\nCodigo: ";
    std::cin >> codigo;
    // Verificar que el codigo no exista
    for (int i = 0; i < cantidadEmpleados; i++){
        if (empleados[i]->obtenerCodigo() == codigo){
            std::cout << "Ese codigo ya existe.\n";
            return;
        }
    }
    std::cin.ignore(1000, '\n');

    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    if (tipo == 1){
        std::string departamento;
        std::string puesto;
        int nivelAcceso;

        std::cout << "Departamento: ";
        std::getline(std::cin, departamento);
        std::cout << "Puesto: ";
        std::getline(std::cin, puesto);
        std::cout << "Nivel de acceso (1-3): ";
        std::cin >> nivelAcceso;
        while (nivelAcceso < 1 || nivelAcceso > 3){
            std::cout << "Error: ingrese un nivel entre 1 y 3: ";
            std::cin >> nivelAcceso;
        }
        empleados[cantidadEmpleados] =new EmpleadoAdministrativo(codigo, nombre, faltas,
            estado, departamento, puesto, nivelAcceso
        );
    }else{
        std::string area;
        int turno;
        std::string maquinaAsignada;

        std::cout << "Area: ";
        std::getline(std::cin, area);

        std::cout << "Turno (1-3): ";
        std::cin >> turno;
        while (turno < 1 || turno > 3){
            std::cout << "Error: ingrese un turno entre 1 y 3: ";
            std::cin >> turno;
        }
        std::cin.ignore(1000, '\n');

        std::cout << "Maquina asignada: ";
        std::getline(std::cin, maquinaAsignada);

        empleados[cantidadEmpleados] = new EmpleadoOperativo(codigo, nombre, faltas, estado, area, turno, maquinaAsignada);
    }
    cantidadEmpleados++;
    std::cout << "\nEmpleado registrado correctamente.\n";
}
void registrarAsistencia(Empleado* empleados[], int cantidadEmpleados){
    if (cantidadEmpleados == 0){
        std::cout << "No hay empleados registrados.\n";
        return;
    }
    std::string codigo;
    std::cout << "\n===== REGISTRAR ASISTENCIA =====\n";
    std::cout << "Codigo del empleado: ";
    std::cin >> codigo;

    Empleado* empleadoEncontrado = nullptr;

    for (int i = 0; i < cantidadEmpleados; i++){
        if (empleados[i]->obtenerCodigo() == codigo){
            empleadoEncontrado = empleados[i];
            break;
        }
    }
    if (empleadoEncontrado == nullptr){
        std::cout << "No se encontro un empleado con ese codigo.\n";
        return;
    }
    std::cout << "Empleado: "<< empleadoEncontrado->obtenerNombre() << '\n';
    int dia;
    std::cout << "Ingrese el dia (1-5): ";
    while (!(std::cin >> dia) || dia < 1 || dia > 5){
        std::cout << "Error: ingrese un dia entre 1 y 5: ";
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
    }
    char asistencia;
    std::cout << "Ingrese A para asistencia o F para falta: ";
    std::cin >> asistencia;

    asistencia = std::toupper(static_cast<unsigned char>(asistencia));
    while (asistencia != 'A' && asistencia != 'F'){
        std::cout << "Error: ingrese A o F: ";
        std::cin >> asistencia;
        asistencia = std::toupper( static_cast<unsigned char>(asistencia));
    }
    int posicionDia = dia - 1;
    char asistenciaAnterior = empleadoEncontrado->obtenerAsistencia(posicionDia);
    if (asistenciaAnterior == asistencia){
        std::cout << "Ese dia ya tiene registrado ese estado.\n";
        return;
    }
    empleadoEncontrado->establecerAsistencia(posicionDia, asistencia);
    int faltas = empleadoEncontrado->obtenerFaltas();
    if (asistencia == 'F' && asistenciaAnterior != 'F'){
        faltas++;
    }
    else if (asistencia == 'A' && asistenciaAnterior == 'F'){
        faltas--;
    }
    empleadoEncontrado->establecerFaltas(faltas);
    std::cout << "\nAsistencia registrada correctamente.\n";
}
void mostrarAsistenciasEmpleado(Empleado* empleados[], int cantidadEmpleados){
    if (cantidadEmpleados == 0){
        std::cout << "No hay empleados registrados.\n";
        return;
    }
    std::string codigo;
    std::cout << "\n===== MOSTRAR ASISTENCIA =====\n";
    std::cout << "Codigo del empleado: ";
    std::cin >> codigo;

    Empleado* empleadoEncontrado = nullptr;
    for (int i = 0; i < cantidadEmpleados; i++){
        if (empleados[i]->obtenerCodigo() == codigo){
            empleadoEncontrado = empleados[i];
            break;
        }
    }
    if (empleadoEncontrado == nullptr){
        std::cout << "No se encontro un empleado con ese codigo.\n";
        return;
    }
    int totalAsistencias = 0;
    for (int i = 0; i < 5; i++){
        char asistencia =empleadoEncontrado->obtenerAsistencia(i);
        if (asistencia == 'A'){
            totalAsistencias++;
        }
    }
    std::cout << "\n===== INFORMACION DE ASISTENCIA =====\n";
    std::cout << "Codigo: " << empleadoEncontrado->obtenerCodigo() << '\n';
    std::cout << "Nombre: " << empleadoEncontrado->obtenerNombre() << '\n';
    std::cout << "Total de asistencia: " << totalAsistencias << '\n';

}
void mostrarFaltasEmpleado(Empleado* empleados[], int cantidadEmpleados){
    if (cantidadEmpleados == 0){
        std::cout << "No hay empleados registrados.\n";
        return;
    }

    std::string codigo;
    std::cout << "\n===== MOSTRAR FALTAS =====\n";
    std::cout << "Codigo del empleado: ";
    std::cin >> codigo;

    Empleado* empleadoEncontrado = nullptr;
    for (int i = 0; i < cantidadEmpleados; i++){
        if (empleados[i]->obtenerCodigo() == codigo){
            empleadoEncontrado = empleados[i];
            break;
        }
    }
    if (empleadoEncontrado == nullptr){
        std::cout << "No se encontro un empleado con ese codigo.\n";
        return;
    }
    std::cout << "\n===== INFORMACION DE FALTAS =====\n";
    std::cout << "Codigo: "<< empleadoEncontrado->obtenerCodigo() << '\n';
    std::cout << "Nombre: "<< empleadoEncontrado->obtenerNombre()<< '\n';
    std::cout << "Total de faltas: " << empleadoEncontrado->obtenerFaltas() << '\n';
}
void buscarEmpleadoPorCodigo(Empleado* empleados[], int cantidadEmpleados){
    if (cantidadEmpleados == 0){
        std::cout << "No hay empleados registrados.\n";
        return;
    }
    std::string codigo;
    std::cout << "Codigo del empleado: ";
    std::cin >> codigo;

    Empleado* empleadoEncontrado = nullptr;
    for (int i = 0; i < cantidadEmpleados; i++){
        if (empleados[i]->obtenerCodigo() == codigo){
            empleadoEncontrado = empleados[i];
            break;
        }
    }
    if (empleadoEncontrado == nullptr){
        std::cout << "No se encontro un empleado con ese codigo.\n";
        return;
    }
    std::cout << "\n===== INFORMACION DEL EMPLEADO =====\n";
    empleadoEncontrado->mostrarInformacion();
}
void mostrarEmpleadosAdministrativos(Empleado* empleados[], int cantidadEmpleados){
    if (cantidadEmpleados == 0){
        std::cout << "No hay empleados registrados.\n";
        return;
    }
    int administrativos = 0;
    std::cout << "\n===== INFORMACION DE EMPLEADOS ADMINISTRATIVOS =====\n";
    for(int i =0; i<cantidadEmpleados; i++){
        EmpleadoAdministrativo* administrativo = dynamic_cast<EmpleadoAdministrativo*>(empleados[i]);
        if (administrativo != nullptr){
            administrativos++;
            administrativo->mostrarInformacion();
        }
    }
    if(administrativos == 0){
        std::cout << "No se encontro ningun Empleado Adminstrativos.\n";
    }
    std::cout << "Total de Empleados Administrativos: " << administrativos << '\n';
}
void mostrarEmpleadosOperativos(Empleado* empleados[], int cantidadEmpleados){
    if (cantidadEmpleados == 0){
        std::cout << "No hay empleados registrados.\n";
        return;
    }
    int operativo = 0;
    std::cout << "\n===== INFORMACION DE EMPLEADOS OPERATIVOS =====\n";
    for(int i =0; i<cantidadEmpleados; i++){
        EmpleadoOperativo* operativos = dynamic_cast<EmpleadoOperativo*>(empleados[i]);
        if (operativos != nullptr){
            operativo++;
            operativos->mostrarInformacion();
        }
    }
    if(operativo == 0){
        std::cout << "No se encontro ningun Empleado Operativo.\n";
    }
    std::cout << "Total de Empleados Operativoo: " << operativo << '\n';
}
void cambiarEstado(Empleado* empleados[], int cantidadEmpleados){
    if (cantidadEmpleados == 0){
        std::cout << "No hay empleados registrados.\n";
        return;
    }
    std::string codigo;
    std::cout << "Codigo del empleado: ";
    std::cin >> codigo;

    Empleado* empleadoEncontrado = nullptr;
    for (int i = 0; i < cantidadEmpleados; i++){
        if (empleados[i]->obtenerCodigo() == codigo){
            empleadoEncontrado = empleados[i];
            break;
        }
    }
    if (empleadoEncontrado == nullptr){
        std::cout << "No se encontro un empleado con ese codigo.\n";
        return;
    }
    std::cout << "\n===== ESTADO ACTUAL DEL EMPLEADO =====\n";
    std::cout << "Codigo: " << empleadoEncontrado->obtenerCodigo() << '\n';
    std::cout << "Nombre: " << empleadoEncontrado->obtenerNombre() << '\n';
    std::cout << "Estado actual: " << empleadoEncontrado->obtenerEstado() << '\n';
    int opcionEstado;
    while (true){
        std::cout << "\n===== NUEVO ESTADO =====\n";
        std::cout << "1. Activo\n";
        std::cout << "2. Inactivo\n";
        std::cout << "3. Suspendido\n";
        std::cout << "4. Vacaciones\n";
        std::cout << "Seleccione una opcion: ";

        if (!(std::cin >> opcionEstado)){
            std::cout << "Error: Debe ingresar un numero.\n";
            std::cin.clear();
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
            continue;
        }
        if (opcionEstado >= 1 && opcionEstado <= 4){
            break;
        }
        std::cout << "Error: Seleccione una opcion entre 1 y 4.\n";
    }
    std::string nuevoEstado;
    switch (opcionEstado){
        case 1:
            nuevoEstado = "Activo";
            break;
        case 2:
            nuevoEstado = "Inactivo";
            break;
        case 3:
            nuevoEstado = "Suspendido";
            break;
        case 4:
            nuevoEstado = "Vacaciones";
            break;
    }
    empleadoEncontrado->establecerEstado(nuevoEstado);
    std::cout << "\n===== EL ESTADO SE ACTUALIZO CORRECTAMENTE =====\n";
    std::cout << "Nuevo estado: " << empleadoEncontrado->obtenerEstado() << '\n';
    empleadoEncontrado->mostrarInformacion();

}