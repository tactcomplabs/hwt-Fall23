# HackWesTex/Tactical Computing Labs Challenge #2

## Overview

The Structural Simulation Toolkit (SST) is a parallel discrete event 
simulation infrastructure designed to support multi-reslution simulations.  
In this case, SST is most often utilized to simulate a variety of different 
computer architecture devices/components.  Unlike other simulation infrastructures 
such as QEMU and Gem5, SST utilizes MPI (message passing interface) and C++ threading 
such that simulations can be scaled out to a large number of host systems.  This 
permits us to build full-system simulations with high fidelity components 
for each discrete architectural unit.

One of the inherent downsides to building very large simulation experiments 
is the size and scope of the output data can be very large.  SST provides 
distinct statistics output from each unique SST component in a variety of 
forms (CSV being the most common).  For this challenge problem, we seek 
to ingest these large, structured CSV files into a web-based, graphical 
visualization and analysis tool such as Grafana.

The difficulty in ingesting these data files into SST is that the particular 
components and included data will not be known until the filese are actually 
ingested.  Further, we seek to cross correlate events and data values across 
disparate component data units in the visualization tool.

## Requirements

There are a number of basic requirements for this challenge, including:
* You must ingest and build the visualizations from the provided files.  Note 
that you *CANNOT* build visualization templates beforehand.  They must be 
generated dynamically.
* SST provides other output data types.  If you can generate different 
output forms (as long as they are standard SST outputs), they can be used
* Grafana is the preferred visualization tool, but you can utilize other 
tools as well.
* Any external plugins utilized must be MIT, BSD or Apache licensed.  No GPL-3 code
will be accepted

Be creative!  Dynamic visualizations will be given priority over basic, static 
graphs.  Additional points will be given to those that can build, run and demonstrate 
SST, especially if you can stream data directly into the visualization tool.

## Deliverables

The deliverables for this challenge include:
* A working demo of your integrated visualization infrastructure.  We must see it work!
* Any source code associated with the solution (scripts, etc)
* Concise documentation to build, integrate and test the solution.  This should also 
include any required external packages outside of what is outlined above.

## Sample Statistics Output

The statistics for each test is contained within one or more CSV files.  For 
parallel runs, there exists one CSV rank per MPI rank.  As a result, some tests 
require ingesting one CSV file.  Some tests require ingesting many CSV files 
that make up the full data set.

## Licensing

See the top-level LICENSE file

## Contact
* *John Leidel* - *Chief Scientist* - [Tactical Computing Labs](http://www.tactcomplabs.com)
