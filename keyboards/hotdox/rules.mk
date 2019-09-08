# Build Options
#   change yes to no to disable
#
CUSTOM_MATRIX           = yes # Custom matrix file for the ErgoDone
UNICODE_ENABLE          = yes # Unicode
BOOTMAGIC_ENABLE        = yes # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE         = yes  # Mouse keys(+4700)
EXTRAKEY_ENABLE         = yes # Audio control and System control(+450)
CONSOLE_ENABLE          = yes # Console for debug(+400)
COMMAND_ENABLE          = no  # Commands for debug and configuration - also timer tied with space cadet
# SLEEP_LED_ENABLE        = no  # Breathing sleep LED during USB suspend
NKRO_ENABLE             = yes # USB Nkey Rollover - not yet supported in LUFA
USB_6KRO_ENABLE         = no  # USB 6key Rollover
BACKLIGHT_ENABLE        = yes # Enable keyboard backlight functionality
SWAP_HANDS_ENABLE       = no  # Disable Onehand
# RGBLIGHT_ENABLE         = no
MIDI_ENABLE             = no
TAP_DANCE_ENABLE = yes
LEADER_ENABLE = yes

# project specific files
SRC =  matrix.c     \
       left.c
I2C_DRIVER_REQUIRED = yes
