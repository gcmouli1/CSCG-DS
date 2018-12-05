EXE = csgmads
SOURCEPATH = $(shell pwd)
STATICLIBRARY = libcscgds.a

OBJFUNCEVAL = funcEval.o 

LIBPATH = $(SOURCEPATH)
INCLUDEDIR = 
LIBRARYPATH += -L $(LIBPATH)

# C Compiler command
CC = gcc

# C Compiler options
CFLAGS = -ggdb
FORTRANFLAG = -lgfortran
CSCGMADSFLAG = -lcscgds

# additional C Compiler options for linking
LFLAGS = -llapack -lblas -lm -Wl,-rpath=$(LIBPATH)

csgds : $(OBJFUNCEVAL) 
	$(CC)  $^  $(INCLUDEDIR) $(LIBRARYPATH) $(CFLAGS) $(LFLAGS) $(CSCGMADSFLAG) -o $@

%.o : %.c
	$(CC) -c $^ $(INCLUDEDIR) $(LIBRARYPATH) $(CFLAGS) $(LFLAGS) $(CSCGMADSFLAG) -o $@

#%.o : %.f
#	$(CC) -c $^ $(INCLUDEDIR) $(LIBRARYPATH) $(CFLAGS) $(LFLAGS) $(FORTRANFLAG) $(CSCGMADSFLAG) -o $@

#%.o : %.for
#	$(CC) -c $^ $(INCLUDEDIR) $(LIBRARYPATH) $(FORTRANFLAG) $(LFLAGS) -o $@

clean:
	rm -f funcEval.o csgds OUTPUTFILE.txt
