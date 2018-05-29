void MyGLWidget::resizeGL (int w, int h) 
{
  glViewport(0, 0, w, h);
  float raV = float(w)/float(h);
  ra = raV;
  if (perspectiva) {
    if (raV < 1.0) FOV = 2.0f*atan(tan(angleinit)/raV);
  }
  else {
   if (raV > 1.0) {
    left = -radiEsc*raV;
    right = radiEsc*raV;
    bottom = -radiEsc;
    top = radiEsc;
   }
   else if (raV < 1.0) {
    left = -radiEsc;
    right = radiEsc;
    top = radiEsc/raV;
    bottom = -radiEsc/raV;
   }
  }
  projectTransform();
}