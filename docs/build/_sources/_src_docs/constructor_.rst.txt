**mmgpy.constructor**
*********************


.. graphviz::

    digraph constructors {
        label = "Choose your contestant!";
        # General node settings.
        node [shape = box, style = filled, width = 1.5, fixedsize = true, color = lightblue, fontname = Times, fontsize = 10];
        graph [splines=ortho, nodesep=0.5, ranksep=1, pad="0.2,0.2"];
        compound=true;


        subgraph cluster_TimeSeries {
            label = "TimeSeries";
            node [shape=record];
            style = "dashed";

            ZerothTimeDerivative    [label="ZerothTimeDerivative"];
            FirstTimeDerivative     [label="FirstTimeDerivative"];
            SecondTimeDerivative    [label="FirstTimeDerivative"];
        }

        subgraph cluster_ContinuousInterpolation {
            label = "ContinuousInterpolation";
            node [shape=record];
            style = "dashed";

            LinearInterpolation     [label="LinearInterpolation"];
            NearestInterpolation    [label="NearestInterpolation"];
            CubicInterpolation      [label="CubicInterpolation"];
        }

        subgraph cluster_TimeIntervalConstructor {
            label = "TimeIntervalConstructor";
            node [shape=record];
            style = "dashed";

            DesignedTimeIntervals   [label="DesignedTimeInterval"];
            VectorTimeIntervals     [label="VectorTimeInterval"];
            EqualTimeIntervals      [label="EqualTimeIntervals"];
        }

        VectorTimeIntervals -> NearestInterpolation [ltail=cluster_TimeIntervalConstructor,lhead=cluster_ContinuousInterpolation];
        NearestInterpolation -> FirstTimeDerivative  [ltail=cluster_ContinuousInterpolation,lhead=cluster_TimeSeries];

    }