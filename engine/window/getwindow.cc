#include "window.ih"

Window& Window::getWindow()
{
  static Window staticWindowInstance;
  return staticWindowInstance;
}
