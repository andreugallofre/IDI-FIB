#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#define GLM_FORCE_RADIANS

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
  Q_OBJECT

  public:
    MyGLWidget (QWidget *parent=0);
    ~MyGLWidget ();
    
  protected:
    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ();

    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ();
 
    // resize - Es cridat quan canvia la mida del widget
    virtual void resizeGL (int width, int height);

    virtual void keyPressEvent (QKeyEvent *e);

  private:
    void createBuffers ();
    void carregaShaders ();
    void modelTransform();
    
    float scl = 0.0;
    float scly = 0.0;

    float rotation = 0.0;

    float x = 0.0;
    float y = 0.0;
    float z = 0.0;

    
    // attribute locations
    GLuint vertexLoc;
    GLuint varLoc;
    GLuint vertexCol;
    GLuint transLoc;
    GLuint rotateLoc;
    GLuint scaleLoc;
    
    // Program
    QOpenGLShaderProgram *program;

    GLuint VAO1;
};
