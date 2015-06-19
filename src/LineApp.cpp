
#include "Mylib/window_size.h"
#include "MyLib/ci_app.h"
#include "MyLib/mouse.h"

#include "Line/line.h"

#define FPS 60


class LineApp : public AppNative {
private:
  Line line;

public:
  void setup();

  void mouseMove(MouseEvent event) {
    Mouse::get().MoveEvent(event);
  }
  void mouseDrag(MouseEvent event) {
    Mouse::get().MoveEvent(event);
  }
  void mouseDown(MouseEvent event) {
    Mouse::get().PushEvent(event);
  }
  void mouseUp(MouseEvent event) {
    Mouse::get().PullEvent(event);
  }

  void update();
  void draw();
};

void LineApp::setup() {
  setWindowSize(int(WindowSize::Width),
                int(WindowSize::Height));
  Mouse::get();

  setFrameRate(FPS);
}

void LineApp::update() {
  if (Mouse::get().Right().isPush) {
    line.clear();
  }
  line.update();
}

void LineApp::draw() {
  gl::clear(Color(0.7f, 0.7f, 0.7f));
  line.draw();
}

CINDER_APP_NATIVE(LineApp, RendererGl)
