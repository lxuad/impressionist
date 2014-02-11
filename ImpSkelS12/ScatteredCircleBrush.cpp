//
// ScatteredCircleBrush.cpp
//
// The implementation of Scattered Circle Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredcirclebrush.h"
#include <math.h>

extern float frand();

ScatteredCircleBrush::ScatteredCircleBrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
}

void ScatteredCircleBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;




	BrushMove( source, target );
}

void ScatteredCircleBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "ScatteredCircleBrush::BrushMove  document is NULL\n" );
		return;
	}
	int radius = pDoc->getSize();
	for (int k=0;k<5;k++) {
		Point offset=Point(frand()*radius-radius/2,frand()*radius-radius/2);
		Point newSource=Point(source.x+offset.x,source.y+offset.y);
		glBegin( GL_POLYGON );
		SetColor( newSource );

		for (int i=0;i<1000;i++) glVertex2d( target.x+offset.x+radius*cos(2*M_PI*i/1000), target.y+offset.y+radius*sin(2*M_PI*i/1000) );

		glEnd();
	}
}

void ScatteredCircleBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
}

