# This file intentionally left blank

DEBUG_MATRIX_SCAN_RATE_ENABLE = yes
SERIAL_DRIVER = vendor

CUSTOM_MATRIX = lite
QUANTUM_LIB_SRC += spi_master.c
SRC += matrix.c

# LED settings
RGB_MATRIX_LEDMAPS_ENABLED = yes 	# turn on per-key colours

# Encoder
ENCODER_MAP_ENABLE = no

# pointing
POINTING_DEVICE_ENABLE = yes
DRAGSCROLL_ENABLE = yes
