#ifndef _FileInMemoryManager_h_
#define _FileInMemoryManager_h_
/* FileInMemoryManager.h
 *
 * Copyright (C) 2017 David Weenink
 *
 * This code is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This code is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this work. If not, see <http://www.gnu.org/licenses/>.
 */


#include "FileInMemorySet.h"
#include "Strings_.h"
#include "Table.h"

/*
Collection_define (SortedSetOfLong, SortedSetOf, SimpleLong) {
	static int s_compareHook (SimpleLong me, SimpleLong thee) {
		if (my number < thy number) return -1;
		if (my number > thy number) return +1;
		return 0;
	}
	CompareHook v_getCompareHook ()
		override { return s_compareHook; }
};*/

#include "FileInMemoryManager_def.h"

autoFileInMemoryManager FileInMemoryManager_create (FileInMemorySet files);

autoFileInMemory FileInMemoryManager_createFile (FileInMemoryManager me, MelderFile file);

autoFileInMemorySet FileInMemoryManager_extractFiles (FileInMemoryManager me, kMelder_string which, const char32 *criterion);

autoTable FileInMemoryManager_downto_Table (FileInMemoryManager me, bool openFilesOnly);

/*
	File open and read emulations. The FILE * is internally used as an pointer to the index of the file in the Set.
	List of open files has to contain per file: index, position, length (bytes), pointer to data
*/

bool FileInMemoryManager_hasDirectory (FileInMemoryManager me, const char32 *name);

FILE *FileInMemoryManager_fopen (FileInMemoryManager me, const char *filename, const char *mode);

void FileInMemoryManager_rewind (FileInMemoryManager me, FILE *stream);

int FileInMemoryManager_fclose (FileInMemoryManager me, FILE *stream);

int FileInMemoryManager_feof (FileInMemoryManager me, FILE *stream);

integer FileInMemoryManager_ftell (FileInMemoryManager me, FILE *stream);

int FileInMemoryManager_fseek (FileInMemoryManager me, FILE *stream, integer offset, int origin);

char *FileInMemoryManager_fgets (FileInMemoryManager me, char *str, int num, FILE *stream);

size_t FileInMemoryManager_fread (FileInMemoryManager me, void *ptr, size_t size, size_t count, FILE *stream);

int FileInMemoryManager_fgetc (FileInMemoryManager me, FILE *stream);

int FileInMemoryManager_ungetc (FileInMemoryManager me, int character, FILE * stream);

int FileInMemoryManager_GetFileLength (FileInMemoryManager me, const char *filename);

#endif // _FileInMemoryManager_h_
