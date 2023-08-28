#!/bin/bash
# SBATCH --nodes=7
#
# Copyright (C) 2017-2023 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# This file is a part of the PAN-RUNTIME package.  For license
# information, see the LICENSE file in the top level directory of
# this distribution.
#
# sbatch -N7 slurm.sh
#

module load riscv/gcc/12.2.0 sst/13.0.0 cmake/3.23.0 riscv-linux/gcc/12.2.0
srun hostname > output.txt
mpirun --hostfile output.txt -np 112 sst Torus.py
