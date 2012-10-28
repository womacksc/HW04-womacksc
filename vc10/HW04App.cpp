#include "HW04App.h"


void HW04App::setup(){
	*arr_ = womackscStarbucks("Starbucks_2006.csv");	
	
}

void HW04App::mouseDown( MouseEvent event )
{
}

void HW04App::update(){
	Entry* node = arr_->getNearest(0.2,0.20);	
	nearest_ = node->identifier;
}

void HW04App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( HW04App, RendererGl )
