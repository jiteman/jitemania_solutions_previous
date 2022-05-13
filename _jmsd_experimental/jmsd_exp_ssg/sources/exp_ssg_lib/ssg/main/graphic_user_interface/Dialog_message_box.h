#pragma once


namespace jmsd {
namespace graphic_user_interface {


class Dialog_message_box {

public:
	// Options for styles to apply to a message box
	enum class Style { Info, Warning, Error, Question };

	// Options for buttons to provide on a message box
	enum class Buttons { OK, OKCancel, YesNo, YesNoCancel, Quit };

	// Possible responses from a message box.
	// 'None' signifies that no option was chosen, and 'Error' signifies that an error was encountered while creating the message box.
	enum class Selection { OK, Cancel, Yes, No, Quit, None, Error };

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// The default style to apply to a message box
	static Style const kDefaultStyle;

	// The default buttons to provide on a message box
	static Buttons const kDefaultButtons;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// Blocking call to create a modal message box with the given message, title, style, and buttons
	static Selection show( char const *message, char const *title, Style style, Buttons buttons );

	// Convenience function to call show() with the default buttons
	static Selection show( char const *message, char const *title, Style style );

	// Convenience function to call show() with the default style
	static Selection show( char const *message, char const *title, Buttons buttons );

	// Convenience function to call show() with the default style and buttons
	static Selection show( char const *message, char const *title );

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	virtual ~Dialog_message_box() noexcept = delete;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Dialog_message_box() noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Dialog_message_box( Dialog_message_box const &another ) noexcept = delete;
	Dialog_message_box &operator =( Dialog_message_box const &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Dialog_message_box( Dialog_message_box &&another ) noexcept = delete;
	Dialog_message_box &operator =( Dialog_message_box &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace graphic_user_interface
} // namespace jmsd
