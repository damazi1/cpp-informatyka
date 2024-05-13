#include <GLFW/glfw3.h> // Do³¹czenie nag³ówka biblioteki GLFW do obs³ugi okien, kontekstów OpenGL, zdarzeñ klawiatury/myszy itp.
#include<iostream> //Dyrektywa do do³¹czenia standardowej biblioteki strumieni wejœcia-wyjœcia
#include<fstream>
#include<stdlib.h>
using namespace std; //Dyrektywa, która pozwala na korzystanie z elementów zdefiniowanych w przestrzeni nazw.
const int lw = 1339;
const int lk = 2000;
int jas = 0;
int Rz = 1, Gz = 1, Bz = 1;

int llw = lw;
int llk = lk;
float Rs[lw][lk];
float Gs[lw][lk];
float Bs[lw][lk];

float Rn[lw][lk];
float Gn[lw][lk];
float Bn[lw][lk];
int Mdp[3][3] = { {1,1,1},{1,1,1},{1,1,1} };
void display(float size) {
    // Ustawienie koloru rysowania na czerwony.
    glPushMatrix();
    glTranslated(0, 0, -6);
    glPointSize(1);
    // Rozpoczêcie definiowania prymitywu GL_QUADS (czworok¹ta).
    glBegin(GL_POINTS);
    for (int i = 0; i < llw; i++) {
        for (int j = 0; j < llk; j++) {
            glColor3f(((Rn[i][j] + jas) / 255)*Rz, ((Gn[i][j] + jas) / 255) * Gz, ((Bn[i][j] + jas) / 255)* Bz );
            glVertex3f(j, i, 0);
        }
    }
    /*
        // Definiowanie wierzcho³ków kwadratu. (wspó³rzêdnych x, y, z kolejnych wierzcho³ków).
        glVertex3f(-20.0, -20.0, 0.0); // Dolny lewy wierzcho³ek
        glVertex3f(20.0, -20.0, 0.0);  // Dolny prawy wierzcho³ek
        glVertex3f(20.0, 20.0, 0.0);   // Górny prawy wierzcho³ek
        glVertex3f(-20.0, 20.0, 0.0);  // Górny lewy wierzcho³ek
    */
    // Zakoñczenie definiowania prymitywu.
    glEnd();
    glPopMatrix();

    
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        switch (key) {
        case GLFW_KEY_R:
            Rz = 1;
            Gz = 1;
            Bz = 1;
            jas = 0;
            break;
        case GLFW_KEY_P:
            jas+=10;
            break;
        case GLFW_KEY_O:
            jas -= 10;
            break;
        case GLFW_KEY_Z:
            Rz = 0;
            break;
        case GLFW_KEY_X:
            Gz = 0;
            break;
        case GLFW_KEY_C:
            Bz = 0;
            Rz = 1;
            Gz = 0;
            break;
        case GLFW_KEY_D:
            for (int i = 1; i < lw - 1; i++) {
                for (int j = 1; j < lk - 1; j++) {
                     Rn[i][j] = (Mdp[0][0] * Rs[i - 1][j - 1] + Mdp[0][1] * Rs[i - 1][j] + Mdp[0][2] * Rs[i - 1][j + 1] + Mdp[1][0] * Rs[i][j - 1]
                        + Mdp[1][1] * Rs[i][j] + Mdp[2][0] * Rs[i + 1][j - 1] + Mdp[2][1] * Rs[i + 1][j] + Mdp[1][2] * Rs[i][j + 1]
                        + Mdp[2][2] * Rs[i + 1][j + 1]) / 9;
                }
            }
            for (int i = 1; i < lw - 1; i++) {
                int k = 0, l = 0;
                for (int j = 1; j < lk - 1; j++) {
                    Gn[i][j] = (Mdp[0][0] * Gs[i - 1][j - 1] +
                        Mdp[0][1] * Gs[i - 1][j] +
                        Mdp[0][2] * Gs[i - 1][j + 1] +
                        Mdp[1][0] * Gs[i][j - 1]
                        + Mdp[1][1] * Gs[i][j] + Mdp[2][0] * Gs[i + 1][j - 1] + Mdp[2][1] * Gs[i + 1][j] + Mdp[1][2] * Gs[i][j + 1]
                        + Mdp[2][2] * Gs[i + 1][j + 1]) / 9;
                }
            }
            for (int i = 1; i < lw - 1; i++) {
                int k = 0, l = 0;
                for (int j = 1; j < lk - 1; j++) {
                    Bn[i][j] = 
                        (Mdp[0][0] * Bs[i - 1][j - 1] + 
                            Mdp[0][1] * Bs[i - 1][j] +
                            Mdp[0][2] * Bs[i - 1][j+1] +
                            Mdp[1][0] * Bs[i][j - 1] +
                            Mdp[1][1] * Bs[i][j] + 
                            Mdp[1][2] * Bs[i][j + 1] +
                            Mdp[2][0] * Bs[i + 1][j - 1] +
                            Mdp[2][1] * Bs[i + 1][j] +
                            Mdp[2][2] * Bs[i + 1][j + 1]) / 9;
                }
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
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    ifstream plik("C:/glfw-3.3.8.bin.WIN64/zd5.txt");
    plik >> llw >> llk;
    cout << "wiersze=" << llw << " kolumny=" << llk << endl;
    for (int i = 0; i < lw; ++i)
        for (int j = 0; j < lk; ++j)
        {
            plik >> Rs[i][j], Rn[i][j] = Rs[i][j];
            plik >> Gs[i][j], Gn[i][j] = Gs[i][j];
            plik >> Bs[i][j], Bn[i][j] = Bs[i][j];
        }
    plik.close();

    glfwSetKeyCallback(window, key_callback);

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
        //glOrtho(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0, -10.0, 10.0);
        glOrtho(0, llk, 0, llw, 2.0, 100.0);

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

        // Przetwarzanie zdarzeñ w kolejce zdarzeñ.
        glfwPollEvents();
    }

    // Zakoñczenie dzia³ania GLFW i zwolnienie przydzielonych zasobów.
    glfwTerminate();
    return 0; // Zakoñczenie programu z kodem powrotu 0.
}