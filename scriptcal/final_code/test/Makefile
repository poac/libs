NAME = Test

INC = ../include/
INC3 = /usr/local/include/
INC5 = $(POACLIBDIR)/include/
INC6 = $(POACLIBDIR)/
INC7 = $(POACLIBDIR)/scriptcal/include/
LINKDIRS = /usr/local/lib -L../../lib
LINKLIBS = cppunit 
INCLUDES =  -I$(INC) -I$(INC3) -I$(INC5) -I$(INC6) -I$(INC7)
CFLAGS = -ldl $(INCLUDES) -D$(_SYSTEM) -L$(LINKDIRS) -l$(LINKLIBS)

SRCS = $(wildcard src/*.cpp)
OBJS = $(filter %.o, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@echo '===> Linking '
	g++ -g -O2 -o $(NAME) $^ $(CFLAGS)
	cp $(NAME) ../

$(OBJS): %.o: %.cpp
	g++ -c $(INCLUDES) -D$(_SYSTEM) $< -o $@

clean:
	-rm -Rf $(NAME) $(OBJS)
