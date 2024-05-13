#include <GLFW/glfw3.h> // Do³¹czenie nag³ówka biblioteki GLFW do obs³ugi okien, kontekstów OpenGL, zdarzeñ klawiatury/myszy itp.
#include<iostream> //Dyrektywa do do³¹czenia standardowej biblioteki strumieni wejœcia-wyjœcia

using namespace std; //Dyrektywa, która pozwala na korzystanie z elementów zdefiniowanych w przestrzeni nazw.

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
        //krawêdŸ dó³ 1
        glVertex3d(-1, -1, 1);
        glVertex3d(1, -1, 1);

        //krawêdŸ dó³ 2
        glVertex3d(1, -1, 1);
        glVertex3d(1, -1, -1);

        //krawêdŸ dó³ 3
        glVertex3d(1, -1, -1);
        glVertex3d(-1, -1, -1);

        //krawêdŸ dó³ 4
        glVertex3d(-1, -1, -1);
        glVertex3d(-1, -1, 1);

        //krawêdŸ gora 1
        glVertex3d(-1, 1, 1);
        glVertex3d(1, 1, 1);

        //krawêdŸ gora 2
        glVertex3d(1, 1, 1);
        glVertex3d(1, 1, -1);

        //krawêdŸ gora 3
        glVertex3d(1, 1, -1);
        glVertex3d(-1, 1, -1);

        //krawêdŸ gora 4
        glVertex3d(-1, 1, -1);
        glVertex3d(-1, 1, 1);

        //krawedŸ bok 1
        glVertex3d(-1, -1, 1);
        glVertex3d(-1, 1, 1);
        //krawedŸ bok 2
        glVertex3d(1, -1, 1);
        glVertex3d(1, 1, 1);
        //krawedŸ bok 3
        glVertex3d(-1, -1, -1);
        glVertex3d(-1, 1, -1);
        //krawedŸ bok 4
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
    // Rozpoczêcie definiowania prymitywu GL_QUADS (czworok¹ta).

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
        int width, height;
        // Pobranie rozmiaru bufora ramki dla bie¿¹cego okna.
        glfwGetFramebufferSize(window, &width, &height);
        // Ustawienie widoku portu do rozmiaru bufora ramki.
        glViewport(0, 0, width, height);
        // Czyszczenie bufora kolorów.
        glClear(GL_COLOR_BUFFER_BIT);

        // Ustawienie macierzy projekcji.
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity(); // Zresetowanie macierzy projekcji do macierzy jednostkowej.
        // Ustawienie ortogonalnego widoku z proporcjami zale¿nymi od rozmiaru okna.
        glOrtho(-8, 8 ,-6, 6, -15, 15);

        // Powrót do modelowania transformacji macierzy.
        glMatrixMode(GL_MODELVIEW);

        // Obliczenie proporcjonalnego rozmiaru kwadratu.
        float squareSize = static_cast<float>(std::min(width, height)) * 0.2f;

        // Wywo³anie funkcji rysuj¹cej obiekty.
        display();

        glEnable(GL_CULL_FACE);
        // Ustawienie koloru t³a.
        glClearColor(1, 1, 1, 1);
        // Zamiana buforów w oknie.
        glfwSwapBuffers(window);

        // W³¹czenie œwiat³a, normalizacji normalnych i materia³ów koloru
        glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_LIGHTING);

        // Ustawienie w³aœciwoœci œwiat³a
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);

        // Ustawienie w³aœciwoœci materia³u
        glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);          //dodane GL_DEPTH_BUFFER_BIT

        glEnable(GL_DEPTH_TEST);                       // Dodane do ustawiania powierzchni widocznych

        glEnable(GL_CULL_FACE);
        // Przetwarzanie zdarzeñ w kolejce zdarzeñ.
        glfwPollEvents();

        
    }

    // Zakoñczenie dzia³ania GLFW i zwolnienie przydzielonych zasobów.
    glfwTerminate();
    return 0; // Zakoñczenie programu z kodem powrotu 0.
}