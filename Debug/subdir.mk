################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../Camera.cc \
../Line.cc \
../Material.cc \
../Sphere.cc \
../Vector.cc \
../raytracer.cc 

OBJS += \
./Camera.o \
./Line.o \
./Material.o \
./Sphere.o \
./Vector.o \
./raytracer.o 

CC_DEPS += \
./Camera.d \
./Line.d \
./Material.d \
./Sphere.d \
./Vector.d \
./raytracer.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/OpenEXR -O0 -g -Wall -c -std=c++11 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


