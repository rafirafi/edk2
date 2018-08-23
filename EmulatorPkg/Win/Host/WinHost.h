/**@file

Copyright (c) 2006 - 2018, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials
are licensed and made available under the terms and conditions of the BSD License
which accompanies this distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.


Module Name:
  WinHost.h

Abstract:
  Include file for Windows Host

**/
#ifndef _HOST_H_
#define _HOST_H_

#include <stdio.h>
#include <time.h>
#include "WinInclude.h"

#include <PiPei.h>
#include <IndustryStandard/PeImage.h>
#include <Guid/FileInfo.h>
#include <Guid/FileSystemInfo.h>
#include <Guid/FileSystemVolumeLabelInfo.h>
#include <Ppi/EmuThunk.h>
#include <Protocol/EmuThunk.h>
#include <Protocol/SimpleFileSystem.h>


#include <Library/BaseLib.h>
#include <Library/PeCoffLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/ThunkPpiList.h>
#include <Library/ThunkProtocolList.h>
#include <Library/PcdLib.h>
#include <Library/PrintLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/PeiServicesLib.h>
#include <Library/PeCoffExtraActionLib.h>


#define TEMPORARY_RAM_SIZE                0x20000

typedef struct {
  VOID                  *Address;
  UINTN                 Size;
} NT_FD_INFO;

typedef struct {
  EFI_PHYSICAL_ADDRESS  Memory;
  UINT64                Size;
} NT_SYSTEM_MEMORY;

RETURN_STATUS
EFIAPI
SecPeCoffGetEntryPoint (
  IN     VOID  *Pe32Data,
  IN OUT VOID  **EntryPoint
);

VOID
SecLoadSecCore (
  IN  UINTN   TemporaryRam,
  IN  UINTN   TemporaryRamSize,
  IN  VOID    *BootFirmwareVolumeBase,
  IN  UINTN   BootFirmwareVolumeSize,
  IN  VOID    *SecCorePe32File
)
/*++

Routine Description:
  This is the service to load the SEC Core from the Firmware Volume

Arguments:
  TemporaryRam            - Memory to use for SEC.
  TemporaryRamSize        - Size of Memory to use for SEC
  BootFirmwareVolumeBase  - Start of the Boot FV
  SecCorePe32File         - SEC Core PE32

Returns:
  Success means control is transfered and thus we should never return

--*/
;

EFI_STATUS
EFIAPI
SecWinNtFdAddress (
  IN     UINTN                 Index,
  IN OUT EFI_PHYSICAL_ADDRESS  *FdBase,
  IN OUT UINT64                *FdSize
  )
/*++

Routine Description:

  TODO: Add function description

Arguments:

  Index   - TODO: add argument description
  FdBase  - TODO: add argument description
  FdSize  - TODO: add argument description

Returns:

  TODO: add return values

--*/
;


EFI_STATUS
EFIAPI
SecImageRead (
  IN     VOID    *FileHandle,
  IN     UINTN   FileOffset,
  IN OUT UINTN   *ReadSize,
  OUT    VOID    *Buffer
  )
/*++

Routine Description:

  TODO: Add function description

Arguments:

  FileHandle  - TODO: add argument description
  FileOffset  - TODO: add argument description
  ReadSize    - TODO: add argument description
  Buffer      - TODO: add argument description

Returns:

  TODO: add return values

--*/
;

CHAR16                            *
AsciiToUnicode (
  IN  CHAR8   *Ascii,
  IN  UINTN   *StrLen OPTIONAL
  )
/*++

Routine Description:

  TODO: Add function description

Arguments:

  Ascii   - TODO: add argument description
  StrLen  - TODO: add argument description

Returns:

  TODO: add return values

--*/
;

UINTN
CountSeparatorsInString (
  IN  CONST CHAR16   *String,
  IN  CHAR16   Separator
  )
/*++

Routine Description:

  TODO: Add function description

Arguments:

  String    - TODO: add argument description
  Separator - TODO: add argument description

Returns:

  TODO: add return values

--*/
;

BOOLEAN
EfiSystemMemoryRange (
  IN  VOID *MemoryAddress
  );
VOID
SecInitializeThunk (
  VOID
);
extern EMU_THUNK_PROTOCOL    gEmuThunkProtocol;
extern EMU_IO_THUNK_PROTOCOL mWinNtWndThunkIo;
extern EMU_IO_THUNK_PROTOCOL mWinNtFileSystemThunkIo;
#endif