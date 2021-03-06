#pragma once

#include <map>
#include <SDL.h>

namespace LM
{
	enum class Key
	{
		Key_BACKSPACE,
		Key_TAB,
		Key_CLEAR,
		Key_RETURN,
		Key_PAUSE,
		Key_ESCAPE,
		Key_SPACE,
		//Key_EXCLAIM,
		//Key_QUOTEDBL,
		//Key_HASH,
		//Key_DOLLAR,
		//Key_AMPERSAND,
		Key_QUOTE,
		//Key_LEFTPAREN,
		//Key_RIGHTPAREN,
		//Key_ASTERISK,
		//Key_PLUS,
		Key_COMMA,
		Key_MINUS,
		Key_PERIOD,
		Key_SLASH,
		Key_0,
		Key_1,
		Key_2,
		Key_3,
		Key_4,
		Key_5,
		Key_6,
		Key_7,
		Key_8,
		Key_9,
		//Key_COLON,
		Key_SEMICOLON,
		//Key_LESS,
		Key_EQUALS,
		//Key_GREATER,
		//Key_QUESTION,
		//Key_AT,
		Key_LEFTBRACKET,
		Key_BACKSLASH,
		Key_RIGHTBRACKET,
		//Key_CARET,
		//Key_UNDERSCORE,
		Key_BACKQUOTE,
		Key_a,
		Key_b,
		Key_c,
		Key_d,
		Key_e,
		Key_f,
		Key_g,
		Key_h,
		Key_i,
		Key_j,
		Key_k,
		Key_l,
		Key_m,
		Key_n,
		Key_o,
		Key_p,
		Key_q,
		Key_r,
		Key_s,
		Key_t,
		Key_u,
		Key_v,
		Key_w,
		Key_x,
		Key_y,
		Key_z,
		Key_DELETE,
		Key_KP0,
		Key_KP1,
		Key_KP2,
		Key_KP3,
		Key_KP4,
		Key_KP5,
		Key_KP6,
		Key_KP7,
		Key_KP8,
		Key_KP9,
		Key_KP_PERIOD,
		Key_KP_DIVIDE,
		Key_KP_MULTIPLY,
		Key_KP_MINUS,
		Key_KP_PLUS,
		Key_KP_ENTER,
		Key_KP_EQUALS,
		Key_UP,
		Key_DOWN,
		Key_RIGHT,
		Key_LEFT,
		Key_INSERT,
		Key_HOME,
		Key_END,
		Key_PAGEUP,
		Key_PAGEDOWN,
		Key_F1,
		Key_F2,
		Key_F3,
		Key_F4,
		Key_F5,
		Key_F6,
		Key_F7,
		Key_F8,
		Key_F9,
		Key_F10,
		Key_F11,
		Key_F12,
		Key_F13,
		Key_F14,
		Key_F15,
		Key_NUMLOCK,
		Key_CAPSLOCK,
		Key_SCROLLOCK,
		Key_RSHIFT,
		Key_LSHIFT,
		Key_RCTRL,
		Key_LCTRL,
		Key_RALT,
		Key_LALT,
		Key_RGUI,
		Key_LGUI,
		Key_MODE,
		Key_HELP,
		Key_PRINT,
		Key_SYSREQ,
		Key_BREAK,
		Key_MENU,
		Key_POWER,
		Key_NUMBER_OF_KEYS
	};

	class Keyboard
	{
	private:
		Uint8 const* m_keyState;
	public:
		Keyboard();
		~Keyboard();
		void SetModState(SDL_Keymod modState);

		bool KeyIsHeld(Key key);
		bool KeyIsHit(Key key);
		Uint8 const* GetState(int* numKeys);
		SDL_Keymod GetModState();
	private:
		int GetSDLScanCode(Key key);
	};
}
