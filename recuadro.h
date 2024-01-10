#ifndef RECUADRO_H_INCLUDED
#define RECUADRO_H_INCLUDED

void recuadro(const char *titulo) {
    rlutil::locate(23, 1); // Esquina superior izquierda
    cout << (char)201;

    rlutil::locate(23, 2); // Línea vertical izquierda
    cout << (char)186;

    rlutil::locate(23, 3); // Esquina inferior izquierda
    cout << (char)200;

    rlutil::locate(50, 2); // Posición para el título

    cout << titulo; // Título

    for (int j = 24; j < 105; j++) {  // Ajustado el inicio de j a 105
        rlutil::locate(j, 1); // Línea horizontal superior
        cout << (char)205;

        rlutil::locate(j, 3); // Línea horizontal inferior
        cout << (char)205;
    }

    rlutil::locate(105, 1); // Esquina superior derecha
    cout << (char)187;

    rlutil::locate(105, 2); // Línea vertical derecha
    cout << (char)186;

    rlutil::locate(105, 3); // Esquina inferior derecha
    cout << (char)188;
}

#endif // RECUADRO_H_INCLUDED
