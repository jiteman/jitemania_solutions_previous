#include "Dialog_message_box.h"


#include "jmsd/platform_support/platform_detection/operating_system_detection.h"


#define JMSD_NATIVE_DIALOG_BOX_USE_SDL


#if defined( JMSD_NATIVE_DIALOG_BOX_USE_SDL )
	#include "_impl/Dialog_message_box_Sdl_implementation.h"

#else // #if defined( JMSD_NATIVE_DIALOG_BOX_USE_SDL )

	#if defined( JMSD_LINUX_OPERATING_SYSTEM_IS_DETECTED )
		#include "_impl/Dialog_message_box_Linux_implementation.h"

	#elif defined( JMSD_MICROSOFT_WINDOWS_OPERATING_SYSTEM_IS_DETECTED )
		#include "_impl/Dialog_message_box_Windows_implementation.h"

	#endif

#endif // #if defined( JMSD_NATIVE_DIALOG_BOX_USE_SDL )


namespace jmsd {
namespace graphic_user_interface {


// static
Dialog_message_box::Style const Dialog_message_box::kDefaultStyle = Dialog_message_box::Style::Info;

// static
Dialog_message_box::Buttons const Dialog_message_box::kDefaultButtons = Dialog_message_box::Buttons::OK;

// static
Dialog_message_box::Selection Dialog_message_box::show( char const *message, char const *title, Style style, Buttons buttons ) {
	return

#if defined( JMSD_NATIVE_DIALOG_BOX_USE_SDL )
			cross_platform::sdl::show( message, title, style, buttons );

#else // #if defined( JMSD_NATIVE_DIALOG_BOX_USE_SDL )
	#if defined( JMSD_LINUX_OPERATING_SYSTEM_IS_DETECTED )
			cross_platform::linux::show( message, title, style, buttons );

	#elif defined( JMSD_MICROSOFT_WINDOWS_OPERATING_SYSTEM_IS_DETECTED )
			cross_platform::windows::show( message, title, style, buttons );

	#endif

#endif // #if defined( JMSD_NATIVE_DIALOG_BOX_USE_SDL )
}

// static
Dialog_message_box::Selection Dialog_message_box::show( char const *message, char const *title, Style style ) {
   return show( message, title, style, kDefaultButtons );
}

// static
Dialog_message_box::Selection Dialog_message_box::show( char const *message, char const *title, Buttons buttons ) {

   return show( message, title, kDefaultStyle, buttons );
}

// static
Dialog_message_box::Selection Dialog_message_box::show( char const *message, char const *title ) {
   return show( message, title, kDefaultStyle, kDefaultButtons );
}


} // namespace graphic_user_interface
} // namespace jmsd
