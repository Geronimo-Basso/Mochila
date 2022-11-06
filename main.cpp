/*
Ejercicio 2: Implementar en C++ un programa sencillo que simule una mochila o almacén de objetos.
El programa debe permitir al usuario que se “almacene” cualquier tipo de objeto que quiera el usuario (solo validos tipos de datos estándar de C++). Para ello, se implementará un menú de “gestión de objetos”,
que permitirá seleccionar si se quiere almacenar un objeto o eliminarlo, permitiendo elegir que objeto eliminar.
A la hora de almacenar los datos, deben emplearse las técnicas y métodos que hagan que el almacenamiento sea lo más eficiente posible en to do momento. Para ello, deben emplearse los operadores de alineación.
 */
#include <iostream>
#include <vector>
using namespace std;

/*
 * Varias funciones para comprobar en el dato que me esta pasando menu el dato que se pide en el menu, algunas tienen la capacidad de poder usarlas para otras funciones del programa.
 * Hay una funcion para cada tipo de dato nativo de C++ los cuales son: Bool, Integer , Float, Double y Char.
 * Algunas de estas funciones usan metodos try catch para poder agarrar cualquier tipo posible de excepcion, y asi no se termine el programa..
 */
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
// plantilla para poder imprimir cualquier tipo de vector, asi no hacemos uno para cada tipo de dato,
template <class T>
void impimirVector(vector<T> lista) {
    for(int i=0;i<lista.size();i++)
        cout << lista.at(i) << endl;
}
int main() {
    //definimos variables de tipo boolean para usar dentro de los diferentes whiles.
    bool condicion=true;
    bool condicion2=true;
    bool condicion3=true;
    //variables de tipo char las cuales se usan a la hora de entrar en los cada caso del switch case correspondiente.
    char opcionMenu,opcionMenuAlmacenar,opcionMenuBorrar;
    //definimos en el free store un vector para cada tipo de dato nativo, junto con su correspodiente iterator para poder recorrer los vectores.
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
    while(condicion){
        //Entramos al while, donde mostraremos las opciones principales dentro del menu.
        cout << "Bienvenido usuario! Elija que quiere hacer: " << "\n" << "1. Almacenar objeto en la mochila" << "\n" << "2. Ver objetos en la mochila" <<  "\n" << "3. Eliminar objeto de la mochila"<<  "\n" << "4. Finalizar programa" << endl;
        cin >> opcionMenu;
        switch (opcionMenu) {
            case '1': //Caso relacionado con almacenar objetos dentro de la mochila.
               condicion2=true;
                while(condicion2){
                    cout << "¿Que objeto quieres almacenear? "  << "\n" << "1. Boolean" << "\n" << "2. Integer" <<  "\n" << "3. Float " << "\n" << "4. Double" << "\n" << "5. Char" << "\n" << "6. Volver al menu" << endl; //pido el tipo de objeto que voy a almacenar dentro de la mochila
                    cin >> opcionMenuAlmacenar;
                    switch (opcionMenuAlmacenar){
                        case '1': //caso de almacenar boolean
                            cout << "Introduzca el boolean que quiere almacenar(en minusculas porfavor): " << endl; //pido que me pasen el string escrito en minusculas
                            cin >> dato;
                            if(checkBool(dato)==0){ //chequeo si es 0, quiere decir que el valor es false, lo meto en la lista despues
                                vectorBool->push_back(false);
                                cout << "Boolean almacenado con éxito" << endl;
                            }else if(checkBool(dato)==1){//chequeo si es 1, quiere decir que el valor es true, lo meto en la lista
                                vectorBool->push_back(true);
                                cout << "Boolean almacenado con éxito" << endl;
                            }
                            else{ //caso en el que no sea ninguno
                                cout << "Error, no ingreso correctamente el tipo de dato." << endl;
                            }
                            break;
                        case '2': //caso de almacenar integer
                            cout << "Introduzca el Integer que quiere almacenar: " << endl;
                            cin >> dato;
                            if(checkInteger(dato)){ //chequeo que lo que me pasaron por terminal es efectivamente un integer
                                vectorInt->push_back(stoi(dato)); //si es integer, lo agrego al vector de integers
                                cout << "Integer almacenado con éxito" << endl;
                            }else{ //si no es un integer, imprimo un mensaje de error por terminar
                                cout << "Error, no ingreso correctamente el tipo de dato." << endl;
                            }
                            break;
                        case '3': //caso de que sea un float lo que el usuario quiere almacenar
                            cout << "Introduzca el Float que quiere alcmacenar: " << endl;
                            cin >> dato;
                            if(checkFloat(dato)){//chequeo que lo que me pasaron por terminar es efectivamente un float
                                vectorFloat->push_back(stof(dato));//si es float, lo agrego al vector de floats
                                cout << "Float almacenado con éxito" << endl;
                            }else{//si no es un float, imprimo un mensaje de error por terminar
                                cout << "Error, no ingreso correctamente el tipo de dato." << endl;
                            }
                            break;
                        case '4'://caso de que sea un double lo que el usuario quiere almacenar
                            cout << "Introduzca el Double que quiere alcmacenar: " << endl;
                            cin >> dato;
                            if(checkDouble(dato)){//chequeo que lo que me pasaron por terminar es efectivamente un double
                                vectorDouble->push_back(stod(dato));//si es double, lo agrego al vector de double
                                cout << "Double almacenado con éxito" << endl;
                            }else{//si no es un double, imprimo un mensaje de error por terminar
                                cout << "Error, no ingreso correctamente el tipo de dato." << endl;
                            }
                            break;
                        case '5'://caso de que sea un char lo que el usuario quiere almacenar
                            cout << "Introduzca el Char que quiere alcmacenar: " << endl;
                            cin >> dato;
                            if(checkChar(dato)){//chequeo que lo que me pasaron por terminar es efectivamente un char
                                vectorChar->push_back(dato[0]);//si es char, lo agrego al vector de chars
                                cout << "Char almacenado con éxito" << endl;
                            }else{//si no es un char, imprimo un mensaje de error por terminar
                                cout << "Error, no ingreso correctamente el tipo de dato." << endl;
                            }
                            break;
                        case '6': //vuelvo al menu principal
                            condicion2=false;
                            break;
                        default: //caso default en el que el usurio no ponga una de las opciones validas.
                            cout << "Por favor elija una opción valida." << endl;
                    }
                }
                break;
            case '2': //imprimo los objetos dentro de la mochila
                cout << "------- Boolean ---------" << endl; //Para hacer el formato mas claro, imprimo el tipo de dato antes
                impimirVector(*vectorBool); //imprimo el vector de booleans
                cout << "------- Integer ---------" << endl;//Para hacer el formato mas claro, imprimo el tipo de dato antes
                impimirVector(*vectorInt);//imprimo el vector de integers
                cout << "------- Float ---------" << endl;//Para hacer el formato mas claro, imprimo el tipo de dato antes
                impimirVector(*vectorFloat);//imprimo el vector de floats
                cout << "------- Double ---------" << endl;//Para hacer el formato mas claro, imprimo el tipo de dato antes
                impimirVector(*vectorDouble);//imprimo el vector de doubles
                cout << "------- Char ---------" << endl;//Para hacer el formato mas claro, imprimo el tipo de dato antes
                impimirVector(*vectorChar);//imprimo el vector de chars
                break;
            case '3': //caso en el que se quiere borrar algo dentro de la mochila.
                condicion3=true;
                while(condicion3){//entro dentro del loop.
                    cout << "¿Que dato quieres borrar? "  << "\n" << "1. Boolean" << "\n" << "2. Integer" <<  "\n" << "3. Float " << "\n" << "4. Double" << "\n" << "5. Char" << "\n" << "6. Volver al menu" << endl; //imprimo las opciones para que el usuario las pueda elegir y decidir que tipo de dato borrar.
                    cin >> opcionMenuBorrar;
                    switch (opcionMenuBorrar){
                        case '1': //borrar un boolean
                            if(!vectorBool->empty()){ //chequeo que el vector no este vacio
                                cout << "Introduzca la posición del elemento que quiere borrar (recuerde que compienza desde 0): " << endl; //pido la posicion
                                cin >> dato;
                                if(checkInteger(dato)){ // chequeo que lo que me pasaron es un integer para poder acceder a esa posicion
                                    if(stoi(dato) <= vectorBool->size()){ //chequeo que el integer no sea mas grande que el size del vector.
                                        iteratorBool=vectorBool->begin()+stoi(dato); // sumo uno al iterator
                                        vectorBool->erase(iteratorBool); // lo borro del vector
                                    }else{
                                        cout << "El numero ingresado es mas grande que el tamaño del array" << endl; //caso que no se puede
                                    }
                                }else{
                                    cout << "No se introduzco un valor numerico" << endl; //caso que no se puede
                                }
                            }else{
                                cout << "No hay nada almacenado en el el vector boolean todavia" << endl; // si el vector esta vacio todavia, imprimo este mensaje por terminal
                            }
                            break;
                        case '2': //borrar un integer
                            if(!vectorInt->empty()){//chequeo que el vector no este vacio
                                cout << "Introduzca la posición del elemento que quiere borrar (recuerde que compienza desde 0): " << endl;//pido la posicion
                                cin >> dato;
                                if(checkInteger(dato)){ // chequeo que lo que me pasaron es un integer para poder acceder a esa posicion
                                    if(stoi(dato) <= vectorInt->size()){//chequeo que el integer no sea mas grande que el size del vector.
                                        iteratorInt=vectorInt->begin()+stoi(dato);// sumo al iterator
                                        vectorInt->erase(iteratorInt);// lo borro del vector
                                    }else{
                                        cout << "El numero ingresado es mas grande que el tamaño del array" << endl;//caso que no se puede
                                    }
                                }else{
                                    cout << "No se introduzco un valor numerico" << endl; //caso que no se puede
                                }
                            }else{
                                cout << "No hay nada almacenado en el el vector Integer todavia" << endl; // si el vector esta vacio todavia, imprimo este mensaje por terminal
                            }
                            break;
                        case '3'://borrar un float
                            if(!vectorFloat->empty()){//chequeo que el vector no este vacio
                                cout << "Introduzca la posición del elemento que quiere borrar (recuerde que compienza desde 0): " << endl;//pido la posicion
                                cin >> dato;
                                if(checkInteger(dato)){// chequeo que lo que me pasaron es un integer para poder acceder a esa posicion
                                    if(stoi(dato) <= vectorFloat->size()){//chequeo que el integer no sea mas grande que el size del vector.
                                        iteratorFloat=vectorFloat->begin()+stoi(dato);// sumo al iterator
                                        vectorFloat->erase(iteratorFloat);// lo borro del vector
                                    }else{
                                        cout << "El numero ingresado es mas grande que el tamaño del array" << endl;//caso que no se puede
                                    }
                                }else{
                                    cout << "No se introduzco un valor numerico" << endl;//caso que no se puede
                                }
                            }else{
                                cout << "No hay nada almacenado en el el vector Float todavia" << endl;// si el vector esta vacio todavia, imprimo este mensaje por terminal
                            }
                            break;
                        case '4'://borrar un Double
                            if(!vectorDouble->empty()){//chequeo que el vector no este vacio
                                cout << "Introduzca la posición del elemento que quiere borrar (recuerde que compienza desde 0): " << endl;//pido la posicion
                                cin >> dato;
                                if(checkInteger(dato)){// chequeo que lo que me pasaron es un integer para poder acceder a esa posicion
                                    if(stoi(dato) <= vectorDouble->size()){//chequeo que el integer no sea mas grande que el size del vector.
                                        iteratorDouble=vectorDouble->begin()+stoi(dato);// sumo al iterator
                                        vectorDouble->erase(iteratorDouble);// lo borro del vector
                                    }else{
                                        cout << "El numero ingresado es mas grande que el tamaño del array" << endl;//caso que no se puede
                                    }
                                }else{
                                    cout << "No se introduzco un valor numerico" << endl;//caso que no se puede
                                }
                            }else{
                                cout << "No hay nada almacenado en el el vector Double todavia" << endl;// si el vector esta vacio todavia, imprimo este mensaje por terminal
                            }
                            break;
                        case '5': //borrar un double
                            if(!vectorChar->empty()){//chequeo que el vector no este vacio
                                cout << "Introduzca la posición del elemento que quiere borrar (recuerde que compienza desde 0): " << endl;//pido la posicion
                                cin >> dato;
                                if(checkInteger(dato)){// chequeo que lo que me pasaron es un integer para poder acceder a esa posicion
                                    if(stoi(dato) <= vectorChar->size()){//chequeo que el integer no sea mas grande que el size del vector.
                                        iteratorChar=vectorChar->begin()+stoi(dato);// sumo al iterator
                                        vectorChar->erase(iteratorChar);// lo borro del vector
                                    }else{
                                        cout << "El numero ingresado es mas grande que el tamaño del array" << endl;//caso que no se puede
                                    }
                                }else{
                                    cout << "No se introduzco un valor numerico" << endl;//caso que no se puede
                                }
                            }else{
                                cout << "No hay nada almacenado en el el vector Char todavia" << endl;// si el vector esta vacio todavia, imprimo este mensaje por terminal
                            }
                            break;
                        case '6': //vuelvo al menu principal
                            condicion3=false;
                            break;
                        default: //no me pasaron uno de los numero que pedi
                            cout << "Por favor elija una opción valida." << endl;
                    }
                }
                break;
            case '4': //finalizo el programa, corto el while general
                condicion=false;
                break;
            default: //default por si no me pasan una de las opciones que quiero
                cout << "Por favor elija una opción valida." << endl;
        }
    }
    return 0;
}