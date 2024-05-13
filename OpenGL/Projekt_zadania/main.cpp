#include <GLFW/glfw3.h> // Do��czenie nag��wka biblioteki GLFW do obs�ugi okien, kontekst�w OpenGL, zdarze� klawiatury/myszy itp.
#include<iostream> //Dyrektywa do do��czenia standardowej biblioteki strumieni wej�cia-wyj�cia
#include <cmath>
#include <fstream>

using namespace std; //Dyrektywa, kt�ra pozwala na korzystanie z element�w zdefiniowanych w przestrzeni nazw.

#define GL_PI 3.1415

enum
{
    FULL_WINDOW,
    ASPECT_1_1,
    ORTO,
    FRUST
};
int lEle, lWez, ** Ele;
double** Wez, **kolor;
void wczytajPlik(const char* nazwaPliku)
{
    ifstream plik(nazwaPliku);
    int pom1, pom2;
    plik >> lWez;
    Wez = new double* [lWez];
    for (int i = 0; i < lWez; i++)
        Wez[i] = new double[3];
    for (int i = 0; i < lWez; i++)
        plik >> pom1 >> Wez[i][0] >> Wez[i][1] >> Wez[i][2];
    plik >> lEle;
    Ele = new int* [lEle];
    for (int i = 0; i < lEle; i++)
        Ele[i] = new int[3];
    for (int i = 0; i < lEle; i++)
    {
        plik >> pom1 >> pom1 >> pom1 >> pom1 >> pom1 >> Ele[i][0] >> Ele[i][1] >> Ele[i][2];
        Ele[i][0]--;
        Ele[i][1]--;
        Ele[i][2]--;
    }
    kolor = new double* [lEle]; //wy�wietlenie ka�dego tr�jk�tnego elementu w innym kolorze
    for (int i = 0; i < lEle; i++)
    {
        kolor[i] = new double[3];
        kolor[i][0] = rand() % 255 / 255.;
        kolor[i][1] = rand() % 255 / 255.;
        kolor[i][2] = rand() % 255 / 255.;
    }
    cout << "Liczba wezlow: " << lWez << "\t" << "Liczba elementow: " << lEle << endl;
    plik.close();
}

GLfloat ssor = 0.25f, ssob = 0.25f, ssog = 0.25f,
    smor = 1.0f, smob = 1.0f, smog = 1.0f,
    ssrr = 0.25f, ssrb = 0.25f, ssrg = 0.25f,
    smrr = 1.0f, smrb = 1.0f, smrg = 1.0f,
    xr=0.0f, yr=-2.0f, zr=0.0f;





//Ustalenie parametr�w materia�u
GLfloat ambient_materials[] = { 0.329412, 0.223529, 0.027451, 1.0 };
GLfloat diffuse_materials[] = { 0.780392, 0.568627, 0.113725, 1.0 };
GLfloat specular_materials[] = { 0.992157, 0.941176, 0.807843, 1.0 };
GLfloat shininess_materials[] = { 27.8974 };

GLfloat kr = 30.0f, sr = 10.0f;

// ustawienie warto�ci startowych
GLint skala = FULL_WINDOW;
GLint rzut = ORTO;
// ustawienie parametr�w zakresu rzutni
GLfloat zakres = 10.0f;
GLfloat blisko = 1.0f;
GLfloat daleko = 10.0f;
GLfloat xAn=0.0f, yAn = 0.0f, zAn = 0.0f, xR = 0.0f, yR=0.0f, zR=0.0f,xT=0.0f,yT=0.0f,zT=-9.0;
bool iCull = 0, iDepth = 1, iOutline = 0, iFill = 0, iClock = 0;

