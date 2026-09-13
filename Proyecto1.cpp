#include <iostream>
#include "Empleado.h"

int main()
{
    Empleado empleado, empleado1, empleado2;
    

    empleado.establecerCodigo("EMP001");
    empleado.establecerNombre("Juan Perez");

    empleado.establecerAsistencia(0, 'A');
    empleado.establecerAsistencia(1, 'A');
    empleado.establecerAsistencia(2, 'F');
    empleado.establecerAsistencia(3, 'A');
    empleado.establecerAsistencia(4, 'A');

    empleado.establecerFaltas(1);
    empleado.establecerEstado("Puntual");

    empleado.mostrarInformacion();

    empleado1.establecerCodigo("EMP002");
    empleado1.establecerNombre("Luis Garcia");

    empleado1.establecerAsistencia(0, 'F');
    empleado1.establecerAsistencia(1, 'F');
    empleado1.establecerAsistencia(2, 'F');
    empleado1.establecerAsistencia(3, 'F');
    empleado1.establecerAsistencia(4, 'A');

    empleado1.establecerFaltas(4);
    empleado1.establecerEstado("Irregular");

    empleado1.mostrarInformacion();

    empleado2.establecerCodigo("EMP003");
    empleado2.establecerNombre("Carlos Lopez");

    empleado2.establecerAsistencia(0, 'A');
    empleado2.establecerAsistencia(1, 'A');
    empleado2.establecerAsistencia(2, 'A');
    empleado2.establecerAsistencia(3, 'A');
    empleado2.establecerAsistencia(4, 'A');

    empleado2.establecerFaltas(0);
    empleado2.establecerEstado("Puntual");

    empleado2.mostrarInformacion();

    return 0;
}