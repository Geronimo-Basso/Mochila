/*
Ejercicio 2: Implementar en C++ un programa sencillo que simule una mochila o almacén de objetos.
El programa debe permitir al usuario que se “almacene” cualquier tipo de objeto que quiera el usuario (solo validos tipos de datos estándar de C++). Para ello, se implementará un menú de “gestión de objetos”,
que permitirá seleccionar si se quiere almacenar un objeto o eliminarlo, permitiendo elegir que objeto eliminar.
A la hora de almacenar los datos, deben emplearse las técnicas y métodos que hagan que el almacenamiento sea lo más eficiente posible en to do momento. Para ello, deben emplearse los operadores de alineación.
 */
#include <iostream>
#include <vector>
using namespace std;
int checkBool(string element){
    int devolucion;
    int compareFalse = element.compare("false");
    int compareTrue = element.compare("true");
    if(compareTrue==0){
        devolucion=1;
    }else if(compareFalse==0){
        devolucion=0;
    }else{
        devolucion=2;
    }
    return devolucion;
}
bool checkInteger(string element){
    bool devolucion=false;
    try {
        stoi(element);
        devolucion=true;
    } catch (...){}
    return devolucion;
}
bool checkFloat(string element){
    bool devolucion=false;
    try {
        stof(element);
        devolucion=true;
    } catch (...){}
    return devolucion;
}
bool checkDouble(string element){
    bool devolucion=false;
    try {
        stod(element);
        devolucion=true;
    } catch (...){}
    return devolucion;
}
bool checkChar(string element){
    bool devolucion=false;
    if(element.size()==1){
        devolucion=true;
    }
    return devolucion;
}
template <class T>
void impimirVector(vector<T> lista) {
    for(int i=0;i<lista.size();i++)
        cout << lista.at(i) << endl;
}
int main() {
    bool condicion=true;
    bool condicion2=true;
    bool condicion3=true;
    char opcionMenu,opcionMenuAlmacenar,opcionMenuBorrar;
    vector<bool> *vectorBool=new vector<bool>;
    vector<bool>::iterator iteratorBool;
    vector<int> *vectorInt=new vector<int>;
    vector<int>::iterator iteratorInt;
    vector<float> *vectorFloat=new vector<float>;
    vector<float>::iterator iteratorFloat;
    vector<double> *vectorDouble=new vector<double>;
    vector<double>::iterator iteratorDouble;
    vector<char> *vectorChar=new vector<char>;
    vector<char>::iterator iteratorChar;
    string dato;
    //definir arrays
    while(condicion){
        cout << "Bienvenido usuario! Elija que quiere hacer: " << "\n" << "1. Almacenar objeto en la mochila" << "\n" << "2. Ver objetos en la mochila" <<  "\n" << "3. Eliminar objeto de la mochila"<<  "\n" << "4. Finalizar programa" << endl;
        cin >> opcionMenu;
        switch (opcionMenu) {
            case '1':
               condicion2=true;
                while(condicion2){
                    cout << "¿Que objeto quieres almacenear? "  << "\n" << "1. Boolean" << "\n" << "2. Integer" <<  "\n" << "3. Float " << "\n" << "4. Double" << "\n" << "5. Char" << "\n" << "6. Volver al menu" << endl;
                    cin >> opcionMenuAlmacenar;
                    switch (opcionMenuAlmacenar){
                        case '1':
                            cout << "Introduzca el boolean que quiere almacenar(en minusculas porfavor): " << endl;
                            cin >> dato;
                            if(checkBool(dato)==0){
                                vectorBool->push_back(false);
                                cout << "Boolean almacenado con éxito" << endl;
                            }else if(checkBool(dato)==1){
                                vectorBool->push_back(true);
                                cout << "Boolean almacenado con éxito" << endl;
                            }
                            else{
                                cout << "Error, no ingreso correctamente el tipo de dato." << endl;
                            }
                            break;
                        case '2':
                            cout << "Introduzca el Integer que quiere almacenar: " << endl;
                            cin >> dato;
                            if(checkInteger(dato)){
                                vectorInt->push_back(stoi(dato));
                                cout << "Integer almacenado con éxito" << endl;
                            }else{
                                cout << "Error, no ingreso correctamente el tipo de dato." << endl;
                            }
                            break;
                        case '3':
                            cout << "Introduzca el Float que quiere alcmacenar: " << endl;
                            cin >> dato;
                            if(checkFloat(dato)){
                                vectorFloat->push_back(stof(dato));
                                cout << "Float almacenado con éxito" << endl;
                            }else{
                                cout << "Error, no ingreso correctamente el tipo de dato." << endl;
                            }
                            break;
                        case '4':
                            cout << "Introduzca el Double que quiere alcmacenar: " << endl;
                            cin >> dato;
                            if(checkDouble(dato)){
                                vectorDouble->push_back(stod(dato));
                                cout << "Double almacenado con éxito" << endl;
                            }else{
                                cout << "Error, no ingreso correctamente el tipo de dato." << endl;
                            }
                            break;
                        case '5':
                            cout << "Introduzca el Char que quiere alcmacenar: " << endl;
                            cin >> dato;
                            if(checkChar(dato)){
                                vectorChar->push_back(dato[0]);
                                cout << "Char almacenado con éxito" << endl;
                            }else{
                                cout << "Error, no ingreso correctamente el tipo de dato." << endl;
                            }
                            break;
                        case '6':
                            condicion2=false;
                        default:
                            cout << "Por favor elija una opción valida." << endl;
                    }
                }
                break;
            case '2':
                cout << "------- Boolean ---------" << endl;
                impimirVector(*vectorBool);
                cout << "------- Integer ---------" << endl;
                impimirVector(*vectorInt);
                cout << "------- Float ---------" << endl;
                impimirVector(*vectorFloat);
                cout << "------- Double ---------" << endl;
                impimirVector(*vectorDouble);
                cout << "------- Char ---------" << endl;
                impimirVector(*vectorChar);
                break;
            case '3':
                condicion3=true;
                while(condicion3){
                    cout << "¿Que dato quieres borrar? "  << "\n" << "1. Boolean" << "\n" << "2. Integer" <<  "\n" << "3. Float " << "\n" << "4. Double" << "\n" << "5. Char" << "\n" << "6. Volver al menu" << endl;
                    cin >> opcionMenuBorrar;
                    switch (opcionMenuBorrar){
                        case '1':
                            if(!vectorBool->empty()){
                                cout << "Introduzca la posición del elemento que quiere borrar (recuerde que compienza desde 0): " << endl;
                                cin >> dato;
                                if(checkInteger(dato)){
                                    if(stoi(dato) <= vectorBool->size()){
                                        iteratorBool=vectorBool->begin()+stoi(dato);
                                        vectorBool->erase(iteratorBool);
                                    }else{
                                        cout << "El numero ingresado es mas grande que el tamaño del array" << endl;
                                    }
                                }else{
                                    cout << "No se introduzco un valor numerico" << endl;
                                }
                            }else{
                                cout << "No hay nada almacenado en el el vector boolean todavia" << endl;
                            }
                            break;
                        case '2':
                            if(!vectorInt->empty()){
                                cout << "Introduzca la posición del elemento que quiere borrar (recuerde que compienza desde 0): " << endl;
                                cin >> dato;
                                if(checkInteger(dato)){
                                    if(stoi(dato) <= vectorInt->size()){
                                        iteratorInt=vectorInt->begin()+stoi(dato);
                                        vectorInt->erase(iteratorInt);
                                    }else{
                                        cout << "El numero ingresado es mas grande que el tamaño del array" << endl;
                                    }
                                }else{
                                    cout << "No se introduzco un valor numerico" << endl;
                                }
                            }else{
                                cout << "No hay nada almacenado en el el vector Integer todavia" << endl;
                            }
                            break;
                        case '3':
                            if(!vectorFloat->empty()){
                                cout << "Introduzca la posición del elemento que quiere borrar (recuerde que compienza desde 0): " << endl;
                                cin >> dato;
                                if(checkInteger(dato)){
                                    if(stoi(dato) <= vectorFloat->size()){
                                        iteratorFloat=vectorFloat->begin()+stoi(dato);
                                        vectorFloat->erase(iteratorFloat);
                                    }else{
                                        cout << "El numero ingresado es mas grande que el tamaño del array" << endl;
                                    }
                                }else{
                                    cout << "No se introduzco un valor numerico" << endl;
                                }
                            }else{
                                cout << "No hay nada almacenado en el el vector Float todavia" << endl;
                            }
                            break;
                        case '4':
                            if(!vectorDouble->empty()){
                                cout << "Introduzca la posición del elemento que quiere borrar (recuerde que compienza desde 0): " << endl;
                                cin >> dato;
                                if(checkInteger(dato)){
                                    if(stoi(dato) <= vectorDouble->size()){
                                        iteratorDouble=vectorDouble->begin()+stoi(dato);
                                        vectorDouble->erase(iteratorDouble);
                                    }else{
                                        cout << "El numero ingresado es mas grande que el tamaño del array" << endl;
                                    }
                                }else{
                                    cout << "No se introduzco un valor numerico" << endl;
                                }
                            }else{
                                cout << "No hay nada almacenado en el el vector Double todavia" << endl;
                            }
                            break;
                        case '5':
                            if(!vectorChar->empty()){
                                cout << "Introduzca la posición del elemento que quiere borrar (recuerde que compienza desde 0): " << endl;
                                cin >> dato;
                                if(checkInteger(dato)){
                                    if(stoi(dato) <= vectorChar->size()){
                                        iteratorChar=vectorChar->begin()+stoi(dato);
                                        vectorChar->erase(iteratorChar);
                                    }else{
                                        cout << "El numero ingresado es mas grande que el tamaño del array" << endl;
                                    }
                                }else{
                                    cout << "No se introduzco un valor numerico" << endl;
                                }
                            }else{
                                cout << "No hay nada almacenado en el el vector Char todavia" << endl;
                            }
                            break;
                        case '6':
                            condicion3=false;
                        default:
                            cout << "Por favor elija una opción valida." << endl;
                    }
                }

                break;
            case '4':
                condicion=false;
                break;
            default:
                cout << "Por favor elija una opción valida." << endl;
        }
    }
    return 0;
}

/*
Integer
Character
Boolean
Floating Point
Double Floating Point
Valueless or Void
Wide Character
 */
