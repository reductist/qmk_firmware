EXTRAKEY_ENABLE = yes

SRC += reductist.c \
	   process_records.c \
	   encoder.c

ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
    SRC += secrets.c
endif
