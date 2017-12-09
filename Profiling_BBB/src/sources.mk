#SOURCES

COM_SOURCES = \
./main.c \
./memory.c \
./memoryopt.c \
./profiler_BBB.c \
./project1.c

KL25Z_SOURCES_C = \
./system_MKL25Z4.c

KL25Z_SOURCES_S = \
./startup_MKL25Z4.S

#INCLUDES 

CMSIS_INCLUDES= \
-I ../include/CMSIS

COM_INCLUDES= \
-I ../include/common

KL25Z_INCLUDES= \
-I ../include/kl25z



