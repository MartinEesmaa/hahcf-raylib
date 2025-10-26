#!/bin/bash

modify_source_code() {

    if [ ! -d "romfs" ]; then
        mkdir romfs
    fi

    cp -rf font romfs
    cp -rf img romfs
    cp -rf chapter romfs
    cp -rf background romfs
    cp -rf character romfs

    if [ ! -d "source" ]; then
        mkdir source
    fi
    cp -f *.c *.h source/

    sed -i 's|img/|romfs:/img/|g' source/*.c
    sed -i 's|font/|romfs:/font/|g' source/*.c
    sed -i 's|chapter/|romfs:/chapter/|g' source/*.c
    sed -i 's|background/|romfs:/background/|g' source/*.c
    sed -i 's|character/|romfs:/character/|g' source/*.c
}

clean_build() {
    rm -rf romfs source build
    if [ -f Makefile.bak ]; then
        mv Makefile Makefile.NX
        mv Makefile.bak Makefile
    fi
    exit 1
}

handle_cancel() {
    echo "Katkestatud, tagasi..."
    clean_build
}

cp Makefile Makefile.bak
cp Makefile.NX Makefile

trap handle_cancel INT TERM

modify_source_code

if ! make PLATFORM=PLATFORM_NX; then
    echo "Make vigu. Tagasi..."
    clean_build
fi

clean_build
