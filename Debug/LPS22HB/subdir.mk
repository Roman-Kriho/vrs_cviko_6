################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LPS22HB/LPS22HB.c 

OBJS += \
./LPS22HB/LPS22HB.o 

C_DEPS += \
./LPS22HB/LPS22HB.d 


# Each subdirectory must supply rules for building sources it contributes
LPS22HB/%.o LPS22HB/%.su LPS22HB/%.cyclo: ../LPS22HB/%.c LPS22HB/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F303x8 -DUSE_FULL_LL_DRIVER -DHSE_VALUE=8000000 -DHSE_STARTUP_TIMEOUT=100 -DLSE_STARTUP_TIMEOUT=5000 -DLSE_VALUE=32768 -DEXTERNAL_CLOCK_VALUE=8000000 -DHSI_VALUE=8000000 -DLSI_VALUE=40000 -DVDD_VALUE=3300 -DPREFETCH_ENABLE=1 -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"D:/4 rocnik/vnorene RS/workspace/vrs6/Temperature" -I"D:/4 rocnik/vnorene RS/workspace/vrs6/LPS22HB" -I"D:/4 rocnik/vnorene RS/workspace/vrs6/HTS221" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LPS22HB

clean-LPS22HB:
	-$(RM) ./LPS22HB/LPS22HB.cyclo ./LPS22HB/LPS22HB.d ./LPS22HB/LPS22HB.o ./LPS22HB/LPS22HB.su

.PHONY: clean-LPS22HB