void stozek() {
    GLfloat x1 = 0.0, k1 = 0.0,angle = 0.0; // Przechowuj� warto�ci wsp�rz�dnych i k�ta
    int iPivot = 1; // Do oznaczania zamiennych kolor�w
    glBegin(GL_TRIANGLE_FAN);
    // Czubek sto�ka jest wsp�lnym wierzcho�kiem wszystkich tr�jk�t�w z wachlarza
    // wysuni�tym do g�ry w osi z. W ten spos�b zamiast ko�a powstanie sto�ek.
    glVertex3f(0.0f, 0.0f, 7.50f);
    // Wykonujemy obr�t w oko�o i oznaczamy w r�wnych odst�pach wierzcho�ki
    // tworz�ce wachlarz tr�jk�t�w.
    for (angle = 0.0f; angle < (2.0f * GL_PI); angle += (GL_PI / 8.0f))
    {
        // Wyliczenie wsp�rz�dnych x i y kolejnego wierzcho�ka
        x1 = 5.0f * sin(angle);
        k1 = 5.0f * cos(angle);
        // Wybieranie koloru - zielony lub czerwony
        if ((iPivot % 2) == 0)
            glColor3f(0.5f, 0.0, 1.0f);
        else
            glColor3f(1.0f, 0.8f, 0.0f);
        
        // Inkrementacja zmiennej okre�laj�cej rodzaj koloru
        iPivot++;
        // Definiowanie kolejnego wierzcho�ka w wachlarzu tr�jk�t�w
        glVertex3f(x1, k1, 0);
    }
    glEnd();
}

void stozek2() {
    GLfloat x1 = 0.0, x2 = 0.0, k1 = 0.0, k2 = 0.0, angle = 0.0; // Przechowuj� warto�ci wsp�rz�dnych i k�ta
    int iPivot = 1; // Do oznaczania zamiennych kolor�w
    glBegin(GL_TRIANGLE_STRIP);
    // Wykonujemy obr�t w oko�o i oznaczamy w r�wnych odst�pach wierzcho�ki
    // tworz�ce tr�jk�ty sklejane.
    for (angle = 0.0f; angle < (2.0f * GL_PI); angle += (GL_PI / 8.0f))
    {
        // Wyliczenie wsp�rz�dnych x i y kolejnego wierzcho�ka
        x2 = 8.0f * sin(angle);
        k2 = 8.0f * cos(angle);
        x1 = 8.0f * sin(angle);
        k1 = 8.0f * cos(angle);
        // Wybieranie koloru - zielony lub czerwony
        if ((iPivot % 2) == 0)
            glColor3f(0.0f, 1.0f, 0.0f);
        else
            glColor3f(1.0f, 0.0f, 0.0f);
        // Inkrementacja zmiennej okre�laj�cej rodzaj koloru
        iPivot++;
        // Definiowanie kolejnej pary wierzcho�k�w
        glVertex3f(x1, k1, 7.5f);
        glVertex3f(x2, k2, 0.0f);
    }
    // Zako�czenie rysowania tr�jk�t�w walca
    glEnd();
}

void klepsydra() {
    glBegin(GL_LINES);
    // przod
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);

    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-0.5, 0.0, 1.0);

    glVertex3f(-0.5, 0.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);


    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);

    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(0.5, 0.0, 1.0);

    glVertex3f(0.5, 0.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);

    // tyl

    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);

    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-0.5, 0.0, -1.0);

    glVertex3f(-0.5, 0.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);


    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);

    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(0.5, 0.0, -1.0);

    glVertex3f(0.5, 0.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);

    // boki
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);

    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);

    glVertex3f(-0.5, 0.0, -1.0);
    glVertex3f(-0.5, 0.0, 1.0);


    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);

    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);

    glVertex3f(0.5, 0.0, -1.0);
    glVertex3f(0.5, 0.0, 1.0);

    glEnd();
}

void Figura() {
    glBegin(GL_TRIANGLES);
    for (int nrEl = 0; nrEl < lEle; nrEl++)
    {
        //ka�dy tr�jk�t w innym kolorze
        glColor3f(kolor[nrEl][0], kolor[nrEl][1], kolor[nrEl][2]);
        // definiowanie 1 wierzcho�ka
        glVertex3f(Wez[Ele[nrEl][0]][0], Wez[Ele[nrEl][0]][1], Wez[Ele[nrEl][0]][2]);
        // nale�y zdefiniowa� wsp�rz�dne dla pozosta�ych 2 wierzcho�k�w
        glVertex3f(Wez[Ele[nrEl][1]][0], Wez[Ele[nrEl][1]][1], Wez[Ele[nrEl][1]][2]);
        glVertex3f(Wez[Ele[nrEl][2]][0], Wez[Ele[nrEl][2]][1], Wez[Ele[nrEl][2]][2]);
    }
    glEnd();
}

