#include <iostream>
#include <string>
#include <limits>
#include <cctype>

int main() {
  int numEmpleados;
  char asistencias[10][5];
  std::string nombres[10];
  int totalAsistencias[10];
  int totalFaltas[10];
  std::string estado[10];

  std::cout << "Ingrese la cantidad de Empleados: ";
  std::cin >> numEmpleados;

  while(numEmpleados <= 0 || numEmpleados > 10){
    std::cout << "Ingrese un numero valido de empleados (1-10):" << std::endl; 
    std::cout << "Ingrese la cantidad de Empleados: ";
    std::cin >> numEmpleados;
  }

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  for (int i = 0; i < numEmpleados; i++){
    std::cout << "Ingrese el Nombre del Empleado " << (i+1) << std::endl;
    std::getline(std::cin, nombres[i]);

    for (int j = 0; j < 5; j++){
      do {
        std::cout << "Dia " << (j + 1) << " (A/F): ";
        std::cin >> asistencias[i][j];

        // Convertir a mayúscula por si escriben 'a' o 'f'
        asistencias[i][j] = toupper(asistencias[i][j]);

        if (asistencias[i][j] != 'A' && asistencias[i][j] != 'F'){
            std::cout << "Entrada invalida. Solo se permite A o F.\n";
        }

    } while (asistencias[i][j] != 'A' && asistencias[i][j] != 'F');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  
  for (int i = 0; i < numEmpleados; i++){
    totalAsistencias[i] = 0;

    for (int j = 0; j < 5; j++){
      if(asistencias[i][j] == 'A'){
        totalAsistencias[i]++;
      }
    }

    totalFaltas[i] = 5 - totalAsistencias[i];
    
    if(totalAsistencias[i]==5){
      estado[i] = "Puntual";
    }else if(totalAsistencias[i]>=3){
      estado[i] = "Regular";
    }else{
      estado[i] = "Irregular";
    }
  }

  std::cout << "\nReporte de asistencia:\n";

  for (int i = 0; i < numEmpleados; i++){
    std::cout << "\nEmpleado " << (i+1) << ": " << nombres[i] << std::endl;
    std::cout << "Asistencias: " << totalAsistencias[i] << std::endl;
    std::cout << "Faltas: " << totalFaltas[i] << std::endl;
    std::cout << "Estado: " << estado[i] << std::endl;
    std::cout << "----------------------" << std::endl;
  }

  return 0;
}