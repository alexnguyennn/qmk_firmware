# Build Options
#   change yes to no to disable
#
#BOOTMAGIC_ENABLE = yes  # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE  = yes  # Mouse keys(+4700)
EXTRAKEY_ENABLE  = yes  # Audio control and System control(+450)
#CONSOLE_ENABLE   = yes  # Console for debug(+400)
#COMMAND_ENABLE   = yes  # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
USB_HID_ENABLE = yes
CUSTOM_MATRIX = yes

SRC += custom_matrix.cpp

DEFAULT_FOLDER = converter/usb_usb/hasu

LAYOUTS = fullsize_ansi fullsize_iso

DEBOUNCE_TYPE = sym_g
