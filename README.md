# 🏢 Sistema de Control de Asistencia en C++

## 📖 Descripción

Sistema de consola desarrollado en **C++** para gestionar el control de asistencia de empleados dentro de una organización.

El proyecto comenzó como una práctica de programación estructurada y posteriormente fue evolucionando hacia un diseño basado en **Programación Orientada a Objetos (POO)**, incorporando clases, encapsulamiento, herencia, punteros, clases derivadas y conceptos de polimorfismo.

El sistema permite registrar diferentes tipos de empleados, controlar sus asistencias, consultar faltas, buscar empleados y modificar información específica según el tipo de empleado.

---

## 🎯 Objetivos del proyecto

Este proyecto tiene como objetivos:

- Practicar programación en C++.
- Aplicar Programación Orientada a Objetos.
- Trabajar con clases y objetos.
- Aplicar encapsulamiento.
- Implementar herencia.
- Trabajar con punteros.
- Utilizar punteros a clases base.
- Practicar `dynamic_cast`.
- Comprender el polimorfismo.
- Implementar constructores y destructores.
- Gestionar objetos creados dinámicamente.
- Desarrollar un sistema modular mediante funciones.

---

## 🚀 Funcionalidades

### 👤 Gestión de empleados

- Registro de empleados.
- Registro de empleados administrativos.
- Registro de empleados operativos.
- Asignación de código.
- Asignación de nombre.
- Control de faltas.
- Control de estado.

### 📅 Control de asistencia

- Registro de asistencia.
- Registro de falta.
- Control de asistencia durante 5 días.
- Consulta de asistencias de un empleado.
- Consulta de faltas de un empleado.

### 🔎 Consultas

- Buscar empleado por código.
- Mostrar información completa de un empleado.
- Mostrar empleados administrativos.
- Mostrar empleados operativos.

### 🔄 Actualización de información

- Cambio de estado del empleado.
- Cambio de área de empleados operativos.
- Cambio de departamento de empleados administrativos.

---

## 🧬 Arquitectura de clases

El proyecto utiliza una clase base `Empleado` y dos clases derivadas:

```text
                    Empleado
                       │
             ┌─────────┴─────────┐
             │                   │
             ▼                   ▼
EmpleadoAdministrativo     EmpleadoOperativo
```

### `Empleado`

Contiene información común:

- Código
- Nombre
- Asistencias
- Faltas
- Estado

### `EmpleadoAdministrativo`

Extiende a `Empleado` con:

- Departamento
- Puesto
- Nivel de acceso

### `EmpleadoOperativo`

Extiende a `Empleado` con:

- Área
- Turno
- Máquina asignada

---

## 🧠 Conceptos de C++ aplicados

Durante el desarrollo se han utilizado diferentes conceptos del lenguaje:

### Variables y tipos de datos

Uso de:

- `int`
- `char`
- `std::string`
- `bool`

### Arreglos

Control de las asistencias mediante un arreglo de cinco posiciones.

### Funciones

El sistema divide las diferentes operaciones en funciones independientes.

### Punteros

Se utilizan punteros a la clase base:

```text
Empleado*
```

Esto permite manejar diferentes tipos de empleados mediante una misma estructura.

### Memoria dinámica

Los empleados son creados dinámicamente utilizando `new` y posteriormente liberados mediante `delete`.

### Herencia

Las clases:

```text
EmpleadoAdministrativo
EmpleadoOperativo
```

heredan características de:

```text
Empleado
```

### `dynamic_cast`

Se utiliza para comprobar si un objeto apuntado mediante `Empleado*` corresponde realmente a un tipo derivado determinado.

Ejemplo conceptual:

```text
Empleado*
    │
    ▼
dynamic_cast
    │
    ├── EmpleadoAdministrativo*
    │
    └── EmpleadoOperativo*
```

### Métodos virtuales

La clase base utiliza métodos virtuales para permitir que las clases derivadas proporcionen su propia implementación.

---

## 📋 Menú principal

```text
=================================
SISTEMA DE GESTION DE ASISTENCIA
=================================

1.- Registrar Empleado
2.- Registrar Asistencia
3.- Mostrar Asistencias de Empleado
4.- Mostrar Faltas de Empleado
5.- Buscar por codigo
6.- Mostrar Empleados Administrativos
7.- Mostrar Empleados Operativos
8.- Cambio de Estado
9.- Cambio de Area
10.- Cambio de Departamento
11.- Salir
```

---

## 📂 Estructura del proyecto

```text
Sistema-Control-de-Asistencia-Cpp/
│
├── Proyecto1.cpp
├── Empleado.h
├── EmpleadoAdministrativo.h
├── EmpleadoOperativo.h
├── funciones.h
│
└── README.md
```

---

## 🛠️ Tecnologías utilizadas

- **Lenguaje:** C++
- **Estándar:** C++17
- **Paradigma:** Programación Orientada a Objetos
- **IDE:** Visual Studio Code
- **Compilador:** g++
- **Sistema:** Aplicación de consola

---

## ▶️ Compilación

El proyecto puede compilarse utilizando:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic Proyecto1.cpp -o asistencia
```

Posteriormente:

### Windows

```bash
asistencia.exe
```

### Linux / macOS

```bash
./asistencia
```

---

## 📚 Aprendizajes obtenidos

Este proyecto permitió reforzar progresivamente conceptos fundamentales de C++:

- Sintaxis básica.
- Variables.
- Condicionales.
- Bucles.
- Arreglos.
- Funciones.
- Clases.
- Encapsulamiento.
- Constructores.
- Destructores.
- Herencia.
- Punteros.
- Memoria dinámica.
- `dynamic_cast`.
- Métodos virtuales.
- Polimorfismo.

El proyecto continúa evolucionando como una práctica progresiva para transformar una aplicación inicialmente sencilla en un sistema con una estructura más cercana a la utilizada en aplicaciones reales.

---

## 🔮 Próximas mejoras

Entre las posibles mejoras futuras se encuentran:

- Implementar completamente el polimorfismo dinámico.
- Separar declaraciones e implementaciones en archivos `.h` y `.cpp`.
- Mejorar la validación de entradas.
- Implementar persistencia de información.
- Guardar empleados en archivos.
- Incorporar búsqueda avanzada.
- Agregar modificación y eliminación de empleados.
- Incorporar reportes de asistencia.
- Utilizar `std::vector`.
- Mejorar la arquitectura del proyecto.
- Incorporar interfaces y abstracción.
- Implementar nuevas funcionalidades relacionadas con la gestión de empleados.

---

## 👨‍💻 Autor

**Francisco Castillo**

Proyecto desarrollado como parte del proceso de aprendizaje y práctica de **C++ y Programación Orientada a Objetos**.