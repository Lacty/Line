
#include "line.h"
#include "../MyLib/mouse.h"


Line::Line() {}


Line::LineInfo Line::create() {
  if (!lines.size()) {
    last = Mouse::get().Pos();
  }
  LineInfo line;
  line.start = last;
  line.end = Mouse::get().Pos();
  line.color = Color(1, 1, 1);

  last = line.end;
  return line;
}

void Line::clear() {
  lines.clear();
}

void Line::update() {
  if (Mouse::get().Left().isPress) {
    lines.push_back(create());
  } else {
    last = Mouse::get().Pos();
  }

#ifdef _DEBUG
  console() << "LinesSize = " << lines.size() << std::endl;
  console() << "MousePos = " << Mouse::get().Pos() << std::endl;
#endif
}

void Line::draw() {
  for (auto it : lines) {
    gl::color(it.color);
    gl::drawLine(it.start, it.end);
  }
}