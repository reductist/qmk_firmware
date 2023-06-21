EXTRAKEY_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes

SRC += reductist.c \
	   process_records.c \
	   encoder.c

ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
    SRC += secrets.c
endif
