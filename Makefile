##########################################################################################################################
# File automatically-generated by tool: [projectgenerator] version: [3.14.1] date: [Thu Oct 28 19:50:40 CST 2021] 
##########################################################################################################################

# ------------------------------------------------
# Generic Makefile (based on gcc)
#
# ChangeLog :
#	2017-02-10 - Several enhancements + project update mode
#   2015-07-22 - first version
# ------------------------------------------------

######################################
# target
######################################
TARGET = 401CCU-Demo


######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Og


#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

######################################
# source
######################################
# C sources
C_SOURCES =  \
Core/Src/main.c \
Core/Src/mysetp.c \
Core/Src/stm32f4xx_it.c \
Core/Src/system_stm32f4xx.c \
Core/Src/stm32f4xx_hal_msp.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c \
u8g2_lib/u8g2_bitmap.c \
u8g2_lib/u8g2_box.c \
u8g2_lib/u8g2_buffer.c \
u8g2_lib/u8g2_circle.c \
u8g2_lib/u8g2_cleardisplay.c \
u8g2_lib/u8g2_com_stm32_hw_spi_hal.c \
u8g2_lib/u8g2_d_memory.c \
u8g2_lib/u8g2_d_setup.c \
u8g2_lib/u8g2_font.c \
u8g2_lib/u8g2_fonts.c \
u8g2_lib/u8g2_hvline.c \
u8g2_lib/u8g2_input_value.c \
u8g2_lib/u8g2_intersection.c \
u8g2_lib/u8g2_kerning.c \
u8g2_lib/u8g2_line.c \
u8g2_lib/u8g2_ll_hvline.c \
u8g2_lib/u8g2_message.c \
u8g2_lib/u8g2_polygon.c \
u8g2_lib/u8g2_selection_list.c \
u8g2_lib/u8g2_setup.c \
u8g2_lib/u8log_u8g2.c \
u8g2_lib/u8log_u8x8.c \
u8g2_lib/u8log.c \
u8g2_lib/u8x8_8x8.c \
u8g2_lib/u8x8_byte.c \
u8g2_lib/u8x8_cad.c \
u8g2_lib/u8x8_capture.c \
u8g2_lib/u8x8_d_ssd1306_128x64_noname.c \
u8g2_lib/u8x8_debounce.c \
u8g2_lib/u8x8_display.c \
u8g2_lib/u8x8_fonts.c \
u8g2_lib/u8x8_gpio.c \
u8g2_lib/u8x8_input_value.c \
u8g2_lib/u8x8_message.c \
u8g2_lib/u8x8_selection_list.c \
u8g2_lib/u8x8_setup.c \
u8g2_lib/u8x8_string.c \
u8g2_lib/u8x8_u8toa.c \
u8g2_lib/u8x8_u16toa.c \
mylibary/kalman/kalman.c \
mylibary/MPU6050/inv_mpu_dmp_motion_driver.c \
mylibary/MPU6050/inv_mpu.c \
mylibary/pid/pid.c \
mylibary/MPU6050/mpu6050.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c


# ASM sources
# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources
ASM_SOURCES =  \
startup_stm32f401xc.s


#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)gcc
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
 
#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m4

# fpu
FPU = -mfpu=fpv4-sp-d16

# float-abi
FLOAT-ABI = -mfloat-abi=hard

# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS =  \
-DSTM32F401xC \
-DUSE_HAL_DRIVER


# AS includes
AS_INCLUDES = 

# C includes
C_INCLUDES =  \
-Imylibary/MPU6050 \
-Imylibary/kalman \
-Imylibary/pid \
-Iu8g2_lib \
-Ilvgl \
-ISDCard \
-Ist7735 \
-Ilvgl/src \
-Ilvgl/port \
-ICore/Inc \
-IDrivers/STM32F4xx_HAL_Driver/Inc \
-IDrivers/CMSIS/Device/ST/STM32F4xx/Include \
-IDrivers/CMSIS/Include \
-IDrivers/STM32F4xx_HAL_Driver/Inc/Legacy



# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = STM32F401CCUx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys 
LIBDIR = 
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@		

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)
  
#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***
