#include "Dialog_message_box_Sdl_implementation.h"


#include <string>

#include <cassert>


namespace jmsd {
namespace graphic_user_interface {
namespace cross_platform {
namespace sdl {


::std::vector< SDL_MessageBoxButtonData > getButtons( Dialog_message_box::Buttons const buttons ) {
	::std::vector< SDL_MessageBoxButtonData > button_list;

	switch ( buttons ) {
		case Dialog_message_box::Buttons::OK:
		case Dialog_message_box::Buttons::Quit:
			{
				char const *button_title = nullptr;
				int button_id = -1;

				SDL_MessageBoxButtonFlags button_keys = ( SDL_MessageBoxButtonFlags )( SDL_MessageBoxButtonFlags::SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT | SDL_MessageBoxButtonFlags::SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT );

				if ( buttons == Dialog_message_box::Buttons::OK ) {
					button_title = "Ok";
					button_id = 0;
				} else if ( buttons == Dialog_message_box::Buttons::Quit ) {
					button_title = "Quit";
					button_id = 3;
				} else {
					assert( false );
				}

				SDL_MessageBoxButtonData button_data = { button_keys, button_id, button_title };
				button_list.push_back( button_data );
			}

			break;

		case Dialog_message_box::Buttons::OKCancel:
			{
				SDL_MessageBoxButtonData button_data_Ok = { SDL_MessageBoxButtonFlags::SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "Ok" };
				SDL_MessageBoxButtonData button_data_Cancel = { SDL_MessageBoxButtonFlags::SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 1, "Cancel" };
				button_list.push_back( button_data_Ok );
				button_list.push_back( button_data_Cancel );
			}

			break;

		case Dialog_message_box::Buttons::YesNo:
			{
				SDL_MessageBoxButtonData button_data_Yes = { SDL_MessageBoxButtonFlags::SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 2, "Yes" };
				SDL_MessageBoxButtonData button_data_No = { SDL_MessageBoxButtonFlags::SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 3, "No" };
				button_list.push_back( button_data_Yes );
				button_list.push_back( button_data_No );
			}

			break;
		case Dialog_message_box::Buttons::YesNoCancel:
			{
				SDL_MessageBoxButtonData button_data_Yes = { SDL_MessageBoxButtonFlags::SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 2, "Yes" };
				SDL_MessageBoxButtonData button_data_No = { 0, 3, "No" };
				SDL_MessageBoxButtonData button_data_Cancel = { SDL_MessageBoxButtonFlags::SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 1, "Cancel" };
				button_list.push_back( button_data_Yes );
				button_list.push_back( button_data_No );
				button_list.push_back( button_data_Cancel );
			}

			break;

		default:
			assert( false );
	}

	return button_list;
}

SDL_MessageBoxFlags getIcon( Dialog_message_box::Style const style ) {
	switch ( style ) {
		case Dialog_message_box::Style::Info:
			return SDL_MessageBoxFlags::SDL_MESSAGEBOX_INFORMATION;

		case Dialog_message_box::Style::Warning:
			return SDL_MessageBoxFlags::SDL_MESSAGEBOX_WARNING;

		case Dialog_message_box::Style::Error:
			return SDL_MessageBoxFlags::SDL_MESSAGEBOX_ERROR;

		case Dialog_message_box::Style::Question:
			return SDL_MessageBoxFlags::SDL_MESSAGEBOX_WARNING;

		default:
			return SDL_MessageBoxFlags::SDL_MESSAGEBOX_INFORMATION;
	}
}

::std::unique_ptr< SDL_MessageBoxData  > get_message_box_data(
	char const *const message,
	char const *const title,
	SDL_MessageBoxFlags const icon_id,
	::std::vector< SDL_MessageBoxButtonData > const &button_list )
{
	auto message_box_data = ::std::make_unique< SDL_MessageBoxData >();
	{
		message_box_data->flags = icon_id;
		message_box_data->window = nullptr;
		message_box_data->title = title;
		message_box_data->message = message;
		message_box_data->numbuttons = button_list.size();
		message_box_data->buttons = &button_list[ 0 ];
		message_box_data->colorScheme = nullptr;
	}

	return message_box_data;
}

Dialog_message_box::Selection getSelection( int const response ) {
	if ( response == -1 ) return Dialog_message_box::Selection::None;

	switch ( response ) {
		case Dialog_message_box::Selection::OK:
			return Dialog_message_box::Selection::OK;

		case Dialog_message_box::Selection::Cancel:
			return Dialog_message_box::Selection::Cancel;

		case Dialog_message_box::Selection::Yes:
			return Dialog_message_box::Selection::Yes;

		case Dialog_message_box::Selection::No:
			return Dialog_message_box::Selection::No;

		case Dialog_message_box::Selection::Quit:
			return Dialog_message_box::Selection::Quit;

		default:
			assert( false );
	}

	return Dialog_message_box::Selection::Error;
}

Dialog_message_box::Selection show( char const *message, char const *title, Dialog_message_box::Style style, Dialog_message_box::Buttons buttons ) {
	int button_id = -1;

	if ( SDL_ShowMessageBox( get_message_box_data( message, title, getIcon( style ), getButtons( buttons ) ).get(), &button_id ) < 0 ) {
		return Dialog_message_box::Selection::Error;
	}

	return getSelection( button_id );
}


} // namespace sdl
} // namespace cross_platform
} // namespace graphic_user_interface
} // namespace jmsd
