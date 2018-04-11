#define GLM_FORCE_RADIANS
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include <QMouseEvent>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "model.h"

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core 
{
  Q_OBJECT

  public:
    MyGLWidget (QWidget *parent=0);
    ~MyGLWidget ();

  protected:
    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ( );
    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ( );
    // resizeGL - És cridat quan canvia la mida del widget
    virtual void resizeGL (int width, int height);
    // keyPressEvent - Es cridat quan es prem una tecla
    virtual void keyPressEvent (QKeyEvent *event);

  private:
    bool test = false;

    void createBuffersModel ();
    void createBuffersTerra ();
    void carregaShaders ();
    void projectTransform ();
    void projectTransform2 ();
    void viewTransform ();
    void viewTransform2 ();
    void viewTransform3 ();
    void modelTransformTerra ();
    void modelTransformPatricio ();
    void modelTransformPatricio2 ();
    void modelTransformPatricio3 ();
    void calculaCapsaModel ();

    glm::vec3 obs = glm::vec3(2.0, 1.0, 2.0);
    glm::vec3 vrp = glm::vec3(0.0, 1.0, 0.0);
    glm::vec3 up = glm::vec3(0.0, 1.0, 0.0);

    glm::vec3 test2 = glm::vec3(0.0, 0.0, 0.0);;

    // VAO i VBO names
    GLuint VAO_Patr;
    GLuint VAO_Terra;
    // Program
    QOpenGLShaderProgram *program;
    // uniform locations
    GLuint transLoc, projLoc, viewLoc;
    // attribute locations
    GLuint vertexLoc, colorLoc;

    // model
    Model patr;
    // paràmetres calculats a partir de la capsa contenidora del model
    glm::vec3 centreBasePatr;
    float escala, rotaX = 5*M_PI/4;
    float r;

};

