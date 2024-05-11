#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Estructura para representar a un empleado
struct Empleado {
    int id;
    string agregarEmpleado;
    string modificarEmpleado;
    string posicion;
    double salario;
    int anioContratacion; // Anio de contratación
    vector<pair<double, time_t>> pagos; // Vector de pagos (monto, fecha)
};

// Vector para almacenar empleados
vector<Empleado> Empleados;
// Funcion para agregar un nuevo empleado
void AgregarEmpleado() {
    Empleado nuevoEmpleado;
    cout << "ID de empleado: ";
    cin >> nuevoEmpleado.id;
    cout << "Nombre: ";
    cin >> nuevoEmpleado.agregarEmpleado;
    cout << "Apellido: ";
    cin >> nuevoEmpleado.modificarEmpleado;
    cout << "Posicion: ";
    cin >> nuevoEmpleado.posicion;
    cout << "Salario: ";
    cin >> nuevoEmpleado.salario;
    cout << "Anio de contratacion: ";
    cin >> nuevoEmpleado.anioContratacion;
    // Agregar el nuevo empleado al vector
    Empleados.push_back(nuevoEmpleado);
    cout << "Empleado agregado correctamente" << endl;
}

// Funcion para mostrar la lista de empleados
void MostrarEmpleados() {
    cout << "Lista de empleados:" << endl;
    for (const auto& emp : Empleados) {
        cout << "ID: " << emp.id << ", Nombre: " << emp.agregarEmpleado << " "
             << emp.modificarEmpleado << ", Posicion: " << emp.posicion
             << ", Salario: Q" << emp.salario << ", Anio de contratacion: " << emp.anioContratacion << endl;
        cout << "Pagos:" << endl;
        for (const auto& pago : emp.pagos) {
            cout << " - Monto: Q" << pago.first << ", Fecha: " << ctime(&pago.second);
        }
        cout << endl;
    }
}

// Funcion para modificar un empleado existente
void ModificarEmpleado() {
    int id;
    cout << "Ingrese el ID del empleado a modificar: ";
    cin >> id;
    for (auto& emp : Empleados) {
        if (emp.id == id) {
            cout << "Nombre: ";
            cin >> emp.agregarEmpleado;
            cout << "Apellido: ";
            cin >> emp.modificarEmpleado;
            cout << "Posicion: ";
            cin >> emp.posicion;
            cout << "Salario: ";
            cin >> emp.salario;
            cout << "Anio de contratacion: ";
            cin >> emp.anioContratacion;
            cout << "Empleado modificado correctamente." << endl;
            return;
        }
    }
    cout << "Empleado no encontrado." << endl;
}

// Funcion para dar de baja a un empleado
void EliminarEmpleado() {
    int id;
    cout << "Ingrese el ID del empleado a dar de baja: ";
    cin >> id;
    for (auto it = Empleados.begin(); it != Empleados.end(); ++it) {
        if (it->id == id) {
            it = Empleados.erase(it);
            cout << "Empleado dado de baja correctamente." << endl;
            return;
        }
    }
    cout << "Empleado no encontrado." << endl;
}

// Funcion para control de pagos
void pagoControl() {
    int id;
    double amount;
    time_t now = time(0); // Fecha actual en segundos desde 1970
    cout << "Ingrese el ID del empleado: ";
    cin >> id;
    for (auto& emp : Empleados) {
        if (emp.id == id) {
            cout << "Monto del pago: ";
            cin >> amount;
            emp.pagos.push_back(make_pair(amount, now));
            cout << "Pago registrado correctamente." << endl;
            return;
        }
    }
    cout << "Empleado no encontrado." << endl;
}

// Funcion para mostrar historial de pagos por empleado
void pagoHistorial() {
    int id;
    cout << "Ingrese el ID del empleado: ";
    cin >> id;
    for (const auto& emp : Empleados) {
        if (emp.id == id) {
            cout << "Historial de pagos para " << emp.agregarEmpleado << " " << emp.modificarEmpleado <<
                 ":" << endl;
            for (const auto& pago : emp.pagos) {
                cout << " - Monto: Q" << pago.first << ", Fecha: " << ctime(&pago.second);
            }
            return;
        }
    }
    cout << "Empleado no encontrado." << endl;
}

int main() {
    int opcion;
    do {
        cout << "\nMenu de Recursos Humanos:" << endl;
        cout << "1. Agregar empleado" << endl;
        cout << "2. Mostrar empleados" << endl;
        cout << "3. Modificar empleado" << endl;
        cout << "4. Dar de baja a un empleado" << endl;
        cout << "5. Control de pagos" << endl;
        cout << "6. Historial de pagos por empleado" << endl;
        cout << "7. Salir" << endl;
        cout << "Elije una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                AgregarEmpleado();
                break;
            case 2:
                MostrarEmpleados();
                break;
            case 3:
                ModificarEmpleado();
                break;
            case 4:
                EliminarEmpleado();
                break;
            case 5:
                pagoControl();
                break;
            case 6:
                pagoHistorial();
                break;
            case 7:
                cout << "Muchas gracias por usar el programa, esperamos que vuelva pronto!" << endl;
                break;
            default:
                cout << "Opcion invalida. Intentalo de nuevo." << endl;
        }
    } while (opcion != 7);
    return 0;
}