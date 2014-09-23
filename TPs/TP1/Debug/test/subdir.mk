################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/Ordonnanceur_test.cpp \
../test/Processus_test.cpp 

OBJS += \
./test/Ordonnanceur_test.o \
./test/Processus_test.o 

CPP_DEPS += \
./test/Ordonnanceur_test.d \
./test/Processus_test.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/etudiant/workspace/TPSAlgoStructureDeDonnees/TPs/TP1/header" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


