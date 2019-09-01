# Build Options
#   change yes to no to disable
#
CUSTOM_MATRIX           = yes # Custom matrix file for the ErgoDone
UNICODE_ENABLE          = yes # Unicode
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE         = yes  # Mouse keys
EXTRAKEY_ENABLE         = yes # Audio control and System control
CONSOLE_ENABLE          = yes # Console for debug
COMMAND_ENABLE          = no  # Commands for debug and configuration
# SLEEP_LED_ENABLE        = no  # Breathing sleep LED during USB suspend
NKRO_ENABLE             = yes # USB Nkey Rollover - not yet supported in LUFA
USB_6KRO_ENABLE         = no  # USB 6key Rollover
BACKLIGHT_ENABLE        = yes # Enable keyboard backlight functionality
SWAP_HANDS_ENABLE       = no  # Disable Onehand
# RGBLIGHT_ENABLE         = no
MIDI_ENABLE             = no
# AUDIO_ENABLE = yes
# TAP_DANCE_ENABLE = yes
LEADER_ENABLE = yes

# project specific files
SRC =  matrix.c     \
       left.c
I2C_DRIVER_REQUIRED = yes
