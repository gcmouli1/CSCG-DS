EXE = cscgds
SOURCEPATH = $(shell pwd)
STATICLIBRARY = libcscgds.a

OBJFUNCEVAL = funcEval.o 

LIBPATH = $(SOURCEPATH)/
INCLUDEDIR = 
LIBRARYPATH += -L $(LIBPATH)

# C Compiler command
CC = gcc

# C Compiler options
CFLAGS = -O3 
CSCGDSFLAG = -lcscgds

# additional C Compiler options for linking
LFLAGS = -Wl,-rpath=$(LIBPATH) -llapack -lblas -lgfortran -lquadmath -lm 

cscgds : $(OBJFUNCEVAL) 
	$(CC)  $^  $(INCLUDEDIR) $(LIBRARYPATH) -o $@ $(CFLAGS) -static $(CSCGDSFLAG) $(LFLAGS)

%.o : %.c
	$(CC) -c $^ $(INCLUDEDIR) $(LIBRARYPATH) $(CFLAGS) $(LFLAGS) $(CSCGDSFLAG) -o $@

%.o : %.f
	$(CC) -c $^ $(INCLUDEDIR) $(LIBRARYPATH) $(CFLAGS) $(LFLAGS) $(FORTRANFLAG) $(CSCGDSFLAG) -o $@

%.o : %.for
	$(CC) -c $^ $(INCLUDEDIR) $(LIBRARYPATH) $(FORTRANFLAG) $(LFLAGS) -o $@

clean:
	rm -f  $(OBJS) funcEval.o
