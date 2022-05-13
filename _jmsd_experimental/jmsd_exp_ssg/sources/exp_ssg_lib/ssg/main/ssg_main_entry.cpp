#include "ssg_main_entry.h"


#include "NeHe_Lesson_0006_plus.h"
#include "NeHe_Lesson_0006_plus_sfml.h"
#include "SFML_Win32_example.h"
#include "ssg_Application.h"


namespace experimental {
namespace ssg {
namespace main {


int main_entry() {
//	return ssg_Application();
//	return ::nehe_lesson_0006_plus::NeHe_lesson_0006_plus();
//	return ::sfml_win32_example::sfml_win32_example_main();
	return ::nehe_lesson_0006_plus_sfml::NeHe_lesson_0006_plus_sfml();
}


} // namespace main
} // namespace ssg
} // namespace experimental