void drawSphere(float R, int numTheta, int numPhi) {
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < numTheta; ++i) {
        float theta1 = (i * 2.0 * GL_PI) / numTheta;
        float theta2 = ((i + 1) * 2.0 * GL_PI) / numTheta;

        for (int j = 0; j < numPhi; ++j) {
            float phi1 = (j * GL_PI) / numPhi;
            float phi2 = ((j + 1) * GL_PI) / numPhi;
            float x1 = R * sin(phi1) * cos(theta1);
            float y1 = R * sin(phi1) * sin(theta1);
            float z1 = R * cos(phi1);
            float x2 = R * sin(phi2) * cos(theta1);
            float y2 = R * sin(phi2) * sin(theta1);
            float z2 = R * cos(phi2);
            float x3 = R * sin(phi2) * cos(theta2);
            float y3 = R * sin(phi2) * sin(theta2);
            float z3 = R * cos(phi2);
            float x4 = R * sin(phi1) * cos(theta2);
            float y4 = R * sin(phi1) * sin(theta2);
            float z4 = R * cos(phi1);
            // Pierwszy tr�jk�t
            glNormal3f(x1, y1, z1);
            glVertex3f(x1, y1, z1);
            glNormal3f(x2, y2, z2);
            glVertex3f(x2, y2, z2);
            glNormal3f(x3, y3, z3);
            glVertex3f(x3, y3, z3);
            // Drugi tr�jk�t
            glNormal3f(x1, y1, z1);
            glVertex3f(x1, y1, z1);
            glNormal3f(x3, y3, z3);
            glVertex3f(x3, y3, z3);
            glNormal3f(x4, y4, z4);
            glVertex3f(x4, y4, z4);
        }
    }
    glEnd();
}


