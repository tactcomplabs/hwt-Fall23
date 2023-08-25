# CHALLENGE1 src/challenge1/Matchers/Msg2/CMakeLists.txt
#
# Copyright (C) 2017-2023 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# See LICENSE in the top level directory for licensing details
#

set(Msg2Sources
  Msg2.h
)

#------------------------------------------------------------------------
# Setup the object target
#------------------------------------------------------------------------
include_directories(.)
add_library(Msg2Objs OBJECT ${Msg2Sources})

# EOF
