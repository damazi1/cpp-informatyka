#include <GLFW/glfw3.h> // Do��czenie nag��wka biblioteki GLFW do obs�ugi okien, kontekst�w OpenGL, zdarze� klawiatury/myszy itp.
#include<iostream> //Dyrektywa do do��czenia standardowej biblioteki strumieni wej�cia-wyj�cia

using namespace std; //Dyrektywa, kt�ra pozwala na korzystanie z element�w zdefiniowanych w przestrzeni nazw.

void szescian() {
    glBegin(GL_QUADS);
    //Podstawa
    glColor3d(0.4, 0.4, 0.2);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, -1, -1); 
    //sciana lewa
    glVertex3f(1, -1, 1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, 1, 1);
    //sciana tylna
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(-1, -1, -1);
    //sciana prawa
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);
    //sciana przod
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, 1, 1);
    //sufit
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);
    glVertex3f(-1, 1, -1);

    glEnd();
}

void ostrosup() {
    glBegin(GL_TRIANGLES);
    //Podstawa
    glColor3d(0.0, 0.0, 1.0);
    glVertex3d(0, -1, -1);
    glVertex3d(1, -1, 1);
    glVertex3d(-1, -1, 1);
    
    //sciana lewa
    glColor3d(1.0, 0.0, 0.0);
    glVertex3d(1, -1, 1);
    glVertex3d(0, -1, -1);
    glVertex3d(0, 1, 0);
    //sciana prawa
    glColor3d(1.0, 0.0, 0.0);
    glVertex3d(0, -1, -1);
    glVertex3d(-1, -1, 1);
    glVertex3d(0, 1, 0);
    //sciana przod
    glColor3d(1.0, 0.0, 0.0);
    glVertex3d(-1, -1, 1);
    glVertex3d(1, -1, 1);
    glVertex3d(0, 1, 0);

    glEnd();
}

void linie() {
    {
        glBegin(GL_LINES);
        //kraw�d� d� 1
        glVertex3d(-1, -1, 1);
        glVertex3d(1, -1, 1);

        //kraw�d� d� 2
        glVertex3d(1, -1, 1);
        glVertex3d(1, -1, -1);

        //kraw�d� d� 3
        glVertex3d(1, -1, -1);
        glVertex3d(-1, -1, -1);

        //kraw�d� d� 4
        glVertex3d(-1, -1, -1);
        glVertex3d(-1, -1, 1);

        //kraw�d� gora 1
        glVertex3d(-1, 1, 1);
        glVertex3d(1, 1, 1);

        //kraw�d� gora 2
        glVertex3d(1, 1, 1);
        glVertex3d(1, 1, -1);

        //kraw�d� gora 3
        glVertex3d(1, 1, -1);
        glVertex3d(-1, 1, -1);

        //kraw�d� gora 4
        glVertex3d(-1, 1, -1);
        glVertex3d(-1, 1, 1);

        //krawed� bok 1
        glVertex3d(-1, -1, 1);
        glVertex3d(-1, 1, 1);
        //krawed� bok 2
        glVertex3d(1, -1, 1);
        glVertex3d(1, 1, 1);
        //krawed� bok 3
        glVertex3d(-1, -1, -1);
        glVertex3d(-1, 1, -1);
        //krawed� bok 4
        glVertex3d(1, -1, -1);
        glVertex3d(1, 1, -1);

        glEnd();
    }
}

void display() {
    // Ustawienie koloru rysowania na czerwony.
    glColor3d(1.0, 0.0, 0.0);

    const double t = glfwGetTime() / 100.0;
    const double a = t * 90.0;
    
    glPushMatrix();
        glRotated(a * 90, 1, 1, 1);
        szescian();
        glPushMatrix();
            glTranslated(-4, 0, 0);
            glRotated(a * 10, 1, 1, 1);
            ostrosup();
            glPushMatrix();
                glScaled(0.2,0.2,0.2);
                glTranslated(-4, 0, 0);
                glRotated(a * 10, 1, 1, 1);
                linie();
                glPopMatrix();
            glPushMatrix();
                glScaled(0.2, 0.2, 0.2);
                glTranslated(4, 0, 0);
                glRotated(a * 10, 1, 1, 1);
                linie();
                glPopMatrix();
            glPopMatrix();
        glPushMatrix();
            glTranslated(4, 0, 0);
            glRotated(a * 10, 1, 1, 1);
            ostrosup();
            glPushMatrix();
                glScaled(0.2, 0.2, 0.2);
                glTranslated(-4, 0, 0);
                glRotated(a * 10, 1, 1, 1);
                linie();
                glPopMatrix();
            glPushMatrix();
                glScaled(0.2, 0.2, 0.2);
                glTranslated(4, 0, 0);
                glRotated(a * 10, 1, 1, 1);
                linie();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    // Rozpocz�cie definiowania prymitywu GL_QUADS (czworok�ta).

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
        int width, height;
        // Pobranie rozmiaru bufora ramki dla bie��cego okna.
        glfwGetFramebufferSize(window, &width, &height);
        // Ustawienie widoku portu do rozmiaru bufora ramki.
        glViewport(0, 0, width, height);
        // Czyszczenie bufora kolor�w.
        glClear(GL_COLOR_BUFFER_BIT);

        // Ustawienie macierzy projekcji.
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity(); // Zresetowanie macierzy projekcji do macierzy jednostkowej.
        // Ustawienie ortogonalnego widoku z proporcjami zale�nymi od rozmiaru okna.
        glOrtho(-8, 8 ,-6, 6, -15, 15);

        // Powr�t do modelowania transformacji macierzy.
        glMatrixMode(GL_MODELVIEW);

        // Obliczenie proporcjonalnego rozmiaru kwadratu.
        float squareSize = static_cast<float>(std::min(width, height)) * 0.2f;

        // Wywo�anie funkcji rysuj�cej obiekty.
        display();

        glEnable(GL_CULL_FACE);
        // Ustawienie koloru t�a.
        glClearColor(1, 1, 1, 1);
        // Zamiana bufor�w w oknie.
        glfwSwapBuffers(window);

        // W��czenie �wiat�a, normalizacji normalnych i materia��w koloru
        glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_LIGHTING);

        // Ustawienie w�a�ciwo�ci �wiat�a
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);

        // Ustawienie w�a�ciwo�ci materia�u
        glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);          //dodane GL_DEPTH_BUFFER_BIT

        glEnable(GL_DEPTH_TEST);                       // Dodane do ustawiania powierzchni widocznych

        glEnable(GL_CULL_FACE);
        // Przetwarzanie zdarze� w kolejce zdarze�.
        glfwPollEvents();

        
    }

    // Zako�czenie dzia�ania GLFW i zwolnienie przydzielonych zasob�w.
    glfwTerminate();
    return 0; // Zako�czenie programu z kodem powrotu 0.
}