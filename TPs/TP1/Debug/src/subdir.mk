################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ContratException.cpp \
../src/Ordonnanceur.cpp \
../src/Processus.cpp 

OBJS += \
./src/ContratException.o \
./src/Ordonnanceur.o \
./src/Processus.o 

CPP_DEPS += \
./src/ContratException.d \
./src/Ordonnanceur.d \
./src/Processus.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/etudiant/workspace/TPSAlgoStructureDeDonnees/TPs/TP1/header" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


