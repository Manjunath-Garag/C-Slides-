TARGET := ../libraray/libhashing.so
SOURCE := hashing.c

${TARGET} : ${SOURCE}
	gcc -fPIC -shared $^ -o $@

clean:
	-rm -f ${TARGET}

