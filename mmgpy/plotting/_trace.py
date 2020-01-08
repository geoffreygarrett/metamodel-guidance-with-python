import plotly
import plotly.graph_objects as go

from ._trisurf import *
from plotly.graph_objects import Figure
from itertools import cycle


class TraceManager:
    """
    Parent class for all derived plot types in N dimensions.
    """

    def __init__(self, figure=None, name=None):
        """

        Parameters
        ----------
        figure
        """
        self._figure = figure or Figure()
        self._layout = dict(scene_aspectmode='cube',
                            scene_camera=dict(
                                # up=dict(x=0, y=0, z=-10),
                                center=dict(x=0, y=0, z=-0.20),
                                # eye=dict(x=1.25, y=1.25, z=1.25),
                            ),
                            xaxis=dict(title="test"),
                            title=name, autosize=True,
                            # width=620, height=580,
                            # autosize=True,
                            # margin=dict(l=65, r=50, b=65, t=90)
                            )

        self._data = []

        self._color_cycle = cycle(plotly.colors.DEFAULT_PLOTLY_COLORS)

    @property
    def layout(self):
        """

        Returns
        -------
        plotly.graph_objects.Layout

        """
        return self._layout

    @property
    def figure(self):
        """

        Returns
        -------
        plotly.graph_objects.Figure

        """
        return self._figure

    def show(self, renderer=None):
        """Shows the plot in the Notebook.
        Updates the layout and returns the underlying figure.

        Parameters
        ----------
        renderer : [optional, str]

        Returns
        -------

        """
        self._figure = Figure(self._data)
        # for trace in self._data:
        #     self._figure.add_trace(trace)
        self._figure.layout.update(self._layout)
        self._figure.show(renderer=renderer)
        # return self._figure

    def save(self, path):
        """

        Parameters
        ----------
        path

        Returns
        -------

        """

        self._figure = Figure(self._data)
        self._figure.layout.update(self._layout)
        self._figure.write_image(path)


class TraceManager2D(TraceManager):
    def __init__(self, figure=None):
        """

        Parameters
        ----------
        figure
        """
        super().__init__(figure)

    def add_scatter(self, *coords, **kwargs):
        """

        Parameters
        ----------
        coords
        kwargs

        Returns
        -------

        """
        assert len(coords) == 2, "Length of coordinates must be 2."
        x, y = coords
        marker_size = kwargs.pop("marker_size", 4.0)
        marker_opacity = kwargs.pop("marker_opacity", 0.7)
        marker_line_width = kwargs.pop("marker_line_width", 1.5)
        marker_line_color = kwargs.pop("marker_line_color", 'black')
        marker_color = 'rgba(255,255,153,0.8)'
        marker_line = kwargs.pop(
            "marker_line",
            dict(width=marker_line_width,
                 color=marker_line_color))
        marker = kwargs.pop(
            "marker",
            dict(size=marker_size,
                 opacity=marker_opacity,
                 line=marker_line,
                 color=marker_color))
        extra_kwargs = kwargs
        self._data.append(go.Scatter(x=x.flatten(),
                                     y=y.flatten(),
                                     mode="markers",
                                     marker=marker,
                                     **extra_kwargs))

    def add_line(self, *coords, **kwargs):
        """

        Parameters
        ----------
        coords
        kwargs

        Returns
        -------

        """
        assert len(coords) == 2, "Length of coordinates must be 2."
        x, y = coords
        # marker_size = kwargs.pop("marker_size", 4.0)
        # marker_opacity = kwargs.pop("marker_opacity", 0.7)
        # marker_line_width = kwargs.pop("marker_line_width", 1.5)
        # marker_line_color = kwargs.pop("marker_line_color", 'black')
        # marker_color = 'rgba(255,255,153,0.8)'
        # marker_line = kwargs.pop(
        #     "marker_line",
        #     dict(width=marker_line_width,
        #          color=marker_line_color))
        # marker = kwargs.pop(
        #     "marker",
        #     dict(size=marker_size,
        #          opacity=marker_opacity,
        #          line=marker_line,
        #          color=marker_color))
        extra_kwargs = kwargs
        self._data.append(go.Scatter(x=x.flatten(),
                                     y=y.flatten(),
                                     mode="lines",
                                     **extra_kwargs))

    def add_contour(self, *coords, **kwargs):
        """

        Parameters
        ----------
        coords
        kwargs

        Returns
        -------

        """
        assert len(coords) == 2, "Length of coordinates must be 2."
        x, y = coords
        colorscale = kwargs.pop('colorscale', 'inferno')
        self._data.append(
            go.Histogram2dContour(
                x=x,
                y=y,
                colorscale=colorscale,
                **kwargs
            )
        )


