#ifndef RECUADRO_H_INCLUDED
#define RECUADRO_H_INCLUDED

void recuadro(const char *titulo) {
    rlutil::locate(23, 1); // Esquina superior izquierda
    cout << (char)201;

    rlutil::locate(23, 2); // L�nea vertical izquierda
    cout << (char)186;

    rlutil::locate(23, 3); // Esquina inferior izquierda
    cout << (char)200;

    rlutil::locate(50, 2); // Posici�n para el t�tulo

    cout << titulo; // T�tulo

    for (int j = 24; j < 105; j++) {  // Ajustado el inicio de j a 105
        rlutil::locate(j, 1); // L�nea horizontal superior
        cout << (char)205;

        rlutil::locate(j, 3); // L�nea horizontal inferior
        cout << (char)205;
    }

    rlutil::locate(105, 1); // Esquina superior derecha
    cout << (char)187;

    rlutil::locate(105, 2); // L�nea vertical derecha
    cout << (char)186;

    rlutil::locate(105, 3); // Esquina inferior derecha
    cout << (char)188;
}

#endif // RECUADRO_H_INCLUDED
