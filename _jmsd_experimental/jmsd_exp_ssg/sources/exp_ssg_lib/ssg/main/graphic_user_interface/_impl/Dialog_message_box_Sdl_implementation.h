#include "../Dialog_message_box.h"


#include "SDL2/SDL.h"

#include <vector>
#include <memory>


namespace jmsd {
namespace graphic_user_interface {
namespace cross_platform {
namespace sdl {


::std::vector< SDL_MessageBoxButtonData > getButtons( Dialog_message_box::Buttons buttons );

SDL_MessageBoxFlags getIcon( Dialog_message_box::Style style );

::std::unique_ptr< SDL_MessageBoxData  > get_message_box_data(
	char const *message,
	char const *title,
	SDL_MessageBoxFlags icon_id,
	::std::vector< SDL_MessageBoxButtonData > const &button_list );

Dialog_message_box::Selection getSelection( int response );

Dialog_message_box::Selection show( char const *message, char const *title, Dialog_message_box::Style style, Dialog_message_box::Buttons buttons );


} // namespace sdl
} // namespace cross_platform
} // namespace graphic_user_interface
} // namespace jmsd