class TraceManager3D(TraceManager):
    def __init__(self, figure=None):
        """

        Parameters
        ----------
        figure
        """
        super().__init__(figure)

    def add_scatter(self, *coords, **kwargs):
        """

        Parameters
        ----------
        coords
        kwargs

        Returns
        -------

        """
        assert len(coords) == 3, "Length of coordinates must be 3."
        x, y, z = coords
        marker_size = kwargs.pop("marker_size", 4.0)
        marker_opacity = kwargs.pop("marker_opacity", 0.7)
        marker_line_width = kwargs.pop("marker_line_width", 1.5)
        marker_line_color = kwargs.pop("marker_line_color", 'black')
        marker_color = 'rgba(255,255,153,0.8)'
        marker_line = kwargs.pop(
            "marker_line",
            dict(width=marker_line_width,
                 color=marker_line_color))
        marker = kwargs.pop(
            "marker",
            dict(size=marker_size,
                 opacity=marker_opacity,
                 line=marker_line,
                 color=marker_color))
        extra_kwargs = kwargs
        self._data.append(go.Scatter3d(x=x.flatten(),
                                       y=y.flatten(),
                                       z=z.flatten(),
                                       mode="markers",
                                       marker=marker,
                                       **extra_kwargs))

    def add_surface(self, *coords, **kwargs):
        """

        Parameters
        ----------
        coords
        kwargs

        Returns
        -------

        """
        assert len(coords) == 3, "Length of coordinates must be 3."
        x, y, z = coords
        contours_z = kwargs.pop('contours_z', False)
        if contours_z:
            _contours_z = dict(show=True, usecolormap=True,
                               highlightcolor="limegreen", project_z=True)
        else:
            _contours_z = None
        colorscale = kwargs.pop('colorscale', 'inferno')
        extra_kwargs = kwargs
        self._data.append(go.Surface(x=x, y=y, z=z, colorscale=colorscale,
                                     contours_z=_contours_z,
                                     **extra_kwargs))

    def add_trisurf(self, *coords, **kwargs):
        """

        Parameters
        ----------
        coords
        kwargs

        Returns
        -------

        """
        assert len(coords) == 3, "Length of coordinates must be 3."
        x, y, z = coords
        points2D = np.vstack([x, y]).T
        tri = Delaunay(points2D)
        simplices = tri.simplices
        self._data += plotly_trisurf(x, y, z, simplices, colormap=cm.inferno,
                                     plot_edges=None)


if __name__ == "__main__":
    from plotly.subplots import make_subplots
    import plotly.graph_objects as go


    def plot1by2(ob1, ob2):
        fig = make_subplots(
            rows=1, cols=2,
            specs=[[{}, {'type': 'surface'}]]
        )
        for data1 in ob1._data:
            fig.add_trace(data1, row=1, col=1)

        for data1 in ob2._data:
            fig.add_trace(data1, row=1, col=2)
        return fig


    t = TraceManager2D()

    x = np.linspace(0, 1, 100)
    y = np.linspace(0, 1, 100)
    x, y = np.meshgrid(x, y)
    z = np.sin(x * 6 * np.pi)

    t.add_contour(x.flatten(), y.flatten(), colorscale='Blues',
                  showscale=False)
    t.save("./test.png")

    t3d = TraceManager3D()
    t3d.add_surface(x, y, z, showscale=False, contours_z=False)
    t3d.save("./test2.png")

    f = plot1by2(t, t3d)
    t._layout.update({"width": 1050})
    f.update_layout(t._layout)
    f.write_image("./test3.png")
