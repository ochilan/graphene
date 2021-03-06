#include "ToggleButton.h"

namespace GUI {
namespace Property {

ToggleButton::ToggleButton(std::string label) : Base(), Notify<void (bool)>(), Value<bool>(), Labeled(label) {
}

ToggleButton::~ToggleButton() {
}

} // Property
} // GUI
