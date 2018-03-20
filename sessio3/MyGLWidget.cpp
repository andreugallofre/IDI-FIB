#include "MyGLWidget.h"

#include <iostream>
using namespace std;

MyGLWidget::MyGLWidget (QWidget* parent) : QOpenGLWidget(parent), program(NULL)
{
  setFocusPolicy(Qt::StrongFocus);  // per rebre events de teclat
}

MyGLWidget::~MyGLWidget ()
{
  if (program != NULL)
    delete program;
}

void MyGLWidget::initializeGL ()
{
  // Cal inicialitzar l'ús de les funcions d'OpenGL
  initializeOpenGLFunctions();
  
  glClearColor (0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  carregaShaders();
  createBuffers();
}

void MyGLWidget::paintGL ()
{
  glClear (GL_COLOR_BUFFER_BIT);  // Esborrem el frame-buffer

  // Activem l'Array a pintar 
  glBindVertexArray(VAO1);

  // Pintem l'escena
  glDrawArrays(GL_TRIANGLES, 0, 3);
  
  // Desactivem el VAO
  glBindVertexArray(0);
}

void MyGLWidget::resizeGL (int w, int h)
{
  glViewport (0, 0, w, h);
}

void MyGLWidget::createBuffers ()
{
  glm::vec3 Vertices[3];  // Tres vèrtexs amb X, Y i Z
  Vertices[0] = glm::vec3(-1.0, -1.0, 0.0);
  Vertices[1] = glm::vec3(1.0, -1.0, 0.0);
  Vertices[2] = glm::vec3(0.0, 1.0, 0.0);
  
  // Creació del Vertex Array Object (VAO) que usarem per pintar
  glGenVertexArrays(1, &VAO1);
  glBindVertexArray(VAO1);

  // Creació del buffer amb les dades dels vèrtexs
  GLuint VBO1;
  glGenBuffers(1, &VBO1);
  glBindBuffer(GL_ARRAY_BUFFER, VBO1);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
  // Activem l'atribut que farem servir per vèrtex	
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  glm::vec3 Vertices2[3];  // Tres vèrtexs amb X, Y i Z
  Vertices2[0] = glm::vec3(1.0, 0.0, 0.0);
  Vertices2[1] = glm::vec3(0.0, 1.0, 0.0);
  Vertices2[2] = glm::vec3(0.0, 0.0, 1.0);
  
  GLuint VBO2;
  glGenBuffers(1, &VBO2);
  glBindBuffer(GL_ARRAY_BUFFER, VBO2);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices2), Vertices2, GL_STATIC_DRAW);
  // Activem l'atribut que farem servir per vèrtex  
  glVertexAttribPointer(vertexCol, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexCol);

  // Desactivem el VAO
  glBindVertexArray(0);
}

void MyGLWidget::carregaShaders()
{
  // Creem els shaders per al fragment shader i el vertex shader
  QOpenGLShader fs (QOpenGLShader::Fragment, this);
  QOpenGLShader vs (QOpenGLShader::Vertex, this);
  // Carreguem el codi dels fitxers i els compilem
  fs.compileSourceFile("shaders/fragshad.frag");
  vs.compileSourceFile("shaders/vertshad.vert");
  // Creem el program
  program = new QOpenGLShaderProgram(this);
  // Li afegim els shaders corresponents
  program->addShader(&fs);
  program->addShader(&vs);
  // Linkem el program
  program->link();
  // Indiquem que aquest és el program que volem usar
  program->bind();

  // Obtenim identificador per a l'atribut “vertex” del vertex shader
  vertexLoc = glGetAttribLocation (program->programId(), "vertex");
  varLoc = glGetUniformLocation (program->programId (), "val");
  vertexCol = glGetAttribLocation (program->programId(), "color");
  transLoc = glGetUniformLocation (program->programId(), "TG");
  rotateLoc = glGetUniformLocation (program->programId(), "RG");
  scaleLoc = glGetUniformLocation (program->programId(), "SG");
}

void MyGLWidget::keyPressEvent (QKeyEvent *e) {
  makeCurrent ();
  switch ( e->key() ) {
    case Qt::Key_S :
      scl += 0.05;
      scly += 0.1;
      modelTransform();
      break;
    case Qt::Key_D :
      scl -= 0.05;
      scly -= 0.1;
      modelTransform();
      break;
    case Qt::Key_Right :
      x+=0.1;
      rotation += M_PI/4;
      modelTransform();
      break;
    case Qt::Key_Left :
      x-=0.1;
      rotation += M_PI/4;
      modelTransform();
      break;
    case Qt::Key_Up :
      y+=0.1;
      rotation += M_PI/4;
      modelTransform();
      break;
    case Qt::Key_Down :
      y-=0.1;
      rotation += M_PI/4;
      modelTransform();
      break;
    default: e->ignore (); // propagar al pare
  }
  update ();
}

void MyGLWidget::modelTransform() {
  glm::mat4 TG (1.0); // Matriu de transformació, inicialment identitat
  glm::mat4 RG (1.0);
  glm::mat4 SG (1.0);

  TG = glm::translate (TG, glm::vec3 (x, y, 0.0));
  RG = glm::rotate (RG, rotation, glm::vec3 (0.0,0.0,1.0));
  SG = glm::scale (SG, glm::vec3 (scl,scly,scl));

  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
  glUniformMatrix4fv (rotateLoc, 1, GL_FALSE, &RG[0][0]);
  glUniformMatrix4fv (scaleLoc, 1, GL_FALSE, &SG[0][0]);
}



