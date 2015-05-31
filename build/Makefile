# Name: Makefile.sh
# Description: makefile for entire build
# Author: G.Molyboga(St.George.Molyboga@gmail.com)
# Date: 30 May, 2015
# Review: 31 May, 2015

include Makefile-settings

all: $(TARGET)
include $(Makefile_core_PWD)/Makefile-core

.PHONY: clean clean_all clean_bin

INCLUDEPATH:=$(core_includePath)# $(app_includePath)
INCLUDEFLAG:=$(foreach src,$(INCLUDEPATH),-I$(src) ) -I .

APP_SRC:=$(code_PWD)/app/app.cpp
APP_OBJ:=$(Makefile_PWD)/app/app.o

$(APP_OBJ): $(CORE_OBJ) $(APP_SRC)
	$(CC) $(COMPILER_FLAGS) $(DEFINES) $(INCLUDEFLAG) -o $(APP_OBJ) -c $(APP_SRC)


#------------------------------------------------------

$(TARGET): $(CORE_LIB) $(APP_OBJ)
	$(CC) $(DEFINES) $(INCLUDEFLAG) -o $(TARGET) $(APP_OBJ) $(CORE_OBJ) -L$(Makefile_core_PWD) -lcore

#------------------------------------------------------


clean: clean_core
	-rm $(APP_OBJ)

clean_bin:
	-rm $(TARGET)

clean_all: clean clean_bin
