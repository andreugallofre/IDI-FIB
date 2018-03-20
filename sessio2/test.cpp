void MyGLWidget::keyPressEvent (QKeyEvent *e) {
	makeCurrent ();
	switch ( e->key() ) {
		case Qt::Key_S :
			scl += 0.1;
			glUniform1f (varLoc, scl);
			break;
		case Qt::Key_D :
			scl -= 0.1;
			glUniform1f (varLoc, scl);
			break;
		default: e->ignore (); // propagar al pare
	}
	update ();
}
