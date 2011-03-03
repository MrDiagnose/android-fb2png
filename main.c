/*
 *   -- http://android-fb2png.googlecode.com/svn/trunk/main.c --
 *
 *   Copyright 2011, Kyan He <kyan.ql.he@gmail.com>
 *
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>

#include "fb2png.h"

#ifdef ANDROID
    #define DEFAULT_SAVE_PATH "/data/local/fbdump.png"
#else
    #define DEFAULT_SAVE_PATH "fbdump.png"
#endif

int main(int argc, char *argv[])
{
    char fn[128];

    if (argc == 2) {
        //if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
        if (argv[1][0] == '-') {
            printf(
                "Usage: fb2png [path/to/output.png]\n"
                "    The default output path is /data/local/fbdump.png\n"
                );
            exit(0);
        } else {
            sprintf(fn, "%s", argv[1]);
        }
    } else {
        sprintf(fn, "%s", DEFAULT_SAVE_PATH);
    }

    return fb2png(fn);
}
