//
// ScatteredPointBrush.cpp
//
// The implementation of Scattered Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredpointbrush.h"

extern float frand();

ScatteredPointBrush::ScatteredPointBrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
}

void ScatteredPointBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;




	glPointSize( (float)1 );

	BrushMove( source, target );
}

void ScatteredPointBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "ScatteredPointBrush::BrushMove  document is NULL\n" );
		return;
	}
	
	int size = pDoc->getSize();

	glBegin( GL_POINTS );
		
		for (int i=0;i<size*size/4;i++) {
			Point offset=Point(frand()*size-size/2,frand()*size-size/2);
			Point newSource=Point(source.x+offset.x,source.y+offset.y);
			SetColor( newSource );
			glVertex2d( target.x+offset.x, target.y+offset.y );
		}

	glEnd();
}

void ScatteredPointBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
}

