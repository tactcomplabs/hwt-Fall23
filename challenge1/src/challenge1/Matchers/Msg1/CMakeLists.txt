# CHALLENGE1 src/challenge1/Matchers/Msg1/CMakeLists.txt
#
# Copyright (C) 2017-2023 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# See LICENSE in the top level directory for licensing details
#

set(Msg1Sources
  Msg1.h
)

#------------------------------------------------------------------------
# Setup the object target
#------------------------------------------------------------------------
include_directories(.)
add_library(Msg1Objs OBJECT ${Msg1Sources})

# EOF
