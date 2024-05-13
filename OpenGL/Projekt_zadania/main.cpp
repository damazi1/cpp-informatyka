#include <GLFW/glfw3.h> // Do³¹czenie nag³ówka biblioteki GLFW do obs³ugi okien, kontekstów OpenGL, zdarzeñ klawiatury/myszy itp.
#include<iostream> //Dyrektywa do do³¹czenia standardowej biblioteki strumieni wejœcia-wyjœcia
#include <cmath>
#include <fstream>

using namespace std; //Dyrektywa, która pozwala na korzystanie z elementów zdefiniowanych w przestrzeni nazw.

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
    kolor = new double* [lEle]; //wyœwietlenie ka¿dego trójk¹tnego elementu w innym kolorze
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





//Ustalenie parametrów materia³u
GLfloat ambient_materials[] = { 0.329412, 0.223529, 0.027451, 1.0 };
GLfloat diffuse_materials[] = { 0.780392, 0.568627, 0.113725, 1.0 };
GLfloat specular_materials[] = { 0.992157, 0.941176, 0.807843, 1.0 };
GLfloat shininess_materials[] = { 27.8974 };

GLfloat kr = 30.0f, sr = 10.0f;

// ustawienie wartoœci startowych
GLint skala = FULL_WINDOW;
GLint rzut = ORTO;
// ustawienie parametrów zakresu rzutni
GLfloat zakres = 10.0f;
GLfloat blisko = 1.0f;
GLfloat daleko = 10.0f;
GLfloat xAn=0.0f, yAn = 0.0f, zAn = 0.0f, xR = 0.0f, yR=0.0f, zR=0.0f,xT=0.0f,yT=0.0f,zT=-9.0;
bool iCull = 0, iDepth = 1, iOutline = 0, iFill = 0, iClock = 0;

void stozek() {
    GLfloat x1 = 0.0, k1 = 0.0,angle = 0.0; // Przechowuj¹ wartoœci wspó³rzêdnych i k¹ta
    int iPivot = 1; // Do oznaczania zamiennych kolorów
    glBegin(GL_TRIANGLE_FAN);
    // Czubek sto¿ka jest wspólnym wierzcho³kiem wszystkich trójk¹tów z wachlarza
    // wysuniêtym do góry w osi z. W ten sposób zamiast ko³a powstanie sto¿ek.
    glVertex3f(0.0f, 0.0f, 7.50f);
    // Wykonujemy obrót w oko³o i oznaczamy w równych odstêpach wierzcho³ki
    // tworz¹ce wachlarz trójk¹tów.
    for (angle = 0.0f; angle < (2.0f * GL_PI); angle += (GL_PI / 8.0f))
    {
        // Wyliczenie wspó³rzêdnych x i y kolejnego wierzcho³ka
        x1 = 5.0f * sin(angle);
        k1 = 5.0f * cos(angle);
        // Wybieranie koloru - zielony lub czerwony
        if ((iPivot % 2) == 0)
            glColor3f(0.5f, 0.0, 1.0f);
        else
            glColor3f(1.0f, 0.8f, 0.0f);
        
        // Inkrementacja zmiennej okreœlaj¹cej rodzaj koloru
        iPivot++;
        // Definiowanie kolejnego wierzcho³ka w wachlarzu trójk¹tów
        glVertex3f(x1, k1, 0);
    }
    glEnd();
}

