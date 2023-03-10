SRC += reductist.c

# Only load these source files if the features are enabled. Keyboards can
# enable or disable these features in their own rules.mk files.
ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
  SRC += secrets.c
endif

ifeq ($(strip $(NO_SECRETS)), yes)
    OPT_DEFS += -DNO_SECRETS
endif

ifeq ($(strip $(USER_MOUSE_JIGGLE_ENABLE)), yes)
	SRC += features/mouse_jiggle.c
    OPT_DEFS += -DUSER_MOUSE_JIGGLE_ENABLE
endif

# Define these last so any other logic can set up some defines first
SRC += matrix_scan.c \
		process_records.c
