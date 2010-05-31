/**
 * Copyright (C) 2009-2010, Shao Miller <shao.miller@yrdsb.edu.on.ca>.
 *
 * This file is part of WinVBlock, derived from WinAoE.
 *
 * WinVBlock is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * WinVBlock is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with WinVBlock.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _filedisk_h
#  define _filedisk_h

/**
 * @file
 *
 * File-backed disk specifics
 *
 */

winvblock__def_struct ( filedisk__type )
{
  disk__type_ptr disk;
  HANDLE file;
  winvblock__uint32 hash;
  device__free_routine prev_free;
  LIST_ENTRY tracking;
  LARGE_INTEGER offset;
};

extern irp__handler_decl (
  filedisk__attach
 );

/**
 * Initialize the global, file-backed disk-common environment
 *
 * @ret ntstatus        STATUS_SUCCESS or the NTSTATUS for a failure
 */
extern NTSTATUS filedisk__init (
  void
 );

/**
 * Create a new file-backed disk
 *
 * @ret filedisk_ptr    The address of a new filedisk, or NULL for failure
 *
 * This function should not be confused with a PDO creation routine, which is
 * actually implemented for each device type.  This routine will allocate a
 * filedisk_type, track it in a global list, as well as populate the disk
 * with default values.
 */
extern filedisk__type_ptr filedisk__create (
  void
 );

#endif				/* _filedisk_h */