void display(float size) {
    // Ustawienie koloru rysowania na czerwony.

    if (iCull)
        glEnable(GL_CULL_FACE);
    else
        glDisable(GL_CULL_FACE);

    if (iDepth)
        glEnable(GL_DEPTH_TEST);
    else
        glDisable(GL_DEPTH_TEST);

    if (iOutline)
        glPolygonMode(GL_BACK, GL_LINE);
    else
        glPolygonMode(GL_BACK, GL_FILL);

    if (iFill)
        glShadeModel(GL_FLAT);
    else
        glShadeModel(GL_SMOOTH);

    if (iClock)
        glFrontFace(GL_CW);
    else
        glFrontFace(GL_CCW);

    const double t = glfwGetTime() / 100.0;
    const double a = t * 90.0;

    // Rozpocz�cie definiowania prymitywu GL_QUADS (czworok�ta).
    glPushMatrix();
    glTranslated(xT, yT, zT);
    glRotated(xAn, 1,0,0);
    glRotated(yAn, 0, 1, 0);
    glRotated(zAn, 0, 0, 1);
    glRotated(a * 10, 1, 1, 0.2);
    glScaled(2, 2, 2);
    drawSphere(1,500,500);
    glPopMatrix();
    // Zako�czenie definiowania prymitywu.

}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        switch (key) {
        case GLFW_KEY_A:
            kr += 3;
            break;
        case GLFW_KEY_S:
            sr += 3;
            break;
        case GLFW_KEY_D:
            kr -= 3;
            break;
        case GLFW_KEY_F:
            sr -= 3;
            break;
        case GLFW_KEY_1:
            ssor = 1.0f;
            ssog = 0.0f;
            ssob = 0.0f;
            break;
        case GLFW_KEY_2:  //kolor swiatla ogolnego slabego
            ssor = 0.25f;
            ssog = 0.25f;
            ssob = 0.25f;
            break;
        case GLFW_KEY_3:
            smor = 0;
            smog = 0;
            smob = 1;
            break;
        case GLFW_KEY_4: //kolor swiatla ogolnego mocnego
            smor = 1;
            smog = 1;
            smob = 1;
            break;
        case GLFW_KEY_5:  //kolor swiatla materialu mocnego
            smrr = 0;
            smrg = 0;
            smrb = 1;
            break;
        case GLFW_KEY_6:
            smrr = 1.0f;
            smrg = 1.0f;
            smrb = 1.0f;
            break;
        case GLFW_KEY_7:    //kolor swiatla slabego materialu
            ssrr = 0.5f;
            ssrg = 0.5f;
            ssrb = 0.0f;
            break;
        case GLFW_KEY_8:
            ssrr = 0.25f;
            ssrg = 0.25f;
            ssrb = 0.25f;
            break;
            case GLFW_KEY_R:
            kr = 30.0f;
            sr = 10.f;
            break;
            case GLFW_KEY_Z:
                zr += 0.1;
                break;
            case GLFW_KEY_X:
                zr -= 0.1;
                break;
            case GLFW_KEY_C:
                yr += 0.1;
                break;
            case GLFW_KEY_V:
                yr -= 0.1;
                break;
            case GLFW_KEY_B:
                zr += 0.1;
                break;
            case GLFW_KEY_G:
                zr -= 0.1;
                break;

            case GLFW_KEY_K:
                glEnable(GL_LIGHTING); // w��czenie o�wietle
                break;

            case GLFW_KEY_L:
                glDisable(GL_LIGHTING); // w��czenie o�wietle
                break;
            case GLFW_KEY_M:
                glEnable(GL_LIGHT1); // w��czenie �wiat�a 1
                break;
            case GLFW_KEY_N:
                glDisable(GL_LIGHT1); // w��czenie �wiat�a 1
                break;
            case GLFW_KEY_J:
                glEnable(GL_LIGHT0); // w��czenie �wiat�a 0 
                break;
            case GLFW_KEY_H:
                glDisable(GL_LIGHT0); // w��czenie �wiat�a 0 
                break;
                
        case GLFW_KEY_T:
            if (iCull) {
                iCull = 0;
            }
            else {
                iCull = 1;
            }
            break;
        case GLFW_KEY_Y:
            if (iDepth) {
                iDepth = 0;
            }
            else {
                iDepth = 1;
            }
            break;
        case GLFW_KEY_U:
            if (iOutline) {
                iOutline = 0;
            }
            else {
                iOutline = 1;
            }
            break;
        case GLFW_KEY_I:
            if (iFill) {
                iFill = 0;
            }
            else {
                iFill = 1;
            }
            break;
        case GLFW_KEY_O:
            if (iClock) {
                iClock = 0;
            }
            else {
                iClock = 1;
            }
            break;
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, GLFW_TRUE);
            break;
        }
    }
}

// Definiowanie sta�ych dla w�a�ciwo�ci �wiat�a
const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

