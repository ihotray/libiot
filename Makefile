CC ?= gcc
DEFS ?=
EXTRA_CFLAGS ?= -Wall -Werror
CFLAGS += $(DEFS) $(EXTRA_CFLAGS)

LIBIOT_CFLAGS = -DMG_ENABLE_MBEDTLS -DMG_ENABLE_IPV6 -DMG_ENABLE_DIRLIST=0
LIBIOT_LDFLAGS = -lmbedtls -lmbedx509 -lmbedcrypto

LIBS +=
VFLAGS=$(shell ./genversion.sh)

json_objs = cJSON-json.o
base_objs_lib = mongoose-base.o
base_nossl_objs_lib = mongoose-base-nossl.o

ver=$(shell cat ./VERSION)
maj=$(shell cat ./VERSION | cut -f1 -d.)

.PHONY: all tests clean install

all: libiot-json.so.$(ver) libiot-base.so.$(ver) libiot-base-nossl.so.$(ver)

%-json.o: %.c
	$(CC) $(CFLAGS) $(VFLAGS) -fPIC -c -o $@ $<

%-base.o: %.c
	$(CC) $(CFLAGS) $(LIBIOT_CFLAGS) $(VFLAGS) -fPIC -c -o $@ $<

%-base-nossl.o: %.c
	$(CC) $(CFLAGS) $(VFLAGS) -fPIC -c -o $@ $<

libiot-json.so.$(ver): $(json_objs)
	$(CC) $(CFLAGS) $(VFLAGS) \
		-shared -Wl,-soname,libiot-json.so.$(maj) -o $@ $^ $(LIBS)
	-ln -sf $@ libiot-json.so.$(maj)
	-ln -sf $@ libiot-json.so

libiot-base.so.$(ver): $(base_objs_lib)
	$(CC) $(CFLAGS) $(VFLAGS) $(LIBIOT_LDFLAGS) \
		-shared -Wl,-soname,libiot-base.so.$(maj) -o $@ $^ $(LIBS)
	-ln -sf $@ libiot-base.so.$(maj)
	-ln -sf $@ libiot-base.so

libiot-base-nossl.so.$(ver): $(base_nossl_objs_lib)
	$(CC) $(CFLAGS) $(VFLAGS) \
		-shared -Wl,-soname,libiot-base-nossl.so.$(maj) -o $@ $^ $(LIBS)
	-ln -sf $@ libiot-base-nossl.so.$(maj)
	-ln -sf $@ libiot-base-nossl.so

tests:
	$(MAKE) -C tests all

INCDIR=/usr/include/iot

-include Makefile.inc

install: install-headers install-libs


clean:
	rm -f *.o *so*
