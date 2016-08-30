float x1, y1 ;


glutMouseFunc( mouse );


void mouse(int button, int state, int x, int y)
{

x1 = x; 
y1 = y;

}

GLfloat line1[] = 
 { x1 , y1, 0,
   x1 , y1 + 100 , 0	 
 }
 
 GLfloat line2[] = 
 { x1 , y1, 0,
   x1 + 10 , y1 + 20 , 0	 
 }

GLfloat line3[] = 
 { x1 , y1, 0,
   x1 - 10 , y1 + 20 , 0	 
 }

// after glClear and swapbuffer put this
glEnable GL_LINE_SMOOTH ) ;
glLineWidth(5) ;
glEnableClientState ( GL_VERTEX_ARRAY ) ;
glVertexPointer ( 3, GL_FLOAT , 0 , line1 );
glDrawArrays ( GL_LINES , 0 ,2 ) ;
glDisableClientState ( GL_VERTEX_ARRAY ) ;
glDisable GL_LINE_SMOOTH ) ;

glEnable GL_LINE_SMOOTH ) ;
glLineWidth(5) ;
glEnableClientState ( GL_VERTEX_ARRAY ) ;
glVertexPointer ( 3, GL_FLOAT , 0 , line2 );
glDrawArrays ( GL_LINES , 0 ,2 ) ;
glDisableClientState ( GL_VERTEX_ARRAY ) ;
glDisable GL_LINE_SMOOTH ) ;

glEnable GL_LINE_SMOOTH ) ;
glLineWidth(5) ;
glEnableClientState ( GL_VERTEX_ARRAY ) ;
glVertexPointer ( 3, GL_FLOAT , 0 , line3 );
glDrawArrays ( GL_LINES , 0 ,2 ) ;
glDisableClientState ( GL_VERTEX_ARRAY ) ;
glDisable GL_LINE_SMOOTH ) ;