// Definiowanie sta�ych dla w�a�ciwo�ci materia�u
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(void)
{
    GLFWwindow* window; // Deklaracja wska�nika na obiekt okna GLFW.

    // Inicjalizacja biblioteki GLFW. Je�li inicjalizacja si� nie powiedzie, program zako�czy dzia�anie z kodem -1.
    if (!glfwInit())
        return -1;

    // Utworzenie okna o rozmiarach 800x600 pikseli i tytule "Przykladowe Okno GLFW". 
    // Ostatnie dwa argumenty dotycz� okna dzielonego i atrybut�w kontekstu OpenGL, kt�re s� tutaj ustawione na NULL.
    window = glfwCreateWindow(800, 600, "Przykladowe Okno GLFW", NULL, NULL);
    // Je�li utworzenie okna si� nie powiedzie, zako�czenie dzia�ania GLFW i zwolnienie zasob�w.
    wczytajPlik("C://glfw-3.3.8.bin.WIN64/torus.msh");
    wczytajPlik("C://student/Dz_P/inicjal.msh");
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Ustawienie bie��cego kontekstu renderowania na utworzone okno.
    glfwMakeContextCurrent(window);

    // P�tla renderowania, wykonuje si� dop�ki okno nie zostanie zamkni�te.
    while (!glfwWindowShouldClose(window))
    {
        // definiowanie warto�ci parametr�w �wiat�a og�lnego
        GLfloat fPozycja_swiatla[4] = { 100.0f, 100.0f, 50.0f, 1.0f };
        GLfloat fSlabe_swiatlo[4] = { ssor, ssog, ssob, 1.0f };
        GLfloat fMocne_swiatlo[4] = { smor,smog,smob, 1.0f };

        GLfloat fPozycja_reflektora[4] = { 0.0f, 10.0f, -2.5f, 1.0f };
        GLfloat fKierunek_reflektora[4] = {xr,yr,zr, 1.0f }; // kierunek w kt�rym ma �wieci� reflektor
        GLfloat ffSlabe_swiatlo[] = { ssrr, ssrg, ssrb, 1.0f };
        GLfloat ffMocne_swiatlo[] = { smrr, smrg, smrb, 1.0f };

        int width, height;
        // Pobranie rozmiaru bufora ramki dla bie��cego okna.
        glfwGetFramebufferSize(window, &width, &height);
        // Ustawienie widoku portu do rozmiaru bufora ramki.
        glViewport(0, 0, width, height);
        // Czyszczenie bufora kolor�w.
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        // Ustawienie macierzy projekcji.
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity(); // Zresetowanie macierzy projekcji do macierzy jednostkowej.
        // Ustawienie ortogonalnego widoku z proporcjami zale�nymi od rozmiaru okna.
        const float ar = (float)width / (float)height;
        glOrtho(-8,8,-6,6,-15,15);
        // Powr�t do modelowania transformacji macierzy.
        glMatrixMode(GL_MODELVIEW);

        // Obliczenie proporcjonalnego rozmiaru kwadratu.
        float squareSize = static_cast<float>(std::min(width, height)) * 0.2f;

        // Wywo�anie funkcji rysuj�cej obiekty.
        display(squareSize);

        glEnable(GL_CULL_FACE);
        // Ustawienie koloru t�a.
        glClearColor(1, 1, 1, 1);
        // Zamiana bufor�w w oknie.
        glfwSwapBuffers(window);

        glEnable(GL_NORMALIZE);
        // ustawienia parametr�w dla �wiat�a og�lnego
        glLightfv(GL_LIGHT0, GL_AMBIENT, fSlabe_swiatlo); // �wiat�o otoczenia
        glLightfv(GL_LIGHT0, GL_DIFFUSE, fMocne_swiatlo); // �wiat�o rozproszenia
        glLightfv(GL_LIGHT0, GL_SPECULAR, fMocne_swiatlo); // �wiat�o odbite
        glLightfv(GL_LIGHT0, GL_POSITION, fPozycja_swiatla); // pozycja �wiat�a

        glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, kr); // reflektor o k�cie rozwarcia 60 stopni
        glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, sr); // stopie� skupienia reflektora
        glLightfv(GL_LIGHT1, GL_AMBIENT, ffSlabe_swiatlo); // �wiat�o otoczenia
        glLightfv(GL_LIGHT1, GL_DIFFUSE, ffMocne_swiatlo); // �wiat�o rozproszenia
        glLightfv(GL_LIGHT1, GL_SPECULAR, ffMocne_swiatlo); // �wiat�o odbite
        glLightfv(GL_LIGHT1, GL_POSITION, fPozycja_reflektora); // pozycja �wiat�a
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, fKierunek_reflektora); // kierunek w kt�ry odwr�cony jest reflektor      
        
        //Ustawienie materia��w
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_materials);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_materials);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_materials);
        glMaterialfv(GL_FRONT, GL_SHININESS, shininess_materials);

        //�ledzenie koloru materia��w
        glEnable(GL_COLOR_MATERIAL);

        glfwSetKeyCallback(window, key_callback);
        // Przetwarzanie zdarze� w kolejce zdarze�.
        glfwPollEvents();
    }

    // Zako�czenie dzia�ania GLFW i zwolnienie przydzielonych zasob�w.
    glfwTerminate();
    return 0; // Zako�czenie programu z kodem powrotu 0.
}