#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "womackscStarbucks.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW04App : public AppBasic {
  public:
	  womackscStarbucks* arr_;
	  string nearest_;
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};