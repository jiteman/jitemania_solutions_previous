#include "../Dialog_message_box.h"


#include "include_Windows.h"


namespace jmsd {
namespace graphic_user_interface {
namespace cross_platform {
namespace windows {


UINT getIcon( Dialog_message_box::Style style );

UINT getButtons( Dialog_message_box::Buttons buttons );

Dialog_message_box::Selection getSelection( int response, Dialog_message_box::Buttons buttons );

Dialog_message_box::Selection show( char const *message, char const *title, Dialog_message_box::Style style, Dialog_message_box::Buttons buttons );


} // namespace windows
} // namespace cross_platform
} // namespace graphic_user_interface
} // namespace jmsd
