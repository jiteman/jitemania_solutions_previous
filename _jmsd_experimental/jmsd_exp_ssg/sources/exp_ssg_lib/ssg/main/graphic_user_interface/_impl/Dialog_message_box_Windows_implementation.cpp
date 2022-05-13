#include "Dialog_message_box_Windows_implementation.h"


namespace jmsd {
namespace graphic_user_interface {
namespace cross_platform {
namespace windows {


UINT getIcon( Dialog_message_box::Style style ) {
	switch ( style ) {
		case Dialog_message_box::Style::Info:
			return MB_ICONINFORMATION;

		case Dialog_message_box::Style::Warning:
			return MB_ICONWARNING;

		case Dialog_message_box::Style::Error:
			return MB_ICONERROR;

		case Dialog_message_box::Style::Question:
			return MB_ICONQUESTION;

		default:
			return MB_ICONINFORMATION;
	}
}

UINT getButtons( Dialog_message_box::Buttons buttons ) {
	switch ( buttons ) {
		case Dialog_message_box::Buttons::OK:
		case Dialog_message_box::Buttons::Quit: // There is no 'Quit' button on Windows :(
			return MB_OK;

		case Dialog_message_box::Buttons::OKCancel:
			return MB_OKCANCEL;

		case Dialog_message_box::Buttons::YesNo:
			return MB_YESNO;

		default:
			return MB_OK;
	}
}

Dialog_message_box::Selection getSelection( int const response, Dialog_message_box::Buttons buttons ) {
	switch ( response ) {
		case IDOK:
			return buttons == Dialog_message_box::Buttons::Quit ? Dialog_message_box::Selection::Quit : Dialog_message_box::Selection::OK;

		case IDCANCEL:
			return Dialog_message_box::Selection::Cancel;

		case IDYES:
			return Dialog_message_box::Selection::Yes;

		case IDNO:
			return Dialog_message_box::Selection::No;

		default:
			return Dialog_message_box::Selection::None;
	}
}


Dialog_message_box::Selection show( char const *message, char const *title, Dialog_message_box::Style style, Dialog_message_box::Buttons buttons ) {
	UINT flags = MB_TASKMODAL;

	flags |= getIcon( style );
	flags |= getButtons( buttons );

	return getSelection( ::MessageBox( nullptr, message, title, flags ), buttons );
}


} // namespace windows
} // namespace cross_platform
} // namespace graphic_user_interface
} // namespace jmsd