void stozek2() {
    GLfloat x1 = 0.0, x2 = 0.0, k1 = 0.0, k2 = 0.0, angle = 0.0; // Przechowuj¹ wartoœci wspó³rzêdnych i k¹ta
    int iPivot = 1; // Do oznaczania zamiennych kolorów
    glBegin(GL_TRIANGLE_STRIP);
    // Wykonujemy obrót w oko³o i oznaczamy w równych odstêpach wierzcho³ki
    // tworz¹ce trójk¹ty sklejane.
    for (angle = 0.0f; angle < (2.0f * GL_PI); angle += (GL_PI / 8.0f))
    {
        // Wyliczenie wspó³rzêdnych x i y kolejnego wierzcho³ka
        x2 = 8.0f * sin(angle);
        k2 = 8.0f * cos(angle);
        x1 = 8.0f * sin(angle);
        k1 = 8.0f * cos(angle);
        // Wybieranie koloru - zielony lub czerwony
        if ((iPivot % 2) == 0)
            glColor3f(0.0f, 1.0f, 0.0f);
        else
            glColor3f(1.0f, 0.0f, 0.0f);
        // Inkrementacja zmiennej okreœlaj¹cej rodzaj koloru
        iPivot++;
        // Definiowanie kolejnej pary wierzcho³ków
        glVertex3f(x1, k1, 7.5f);
        glVertex3f(x2, k2, 0.0f);
    }
    // Zakoñczenie rysowania trójk¹tów walca
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
        //ka¿dy trójk¹t w innym kolorze
        glColor3f(kolor[nrEl][0], kolor[nrEl][1], kolor[nrEl][2]);
        // definiowanie 1 wierzcho³ka
        glVertex3f(Wez[Ele[nrEl][0]][0], Wez[Ele[nrEl][0]][1], Wez[Ele[nrEl][0]][2]);
        // nale¿y zdefiniowaæ wspó³rzêdne dla pozosta³ych 2 wierzcho³ków
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
            // Pierwszy trójk¹t
            glNormal3f(x1, y1, z1);
            glVertex3f(x1, y1, z1);
            glNormal3f(x2, y2, z2);
            glVertex3f(x2, y2, z2);
            glNormal3f(x3, y3, z3);
            glVertex3f(x3, y3, z3);
            // Drugi trójk¹t
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

    // Rozpoczêcie definiowania prymitywu GL_QUADS (czworok¹ta).
    glPushMatrix();
    glTranslated(xT, yT, zT);
    glRotated(xAn, 1,0,0);
    glRotated(yAn, 0, 1, 0);
    glRotated(zAn, 0, 0, 1);
    glRotated(a * 10, 1, 1, 0.2);
    glScaled(2, 2, 2);
    drawSphere(1,500,500);
    glPopMatrix();
    // Zakoñczenie definiowania prymitywu.

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
                glEnable(GL_LIGHTING); // w³¹czenie oœwietle
                break;

            case GLFW_KEY_L:
                glDisable(GL_LIGHTING); // w³¹czenie oœwietle
                break;
            case GLFW_KEY_M:
                glEnable(GL_LIGHT1); // w³¹czenie œwiat³a 1
                break;
            case GLFW_KEY_N:
                glDisable(GL_LIGHT1); // w³¹czenie œwiat³a 1
                break;
            case GLFW_KEY_J:
                glEnable(GL_LIGHT0); // w³¹czenie œwiat³a 0 
                break;
            case GLFW_KEY_H:
                glDisable(GL_LIGHT0); // w³¹czenie œwiat³a 0 
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

// Definiowanie sta³ych dla w³aœciwoœci œwiat³a
const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

// Definiowanie sta³ych dla w³aœciwoœci materia³u
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(void)
{
    GLFWwindow* window; // Deklaracja wskaŸnika na obiekt okna GLFW.

    // Inicjalizacja biblioteki GLFW. Jeœli inicjalizacja siê nie powiedzie, program zakoñczy dzia³anie z kodem -1.
    if (!glfwInit())
        return -1;

    // Utworzenie okna o rozmiarach 800x600 pikseli i tytule "Przykladowe Okno GLFW". 
    // Ostatnie dwa argumenty dotycz¹ okna dzielonego i atrybutów kontekstu OpenGL, które s¹ tutaj ustawione na NULL.
    window = glfwCreateWindow(800, 600, "Przykladowe Okno GLFW", NULL, NULL);
    // Jeœli utworzenie okna siê nie powiedzie, zakoñczenie dzia³ania GLFW i zwolnienie zasobów.
    wczytajPlik("C://glfw-3.3.8.bin.WIN64/torus.msh");
    wczytajPlik("C://student/Dz_P/inicjal.msh");
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Ustawienie bie¿¹cego kontekstu renderowania na utworzone okno.
    glfwMakeContextCurrent(window);

    // Pêtla renderowania, wykonuje siê dopóki okno nie zostanie zamkniête.
    while (!glfwWindowShouldClose(window))
    {
        // definiowanie wartoœci parametrów œwiat³a ogólnego
        GLfloat fPozycja_swiatla[4] = { 100.0f, 100.0f, 50.0f, 1.0f };
        GLfloat fSlabe_swiatlo[4] = { ssor, ssog, ssob, 1.0f };
        GLfloat fMocne_swiatlo[4] = { smor,smog,smob, 1.0f };

        GLfloat fPozycja_reflektora[4] = { 0.0f, 10.0f, -2.5f, 1.0f };
        GLfloat fKierunek_reflektora[4] = {xr,yr,zr, 1.0f }; // kierunek w którym ma œwieciæ reflektor
        GLfloat ffSlabe_swiatlo[] = { ssrr, ssrg, ssrb, 1.0f };
        GLfloat ffMocne_swiatlo[] = { smrr, smrg, smrb, 1.0f };

        int width, height;
        // Pobranie rozmiaru bufora ramki dla bie¿¹cego okna.
        glfwGetFramebufferSize(window, &width, &height);
        // Ustawienie widoku portu do rozmiaru bufora ramki.
        glViewport(0, 0, width, height);
        // Czyszczenie bufora kolorów.
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        // Ustawienie macierzy projekcji.
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity(); // Zresetowanie macierzy projekcji do macierzy jednostkowej.
        // Ustawienie ortogonalnego widoku z proporcjami zale¿nymi od rozmiaru okna.
        const float ar = (float)width / (float)height;
        glOrtho(-8,8,-6,6,-15,15);
        // Powrót do modelowania transformacji macierzy.
        glMatrixMode(GL_MODELVIEW);

        // Obliczenie proporcjonalnego rozmiaru kwadratu.
        float squareSize = static_cast<float>(std::min(width, height)) * 0.2f;

        // Wywo³anie funkcji rysuj¹cej obiekty.
        display(squareSize);

        glEnable(GL_CULL_FACE);
        // Ustawienie koloru t³a.
        glClearColor(1, 1, 1, 1);
        // Zamiana buforów w oknie.
        glfwSwapBuffers(window);

        glEnable(GL_NORMALIZE);
        // ustawienia parametrów dla œwiat³a ogólnego
        glLightfv(GL_LIGHT0, GL_AMBIENT, fSlabe_swiatlo); // œwiat³o otoczenia
        glLightfv(GL_LIGHT0, GL_DIFFUSE, fMocne_swiatlo); // œwiat³o rozproszenia
        glLightfv(GL_LIGHT0, GL_SPECULAR, fMocne_swiatlo); // œwiat³o odbite
        glLightfv(GL_LIGHT0, GL_POSITION, fPozycja_swiatla); // pozycja œwiat³a

        glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, kr); // reflektor o k¹cie rozwarcia 60 stopni
        glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, sr); // stopieñ skupienia reflektora
        glLightfv(GL_LIGHT1, GL_AMBIENT, ffSlabe_swiatlo); // œwiat³o otoczenia
        glLightfv(GL_LIGHT1, GL_DIFFUSE, ffMocne_swiatlo); // œwiat³o rozproszenia
        glLightfv(GL_LIGHT1, GL_SPECULAR, ffMocne_swiatlo); // œwiat³o odbite
        glLightfv(GL_LIGHT1, GL_POSITION, fPozycja_reflektora); // pozycja œwiat³a
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, fKierunek_reflektora); // kierunek w który odwrócony jest reflektor      
        
        //Ustawienie materia³ów
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_materials);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_materials);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_materials);
        glMaterialfv(GL_FRONT, GL_SHININESS, shininess_materials);

        //Œledzenie koloru materia³ów
        glEnable(GL_COLOR_MATERIAL);

        glfwSetKeyCallback(window, key_callback);
        // Przetwarzanie zdarzeñ w kolejce zdarzeñ.
        glfwPollEvents();
    }

    // Zakoñczenie dzia³ania GLFW i zwolnienie przydzielonych zasobów.
    glfwTerminate();
    return 0; // Zakoñczenie programu z kodem powrotu 0.
}