# CHALLENGE1 src/challenge1/Matchers/CMakeLists.txt
#
# Copyright (C) 2017-2023 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# See LICENSE in the top level directory for licensing details
#

set(MsgSources
  Msg1.h
  Msg2.h
)

#------------------------------------------------------------------------
# Setup the object target
#------------------------------------------------------------------------
include_directories(.)
add_library(MsgObjs OBJECT ${MsgSources})

# EOF
