# makefile for compiling native unix builds
# use "make -f makefile.unix RELEASE=TRUE" to create release executable

CC	= g++

GFLAGS	= -Wall `sdl-config --cflags`

#ifdef RELEASE
CFLAGS	= $(GFLAGS) -O2 -funroll-loops -ffast-math -fomit-frame-pointer -fno-strength-reduce -finline-functions -s
#else
#CFLAGS	= $(GFLAGS) -gstabs+
#endif

LIBS = `sdl-config --libs` `pkg-config --libs gtk+-2.0` -lz

cap32: cap32.cpp crtc.o fdc.o glfuncs.o psg.o tape.o video.o insertdisk.o z80.o cap32.h z80.h
	$(CC) $(CFLAGS) $(IPATHS) -o cap32 cap32.cpp crtc.o fdc.o glfuncs.o psg.o tape.o video.o z80.o insertdisk.o $(LIBS) && mv cap32 ../

crtc.o: crtc.c cap32.h crtc.h z80.h
	$(CC) $(CFLAGS) -c crtc.c

fdc.o: fdc.c cap32.h z80.h
	$(CC) $(CFLAGS) -c fdc.c

glfuncs.o: glfuncs.cpp glfuncs.h glfunclist.h
	$(CC) $(CFLAGS) -c glfuncs.cpp

psg.o: psg.c cap32.h z80.h
	$(CC) $(CFLAGS) -c psg.c

tape.o: tape.c cap32.h tape.h z80.h
	$(CC) $(CFLAGS) -c tape.c

video.o: video.cpp video.h
	$(CC) $(CFLAGS) -c video.cpp

insertdisk.o: insertdisk.c insertdisk.h
	$(CC) $(CFLAGS) `pkg-config --cflags-only-I gtk+-2.0` -c insertdisk.c

z80.o: z80.c z80.h cap32.h
	$(CC) $(CFLAGS) -c z80.c

clean:
	rm *.o ../cap32
