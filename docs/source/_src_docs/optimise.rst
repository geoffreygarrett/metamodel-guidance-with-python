**mmgpy.optimise**
==================

Constructors
############

Base constructor
****************

Base dynamics constructor
*************************

Routines
########

The general optimisation routine management framework is described by three routines: **initial**, **intermediate** and
**closing**. There are two conditions that are checked during further optimisation calls, which are dependent on the
current state of the optimisation manager: **reset** and **close**. Each subroutine optimisation call is performed on a
subset of the **global static parameters**. The following flowchart is exemplar of the framework.

.. graphviz::

   digraph foo {

        # General diagram settings.
        graph [splines=ortho, nodesep=0.5, pad="0.2,0.2"];

        # General node settings.
        node [shape = box, style = filled, width = 1.5, fixedsize = true, color = lightgrey, fontname = Times, fontsize = 10];

        # Specific node color settings.
        Global [color = lightgrey, label="Global static parameters"];
        Initial [color = aquamarine, label="Initial routine"];
        Intermediate [color = lightblue, label="Intermediate routine"];
        Closing [color = tomato, label="Closing routine"];

        # Decision node settings.
        reset [color = khaki1, shape = diamond, label="reset?"];
        close [color = khaki1, shape = diamond, label="close?"];

        subgraph cluster_process
        {
            # cluster settings
            fontsize = 9;
            style=invisible;

            Initial -> reset;
            reset -> Intermediate [ label="no" ];
            reset -> Initial [ label="yes" ];
            Intermediate -> close;
            close -> reset [ label="no" , spline=ortho ];
            close -> Closing [ label="yes" ];
        }


    }

Base optimisation routine
*************************

.. automodule:: optimise.routine
   :members:
   :private-members:
   :special-members:

.. automodule:: optimise.constructor
   :members:
   :private-members:
   :special-members: