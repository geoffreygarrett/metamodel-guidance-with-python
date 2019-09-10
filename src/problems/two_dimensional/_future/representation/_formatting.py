from collections import namedtuple
from prettytable import PrettyTable
import pandas as pd
import numpy as np

# Formatting global arguments.
LaTeX_IMPULSE_NAME_C = r"Coefficient ($a_k$)"
LaTeX_IMPULSE_NAME_T = r"Impulse ($\delta{(t-t_k)}$)"
LaTeX_IMPULSE_NAME_N = r"N"


def process_latex_tabular_string_to_table_string(self, tabular_string):
    """
    :param tabular_string: String exported by Pandas.dataframe.tostring(), to be processed for documentation.
    :return: Processed string.
    """
    _tabular_string = tabular_string
    _preshaving, _tabular_string = _tabular_string.split(r"\toprule")
    _tabular_string, _postshaving = _tabular_string.split(r"\bottomrule")
    _tabular_string_rows = _tabular_string.split(r"\\")
    if r"{} &" in _tabular_string_rows[0]:
        _headers = [_tabular_string_rows[1].split(r"&")[0]] + _tabular_string_rows[0].split(r"&")[1:]
        _headers = r" & ".join(_headers)
        _tabular_string_rows = [_headers] + _tabular_string_rows[2:]
        _tabular_string = r"\\".join(_tabular_string_rows).replace(r"\midrule", r"")
    _preamble = [
        r"\begin{table}",
        r"\centering",
        r"\caption{Test}",
        r"\begin{tabular*}"
    ]
    _postamble = [
        fr"\caption{{"
        + fr"("
        + fr"\tilde{{a}}\in[-1,1];\;"
        + fr"\Delta{{\Omega}}_{{max}}={np.round(self.delta_omega_max, 3)});\;"
        + fr"t\in[{np.round(self.time_bounds, 3)[0]},{np.round(self.time_bounds, 3)[-1]}];\;"
        + fr"\theta\in[{np.round(self.theta_bounds, 3)[0]},{np.round(self.theta_bounds, 3)[-1]}];\;"
        + fr"\Omega\in[{np.round(self.omega_bounds, 3)[0]},{np.round(self.omega_bounds, 3)[-1]}];\;"
        + fr"}}"
          r"\end{tabular*}",
        r"\end{table}",
    ]
    return "\n".join(_preamble) + _tabular_string + "\n".join(_postamble)


def representation_latex_table(self, df):
    _df = df.sort_values(by=[LaTeX_IMPULSE_NAME_T])
    _df.index.name = LaTeX_IMPULSE_NAME_N
    _df.index += 1
    _tabular_str = _df.to_latex(escape=False, index=True)
    return process_latex_tabular_string_to_table_string(self, _tabular_str)


def representation_base_repr(self):
    _repr = PrettyTable()
    _repr.add_column("a", self.a_array)
    _repr.add_column("DiracDelta(t-t_i)", self.k_array)
    _repr = _repr.get_string() + "\n"
    _repr += str(f"ΔΩ max: {self.delta_omega_max} \n")
    _repr += str(f"t bounds: {self.time_bounds} \n")
    _repr += str(f"θ bounds: {self.theta_bounds} \n")
    _repr += str(f"Ω bounds: {self.omega_bounds} \n")
    return _repr


def representation_base_latex(self):
    _df = pd.DataFrame(data={
        LaTeX_IMPULSE_NAME_C: self.a_array,
        LaTeX_IMPULSE_NAME_T: self.k_array})
    return representation_latex_table(self, _df)
