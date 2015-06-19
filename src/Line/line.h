
#pragma once
#include "../MyLib/noncopyable.h"
#include "../MyLib/ci_app.h"
#include <list>


class Line : public ly::noncopyable {
private:
  Vec2f last;

  struct LineInfo {
    Vec2f start;
    Vec2f end;
    Color color;
  };
  std::list<LineInfo> lines;

  LineInfo create();

public:
  Line();
  ~Line() = default;

  void clear();

  void update();
  void draw();
};