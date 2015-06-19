
#include "Mylib/window_size.h"
#include "MyLib/ci_app.h"
#include "MyLib/mouse.h"


class LineApp : public AppNative {
private:

public:
  void setup();

  void mouseDown(MouseEvent event) {
    Mouse::get().PushEvent(event);
  }
  void mouseUp(MouseEvent event) {
    Mouse::get().PullEvent(event);
  }
  void mouseMove(MouseEvent event) {
    Mouse::get().MoveEvent(event);
  }

  void update();
  void draw();
};

void LineApp::setup() {
  setWindowSize(int(WindowSize::Width),
                int(WindowSize::Height));
  Mouse::get();
}

void LineApp::update() {}

void LineApp::draw() {
  gl::clear(Color(0, 0, 0));
}

CINDER_APP_NATIVE(LineApp, RendererGl)
